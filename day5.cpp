#include <bits/stdc++.h>
using namespace std;
stack<char> p1, p2, p3, p4, p5, p6, p7, p8, p9;

string s1, s2, s3, s4, s5, s6, s7, s8, s9;

stack<char> stacks[] = {p1, p2, p3, p4, p5, p6, p7, p8, p9};
string strs[] = {"NRGP",    "JTBLFGDC", "MSV",      "LSRCZP", "PSLVCWDQ",
                 "CTNWDMS", "HDGWP",    "ZLPHSCMV", "RPFLWGZ"};

map<int, stack<char> > mp;

void part1() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < strs[i].size(); j++) {
      stacks[i].push(strs[i][j]);
    }

    mp[i + 1] = stacks[i];
  }

  string a, b, c;
  int qtd, id, to;

  while (cin >> a >> qtd >> b >> id >> c >> to) {
    for (int i = 0; i < qtd; i++) {
      char value;
      if (!mp[id].empty()) {
        value = mp[id].top();

        mp[id].pop();
        mp[to].push(value);
      }
    }
  }

  for (int i = 0; i < 9; i++)
    cout << mp[i + 1].top();
}

void part2() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < strs[i].size(); j++) {
      stacks[i].push(strs[i][j]);
    }

    mp[i + 1] = stacks[i];
  }

  string a, b, c;
  int qtd, id, to;

  while (cin >> a >> qtd >> b >> id >> c >> to) {
    string aux = "";

    for (int i = 0; i < qtd; i++) {
      char value;

      if (!mp[id].empty()) {
        value = mp[id].top();
        aux += value;
        mp[id].pop();
      }
    }

    for (int j = aux.size() - 1; j >= 0; j--) {
      mp[to].push(aux[j]);
    }
  }

  for (int i = 0; i < 9; i++)
    cout << mp[i + 1].top();
}

int main() {
  // part1();
  //  cout << endl;
  part2();
  return 0;
}
