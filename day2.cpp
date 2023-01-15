#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Parte 2 só alterei o map um pouquito
int main() {
  map<string, int> mp;

  mp["A X"] = 3;
  mp["A Y"] = 4;
  mp["A Z"] = 8;
  mp["B X"] = 1;
  mp["B Y"] = 5;
  mp["B Z"] = 9;
  mp["C X"] = 2;
  mp["C Y"] = 6;
  mp["C Z"] = 7;

  string str;
  int ans = 0;

  while (getline(cin, str)) {
    // cout << mp[str] << endl;
    ans += mp[str];
  }

  cout << ans << endl;
  return 0;
}

// x - perder
// y - empate
// z - vencer

// AX - 1+3 = 4
// AY - 2+6 = 8
// AZ - 3+0 = 3
// BX - 1+0 = 1
// BY - 2 + 3 = 5
// BZ - 3 + 6 = 9
// CX - 1 + 6 = 7
// CY - 2 + 0 = 2
// CZ - 3 + 3 = 6

/**
 * A - PD
 * B - PP
 * C - T
 *
 * X - PD
 * Y - PP
 * Z - T
 *
 * PD - 1
 * PP - 2
 * T - 3
 *
 * L - 0
 * W - 6
 * E - 3
 */