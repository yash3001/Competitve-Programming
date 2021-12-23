#include <bits/stdc++.h>

using namespace std;

const int N = 500 * 1000 + 13;

int main() {
  int q;
  scanf("%d", &q);
  vector<int> t(q), x(q), y(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &t[i], &x[i]);
    if (t[i] == 2) scanf("%d", &y[i]);
  }
  vector<int> p(N);
  iota(p.begin(), p.end(), 0);
  vector<int> ans;
  for (int i = q - 1; i >= 0; --i) {
    if (t[i] == 1) {
      ans.push_back(p[x[i]]);
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (int &x : ans) printf("%d ", x);
} 