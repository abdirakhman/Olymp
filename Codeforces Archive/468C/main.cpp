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

int pw[20];

ll F(ll x) {
	ll ans = 0; 
	int s = 0;
	vector <int> r;
	while (x) {
		r.pb(x % 10);
		x /= 10;
	}
	reverse(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++) {
		if (i == r.size() - 1) ans = ans + (2 * s + r[i] - 1) * r[i] / 2;
		else ans = ans + pw[r.size() - i - 1] * ((2 * s + r[i] - 1) * r[i] / 2) + pw[r.size() - i - 2] * (r[i] * 45 * (r.size() - i -1));
		s += r[i];
	}
	return ans;
}

int f(int x) {
	int ans = 0;
	while(x) {
		ans += (x % 10);
	    x /= 10;
	}
	return ans;	
}

 main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
	pw[0] = 1;
	for (int i = 1; i <= 18; i++) pw[i] = pw[i-1] * 10;	
	int L = 1, R = (1LL << 55);
	while(R - L > 1) {
		int mid = (L + R) / 2;
		if (F(mid) >= n) {
			R = mid;
		} else {
			L = mid;
		}
	}    
	int sum = F(R);
	for (int l = 1;; l++) {
		if (sum == n) {
			cout << l << ' ' << R - 1;
			return 0;
		}
		sum -= f(l);
		while(sum < n) sum += f(R++);
	}
    return 0;
}