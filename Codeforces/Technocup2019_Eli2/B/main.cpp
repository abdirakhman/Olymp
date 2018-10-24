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


int a[MAXN];
int b[MAXN];
int n;

int M[4][4];

vector <pair <int, int> > var[5][5];


pair <int, int> F(vector <pair <int, int> >& v, int x) {
	for (pair <int, int> C : v) {
		if (C.first == x) {
			return C;
		}
	}
	return {-1, -1};
}

void check(int x, int y) {
	vector <int> ans;
	ans.pb(x);
	for (int i = 2; i < n; i++) {
		
		ans.pb(y);
		pair <int, int> kek = F(var[a[i]][b[i]], y);
		if (kek.first != -1) {
			x = kek.F;
			y = kek.S;									
		} else {
			return;
		}	        		
	}
	ans.pb(y);
	cout << "YES\n";
	for (int i : ans) {
		cout << i << ' ';
	}
	exit(0);
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	/*M[0][0] = 1;
	M[1][0] = 1;
	M[1][1] = 1;
	M[2][0] = 1;
	M[2][2] = 1;
	M[3][0] = M[3][1] = M[3][2] = M[3][3] = 1;*/
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			M[(i|j)][(i&j)] = 1;
		}
	}
	/*for (int i = 0; i <= 3; i ++) {
		for (int j = 0; j <= 3; j++) {
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}*/
	n = readInt();
	for (int i = 1; i < n; i++) {
		a[i] = readInt();
	}
	for (int i = 1; i < n; i++) {
		b[i] = readInt();
	}
	for (int i = 1; i < n; i++) {
		if (!M[a[i]][b[i]]) {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			var[(i|j)][(i & j)].pb({i, j});
			//cout << i << ' ' << j << endl;
		}
	}
	/*for (int i = 0; i <= 3; i ++) {
		for (int j = 0; j <= 3; j++) {
			cout << (i|j) << ' ' << (i & j) << "==>" << ' ';
			for (pair <int, int> k : var[(i|j)][(j&i)]) {
				cout << k.first << ' ' << k.second << ' ';
			}
			cout << endl;
		}
	}*/
	for (pair <int, int> C : var[a[1]][b[1]]) {
		check(C.first, C.second);
		check(C.second, C.first);
	}
	return 0;
}