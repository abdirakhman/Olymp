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

int cnt[3];

int j[3];
int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    int mn = 100001;
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    	mn = min(a[i], mn);
    	
    }
	for (int i = 1; i <= n; i++) {
		a[i] -= mn;
		cnt[a[i]]++;
		j[a[i]] ++;
	}
	int ans1 = min(cnt[2], cnt[0]);
	int ans2 = cnt[1] / 2;	
	if (ans1 > ans2) {
		cnt[1] += 2 * ans1;
		cnt[2] -= ans1;
		cnt[0] -= ans1;
		vector <int> v;
		while(cnt[2]--) {
			v.pb(2+mn);
		}		
		
		while(cnt[1]--) {
			v.pb(1+mn);
		} 
		while(cnt[0]--) {
			v.pb(mn);
		}
		
		int ans = 0;
		for (int i : v) {
			if (j[i - mn]) {
				ans ++;
				j [i-mn]--;
			}
		}
		cout << ans << endl;;
		for (int i : v) {
			cout << i << ' ';	
		}
	} else {
		cnt[2] += ans2;
		cnt[1] -= ans2 * 2;
		cnt[0] += ans2;
		vector <int> v;
		while(cnt[2]--) {
			v.pb(2+mn);
		}		
		   int ans = 0;
		while(cnt[1]--) {
			v.pb(1+mn);
		} 
		while(cnt[0]--) {
			v.pb(mn);
		}
		for (int i : v) {
			if (j[i - mn]) {
				ans ++;
				j [i-mn]--;
			}
		}
		cout << ans << endl;;
		for (int i : v) {
			cout << i << ' ';	
		}
	}
    return 0;
}