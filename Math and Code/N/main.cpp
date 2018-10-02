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

#define int __int64_t

const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long MAXN = 1e6 + 1;
const long long P = 997;

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

char s[MAXN], t[MAXN];

char a[MAXN];

string tmp;

int h1_1[MAXN];
int h1_2[MAXN];

int h2_1[MAXN];
int h2_2[MAXN];

int p1[MAXN];
int p2[MAXN];

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	cin  >> tmp;
	int n = tmp.size();
	for (int i = 0; i < tmp.size(); i++) {
		s[i + 1] = tmp[i];
	}
	cin >> tmp;
	int m = tmp.size();
	if (m > n) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < tmp.size(); i++) {
		t[i + 1] = tmp[i];	
	}     
	for (int i = 1; i <= n * 3; i++) {
		a[i] = s[(i % n ? i % n : n)];
	}
	h1_1[0] = 0;
    h1_2[0] = 0;
    h2_1[0] = 0;
    h2_2[0] = 0;
    p1[0] = 1;
    p2[0] = 1;
	for (int i = 1; i < MAXN; i++) {
        p1[i] = (p1[i - 1] * P) % MOD1;
        p2[i] = (p2[i - 1] * P) % MOD2;
    }
    for (int i = 1; i <= n * 3; i++) {
        h1_1[i] = (h1_1[i - 1] * P) % MOD1;
        h1_1[i] = (h1_1[i] + a[i]) % MOD1;
        h1_2[i] = (h1_2[i - 1] * P) % MOD2;
        h1_2[i] = (h1_2[i] + a[i]) % MOD2;
    }
    ///aabbcc
	for (int i = 1; i <= m; i++) {
        h2_1[i] = (h2_1[i - 1] * P) % MOD1;
        h2_1[i] = (h2_1[i] + t[i]) % MOD1;
        h2_2[i] = (h2_2[i - 1] * P) % MOD2;
        h2_2[i] = (h2_2[i] + t[i]) % MOD2;
    }
    int ans = MOD1;
	for (int i = n + 1; i <= 2 * n; i++) {
		int r = i + m - 1;
		int l = i - 1;
		int h1 = h1_1[r] - ((h1_1[l] * p1[r - l])%MOD1) + 2 * MOD1;
		int h2 = h1_2[r] - ((h1_2[l] * p2[r - l])%MOD2) + 2 * MOD2;
		h1 %= MOD1;
		h2 %= MOD2;
		if (h1 == h2_1[m] && h2 == h2_2[m]) {
			if (i + m - 1 <= 2 * n) {
				ans = 0;
			}
			ans = min(ans, min (i - n - 1, n - (i - n) + 1));					
		}
	}
	cout << (ans == MOD1 ? -1 : ans);
    return 0;
}