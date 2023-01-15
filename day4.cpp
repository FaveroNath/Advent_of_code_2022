#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second

bool verify_interval(pii a, pii b) { return b.F >= a.F && b.S <= a.S; }

int main() {
  char x, y, z;
  int ans = 0;
  pair<int, int> a, b;

  while (cin >> a.F >> x >> a.S >> y >> b.F >> z >> b.S) {

    if (verify_interval(a, b) || verify_interval(b, a))
      ans++;
  }

  cout << ans;

  return 0;
}

// ---------------------------------- Parte 2
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second

bool verify_interval(pii a, pii b) {
  return (b.F >= a.F && b.F <= a.S) || (b.S <= a.S && b.S >= a.F);
}

int main() {
  char x, y, z;
  int ans = 0;
  pair<int, int> a, b;

  while (cin >> a.F >> x >> a.S >> y >> b.F >> z >> b.S) {

    if (verify_interval(a, b) || verify_interval(b, a))
      ans++;
  }

  cout << ans;

  return 0;
}
