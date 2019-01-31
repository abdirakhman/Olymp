/*
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

using namespace std;

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


const int N = 300;
const int V = N * N;
const int E = 4 * V + 1;

int e = 1, he[V], ne[E], to[E];
char s[N][N + 1];
int cc = 1, u[V], pa[V];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void add( int a, int b ) {
  ne[e] = he[a], to[e] = b, he[a] = e++;
}

int dfs( int v ) {
  u[v] = cc;
  for (int x, e = he[v]; e; e = ne[e])
    if (pa[x = to[e]] == -1 || (u[pa[x]] != cc && dfs(pa[x]))) {
      pa[x] = v, pa[v] = x;
      return 1;
    }
  return 0;
}


bool isin (int a, int b, int n, int m) {
    return 0 <= a && a < n && 0 <= b && b < m;
}
int main() {        
 
    #ifdef IZI_KATKA
    assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
   int n = readInt(), m = readInt(), A = readInt(), B = readInt();
   A = min(A, 2 * B);    
   for (int i = 0; i < n; i++) {
        cin >> s[i];  
   }
  int res = 0, ans = 0;
  for(int i = 0; i < n; i ++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') {
        res++;
        if ((i + j) % 2 == 1)
          for(int k = 0; k < 4; k++) {
            int j1 = j + dx[k], i1 = i + dy[k];
            if (isin(i1, j1, n, m) && s[i1][j1] == '*')
              add(i * m + j, i1 * m + j1);
          }
      }

  for (int i = 0; i < V; i++) {
  	pa[i] = -1;
  }
  for (int run = 1; run;) {
    run = 0, cc++;
    for(int i = 0; i < n * m; i++) 
      if (pa[i] == -1 && dfs(i))
        ans++, run = 1;
  }
  cout << ans * A + (res - 2 * ans) * B;
  return 0;
}
