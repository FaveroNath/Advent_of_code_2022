#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_new_value(int ops, int oldValue) {
  switch (ops) {
    case 0:
      return oldValue * 19;
      break;
    case 1:
      return oldValue + 1;
      break;
    case 2:
      return oldValue + 6;
      break;
    case 3:
      return oldValue + 5;
      break;
    case 4:
      return oldValue * oldValue;
      break;
    case 5:
      return oldValue + 7;
      break;
    case 6:
      return oldValue * 7;
      break;
    case 7:
      return oldValue + 2;
      break;
    default:
      break;
  }
  return 0;
}

int get_new_monkey(int oldMonkey, int value) {
  switch (oldMonkey) {
    case 0:
      return (value % 7) == 0 ? 2 : 3;
      break;
    case 1:
      return (value % 19) == 0 ? 4 : 6;
      break;
    case 2:
      return (value % 5) == 0 ? 7 : 5;
      break;
    case 3:
      return (value % 11) == 0 ? 5 : 2;
      break;
    case 4:
      return (value % 17) == 0 ? 0 : 3;
      break;
    case 5:
      return (value % 13) == 0 ? 1 : 7;
      break;
    case 6:
      return (value % 2) == 0 ? 0 : 4;
      break;
    case 7:
      return (value % 3) == 0 ? 1 : 6;
      break;
    default:

      break;
  }
  return 0;
}

int main() {
  int n, item;

  cin >> n;

  map<int, queue<int>> mp_monkey_itens;
  vector<int> ans(n, 0);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
      cin >> item;
      mp_monkey_itens[i].push(item);
    }
  }

  for (int r = 0; r < 20; r++) {
    for (int i = 0; i < n; i++) {
      while (!mp_monkey_itens[i].empty()) {
        int it = mp_monkey_itens[i].front();
        mp_monkey_itens[i].pop();

        int new_value = get_new_value(i, it);
        double v = new_value / 3;
        new_value = round(v);

        int new_monkey = get_new_monkey(i, new_value);
        mp_monkey_itens[new_monkey].push(new_value);
        ans[i]++;
      }
    }
  }

  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());

  ll resp = ans[0] * ans[1];
  cout << resp << endl;
  return 0;
}

// 8
// 2
// 58 58
// 6
// 66 52 59 79 94 73
// 1
// 80
// 8
// 82 81 68 66 71 83 75 97
// 7
// 55 52 67 70 69 94 90
// 4
// 69 85 89 91
// 5
// 75 53 73 52 75
// 3
// 94 60 79

// 4
// 2
// 79 98
// 4
// 54 65 75 74
// 3
// 79 60 97
// 1
// 74