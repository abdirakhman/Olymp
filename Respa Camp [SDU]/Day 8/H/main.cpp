/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
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

int a[MAXN];

int dp[(1 << 20)][22];

int g[20][20];
int main() {
	#ifndef ONLINE_JUDGE
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt(), k = readInt();
    for (int i = 0; i < n; i++) {
    	a[i] = readInt();
    	dp[(1 << i)][i] = a[i];	
    }
    for (int i = 1; i <= k; i++) {
    	int v = readInt() - 1, u = readInt() - 1, w = readInt();
    	g[u][v] = w;
    }
    int mx = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if (!((mask >> i) & 1)) continue;
            for (int j = 0; j < n; j++) {
                if ((mask >> j) & 1)  continue;
                int newmask = (mask | (1 << j));
                dp[newmask][j] = max(dp[newmask][j], dp[mask][i] + a[j] + g[i][j]);
            }
            if (__builtin_popcount(mask) == m) {
                mx = max(mx, dp[mask][i]);
            }
		}
    }
    cout << mx;
    return 0;
}