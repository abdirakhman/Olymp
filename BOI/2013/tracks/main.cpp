/**
https://boi2013.informatik-olympiade.de/wp-content/uploads/2013/05/tracks-spoiler.pdf
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
 
const int N = 4001;
 
char a[N][N];
 
int d[N][N];
 
int d_x[] = {1, -1, 0, 0};
int d_y[] = {0, 0, 1, -1};
 
int H, W; 
 
int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    H = readInt(), W = readInt();
    for (int i = 1; i <= H; i++) {
    	for (int j = 1; j <= W; j++) {
    		cin >> a[i][j];
        	d[i][j] = MOD;
    	}
    }
	deque<pair <int, int> > q;
	q.push_front({1, 1});       
	d[1][1] = 0;
	int mx = 0;
	while (!q.empty()) {
		pair <int, int> v = q.front();
		q.pop_front();
		int x = v.F;
		int y = v.S;
		//cerr << v.F << ' ' << v.S << endl;
		for (int i = 0; i < 4; i++) {
			int X = v.first + d_x[i];
			int Y = v.second + d_y[i]; 
			if (X >= 1 && Y >= 1 && X <= H && Y <= W && a[X][Y] != '.') {
				if (d[X][Y] > d[x][y] + (a[X][Y] != a[x][y])) {
					d[X][Y] = d[x][y] + (a[X][Y] != a[x][y]);
					if ((a[X][Y] != a[x][y])) {
						q.push_back({X, Y});
					} else {
						q.push_front({X, Y});
					}	 	
				}
			}
		}
	}
	
	for (int i =1 ; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (a[i][j] != '.')
			mx = max(mx, d[i][j]);
			//cout << d[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << mx+1;
	return 0;
}