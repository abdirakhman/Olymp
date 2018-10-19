#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;
using namespace std;

const ll MAXN = +2005;
const ll INF = 1e18;

char a[MAXN][MAXN];
bool used1[MAXN][MAXN];
bool used2[MAXN][MAXN];
bool used3[MAXN][MAXN];
bool used4[MAXN][MAXN];


ll mxl, mxr;

ll ans;

void dfs1(ll x, ll y, ll l, ll r) {
    if (a[x][y] == '*' || used1[x][y] == true) return;
    used1[x][y] = true;
    dfs1(x + 1, y, l, r);
    dfs1(x - 1, y, l, r);
    if (l > 0) {
        dfs1(x, y - 1, l - 1, r);
    }
    if (r > 0) {
        dfs1(x, y + 1, l, r - 1);
    }
}

void dfs2(ll x, ll y, ll l, ll r) {
    if (a[x][y] == '*' || used2[x][y] == true) return;
    used2[x][y] = true;
    dfs2(x + 1, y, l, r);
    dfs2(x - 1, y, l, r);
    if (r > 0) {
        dfs2(x, y + 1, l, r - 1);
    }
    if (l > 0) {
        dfs2(x, y - 1, l - 1, r);
    }
}


void dfs3(ll x, ll y, ll l, ll r) {
    if (a[x][y] == '*' || used3[x][y] == true) return;
    used3[x][y] = true;
    if (l > 0) {
        dfs3(x, y - 1, l - 1, r);
    }
    if (r > 0) {
        dfs3(x, y + 1, l, r - 1);
    }
    dfs3(x + 1, y, l, r);
    dfs3(x - 1, y, l, r);
    
}

void dfs4(ll x, ll y, ll l, ll r) {
    if (a[x][y] == '*' || used4[x][y] == true) return;
    used4[x][y] = true;
    if (r > 0) {
        dfs4(x, y + 1, l, r - 1);
    }
    if (l > 0) {
        dfs4(x, y - 1, l - 1, r);
    }
    dfs4(x + 1, y, l, r);
    dfs4(x - 1, y, l, r);
    
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll r, c;
    cin >> r >> c;
    cin >> mxl >> mxr;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i][0] = '*';
        a[i][m + 1] = '*';
    }
    for (int i = 1; i <= m; i++) {
        a[0][i] = '*';
        a[n + 1][i] = '*';
    }
    dfs1(r, c, mxl, mxr);
    dfs2(r, c, mxl, mxr);
    dfs3(r, c, mxl, mxr);
    dfs4(r, c, mxl, mxr);


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += (used1[i][j] || used2[i][j] || used3[i][j] || used4[i][j]);
        }
    }
    cout << ans;
}