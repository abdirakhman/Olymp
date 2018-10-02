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
const long long MXN = 555;
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

string s[MXN];

int dp[MXN][MXN];

int prec[MXN][MXN];

int pref[MXN][MXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt(), K = readInt();
    for (int i = 1; i <= n; i ++) {
    	cin >> s[i];
    	s[i] = '#' + s[i];
    	for (int j = 1; j <= m; j++) {
			pref[i][j] = pref[i][j-1] + (s[i][j]=='1');    		
    	}
    
    }
    
    for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= K; j++) {
			prec[i][j] = 1e9;
			dp[i][j] = 1e9;
		}			    	
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
		prec[i][pref[i][m]] = 0;
    	for (int j = 1; j <= m; j++) {
    		for (int k = j; k <= m; k++) {
				prec[i][pref[i][j-1] + pref[i][m] - pref[i][k]] = min(prec[i][pref[i][j-1] + pref[i][m] - pref[i][k]], k - j + 1);    			
    			
    		}
    	}
    	
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= K; j++) {
            for(int u = 0; j + u <= K; u++) {
            	if (dp[i][j] < 1e9 && prec[i+1][u] < 1e9 && j + u <= K) 
                dp[i + 1][j + u] = min(dp[i + 1][j + u], dp[i][j] + prec[i+1][u]);
            }
        }
    }
    ///TODO
    int mn = 1e9;
    for(int i = 0; i <= K; i++) {
        mn = min(mn, dp[n][i]);
    }
    cout << mn;
        
    return 0;
}