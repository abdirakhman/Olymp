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

const long long MOD = 1e18 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

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


vector <pii> g[MAXN];

ll d[6][MAXN];

int n, k, m;
ll dp[6][6][MAXN];

void dijkstra(int id, int s) {
	for (int i = 1; i <= n; i++) {
		d[id][i] = MOD;
	}
	d[id][s] = 0;
	set < pii > q;
	q.insert (make_pair (d[id][s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
		for (size_t j=0; j<g[v].size(); ++j) {
			ll to = g[v][j].first,
				len = g[v][j].second;
			if (d[id][v] + len < d[id][to]) {
				q.erase (make_pair (d[id][to], to));
				d[id][to] = d[id][v] + len;
				q.insert (make_pair (d[id][to], to));
			}
		}
	}
}

priority_queue<pii, vector<pii>, greater<pii> > pq;

void go(int S, int E){
	for(int i = 1; i<=n; i++){
		pq.push(pii(d[S][i] + d[E][i], i));
		dp[S][E][i] = d[S][i] + d[E][i];
	}
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		if(dp[S][E][t.second] < t.first) continue;
		for(auto &i : g[t.second]){
			if(dp[S][E][i.first] > dp[S][E][t.second] + i.second){
				dp[S][E][i.first] = dp[S][E][t.second] + i.second;
				pq.push(pii(dp[S][E][i.first], i.first));
			}
		}
	}
 
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), k = readInt(), m = readInt();
    vector <int> vec;
    for (int i = 1; i <= k; i++) {
    	vec.pb(readInt());
    }
    sort( vec.begin(), vec.end() );
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

    for (int i = 1; i <= m; i++) {
    	int u = readInt(), v = readInt(), c = readInt();
    	g[u].pb({u, c});
    	g[v].pb({u, c}); 
    }
   	for (int i = 0; i < vec.size(); i++) {
   		dijkstra(i, vec[i]);
   	}
    if (vec.size() == 1) {
    	cout << 0;
    	return 0;
    } else if (vec.size() == 2){
    	ll res = MOD;
		for (int i = 1; i <= n; i++) {
			res = min(res, d[0][i] + d[1][i]);									
		}    	
		cout << res << endl;
    } else if (vec.size() == 3) {
		ll res = MOD;
		for (int i = 1; i <= n; i++) {
			res = min(res, d[0][i] + d[1][i] + d[2][i]);									
		}    		
		cout << res << endl;
    } else if (vec.size() == 4) {
    	ll res = MOD;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = i + 1; j < vec.size(); j++) {
				if (i != j)
					go(i, j);
			}
		}    		
		vector <int> Z = {0, 1, 2, 3};
		do{
			if(Z[0] < Z[1] && Z[2] < Z[3] && Z[0] < Z[2]){
				for (int i = 1; i <= n; i++)
					res = min(res, 1ll * dp[Z[0]][Z[1]][i] + dp[Z[2]][Z[3]][i]);
			}
		}while(next_permutation(Z.begin(), Z.end()));
		cout << res << endl;
    } else if (vec.size() == 5) {
    	ll res = MOD;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < vec.size(); j++) {
				if (i != j)
					go(i, j);
			}
		}    		
		vector <int> Z = {0, 1, 2, 3, 4};
		do{
			for (int i = 1; i <= n; i++)
				res = min(res, 1ll * dp[Z[0]][Z[1]][i] + dp[Z[2]][Z[3]][i] + d[Z[4]][i]);
		
		} while(next_permutation(Z.begin(), Z.end()));
		cout << res << endl;
    }
    return 0;
}
