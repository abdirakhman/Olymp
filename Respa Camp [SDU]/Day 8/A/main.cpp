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

string a[MAXN];

bool cmp(string s, string t) {
    string S = s + t;
    int cnt_1 = 0, ans = 0;
    for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') {
			cnt_1 ++;
		} else {
			ans += cnt_1;
		}		       	
    }
    S = t + s;
    int ans1 = 0;
    cnt_1 = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') {
			cnt_1 ++;
		} else {
			ans1 += cnt_1;
		}		       	
    }
    return ans > ans1;
}

int main() {
	#ifndef ONLINE_JUDGE
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
		cin >> a[i];    	
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] == 's') a[i][j] = '0';
			else a[i][j] = '1';
		}
	}
    sort(a + 1, a + 1+ n, cmp);
    string S;
    for (int i = 1; i <= n; i++) {
		S += a[i];			    	
    }
    int ans = 0;
    int cnt_1 = 0;
    for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') {
			cnt_1 ++;
		} else {
			ans += cnt_1;
		}		       	
    }
    cout << ans;
    return 0;
}
