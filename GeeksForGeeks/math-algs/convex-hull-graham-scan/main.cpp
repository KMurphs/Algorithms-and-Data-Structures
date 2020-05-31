#include <bits/stdc++.h>

using namespace std;

class Point{
  public:
    int x, y;
    Point(int _x, int _y){
      x = _x, y = _y;
    }
};


int isClockwise(Point p1, Point p2, Point p3){
  int dir = (p3.x - p2.x)*(p2.y - p1.y) - (p2.x - p1.x)*(p3.y - p2.y);
  if(dir > 0) return 1;
  if(dir < 0) return -1;
  return 0;
}

void Swap(vector<Point>& points, int x, int y){
  Point tmp = points[x];
  points[x] = points[y];
  points[y] = tmp;
}
int getAngle(Point ref, Point p){
  return (p.y - ref.y)/(p.x - ref.x);
}
int getDistance(Point ref, Point p){
  return (p.y - ref.y)*(p.y - ref.y) + (p.x - ref.x)*(p.x - ref.x);
}
void heapify(vector<Point>& points, int heapSize, int parent){
  int ch1 = 2 * parent + 1;
  int ch2 = 2 * parent + 2;
  int maxFamily = parent;

  int ch1Angle = getAngle(points[0], points[ch1]);
  int ch2Angle = getAngle(points[0], points[ch2]);
  int parentAngle = getAngle(points[0], points[parent]);
  int maxFamilyAngle = parentAngle;

  if(ch1 < heapSize && ch1Angle > maxFamilyAngle)
    maxFamily = ch1, maxFamilyAngle = ch1Angle;
  if(ch2 < heapSize && ch2Angle > parentAngle)
    maxFamily = ch2, maxFamilyAngle = ch2Angle;
  if(maxFamily != parent){
    Swap(points, maxFamily, parent);
    heapify(points, heapSize, parent);
  }
}

void heapSort(vector<Point>& points){

  for(int i = 1 + points.size()/2; i > 0; i--){
    heapify(points, points.size() - 1, i);
  }
  for(int i = points.size() - 1; i > 0; i--){
    Swap(points, 1, i);
    heapify(points, i - 1, 1);
  }

}


vector<Point> grahamScan(vector<Point> points){

  vector<Point> hull;

  // Find most bottom left
  int mbl = 0;
  for(int i = 1; i < points.size(); i++){
    if(
      points[mbl].y > points[i].y ||
      (points[mbl].y == points[i].y && points[mbl].x > points[i].x)
    )
      mbl = i;
  }
  // Make most bottom left, first in collection
  // this is the origin/reference for everything else that follows
  Swap(points, mbl, 0);


  // Sort by polar angle
  heapSort(points);


  // Mutate collection as to only have points which are not on the same radius
  // If points are met on the same radius, keep farthest point
  int newArrayCounter = 1;
  for(int i = 2; i < points.size(); i++){
    Point tmp = *new Point(0, 0);
    int tmpAngle;
    if(getAngle(points[0], points[i]) == getAngle(points[0], points[i - 1])){
      if(getDistance(points[0], points[newArrayCounter]) < getDistance(points[0], points[i]))
        Swap(points, newArrayCounter, i);
    }else{
      Swap(points, newArrayCounter, i);
      newArrayCounter++;
    }
  }


  // Do Graham
  if(newArrayCounter < 3) return points;
  hull.push_back(points[0]);
  hull.push_back(points[1]);
  hull.push_back(points[2]);
  for(int i = 3 ; i < points.size(); i++){
    if(isClockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
      hull.pop_back();   
    hull.push_back(points[i]);
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




  vector<Point> convexHull = grahamScan(Points);
  for(int i = 0 ; i < convexHull.size() ; i++){
    cout << "(" << convexHull[i].x << ", " << convexHull[i].y << ") ";
  }
  cout << endl;

  assert(convexHull.size() == 5);

  cout << "\n\nProgram exited successfully..." << endl;
  return 0;
}