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
#include <unordered_map>
#pragma GCC optimize("Ofast")


#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back
//#define int long long
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


main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    const int N = 3*1e4+1;
	const ll mod = 36028797018963913;    
	const ll B = 29;
    ll Hash[N];
	ll Hash1[N];
	ll P[N];
	
	bool ans[N];

    int T = readInt();
    P[0] = 1;
    for (int i = 1; i < N; i++) {
    	P[i] = (P[i-1] * B) % mod;
    }
	while(T--) {
		int n = readInt(),k = readInt();
		char s[n+1][k];

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < k; j++) {
				s[i][j] = getchar();
			}
			getchar();
		}
		if (n > k) {
			memset(Hash, 0, sizeof(Hash));
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < k; j++) {
					Hash[i] = (Hash[i] + ((s[i][j] - 'a' + 1) * P[j])%mod)%mod;
				}
			}
			unordered_map<ll, ll> H;
			for (int i = 0; i < k; i++) {
				for (int j = i+1; j < k; j++) {
				    H.clear();
					for (int I = 1; I <= n; I++) {
						Hash1[I] = Hash[I];
						Hash1[I] = (Hash1[I] - (P[i] * (s[I][i] - 'a' + 1)) % mod + mod) % mod;
                        Hash1[I] = (Hash1[I] - (P[j] * (s[I][j] - 'a' + 1)) % mod + mod) % mod;
                        H[Hash1[I]]++;

					}
					for (int I = 1; I <= n; I++) {
						if (H[Hash1[I]] > 1) {
							ans[I] = 1;
						}
					}
				}
			}			
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					int dif = 0;
					for (int L = 0; L < k; L++) {
						dif += (s[i][L] != s[j][L]);
					}					
					if (dif <= 2) {
						ans[i] = ans[j] = 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			putchar(ans[i]+'0');
			ans[i]= 0;
		}		     
		putchar('\n');
	}                
    return 0;
}