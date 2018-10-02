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
const long long MOD = 1e9 + 9;
const long long MAXN = 1e7 + 5;
const long long N = 1e7 +4;
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
int suff[MAXN];  
ll cnt[MAXN];
int lp[MAXN];
ll sum;
vector <int> vec;            

bool ok(ll mid) {
	for (int i : vec) {
		ll tmp = mid;
		ll res = 0;
		while(tmp) {
			res += (tmp /= i);	
		}
		if (res < cnt[i]) {
			return 0;
		}
	}	
	return 1;
}

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
        suff[a[i]]++;
    	sum += a[i];
    }

 	for (int i = MAXN - 2; i >= 2; i--) {
		suff[i] += suff[i + 1]; 		
 	}
 	for (int i = 2; i < N; i++) {
 		if (lp[i] == 0) {
 			lp[i] = i;
 			for (int j = i; j <= N; j += i) {
 				if (!lp[j]) {
 					lp[j] = i;
 				}
 			}
 		}
 	}
 	for (int i = 2; i < N; i++) {
 		if (lp[i] == i) {
 		 	vec.pb(i);
 		}
 	}
 	for (int i = N; i >= 2; i--) {
 		int x = i;
		while(x > 1) {
  			int y = lp[x];
  			while(x % y == 0) {
  				cnt[y] += suff[i];
	  			x /= y;
  			}
  		} 		
 	}
	ll l = 1, r = sum;
	while(r - l > 1) {
		ll mid = (l + r) / 2;
		if (ok(mid)) {
			r = mid;			
		} else {
			l = mid;			
		}
	}
	cout << (ok(l) ? l : r);
	return 0;
}