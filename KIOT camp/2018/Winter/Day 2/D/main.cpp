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

map <int, int> used;

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	int m = readInt();
	vector <int> v;
	int pos = 0;
	v.pb(-228);
	vector <pair <int, pair <int, int> >> P;
	while(m--) {
		int type = readInt();
		if (type == 1) {
			int x = readInt();
			//v.pb(x);
			pos++;
			used[pos] = x;
			if (pos <= 100005) {
				v.pb(x);
			}
		} else {
			int pref = readInt(), cnt = readInt();
			int len = pref * cnt;
			P.pb({pos + 1, {pos + len, pref}});
			int tot = pos + len;
			for (int i = 1; i <= cnt && pos <= 100005; i++) {
				for (int j = 1; j <= pref && pos <= 100005; j++) {
					pos++;
					v.pb(v[j]);
				}
			}
			pos = tot;
		}				
	}
	int q = readInt();
	while(q--) {
		int x = readInt();
		if (x <= 100004) {
			cout << v[x] << ' ';
		} else if (used[x]) {
			cout << used[x] << ' ';
			continue;
		} else {
			auto K = upper_bound(P.begin(), P.end(), make_pair(x, make_pair((int) 0, (int)0))) - P.begin();
			K--;
			pair <int, pair <int, int>> kek = P[K];
			if (!(kek.F <= x && x <= kek.S.F)) {
				cout << "wtf";
				return 0;
			} 
			x -= (kek.F - 1);
			x %= kek.S.S;
			if (!x) {
				x = kek.S.S;
			}	
			cout << v[x] << ' ';
		}
	}
    return 0;
}