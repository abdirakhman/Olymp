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


const long long MOD = 1e15 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


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

struct aaa {
	int a, b, c;
};
aaa arr[MAXN];

bool cmp(aaa x, aaa y) {
	return x.a - x.b > y.a - y.b;
}

int pref[MAXN];
int suff[MAXN];

 main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int X = readInt(), Y = readInt(), Z = readInt();
    int n = X + Y + Z;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	arr[i].a = readInt();
    	arr[i].b = readInt();
    	arr[i].c = readInt();
    	ans += arr[i].c;
    	arr[i].a -= arr[i].c;
    	arr[i].b -= arr[i].c;
    	arr[i].c -= arr[i].c;
    	suff[i] = -MOD;
    	pref[i] = -MOD;
    }
    int sum = 0;
	sort(arr + 1, arr + 1 + n, cmp);		   
    multiset<int> s;
    for (int i = 1; i <= n; i++) {
    	int cand = arr[i].a;
    	if (s.size() < X) {
    		s.insert(cand);
    		sum += cand;
    	} else {
    		int mn = *s.begin();
    		if (mn < cand) {
    			sum -= mn;
    			sum += cand;
    			s.erase(s.find(mn));
    			s.insert(cand);
    		}
    	}
    	if (s.size() == X) {
    		pref[i] = sum;
    	}
    }
    s.clear();
    sum = 0;
    for (int i = n; i >= 1; i--) {
    	int cand = arr[i].b;
    	if (s.size() < Y) {
    		s.insert(cand);
    		sum += cand;
    	} else {
    		int mn = *s.begin();
    		if (mn < cand) {
    			sum -= mn;
    			sum += cand;
    			s.erase(s.find(mn));
    			s.insert(cand);
    		}
    	}
    	if (s.size() == Y) {
    		suff[i] = sum;
    	}
    }
    int res = -MOD;
    for (int i = 1; i < n; i++) {
    	res = max(res, pref[i] + suff[i + 1]);
    }
    cout << res + ans;
	return 0;
}