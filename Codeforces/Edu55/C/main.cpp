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


vector <int> v[MAXN];
int n, m;
int s[MAXN];
int r[MAXN];
vector <int> pref[MAXN];

vector <int> kek;
int used[MAXN];

int f(int x) {
	if (x == 0) return 0;
	int sum = 0;
	for (int Z = 0; Z < kek.size(); Z++) {
		int i = kek[Z];
		if (v[i].size() < x) {
			//continue;
			swap(kek[Z], kek[kek.size() - 1]);
			kek.pop_back();
		} else {
			if (pref[i][x-1] > 0) {
				sum += pref[i][x-1];
			} else {
					swap(kek[Z], kek[kek.size() - 1]);
					kek.pop_back();
			}	
		}
	}
	return sum;
}
main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt();    
    for (int i = 1; i <= n; i++) {
    	s[i] = readInt();
    	r[i] = readInt();
    	v[s[i]].pb(r[i]);
		if (!used[s[i]]) {
			kek.pb(s[i]);
		}
		used[s[i]] = 1;
    }
    for (int Z = 0; Z < kek.size(); Z++) {
    	int i = kek[Z];
		sort(v[i].begin(), v[i].end());    
    	reverse(v[i].begin(), v[i].end());
    	for (int j = 0; j < v[i].size(); j++) {
    		pref[i].pb((j == 0 ? 0 : pref[i][pref[i].size() - 1]) + v[i][j]);
    	}
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
		ans = max(ans, f(i));
		if (kek.size() == 0) {
			break;
		}
	}
	cout << ans;
    return 0;
}