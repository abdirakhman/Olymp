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


int par[MAXN];
int rk[MAXN];
int ans[MAXN];
pair<int, int> q[MAXN];
int N, M, Q;

void init() {
	for (int i = 1; i <= N; i++) {
		par[i] = i;
		rk[i] = 0;
	}
}

int find_par(int v) {
	if (par[v] == v) {
		return v;
	} else {
		return par[v] = find_par(par[v]);
	}
}

int Merge(int a, int b, int type) {
	a = find_par(a);
	b = find_par(b);
	if (a == b) return 0;
	if (type) return 1;
	if (rk[a] < rk[b])  {
		swap(a, b);
	}
	par[b] = a;
	if (rk[a] == rk[b]) rk[a]++;
	return 1;
}

void kosu(int x) {
	for (int i = x; i + x <= N; i += x) {
		Merge(i, i + x, 0);
	}
}
            
 

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    N = readInt(), M = readInt(), Q = readInt();
    init();
    for (int i = 1; i <= Q; i++) {
    	q[i] = {readInt(), readInt()};
    }
	for (int i = M; i >= 1; i--) {
		kosu(i);
		for (int j = 1; j <= Q; j++) {
			if (!ans[j] && !Merge(q[j].first, q[j].second, 1)) {
				ans[j] = i;	
			}
		}
	}
	for (int i = 1; i <= Q; i++) {
		cout << M - ans[i] + 1 << endl;
	}
    return 0;
}