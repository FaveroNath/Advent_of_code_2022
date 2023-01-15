#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;

typedef pair<int, int> pii;

vector<int> board[N + 5];
int lines = 0;

void build_mat() {
  string heights;

  while (cin >> heights) {
    for (int j = 0; j < heights.size(); j++) {
      int value = heights[j] - '0';

      board[lines].push_back(value);
    }

    lines++;
  }
}

int part_1(int lines, int cols) {
  int ans = (2 * lines) + (2 * (cols - 2));
  int aux = 0, is_visible = 1;

  for (int i = 1; i < lines - 1; i++) {
    for (int j = 1; j < cols - 1; j++) {
      int vt = 1, vd = 1, vl = 1, vr = 1;

      // cima
      for (int k = 0; k <= i - 1; k++)
        if (board[k][j] >= board[i][j])
          vt = 0;

      // direita
      for (int k = cols - 1; k >= j + 1; k--)
        if (board[i][k] >= board[i][j])
          vr = 0;

      // baixo
      for (int k = lines - 1; k >= i + 1; k--)
        if (board[k][j] >= board[i][j])
          vd = 0;

      // esquerda
      for (int k = 0; k <= j - 1; k++)
        if (board[i][k] >= board[i][j])
          vl = 0;

      is_visible = !vt && !vd && !vl && !vr;

      if (is_visible)
        ans++;

      is_visible = 1;
    }
  }

  return ans;
}

int part_2(int lines, int cols) {
  int ans = 0;
  int aux = 0;

  for (int i = 1; i < lines - 1; i++) {
    for (int j = 1; j < cols - 1; j++) {
      int vt = 0, vd = 0, vl = 0, vr = 0;

      // cima
      for (int k = i - 1; k >= 0; k--)
        if (board[k][j] < board[i][j])
          vt++;
        else {
          vt++;
          break;
        }

      // direita
      for (int k = j + 1; k <= cols - 1; k++)
        if (board[i][k] < board[i][j])
          vr++;
        else {
          vr++;
          break;
        }

      // baixo
      for (int k = i + 1; k <= lines - 1; k++)
        if (board[k][j] < board[i][j])
          vd++;
        else {
          vd++;
          break;
        }

      // esquerda
      for (int k = j - 1; k >= 0; k--)
        if (board[i][k] < board[i][j])
          vl++;
        else {
          vl++;
          break;
        }

      // cout << vt << " " << vr << " " << vd << " " << vl << endl;
      ans = max(ans, (vt * vr * vd * vl));
    }
  }

  return ans;
}

int main() {
  build_mat();

  cout << part_1(lines, board[0].size()) << endl;
  cout << part_2(lines, board[0].size()) << endl;
  return 0;
}
