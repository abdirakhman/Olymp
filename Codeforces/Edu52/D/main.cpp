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

const int N = 11;

int used[N][N];
int d[N][N];

int Dx[4] = {-1, -1, 1, 1};
int Dy[4] = {-1, 1, -1, 1};

int d_x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int d_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 


int ways[N][N][N][N][4];


int n;

bool normal(int x, int y) {
	return (x >= 1 && y >= 1 && x <= n && y <= n && !used[x][y]);
}

void bfs(int x, int y) {
	queue<pair <int, int> > q;
	q.push ({x, y});
	memset(used, 0, sizeof(used));
	memset(d, 0, sizeof(d));
	used[x][y] = true;
	
	while (!q.empty()) {
		pair <int, int> v = q.front();
		q.pop();
		for (int k = 0; k < 8; k++) {
			int x1 = d_x[k] + v.F;
			int y1 = d_y[k] + v.S;
			if (normal(x1, y1)) {
				used[x1][y1] = true;
				q.push ({x1, y1});
				d[x1][y1] = d[x][y] + 1;
			}
		}
	}
}


void build_kon() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bfs(i, j);
	    	for (int i1 = 1; i1 <= n; i1++) {
				for (int j1 = 1; j1 <= n; j1++) {
					if (!used[i1][j1]) {
						ways[i][j][i1][j1][0] = MOD;
					} else {
						ways[i][j][i1][j1][0] = d[i1][j1];						
					}
				}	    		
	    	}
		}
	}
}


void build_ladya() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int i1 = 1; i1 <= n; i1++) {
				for (int j1 = 1; j1 <= n; j1++) {
					ways[i][j][i1][j1][1] = ((i1 == i || j1 == j) ? 1 : 2);
				}
			}
		}
	}
}


void build_slon() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
	    	for (int i1 = 1; i1 <= n; i1++) {
				for (int j1 = 1; j1 <= n; j1++) {
					if (i%2 == i1&2 && j&2==j1&2) {
						ways[i][j][i1][j1][2] = (abs(i-i1)==abs(j-j1) ? 1 : 2);
					} else {
						ways[i][j][i1][j1][2] = MOD;												
					}
				}	    		
	    	}
		}
	}	
}
pair <int, int> pos[111];

vector <int> G[N*N][4];

int a[111][111];
pair<int,int> D[999][999];


pair <int, int> kek(pair <int, int> a, pair <int, int> b, pair <int, int> c) {
	pair <int, int> res = {b.F + c.F, b.S + c.S};
	if (a.F != res.F) {
		if (a.F < res.F) {
			return a;
		} else {
			return res;
		}		
	} else {
		if (a.S < res.S) {
			return a;
		} else {
			return res;
		}
	}
}

pair <int, int> K(pair <int, int> a, pair <int, int> b) {
	pair <int, int> res = {b.F, b.S};
	if (a.F != res.F) {
		if (a.F < res.F) {
			return a;
		} else {
			return res;
		}		
	} else {
		if (a.S < res.S) {
			return a;
		} else {
			return res;
		}
	}
}
int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt();
    build_kon();
    build_slon();
    build_ladya();
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
    		pos[a[i][j]] = {i, j};
    	}
    }        
    for (int i = 1; i <= 3*n*n; i++) {
    	for (int j = 1; j <= 3*n*n; j++) {
    		D[i][j] = {MOD, MOD};
    	}
    }
	for (int i = 1; i < n*n; i++) {
		int x = pos[i].F;
		int y = pos[i].S;
		for (int j = 1; j <= 3; j++) {
			for (int j1 = 1; j1 <= 3; j1++) {
				int x1 = pos[i+1].F;
				int y1 = pos[i+1].S;
				D[3*(i-1)+j][3 * (i) + j1] = {ways[x][y][x1][y1][j-1], (j != j1)};
			}			
		}		
	}
	for (int k = 1; k<=3*n*n; ++k) {
		for (int i=1; i<=3*n*n; ++i) {
			for (int j=1; j<=3*n*n; ++j) {
				D[i][j] = kek (D[i][j], D[i][k], D[k][j]);
			}		
		}
	}
	pair <int, int> ans = {MOD, MOD};
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			ans = K(ans, D[i][3*(n-1)+j]);		
		}                         
	}
	cout << ans.F << ' ' << ans.S;
    return 0;
}