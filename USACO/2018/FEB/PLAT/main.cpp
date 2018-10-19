/**
https://github.com/updown2/OI-Practice/blob/master/USACO/2017-2018/3.%20February/Problem%202%20New%20Barns.txt
*/

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

int cur = 1;

int dep[MAXN];
int anc[MAXN][20];
int mx_depth[2][MAXN];


int LCA(int A, int B) {
	if (dep[A] > dep[B]) swap(A, B);
	int d = dep[B] - dep[A];
	for (int i = 0; i < 18; i++) {
		if (d & (1<<i)) B = anc[B][i];
	}
	if (A == B) return A;

	for (int i = 17; i >= 0; i--) {
		if (anc[A][i] != anc[B][i]) {
			A = anc[A][i];
			B = anc[B][i];
		}
	}
	return anc[A][0];
}
int dist (int A, int B) {
	return dep[A] + dep[B] - 2*dep[LCA(A, B)];
}


int main() {

	assert(freopen("newbarn.in", "r", stdin));
    assert(freopen("newbarn.out", "w", stdout));
    int Q = readInt();
    while(Q--) {
    	char x;
    	int a;
    	cin >> x >> a;
    	if (x == 'B') {
    		if (a == -1) {
    			a = cur;
				dep[a] = -1;
    		} 
    		mx_depth[0][cur] = mx_depth[1][cur] = -1;
    		anc[cur][0] = a;
			for (int k = 1; k <= 17; k++) {
				anc[cur][k] = anc[anc[cur][k - 1]][k - 1];
			}    		                 
			dep[cur] = dep[a] + 1;
			int FATHER = anc[cur][17];
			if (mx_depth[0][FATHER] == -1) mx_depth[0][FATHER] = cur;
			else if (mx_depth[1][FATHER] == -1) mx_depth[1][FATHER] = cur;
            else {
				int curr = dist(mx_depth[0][FATHER], mx_depth[1][FATHER]), c1 = dist(cur, mx_depth[1][FATHER]), c2 = dist(mx_depth[0][FATHER], cur);
                if (curr > max(c1, c2)) {}
                else if (c1 > c2) mx_depth[0][FATHER] = cur;
                else mx_depth[1][FATHER] = cur;
            }
    		cur ++;
    	} else {
    	    int FATHER = anc[a][17];
    		cout << max(dist(mx_depth[0][FATHER], a), dist(mx_depth[1][FATHER], a)) << endl;
    	}
    }
    return 0;
}