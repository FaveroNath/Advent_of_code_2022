#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long calcule_cost(char a) {
  if (a >= 'a' && a <= 'z')
    return a - 'a' + 1;
  else if (a >= 'A' && a <= 'Z')
    return a - 'A' + 27;
}

int search(string str, char a, int n) {
  for (int j = (n / 2); j < n; j++) {
    if (a == str[j])
      return 1;
  }

  return 0;
}

int main() {
  string str;
  long long ans = 0;

  while (cin >> str) {
    int n = str.size();

    for (int i = 0; i < n / 2; i++) {
      if (search(str, str[i], n)) {
        // cout << str[i] << endl;
        ans += calcule_cost(str[i]);
        break;
      }
    }
  }

  // for(char i:s) ans += calcule_cost(i);

  cout << ans << endl;
  return 0;
}

//---------------------------------- Parte 2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long calcule_cost(char a) {
  if (a >= 'a' && a <= 'z')
    return a - 'a' + 1;
  else if (a >= 'A' && a <= 'Z')
    return a - 'A' + 27;
}

int search(string str, char a, int n) {
  for (int j = 0; j < n; j++) {
    if (a == str[j])
      return 1;
  }

  return 0;
}

int main() {
  string str, str2, str3;
  long long ans = 0;

  while (cin >> str >> str2 >> str3) {
    int n = str.size();
    int n2 = str2.size();
    int n3 = str3.size();

    for (int i = 0; i < n; i++) {
      if (search(str2, str[i], n2) && search(str3, str[i], n3)) {
        // cout << str[i] << endl;
        ans += calcule_cost(str[i]);
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}