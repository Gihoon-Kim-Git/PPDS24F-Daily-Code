#include <iostream>

using namespace std;

int AddingOneTwoThree(int x) {
  if (x < 0) return 0;
  if (x == 0) return 1;  // There is one way to create zero

  int num_ways = 0;
  for (int k = 1; k <= 3; ++k) {
    num_ways += AddingOneTwoThree(x - k);
  }
  return num_ways;
}

int main() {
  int n;
  // freopen("input.txt", "r", stdin);
  cin >> n;

  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    cout << AddingOneTwoThree(x) << endl;
  }
}