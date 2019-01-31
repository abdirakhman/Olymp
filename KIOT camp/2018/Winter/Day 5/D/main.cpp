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
#define int __int64_t
#endif

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

const int N = 2222;
const int MXN = 5005;


//bool dp[N][N][MXN+N];

int pref[N];

int A, B;
int a[N];
bool dp[N][N];
int dp1[N];

/// dp[i][j][k] = 0..1


int n;

bool campbell(int mask) {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 1; k <= n; k++) {
				int sum = pref[i] - pref[j];
				if ((sum & (mask)) == sum) {
					dp[i][k] |= dp[j][k - 1];
				}
			}
		}
	}
	bool res = 0;
	for (int i = A; i <= B; i++) {
		res |= dp[n][i];		
	}
	return res;
}

bool cambell (int mask) {
	for (int i = 0; i <= n; i++) {
		dp1[i] = MOD;		
	}
	dp1[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			int sum = pref[i] - pref[j];
			if ((sum & (mask)) == sum) {
				dp1[i] = min(dp1[i], dp1[j] + 1);
			}
		}
	}
	return (dp1[n] <= B);
}


main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), A = readInt(), B = readInt();
	for (int i = 1; i <= n; i++) {
	    a[i] = readInt();
		pref[i] = pref[i - 1] + a[i];
	}
	if (A != 1) {
		int mask = (1ll << (61)) - 1;
		for (int bits = 60; bits  >= 0; bits --) {
			if (campbell(mask ^ (1ll << bits))) {
				mask ^= (1ll << bits);	
			} else {
				continue;
			}
		}
		cout << mask << endl;
	} else {
		int mask = (1ll << (61)) - 1;
		for (int bits = 60; bits  >= 0; bits --) {
			if (cambell(mask ^ (1ll << bits))) {
				mask ^= (1ll << bits);	
			} else {
				continue;
			}
		}
		cout << mask << endl;
	
	}
	return 0;
}