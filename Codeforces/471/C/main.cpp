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

const long long LIM = 1e18;


ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		ll b = binpow (a, n/2);
		return b * b;
	}
}


ll getr(ll step, ll lim) {
	ll L = 2, R = log(lim)/log(step) + 1;
	while(R - L > 1) {
		ll mid = (L + R) / 2;
		if (binpow(mid, step) <= lim) {
			L = mid;			
		} else {
			R = mid;
		}
	}	
	if (binpow(R, step) <= lim) {
		return R;
	} else return L;		
}

bool isprime(ll x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
}


ll used[80];

ll get(ll lim) {
	memset(used, 0, sizeof(used));
	for (int i = 2; i <= 60; i++) {
		if (binpow(2, i) > lim) {
			break;
		}
		used[i] = getr(i, lim);
		cout << i << ' '<<binpow(used[i], i)<<' ' << used[i] << ' ' << lim << endl;
		for (int j = 2; j * j <= i; j++) {        
			if (i % j == 0) {
				used[i] -= used[j];
				if (j * j != i) {
					used[i] -= used[i/j];
				}
			}
		}
		used[i]--;
	}
	ll ans = 0;
	for (int i = 2; i <= 60; i++) {
		ans += used[i];	
	}
	return ans;
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif                      
	int Q = readInt();
	while(Q--) {
		ll L= readInt(), R = readInt();
		ll ans = 0;
		if (L == 1) {
			ans ++;
			L = 2;
		}
		cout << ans + get (R) - get(L - 1)<< endl;
	} 
	return 0;
}           	