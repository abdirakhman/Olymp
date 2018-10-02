/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif


const long long MOD = 1e18;
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



int pref_sm[MAXN];
int pref_mn[MAXN];
int pref_abs[MAXN];
int pref_neg[MAXN];

int suff_sm[MAXN];
int suff_mn[MAXN];
int suff_abs[MAXN];
int suff_neg[MAXN];

int a[MAXN];

 main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    if (n == 1) {
    	cout << readInt() << endl;
    	return 0;
    }  
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    pref_mn[0] = suff_mn[n + 1] = MOD;
    for (int i = 1; i <= n; i++) {
    	pref_mn[i] = min(pref_mn[i- 1], a[i]);
    	pref_abs[i] = pref_abs[i - 1] + abs(a[i]);
    	pref_sm[i] = pref_sm[i - 1] + a[i];
    	pref_neg[i] = (pref_neg[i-1] | (a[i] < 0));
    }    
    for (int i = n; i >= 1; i--) {
    	suff_abs[i] = suff_abs[i + 1] + abs(a[i]);
    	suff_mn[i] = min(suff_mn[i + 1], a[i]);
    	suff_sm[i] = suff_sm[i + 1] + a[i];
    	suff_neg[i] = (suff_neg[i+1] | (a[i] < 0));
    }
    int ans = -MOD;
	pref_mn[0] = suff_mn[n+1] = 0;    
    for (int i = 1; i <= n; i++) {
		int res = a[i];
		if (pref_neg[i-1]) {
			res += pref_abs[i - 1];			
		} else {
			res -= pref_mn[i - 1] * 2 - pref_sm[i - 1];
		}
		if (suff_neg[i + 1]) {
			res += suff_abs[i + 1];
		} else {
			res -= suff_mn[i + 1] * 2 - suff_sm[i + 1]; 			
		}
		ans = max(ans, res);
    }
    cout << ans;

    return 0;
}