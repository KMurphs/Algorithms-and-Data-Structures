
// C program for flattening a linked list 
#include <stdio.h> 
#include <stdlib.h> 
#include <cmath>

#include <bits/stdc++.h>
using namespace std;


int power(int a, int b){
    int res = 1;
    while(b != 0){
        if(b & 1)
            res = res * a;
        b = b >> 1, a = a * a;
    }
    return res;
}


void recur(set<int>& sols, int n, int m, int pos, int curr){

    int tmp = curr / power(10, pos);


    if(curr > m) {
        return;
    }
    if(curr >= n && curr <= m){
        sols.insert(curr);
    }


    for( set<int>::iterator itr = sols.begin() ; itr != sols.end() ; ++itr )
        cout << *itr << "  ";
    cout << endl;



    if(tmp + 1 <= 9) recur(sols, n, m, pos + 1, ((tmp + 1) * power(10, pos + 1)) + curr);
    if(tmp - 1 >= 0) recur(sols, n, m, pos + 1, ((tmp - 1) * power(10, pos + 1)) + curr);
}

set<int> stepNumbers(int n, int m){

    set<int> sols = *new set<int>();
    int curr;

    for(int i = 0; i < 10 ; i++){
        curr = i;
        recur(sols, n, m, 0, curr);
    }

    return sols;
}


set<int> stepNumbersQ(int n, int m){

    set<int> sols = *new set<int>();
    vector<pair<int, int>> Q = *new vector<pair<int, int>>();


    for(int i = 0; i < 10 ; i++){
        Q.push_back(pair<int, int>(i, 0));
    }

    pair<int, int> curr;
    int mult = 1, tmp, future, prev = -1;
    while (Q.size() != 0){
        curr = Q.front();
        Q.erase(Q.begin());


        if(curr.first >= n && curr.first <= m && curr.first != prev){
            sols.insert(curr.first);
            for( set<int>::iterator itr = sols.begin() ; itr != sols.end() ; ++itr )
                cout << *itr << "  ";
            cout << endl;
            prev = curr.first;
        }


        mult = power(10, curr.second);
        tmp = curr.first / mult;
        future = ((tmp - 1) * mult * 10) + curr.first;
        if(tmp - 1 >= 0 && future <= m) Q.push_back(pair<int, int>(future, curr.second + 1));
        future = ((tmp + 1) * mult * 10) + curr.first;
        if(tmp + 1 <= 9 && future <= m) Q.push_back(pair<int, int>(future, curr.second + 1)); 
    }
    

    return sols;
}




// https://www.geeksforgeeks.org/stepping-numbers/
// Driver program to test above functions 
int main() 
{ 

    assert(power(10, 2) == 100);

    int n, m, *exp, expSize;
    set<int> res;

    n = 0, m = 21, expSize = 13, exp = new int[expSize]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21 };
    res = stepNumbers(n, m);
    assert(res.size() == expSize);
    res = stepNumbersQ(n, m);
    assert(res.size() == expSize);


    n = 10, m = 15, expSize = 2, exp = new int[expSize]{ 10, 12 };
    res = stepNumbers(n, m);
    assert(res.size() == expSize);
    res = stepNumbersQ(n, m);
    assert(res.size() == expSize);

    cout << "\n\nProgram exited successfully" << endl;
    return 0; 
} 
