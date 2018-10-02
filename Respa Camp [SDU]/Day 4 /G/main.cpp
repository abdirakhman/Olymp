/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second

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

const int SZ = 30;

int lvl[MAXN];
vector <int> g[MAXN];
int up[MAXN][SZ];
int d[MAXN];

int dfs(int v, int par) {
    lvl[v] = lvl[par] + 1;
    up[v][0] = par;
    for (int i = 1; i < SZ; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    d[v] = 1;
    for (auto i : g[v]) {
        if (i == par) continue;
        dfs(i, v);
        d[v] += d[i];
    }
}
int lca(int a, int b) {
    if (lvl[a] > lvl[b]) swap(a, b);
    for (int i = SZ - 1; i >= 0; i--) {
        if (lvl[up[b][i]] >= lvl[a]) {
            b = up[b][i];
        }
    }
    if (a == b) return a;
    for (int i = SZ - 1; i >= 0; i--) {
        if (up[b][i] != up[a][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int dist(int a, int b) {
    return lvl[a]+lvl[b]-2*lvl[lca(a, b)];
}

int Kth(int v, int k) {
    for (int i = SZ - 1; i >= 0; i--) {
        if ((k >> i) & 1) {
            v = up[v][i];
        }
    }
    return v;
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	#endif
    int n = readInt();
    for (int i = 1; i < n; i++) {
        int u = readInt(), v = readInt();
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1, 0);
    int q = readInt();
    while(q --) {
        int x = readInt(), y = readInt();
        if (x == y) {
            cout << n << "\n";
            continue;
        }
        if (dist(x, y) % 2 == 1) {
            cout << 0 << "\n";
        } else {
            if (lvl[x] == lvl[y]) {
                int X = Kth(x, lvl[x] - lvl[lca(x, y)] - 1);
                int Y = Kth(y, lvl[y] - lvl[lca(x, y)] - 1);
                cout << n - d[X] - d[Y] << "\n";
            } else {
                if (lvl[x] > lvl[y]) swap(x, y);
                int parent = Kth(y, dist(x, y) / 2 - 1);
                cout << d[up[parent][0]] - d[parent] << "\n";
            }
        }
    }
}
  