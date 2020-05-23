#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

struct Segment {
  int start, end;
};

bool sortby(const Segment &a,const Segment &b){
    return (a.end < b.end);
}

vector<int> optimal_points(vector<Segment> &segments) {
  sort(segments.begin(), segments.end(), sortby);

  vector<int> points;
  vector<bool> flags(segments.size(), false);

  //write your code here
  int i=0, prev=0;
  while( i<segments.size() ){
    prev = segments[i].end;
    i++;
    while(i<segments.size() && prev >= segments[i].start){
        i++;
    }
    points.push_back(prev);
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for(size_t i=0; i<points.size(); ++i)
    cout<<points[i]<<" ";
}
