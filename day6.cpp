#include <bits/stdc++.h>

using namespace std;

bool checkBuffer(string str) {
  for (int i = 0; i < str.size(); i++) {
    for (int j = 0; j < str.size(); j++) {
      if (i != j && str[i] == str[j])
        return 0;
    }
  }

  return 1;
}

int part1(string buffer, int n) {
  int ans = 0;

  for (int i = 3; i < n; i++) {
    string aux = buffer.substr(i - 3, 4);

    if (checkBuffer(aux)) {
      return i + 1;
    }
  }
}

int part2(string buffer, int n) {
  int ans = 0;

  for (int i = 13; i < n; i++) {
    string aux = buffer.substr(i - 13, 14);

    if (checkBuffer(aux)) {
      return i + 1;
    }
  }
}

int main() {
  string buffer;

  cin >> buffer;
  int n = buffer.size();

  cout << part1(buffer, n) << endl;
  cout << part2(buffer, n) << endl;

  return 0;
}
