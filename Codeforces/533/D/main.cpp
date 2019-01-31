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

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

int d[10][1111][1111];
int used[10][1111][1111];


char a[1111][1111];
pii s[10];
int Speed[10];
int n, m;
     
bool normal(int x, int posx, int posy) {
	if (!(1 <= posx && posx <= n && 1 <= posy && posy <= m)) return 0;
	if (used[x][posx][posy]) return 0;
	if (a[posx][posy] == '#') return 0;
	if (isdigit(a[posx][posy])) return 0;
	return 1;
} 

int bfs(int p) {
	queue<pii> q;
	q.push (s[p]);
	used[p][s[p].F][s[p].S] = true;
	d[p][s[p].F][s[p].S] = 0;
	while (!q.empty()) {
  		pii v = q.front();
  		q.pop();
  		for (int i = 0; i <= 3; i++) {
  			int nx = v.F + dx[i];
  			int ny = v.S + dy[i];
  			if (normal(p, nx, ny)) {
  				used[p][nx][ny] = 1;
  				q.push({nx, ny});
  				d[p][nx][ny] = d[p][v.F][v.S] + 1;
  			}
  		}
	}
}
int cnt[10];
main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	 n = readInt(), m = readInt();int p = readInt();
    for (int i = 1; i <= p; i++) {
    	Speed[i] =readInt();
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    		if (isdigit(a[i][j])) {
    			s[a[i][j] - '0'] = {i, j};
    		}
    	}	
    }
   	for (int i = 1; i <= p; i++) {
   		for (int j = 1; j <= n; j++) {
   			for (int k  = 1; k <= m; k++) {
   				d[i][j][k] = MOD;
   			}
   		}
   	}
   	for (int i = 1; i <= p; i++) {
   		bfs(i);
   	}   
   	
   	for (int i = 1; i <= p; i++) {
   		for (int j = 1; j <= n; j++) {
   			for (int k  = 1; k <= m; k++) {
   				cout << d[i][j][k] << ' ';
   			}
		cout << endl;
   		}
   		cout << endl; cout << endl;
   	}
    
   	for (int i = 1; i <= n; i++) {
   		for (int j = 1; j <= m; j++) {
   			if (a[i][j] == '#') continue;
   			int upper = d[1][i][j];
   			int lower = Speed[1];
   			int ans = 1;
   			for (int k = 2; k <= p; k++) {
				//cout << upper * Speed[k] << ' ' << d[k][i][j] * lower << endl;
				if (upper * Speed[k] > d[k][i][j] * lower) {
					ans = k;
					upper = d[k][i][j];
					lower = Speed[k]; 					
				}
   			}
   			if (upper != MOD) {
   				cnt[ans]++;		
				//cout << i << ' ' << j << ' '<< ans << endl;
   			}
   		}
   	}
   	for (int i = 1; i <= p; i++) {
   		cout << cnt[i] << ' ';
   	}
    return 0;
}