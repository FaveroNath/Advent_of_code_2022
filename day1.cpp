#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string n;
  ll sum = 0, ans = 0;

  while (getline(cin, n)) {

    if (n.empty()) {
      ans = max(ans, sum);
      sum = 0;
      continue;
    }

    sum += stoi(n);
  }

  cout << ans << endl;
  return 0;
}

// ---------------------------------- Parte 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string n;
  ll sum = 0, ans = 0;
  vector<int> v;

  while (getline(cin, n)) {
    if (n.empty()) {
      v.push_back(sum);
      sum = 0;
    } else {
      sum += stoi(n);
    }
  }

  v.push_back(sum);

  sort(v.begin(), v.end());

  ans = v[v.size() - 1] + v[v.size() - 2] + v[v.size() - 3];
  cout << ans << endl;
  return 0;
}