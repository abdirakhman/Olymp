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

/*
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif
*/

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
ll a[MAXN];
ll b[MAXN];

ll pref_a[MAXN];
ll pref_b[MAXN];

ll mn[MAXN];
ll n, m;

ll x;

ll GGGG(ll kek) {
	int l = 1, r = m;
	while(r - l > 1) {
		int mid = (l + r) / 2;
		if (kek * mn[mid] <= x) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return (kek * mn[r] <= x ? r : kek * mn[l] <= x ? l : 0);
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
     n = readInt(), m = readInt();
    for (int i =  1; i <= n; i++) {
    	a[i] = readInt();
    }
    for (int j = 1; j <= m; j++) {
    	b[j] = readInt();
    }
    x = readInt();
    for (int i = 1; i <= n; i++) {
    	pref_a[i] = pref_a[i - 1] + a[i];
    }
	for (int i = 1; i <= m; i++) {
		pref_b[i] = pref_b[i - 1] + b[i];
	}
	multiset < pair <int, int> > S;
	for (int i = 1; i <= m; i++) {
		mn[i] = MOD;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			mn[j-i+1] = min(mn[j-i+1], pref_b[j] - pref_b[i - 1]);
		}
	}
	ll mx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			mx = max(mx, (j - i + 1) * GGGG(pref_a[j] - pref_a[i - 1]));
		}
	}
	cout << mx;
	return 0;
}