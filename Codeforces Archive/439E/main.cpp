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

#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif

int used[MAXN];
int tmr;
int f[MAXN];
int dp[MAXN];
int revf[MAXN];
vector <int> divisors[MAXN];


int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow (a, n-1) * a) % MOD;
	else {
		int b = binpow (a, n/2) % MOD;
		return (b * b) % MOD;
	}
}

int rev(int x) {
	return binpow(x, MOD - 2);
}

int C(int n, int k){
    if(k < 0 || k > n)
        return 0;
    if(k == 0)
        return 1;
    int ans = (f[n] * revf[k]) % MOD;
    ans = (ans * revf[n - k]) % MOD;
    return ans;
}


int go(int n, int f) {
	if (f > n) return 0;
	if (f == n) return 1;
	if (used[n] == tmr) {
		return dp[n];
	}  	
	used[n] = tmr;
	dp[n] = C(n - 1, f - 1);
	for (int i : divisors[n]) {
		dp[n] -= go(i, f);
		if (dp[n] < 0)
		dp[n] += MOD;	
	}
	return dp[n];
}

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    f[0] = 1, revf[0] = 1;
    for (int i = 1; i < MAXN; i++) {
    	for (int j = i + i; j < MAXN; j += i) {
    		divisors[j].pb(i);
    	}
    }             
    for(int i = 1; i < MAXN; i++){
        f[i] = (f[i - 1] * i) % MOD;
        revf[i] = rev(f[i]) % MOD;
    }
    int q = readInt();
    while(q--) {
    	int n = readInt(), f = readInt();
    	tmr ++;
    	cout << go(n, f) % MOD << endl;
    }
    return 0;
}