#include <bits/stdc++.h>

using namespace std;

class Point{
  public:
    int x, y;
    Point(int _x, int _y){
      x = _x, y = _y;
    }
};
struct sPoint 
{ 
    int x, y; 
}; 

int isClockwise(Point p1, Point p2, Point p3){
  int dir = (p3.x - p2.x)*(p2.y - p1.y) - (p2.x - p1.x)*(p3.y - p2.y);
  if(dir > 0) return 1;
  if(dir < 0) return -1;
  return 0;
}


vector<Point> jarvisHull(vector<Point> points){

  vector<Point> hull;

  // Find the most left point
  int ml = 0;
  for(int i = 1; i < points.size(); i++){
    if(
      points[ml].x > points[i].x ||
      (points[ml].x == points[i].x && points[ml].y > points[i].y)
    )
      ml = i;
  }

  
  int p = ml, q;
  while(q != ml){
    q = (p + 1) % points.size();
    
    // Find the most outside point i.e p, anything and q will go clockwise
    // in essence sweeping from down arrow in counter clock wise direction
    // unitl the first element is hit
    for(int i = 0; i < points.size(); i++){
      if(isClockwise(points[p], points[i], points[q]) == -1)
        q = i;
    }

    hull.push_back(points[q]);
    p = q;
  }

  return hull;
}

int main(){
  vector<Point> Points;
  
  Points.push_back(*new Point(0, 0));
  Points.push_back(*new Point(1, 1));
  Points.push_back(*new Point(2, 2));
  Points.push_back(*new Point(3, 1));
  Points.push_back(*new Point(2, -1));
  Points.push_back(*new Point(0, 2));
  Points.push_back(*new Point(0, 5));
  Points.push_back(*new Point(-1, -2));
  Points.push_back(*new Point(-1, -1));
  Points.push_back(*new Point(-2, -2));

  // for(int i = 0 ; i < Points.size(); i++)
    // cout << "(" << Points[i].x << ", " << Points[i].y << ") "<< endl;

  // vector<sPoint> sPoints;
  // sPoints.push_back({ 0, 0 });
  // for(int i = 0 ; i < sPoints.size(); i++)
  //   cout << "(" << sPoints[i].x << ", " << sPoints[i].y << ") "<< endl;


  vector<Point> convexHull = jarvisHull(Points);
  for(int i = 0 ; i < convexHull.size() ; i++){
    cout << "(" << convexHull[i].x << ", " << convexHull[i].y << ") ";
  }
  cout << endl;

  assert(convexHull.size() == 5);

  cout << "\n\nProgram exited successfully..." << endl;
  return 0;
}