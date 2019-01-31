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


const long long MAXN = 20;
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

#define int __int64_t
const int MOD = 1e9 + 7;

const int N = 20;
int inv[N][N];
int a[N][N];
pair <int, int> nvi[N*N];


int n, m;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct edge {
	int a, b, cost;
};

vector<edge> e;


void build() {          	
	e.clear();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				int i1 = i + dx[k];
				int j1 = j + dy[k];
				if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
					edge kek;
					kek.a = (i-1) * m + j;
					kek.b = (i1 - 1) * m + j1; 
					kek.cost = a[i1][j1];
					e.pb(kek);        
				}
			}
		}
	}		
}

void build_mykty(int s, int t) {
	e.clear();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				int i1 = i + dx[k];
				int j1 = j + dy[k];
				if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
					edge kek;
					kek.a = (i-1) * m + j;
					kek.b = (i1 - 1) * m + j1; 
					kek.cost = a[i1][j1];
					if (kek.b == t || kek.b == s) {
						kek.cost = 0;
					}
					else {
						if (kek.cost < 0) {
						    kek.cost = MOD;
						} 	
					}
					e.pb(kek);        
				}
			}
		}
	}
}

int d[N*N];

void out() {
	for (int i = 1; i <= n*m; i++) {
		cout << d[i] << ' ';
		if (i % m == 0) cout << endl;
	}
	cout << endl;
}

bool go(int s, int t) {
	int x;
	deb(s);
	deb(t);
	for (int i = 1; i <= n*n; i++) {
		d[i] = MOD;
	}
	d[s] = 0;
	vector <int> p(N*N + N, -1);
	for (int i = 0; i < n*n - 1; ++i) {
		x = -1;
		for (int j = 0; j < e.size(); ++j) {
			if (d[e[j].a] < MOD)
				if (d[e[j].b] > d[e[j].a] + e[j].cost) {
					d[e[j].b] = max (-MOD, d[e[j].a] + e[j].cost);
					p[e[j].b] = e[j].a;
					x = e[j].b;
				}
		}
	}
	out();		
	return 0;	
}

int dp[N][N];

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt() + 2, m = readInt();
    vector <int> vec;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 || i == n) {
			    char x;
			    cin >> x;
				a[i][j] = 0;				
			} else {
				a[i][j] = readInt();
				if (a[i][j] < 0) {
					vec.pb(m * (i-1) + j);
				}
			}
			inv[i][j] = (m * (i - 1) + j);
			nvi[(m * (i - 1) + j)] = {i, j};
		}		
    }
    ///Proverka na 1
    build();
    vector <pair <int, int> > cand;
    for (int i = 0; i < vec.size(); i++) {
    	for (int j = 0; j < vec.size(); j++) {
    		if (i == j) continue;
    		build_mykty(vec[i], vec[j]);
    		go(vec[i], vec[j]);
    		if (2 * d[vec[j]] + a[nvi[vec[i]].F][nvi[vec[i]].S] + a[nvi[vec[j]].F][nvi[vec[j]].S] < 0) {
    			cand.pb({vec[i], vec[j]});	
    		}
    	}
    }
    cout << cand.size() << endl;
	/*build();
	go(1, MOD);
	int ans = min(ans, d[ inv[n][m] ]);
	for (auto i : cand) {
		cout << i.F << ' ' << i.S << endl;
	}	
    */
    int ans = MOD;
    for (pair<int,int> i : cand) {
    	int kek1 = i.F;
    	int kek2 = i.S;
    	build_mykty(kek1, kek2);
    	go(inv[n][m], MOD);
    	int dist1 = d[kek1];
    	int dist2 = d[kek2];
		go(kek1, kek2);
		ans = min(ans, dist1 + d[kek2] + a[nvi[kek1].F][nvi[kek1].S]);
		ans = min(ans, dist2 + d[kek2] + a[nvi[kek2].F][nvi[kek2].S]);
    }
    ans = max(ans, (int)0);
    cout << max(ans, (int)0) << endl;
	return 0;
}