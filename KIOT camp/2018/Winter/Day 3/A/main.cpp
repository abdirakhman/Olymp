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


int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

string kek = "IMAD";

const int N = 1e3 + 4;

int Z[N][N];
int used[N][N];
int a[N][N];
int n, m;
vector <pair <int,int> > tp;

void go_cyc(int x, int y) {
	used[x][y] = 1;
	for (int i = 0; i <= 3; i++) {
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (!(1 <= xx && xx <= n && 1 <= yy && yy <= m)) continue;
		if (used[xx][yy] == 1 && a[xx][yy] == (a[x][y] + 1) % 4) {
			cout << "Poor Inna!";
			exit(0);			
		}
		if (!used[xx][yy] && a[xx][yy] == (a[x][y] + 1) % 4) {
			go_cyc(xx, yy);
		}
	}
	tp.pb({x, y});
	used[x][y] = 2;
}

int dp[N][N];

void go(int x, int y) {
	for (int i = 0; i <= 3; i++) {
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (!(1 <= xx && xx <= n && 1 <= yy && yy <= m)) continue;
		if (a[xx][yy] == (a[x][y] + 1) % 4)
			dp[xx][yy] = max(dp[xx][yy], dp[x][y] + 1);
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		char x;
    		cin >> x;
    		//	dp[i][j] = -MOD;
    		if (x == 'D') {
    		    a[i][j] = 0;
    		    dp[i][j] = 1;
    		} else if (x == 'I') {
				a[i][j] = 1;    			
    		} else if (x == 'M') {
				a[i][j] = 2;    			
    		} else {
				a[i][j] = 3;    			
    		}		
    	}
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (!used[i][j]) {
				go_cyc(i, j);    		
    		}
    	}
    }
    memset(used, 0, sizeof(used));
    reverse(tp.begin(), tp.end());
                                              
    for (pair <int, int> i : tp) {
    	if (dp[i.F][i.S] > 0) {
    		go(i.F, i.S);
    	}
    }
    int kek = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j<=m; j++) {
    		kek = max(kek, dp[i][j]);
    	}
    }
    if (kek < 4) {
    	cout << "Poor Dima!";
    	return 0;
    } else {
    	cout << (kek >> 2);	
    }
    return 0;
}