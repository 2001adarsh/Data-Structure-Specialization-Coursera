#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
/*
    for(int i=0; i<stops.size(); ++i)
        cout<<stops[i]<<" ";
    cout<<endl;
*/
    // write your code here
    int currentNumber = 0, lastInd = 0, count =0;
    while(currentNumber < stops.size()-1 ){
        lastInd = currentNumber;
        while( currentNumber < stops.size()-1 && (stops[currentNumber+1] - stops[lastInd] <= tank)) {
            currentNumber++;
            if(currentNumber == stops.size()-1 )
                break;
        }
        if(currentNumber == lastInd){
            return -1;
        }
        if(currentNumber < stops.size()-1){
      //    cout << currentNumber<<" ";
            count++;
        }
    }
    return count;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);
    stops[0] = 0;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);
    stops[n+1] = d;
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
