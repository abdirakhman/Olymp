
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
#define pb push_back

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

vector <int> g[MAXN];
int a[MAXN];
int b[MAXN];
int up[MAXN][26];
int lvl[MAXN];
int dp[MAXN][26];
int tin[MAXN];
int tout[MAXN];
int timer = 0;

void dfs (int v, int par = 0) {
    tin[v] = ++timer;
    up[v][0] = par;
    dp[v][0] = a[par] * b[v];
    depth[v] = depth[par] + 1;
    for(int h = 1; h <= 21; h++) {
        up[v][h] = up[up[v][h - 1]][h - 1];
		dp[v][h] = min(dp[v][h-1], dp[up[v][h-1]][h-1]);
	}
    for(const int &u : g[v])
        if(u != par)
            dfs(u, v);
    tout[v] = timer;
}


int lca(int a, int b) {
    int ans = 0;
    if (lvl[a] > lvl[b]) swap(a, b);
    for (int i = 21; i >= 0; i--) {
        if (lvl[up[b][i]] >= lvl[a]) {
            ans += dp[b][i];
            b = up[b][i];
        }
    }  
    if (a == b) return ans;
    for (int i = 21; i >= 0; i--) {
        if (up[b][i] != up[a][i]) {
            ans += dp[b][i];
            ans += dp[a][i];
            a = up[a][i];
            b = up[b][i];
        }
    }
    return ans;
}




int main() {
	#ifndef ONLINE_JUDGE
	//assert(freopen("input", "r", stdin));
    //assert(freopen("output", "w", stdout));
    #endif
	int n = readInt();
	for (int i = 1; i <= n; i++) {
		a[i] = readInt();
	}
	for (int i = 1; i <= n; i++) {
		b[i] = readInt();
	}    
	for (int i = 1; i < n; i++) {
		int u = readInt(), v = readInt();
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);    
	for (int i = 1; i <= 100; i++) {
		int v = readInt(), u = readInt();
		cout << lca(v, u) << endl;
	}
    return 0;
}