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

int a[MAXN];


int pref[2222];
int suff[2222];
int dp[2222][2222];

int f(int l, int r, int x) {
	int ans1 = 0, ans2 = 0;
	for (int i = l; i <= x; i++) {
		ans1 += (a[i] == 1);	
	}
	for (int i = x; i <= r; i++) {
		ans2 += (a[i] == 2);
	}
	return ans1 + ans2; 
}

int get(int L, int R) {
	int l = L, r = R;
	while (r - l >= 3) {
   	int m1 = l + (r - l) / 3,
		m2 = r - (r - l) / 3;
   	if (f (L, R,  m1) < f (L, R, m2))
		l = m1;
	else
		r = m2;
	}     

	int MX = 0;
	for (int i = l; i <= r; i++) {
		MX = max(MX, f(L, R, i));
	}
	return MX;
}

int main() {
	#ifndef ONLINE_JUDGE
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    reverse(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
    	if (a[i] == 2) {
    		pref[i]++;
    		pref[i] += pref[i-1];
    	}    
    }
    for (int i = n; i >= 1; i--) {
    	if (a[i] == 1) {
			suff[i]++;
			suff[i] += suff[i+1];     		
    	}
    }
   	int mx = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = i; j <= n; j++) {
			dp[i][j] = get(i, j);     		
    		mx = max(mx, dp[i][j] + pref[i - 1] + suff[j + 1])	;    	    		
    	}        
    }    
    cout << mx;
    return 0;
}