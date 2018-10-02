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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second    
#define deb(x) cout<<#x<<' '<<x<<endl;
#define endl '\n'
#define pb push_back
#define int __int64_t

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

bool islucky(int x) {
	while(x) {
		if (x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

int dp[1111][1111];
int fact[MAXN];

map <int, int> used;	
vector <int> v;
int cnt[1111];

int binpow(int a, int n) {
	if (n == 0) {
		return 1;
	}
	if (n & 1) {
		return a * binpow(a, n - 1) % MOD;
	} else {
		int b = binpow(a, n / 2) % MOD;
		return (b*b) % MOD;
	}
}

int C(int n, int k) {
	if (k > n) return 0;
	if (n == k || k == 0) return 1;
	return (fact[n] * binpow((fact[k] * fact[n-k]) % MOD, MOD - 2)) % MOD;
}


main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	int n = readInt(), k = readInt();

	int not_lucky = 0;

	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i-1] * i;
		fact[i] %= MOD;	
	}
	vector <int> tmp;
	for (int i = 1; i <= n; i++) {
		int x = readInt();
		if (islucky(x)) {
			tmp.pb(x);
		} else {
			not_lucky++;
		}
	}	    
	sort(tmp.begin(), tmp.end());
	int timer = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (!used[tmp[i]]) {
			timer ++;
			used[tmp[i]] = timer;
			tmp[i] = timer;
			v.pb(tmp[i]);
		} else {
			tmp[i] = used[tmp[i]];
		}
		cnt[tmp[i]]++;
	}
	dp[0][0] = 1;	
	for (int i = 0; i < v.size(); i++) {    
		for (int K = 1; K <= v.size(); K++) {
			dp[K][i+1] += dp[K - 1][i] * cnt[v[i]];
			dp[K][i+1] += dp[K][i];
			dp[K][i+1] %= MOD;
		}
		dp[0][i + 1] += dp[0][i]; 				
		dp[0][i+1] %= MOD;
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		if (k - i <= v.size())
		ans += dp[k - i][v.size()] * C(not_lucky, i);
		ans %= MOD;
	}
	cout << ans;
    return 0;
}
