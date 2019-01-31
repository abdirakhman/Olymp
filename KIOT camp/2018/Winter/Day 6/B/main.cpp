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
const long long MAXN = 2e6 + 221;
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


ll sum(ll n, ll x) {
	ll a = n;
	ll b = n + 1;
	if (a & 1) {
		b /= 2;
	} else {
		a /= 2;
	}
	a %= x;
	b %= x;	
	return (a * b) % x;
	
}


vector <int> v[30];

int ans [50005];

__int32_t pref[MAXN];

vector <pair <int, int> > Q[30];

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
	string a;
	cin >> a;
	int N = a.size();
	a += a;
	int k = readInt();
	for (int i = 1; i <= k; i++) {
		int x;
		char b;
		cin >> x >> b;
		Q[b - 'A'].pb({x, i});
	}
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < a.size(); j++) {
			pref[j] = (!j ? 0 : pref[j - 1]) + (a[j]-'A' == i);
		}
		for (pair <int, int> j : Q[i]) {
			int x = j.F;
			int start = sum(x - 1, N); ///starting pointll 
		
			ll dv = x / (N); /// how many divides
			ll kaldi = x % (N); /// remainder        
		
			ll to_add = dv * pref[N - 1]; /// pref[a.size() - 1][b - 'A'];
			if (kaldi)
				to_add += (pref[start + kaldi - 1] - (!start ? 0 : pref[start - 1]));
			ans[j.S] = to_add;
		}
	}
	for (int i = 1; i <= k; i++) {
		cout << ans[i] << endl;
	}                              
    return 0;
}