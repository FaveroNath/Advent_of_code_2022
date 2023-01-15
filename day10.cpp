#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

long long calc_wight(int weight, int x) {
  return (x * weight);
}

void print_ans(int& cycle, int x) {
  if (cycle == 40) {
    cout << endl;
    cycle = 0;
  }

  if (x == cycle || x - 1 == cycle || x + 1 == cycle)
    cout << "#";
  else
    cout << " ";
}

long long part1() {
  string cmd;
  long long n, cycle = 0, x = 1, ans = 0, cycles;

  vector<int> weights(N + 5);

  for (int i = 20; i <= 220; i += 40) {
    weights[i] = i;
  }

  while (cin >> cmd) {
    if (cmd == "noop")
      cycles = 1;
    else {
      cin >> n;
      cycles = 2;
    }

    for (int i = 0; i < cycles; i++) {
      cycle += 1;
      ans += calc_wight(weights[cycle], x);
      if (i == 1)
        x += n;
    }
  }

  return ans;
}

void part2() {
  string cmd;
  int n, cycle = 0, x = 1, cycles;

  while (cin >> cmd) {
    if (cmd == "noop")
      cycles = 1;
    else {
      cin >> n;
      cycles = 2;
    }

    for (int i = 0; i < cycles; i++) {
      if (i == 1) {
        cycle++;
        x += n;
        print_ans(cycle, x);
      } else {
        cycle++;
        print_ans(cycle, x);
      }
    }
  }
}

int main() {
  // cout << part1() << endl;
  part2();
  return 0;
}
