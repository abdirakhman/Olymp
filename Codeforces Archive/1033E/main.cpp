///from editorial
/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

/*
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif
*/

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;

long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}


int ask(const vector<int> &v, char c = '?') {
  int sz = (int) v.size();
  if (sz == 0) {
    return 0;
  }
  printf("%c %d\n", c, sz);
  for (int i = 0; i < sz; i++) {
    printf("%d ", v[i] + 1);
  }
  printf("\n");
  fflush(stdout);
  if (c == '?') {
    int x;
    scanf("%d", &x);
    return x;
  }
  return -1;
}

int f(int a, vector<int> v) {
  int x = ask(v);
  v.push_back(a);
  int y = ask(v);
  return y - x;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> pr(n, -1);
  vector<int> color(n, -1);
  color[0] = 0;
  vector<int> Q(1, 0);
  for (int i = 0; i < Q.size(); i++) {
    int v = Q[i];
    vector<int> awein;
    for (int j = 0; j < n; j++) {
      if (color[j] == -1) {
        awein.push_back(j);
      }
    }
    int cnt = f(v, awein);
    for (int it = 1; it <= cnt; it++) {
      int L = 0, R = awein.size() - 1;
      while (L < R) {
        int mid = (L +R ) >> 1;
        int now = f(v, vector<int>(awein.begin(), awein.begin() + mid + 1));
        if (now >= it) {
          R = mid;
        } else {
          L = mid + 1;
        }
      }
      int found = awein[L];
      color[found] = color[v] ^ 1;
      pr[found] = v;
      Q.push_back(found);
    }
  }
  vector<vector<int>> B(2);
  for (int i = 0; i < n; i++) {
    B[color[i]].push_back(i);
  }
  for (int c = 0; c < 2; c++) {
    int xx = ask(B[c]);
    if (xx == 0) {
      continue;
    }
    int L = 0, R = B[c].size();
    while (L < R) {
      int mid = (L + R) >> 1;
      int x = ask(vector<int>(B[c].begin(), B[c].begin() + mid));
      if (x == 0) {
        L = mid + 1;
      } else {
        R = mid;
      }
    }
    int v = B[c][L - 1];
    L = 0; R -= 2;
    while (L < R) {
      int mid = (L + R) >> 1;
      int x = f(v, vector<int>(B[c].begin(), B[c].begin() + mid + 1));
      if (x == 0) {
        L = mid + 1;
      } else {
        R = mid;
      }
    }
    int u = B[c][L];
    vector<int> pv, pu;
    while (v != u) {
      pv.push_back(v);
      pu.push_back(u);
      v = pr[v];
      u = pr[u];
    }
    reverse(pu.begin(), pu.end());
    vector<int> path;
    for (int w : pv) {
      path.push_back(w);
    }
    path.push_back(v);
    for (int w : pu) {
      path.push_back(w);
    }
    ask(path, 'N');
    return 0;
  }
  ask(B[0], 'Y');
  return 0;
}