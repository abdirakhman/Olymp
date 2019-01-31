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

const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;

const long long MAXN = 100 + 1;
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

const long long P = 127;
long long p[MAXN + 110], p1[MAXN + 110];
long long h[MAXN + 110], h1[MAXN + 110];
long long Hash(long long l, long long r, long long mod, long long h[], long long p[]) {
    return (h[r] - (h[l] * p[r - l]) % mod + (2 * mod)) % mod;
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    string a;
    cin >> a;
    h[0] = 0;
    h1[0] = 0;
    p[0] = 1;
    p1[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        p[i] = (p[i - 1] * P) % MOD1;
        p1[i] = (p1[i - 1] * P) % MOD2;
    }
    for (int i = 1; i <= a.size(); i++) {
        h[i] = (h[i - 1] * P) % MOD1;
        h[i] = (h[i] + a[i - 1]) % MOD1;
        h1[i] = (h1[i - 1] * P) % MOD2;
        h1[i] = (h1[i] + a[i - 1]) % MOD2;
    }
    set <string> s;
    for (int len = 2; len <= a.size(); len++) { 
        for (int i = 0; i < a.size() - len + 1; i++) { 
            int j = i + len - 1;
       		for (int i1 = i + 1; i1 <= j; i1++) {
       			int j1 = i1 + len - 1;
       			if (j1 >= a.size()) continue;
       			//cout << i << ' ' << j << ' ' << i1 << ' ' << j1<< endl;
				if (a.substr(i,len) == a.substr(i1, len)) {
					s.insert(a.substr(i,len));
				}
       		}
		} 
    }
    cout << s.size();
    return 0;
}