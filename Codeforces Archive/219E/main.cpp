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


int kaida[MAXN];

int n, q;
set <pair <int, int> > S;
set <int> used;    

int f(int x) {
	int dist = MOD;
	int R = *used.lower_bound(x);
	if (R != n + 1) {
		dist = min(dist, abs(x - R));		
	}
	auto tmp = used.lower_bound(x);
	--tmp;
	int L = *(tmp);
	if (L != 0) {
		dist = min(dist, abs(x - L));
	}
    return dist;
}

int go() {
	int ans = 1;
	if (f(ans) < f(n)) {
		ans = n;
	}
	/// (L - R) / 2, L
	/// -(-L + R) / 2, 2L / 2
	/// 2L/2 - (-(-L+R))
	/// (2L-(L - R))/2
	/// (L + R) / 2
	pair <int, int> kek = *S.begin();
	if (f(ans) < f(kek.second - kek.first)) {
		ans = kek.second - kek.first;
	}
	return ans;
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), q = readInt();
	used.insert(0);
	used.insert(n+1);
	S.insert({-(n+1)/2, 0});    
    while(q--) {
    	int type = readInt(), id = readInt();
    	if (type & 1) {
    		int candidate = go();
		    kaida[id] = candidate;
			int R = *used.lower_bound(candidate);
			auto tmp = used.lower_bound(candidate);
			--tmp;
			int L = *(tmp);
			S.erase({(L - R) / 2, L});
		    S.insert({(candidate - R) / 2, candidate});
		    S.insert({(L - candidate) / 2, L});
		    used.insert(candidate);
    		cout << candidate << endl;
    	} else {
			int candidate = kaida[id];
			used.erase(kaida[id]);
			kaida[id] = 0;
			int R = *used.lower_bound(candidate);
			auto tmp = used.lower_bound(candidate);
			--tmp;
			int L = *(tmp);			
			S.erase({(candidate - R) / 2, candidate});
			S.erase({(L - candidate) / 2, L});
			S.insert({(L - R) / 2, L});	    		
    	}
    }
    return 0;
}