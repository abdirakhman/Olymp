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
#define hash asdasdasdnajksldsnd
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

pair <long long, long long> hash[MAXN];

vector <int> g[MAXN];

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;    
const ll pw = 1e6+7;

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	int n = readInt(), m = readInt();
	for (int i = 1; i <= m; i++) {
		int u = readInt(), v = readInt();
		g[v].pb(u);
		g[u].pb(v);
	}

	for (int i = 1; i <= n; i++) {
			sort(g[i].begin(), g[i].end());
			hash[i] = {0, 0};
			for (int j : g[i]) {
				hash[i].F *= pw;
				hash[i].F %= MOD1;
				hash[i].F += j;
				hash[i].F %= MOD1;
				
				hash[i].S *= pw;
				hash[i].S %= MOD2;
				hash[i].S += j;
				hash[i].S %= MOD2;				
		}
	}	
	ll ans = 0;
	ll cnt = 1;
	sort(hash + 1, hash + 1 + n);
	for (int i = 2; i <= n; i++) {
		if (hash[i].F == hash[i - 1].F && hash[i].S == hash[i - 1].S) {
			cnt ++;
		} else {
			if (cnt >= 2)
				ans += (cnt * (cnt - 1)) / 2;
			cnt = 1;
		}
	}
	if (cnt >= 2)
		ans += (cnt * (cnt - 1)) / 2;	

	for (int i = 1; i <= n; i++) {
			g[i].pb(i);
			sort(g[i].begin(), g[i].end());
			hash[i] = {0, 0};
			for (int j : g[i]) {
				hash[i].F *= pw;
				hash[i].F %= MOD1;
				hash[i].F += j;
				hash[i].F %= MOD1;
				
				hash[i].S *= pw;
				hash[i].S %= MOD2;
				hash[i].S += j;
				hash[i].S %= MOD2;				
		}
	}	
	cnt = 1;
	sort(hash + 1, hash + 1 + n);
	for (int i = 2; i <= n; i++) {
		if (hash[i].F == hash[i - 1].F && hash[i].S == hash[i - 1].S) {
			cnt ++;
		} else {
			if (cnt >= 2)
				ans += (cnt * (cnt - 1)) / 2;
			cnt = 1;
		}
	}
	if (cnt >= 2)
		ans += (cnt * (cnt - 1)) / 2;	
	
	cout << ans;
	return 0;   
}