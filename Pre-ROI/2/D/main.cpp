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
int dp[2][8000*2+8000];
int cnt[2][8000*2+8000];

int a[MAXN];
        
void add(int v) {

	for (int i = 0; i <= 2*8000; i++) {
		dp[1][i] = dp[0][i];
		cnt[1][i] = cnt[0][i];
	}
	
	for (int i = 0; i <= 2*8000; i++) {
		if (dp[0][i^v]) {	       
			if (dp[1][i] <= dp[0][i^v]+v) {
				dp[1][i] = dp[0][i^v]+v;
				cnt[1][i] = cnt[0][i^v]+1;	
			}
		}
	}	
	for (int i = 0; i <= 2*8000; i++) {
		dp[0][i] = dp[1][i];
		cnt[0][i] = cnt[1][i];
	}
	if (dp[0][v] == 0) {
		dp[0][v] = v;
	}	
	cnt[0][v] ++;
	
}


void del(int v) {
	for (int i = 0; i <= 2*8000; i++) {
		dp[1][i] = 0;
		cnt[1][i] = 0;
	}
	for (int i = 0; i <= 2*8000; i++) {
	    if (dp[0][i^v]) {
	    	if (dp[1][i] <= dp[0][i^v] - v) {
	    		dp[1][i] = dp[0][i^v] - v;
	    		cnt[1][i] = cnt[0][i^v] - 1; 
	    	}              
	    }	       
	}
	
	for (int i = 0; i <= 2*8000; i++) {
		dp[0][i] = dp[1][i];
		cnt[0][i] = cnt[1][i];
		if (dp[0][i] <= 0) {
			dp[0][i] = 0;
			cnt[0][i] = 0;
		}
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), k = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    for (int i = 1; i <= k; i ++) {
    	add(a[i]);
    }
	int L = 1;
	for (int i = 1; i <= n - k + 1; i ++) {
		cout << dp[0][0] << ' ' << cnt[0][0] <<  endl;
		del(a[L]);
		L++;	
		add(a[i+k]);
	}
    return 0;
}