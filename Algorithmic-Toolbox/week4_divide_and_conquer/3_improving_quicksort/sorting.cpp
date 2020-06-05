#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    } else if(a[i] == x){
        j++;
    }
  }
  swap(a[l], a[j]);
  return j;
}
void partition3(vector<int>&a, int l, int r, int& i, int&j) {
    int x = a[l];
    i = l, j = l;
    for(int k=l+1; k<=r; k++) {
        if(a[k] == x){
            j++;
            swap(a[j], a[k]);
        }
        if(a[k] < x){
            i++;   j++;
            swap(a[i], a[k]);
            if(a[k] == x){
                swap(a[j], a[k]);
            }
        }
    }
    swap(a[i], a[l]);
}
void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m = partition2(a, l, r);
    int i,j;
    partition3(a,l,r, i,j);

  randomized_quick_sort(a, l, i);
  randomized_quick_sort(a, j+1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
