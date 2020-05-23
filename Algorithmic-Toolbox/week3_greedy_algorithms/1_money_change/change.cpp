#include <iostream>
using namespace std;
int get_change(int m) {
    int ans = 0;
    if(m >= 10){
        int x = m/10;
        ans += x;
        m = m - (x*10);
    }
    if(m >= 5){
        int x = m/5;
        ans += x;
        m = m - (x*5);
    }
    ans +=m;
  return ans;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
