/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
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

inline void writeInt(long long x, char END) {
	if (x < 0)
		putchar('-'), x = -x;
	char s[65];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		putchar(s[n]);
	if (END)
		putchar(END);
}
int n, m, k;

int dp[111][111];

int go(int a, int b, int K) {
	if (a == b) {
		return 0;
	}
	int ans = 1e9+7;
	for (int i = 1; i <= k; i++) {
		if (dp[a+1][i]) {
			continue;
		}
		if (i == K) {
			ans = min(ans, go(a + 1, b, i));			
		} else {
			ans = min(ans, go(a + 1, b, i) + 1);
		}          	
	}
	return ans;	
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    n = readInt(), m = readInt(), k = readInt();
    for (int i = 1; i <= m; i++) {                      
		int a = readInt(), b = readInt(), c = readInt();
		dp[a][c]++;
		dp[b][c]--;    	
    }
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] += dp[i - 1][j];
		}
	}
    int q = readInt();       
    while(q--) {
    	int a = readInt(), b = readInt(); 
    	int mn = 1e9 + 7;
    	for (int i = 1; i <= k; i ++) {
    		if (!dp[a][i])
    		mn = min(mn, go(a, b, i) + 1);
    	}
    	cout << (mn>=1e9+7?-1:mn) << endl;
    }
    return 0;
}