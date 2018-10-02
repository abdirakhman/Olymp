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
const long long MAXN = 1e6 + 100;
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
int p[4];
int n;

set <int> pref[MAXN];
set <int> suff[MAXN];

void solve1() {
	///ax < ay < az
	int ans = MOD;
	for (int i = 2; i < n; i++) {
		auto tmp1 = pref[i - 1].find(a[i]);
		auto tmp2 = suff[i + 1].upper_bound(a[i]);
		if (tmp2 == suff[i + 1].end()) continue;
		if (tmp1 == pref[i - 1].end()) {
			tmp1 = pref[i - 1].begin();
			if (*tmp1 > a[i]) continue;
		} else {
			pref[i - 1].erase(a[i]);
			if (pref[i - 1].size () != 0) {
				tmp1 = pref[i - 1].begin();
				pref[i - 1].insert(a[i]);
			} else {
				pref[i - 1].insert(a[i]);
				continue;
			}
			if (*tmp1 > a[i]) continue;
		}
		int R = *tmp2;
		int L = *tmp1;
		ans = min(ans, R + a[i] + L);
	}
	cout << (ans == MOD ? -1 : ans) << endl;
}

void solve2() {
	/// ay > az > ax
	///lower_bound first that >=
	int ans = MOD;
	for (int i = 2; i < n; i++) {
		auto tmp1 = pref[i - 1].find(a[i]);
		if (tmp1 == pref[i - 1].end()) {
			tmp1 = pref[i - 1].begin();
			if (*tmp1 > a[i]) continue;
		} else {
			pref[i - 1].erase(a[i]);
			if (pref[i - 1].size() == 0) {
				pref[i - 1].insert(a[i]);
				continue;
			}
			tmp1 = pref[i - 1].begin();
			pref[i - 1].insert(a[i]);
			if (*tmp1 > a[i]) continue;
		}
		int L = *tmp1;
		auto tmp2 = suff[i + 1].upper_bound(L);
		if (tmp2 == suff[i + 1].end()) {
			continue;
		}
		if (*tmp2 > a[i]) continue;
		int R = *tmp2;
		ans = min(ans, R + L + a[i]);
	}
	cout << (ans == MOD ? -1 : ans) << endl;
}
void solve3() {
	///az > ax > ay
	int ans = MOD;
	for (int i = 2; i < n; i++) {
		auto tmp1 = pref[i - 1].upper_bound(a[i]);
		if (tmp1 == pref[i - 1].end()) continue;
		int L = *tmp1;
		auto tmp2 = suff[i + 1].upper_bound(L);
		if (tmp2 == suff[i + 1].end()) continue;
		int R = *tmp2;
		ans = min(ans, L + R + a[i]);
	}
	cout << (ans == MOD ? -1 : ans) << endl;
}
void solve4() {
	/// az < ax < ay
	/// z = R
	/// x = L
	int ans = MOD;
	for (int i = 2; i < n; i++) {
		auto tmp1 = suff[i + 1].find(a[i]);
		if (tmp1 == suff[i + 1].end()) {
			tmp1 = suff[i + 1].begin();
			if (*tmp1 > a[i]) continue;
		} else {
			suff[i + 1].erase(a[i]);
			if (suff[i + 1].size() == 0) {
				suff[i + 1].insert(a[i]);
				continue;
			}
			tmp1 = suff[i + 1].begin();
			suff[i + 1].insert(a[i]);
			if (*tmp1 > a[i]) continue;
		}
		int R = *tmp1;
		auto tmp2 = pref[i - 1].upper_bound(R);
		if (tmp2 == pref[i - 1].end()) continue;
		if (*tmp2 > a[i]) continue;
		int L = *tmp2;
		ans = min(ans, L + R + a[i]);
	}
	cout << (ans == MOD ? -1 : ans) << endl;
}
void solve5() {
	/// ay < az < ax
	int ans = MOD;
	for (int i = 2; i < n; i++) {
		auto tmp1 = suff[i + 1].upper_bound(a[i]);
		if (tmp1 == suff[i + 1].end()) continue;
		int R = *tmp1;
		auto tmp2 = pref[i - 1].upper_bound(a[i]);
		if (tmp2 == pref[i - 1].end()) continue;
		int L = *tmp2;
		ans = min(ans, L + R + a[i]);
	}
	cout << (ans == MOD ? -1 : ans) << endl;
}
void solve6() {
	/// ax > ay > az
	int ans = MOD;
    for (int i = 2; i < n; i++) {
		 auto tmp1 = suff[i + 1].find(a[i]);
		 if (tmp1 == suff[i + 1].end()) {
		 	tmp1 = suff[i + 1].begin();
		 	if (*tmp1 > a[i]) continue;
		 } else {
		 	suff[i + 1].erase(a[i]);
		 	if (suff[i + 1].size() == 0) {
		 		suff[i + 1].insert(a[i]);
		 		continue;
		 	}
		 	tmp1 = suff[i + 1].begin();
		 	suff[i + 1].insert(a[i]);
		 	if (*tmp1 > a[i]) continue;
		 }
		 int R = *tmp1;
		 auto tmp2 = pref[i - 1].upper_bound(a[i]);
		 if (tmp2 == pref[i - 1].end()) continue;
		 int L = *tmp2;
		 ans = min(ans, R + L + a[i]);
    }
    cout << (ans == MOD ? -1 : ans) << endl;
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt();
    if (n <= 2) {
    	cout << -1;
    }
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    for (int i = 1; i <= 3; i++) {
    	p[i] = readInt();
    }
    set <int> tmp;
    for (int i = 1; i <= n; i ++) {
		tmp.insert(a[i]);
		pref[i] = tmp;
    }
	tmp.clear();
	for (int i = n; i >= 1; i--) {
		tmp.insert(a[i]);
		suff[i] = tmp;
	}
	if (p[1] == 1 && p[2] == 2 && p[3] == 3) {
		solve1();
	} else if (p[1] == 1 && p[2] == 3 && p[3] == 2) {
		solve2();
	} else if (p[1] == 2 && p[2] == 1 && p[3] == 3) {
		solve3();
	} else if (p[1] == 2 && p[2] == 3 && p[3] == 1) {
		solve4();
	} else if (p[1] == 3 && p[2] == 1 && p[3] == 2) {
		solve5();
	} else if (p[1] == 3 && p[2] == 2 && p[1] == 1) {
		solve6();
	}
    return 0;
}
