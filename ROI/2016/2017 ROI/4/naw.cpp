#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int w, h, s, q;
int x[N], y[N];
int b[N], m[N];
long long n[N];

vector < pair <int, long long> > at[N];
int mob[N];

bool dfs(int v, long long users) {
  if (v == s) {
    long long area = 0;
    for (int mask = 1; mask < (1 << s); mask++) {
      int xa = 0, ya = 0;
      int xb = w - 1, yb = h - 1;
      int sign = -1;
      for (int i = 0; i < s; i++) {
        if (mask & (1 << i)) {
          xa = max(xa, x[i] - mob[i]);
          ya = max(ya, y[i] - mob[i]);
          xb = min(xb, x[i] + mob[i]);
          yb = min(yb, y[i] + mob[i]);
          sign *= -1;
        }
      }
      if (xa <= xb && ya <= yb) {
        area += (long long) sign * (xb - xa + 1) * (yb - ya + 1);
      }
    }
    return (area * q >= users);
  }
  mob[v] = -1;
  if (!dfs(v + 1, users)) {
    return false;
  }
  for (int j = 0; j < (int) at[v].size(); j++) {
    mob[v] = at[v][j].first;
    users += at[v][j].second;
    if (!dfs(v + 1, users)) {
      return false;
    }
  }
  return true;
}

bool possible(int t) {
  for (int i = 0; i < s; i++) {
    at[i].clear();
  }
  for (int i = 0; i < t; i++) {
    at[b[i]].push_back(make_pair(m[i], n[i]));
  }
  for (int i = 0; i < s; i++) {
    sort(at[i].begin(), at[i].end());
  }
  return dfs(0, 0);
}

int main() {
  freopen("mining.in", "r", stdin);
  freopen("mining.out", "w", stdout);
  cin >> w >> h >> s >> q;
  for (int i = 0; i < s; i++) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> b[i] >> n[i] >> m[i];
    b[i]--;
  }
  int pos = -1;
  {
    int low = 0, high = t;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      if (possible(mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    pos = low;
  }
  if (pos == t) {
    cout << t << " " << 0 << endl;
  } else {
    long long low = 0, high = n[pos];
    while (low < high) {
      long long mid = (low + high + 1) >> 1;
      n[pos] = mid;
      if (possible(pos + 1)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    cout << pos << " " << low << endl;
  }
  return 0;
}
