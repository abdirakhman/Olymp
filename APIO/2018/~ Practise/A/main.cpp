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

int x[MAXN], t[MAXN], a[MAXN], b[MAXN];
int used[MAXN];

int n, k, q;

vector <int> G[MAXN];

void solve3() {
	
		while(q--) {
			cout << -1;
		} 
		for (int i = 1; i <= n; i++) {
			G[t[i]].pb(i);			
		}
		for (int i = 1; i <= k; i++) {
			sort(G[i].begin(), G[i].end(), cmp);
		}
		while(q--) {
			
		}
   	
}  

void solve1() {
	while(q--) {                     
		int l = readInt(), r = readInt();
		///r - year
		for (int i = 1; i <= k; i++) {
			used[i] = MOD;
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] <= r && r <= b[i]) {
				used[t[i]] = min(abs(l - x[i]), used[t[i]]);				
			}				
		}
		int ans = *max_element(used + 1, used + 1 + k);    
		cout << (ans == MOD ? -1 : ans) << endl;
	}
}

void solve2()  {
	for (int i = 1; i <= n; i++) {
		G[t[i]].pb(x[i]);		 
	}
	for (int i = 1; i <= k; i++) {
		sort(G[i].begin(), G[i].end());
	}
	while(q--) {                     
		int l = readInt(), r = readInt();
		int ans = -1;
		for (int i = 1; i <= k; i++) {
			
			ans = max(ans, min());
		}
		cout << ans << endl;
	}	
}

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), k = readInt(), q = readInt();
    bool sub3 = 0;
    bool sub1 = (n <= 400 && q <= 400);
    bool sub2 = (n <= 60000 && q <= 60000 && k <= 400);
    bool sub4 = (n <= 300000 && q <= 300000);
    for (int i = 1; i <= n; i++) {
		x[i] = readInt(), t[i] = readInt(), a[i] = readInt(), b[i] = readInt();		    	
        if (a[i] != 1) sub4 = 0;
        if (a[i] != 1 || b[i] != 100000000) sub3 = 0;
    }
    if (sub1) {
    	solve1();
    }
    if (sub2) {
     	solve2();
    }
	if (sub3) {
		solve3();
	}	
    return 0;
}