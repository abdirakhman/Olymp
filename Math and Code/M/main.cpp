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

vector <short int> G[111];
vector <vector <short int> > ans;

bool ch(short int x, vector <short int> & k) {
	for (short int i : k) {
		if (i == x) return true;
	}
	return false;
}
int used[111];
int timer = 1;
int res = MOD;

int tekser(vector <short int> & a, vector <short int> & b) {
    short int ans = 0;
	for (short int i : a) {
		if (used[i] < timer) {
			ans ++;
			used[i] = timer;
		}
	}	
	for (int i : b) {
		if (used[i] < timer) {
			ans ++;
			used[i] = timer;
		}
	}
	return ans;
}




void go(short int S, short int T, bool tp) {
	queue <vector <short int> > q;
	vector <short int> p;
	p.pb(S);
	q.push(p);
	while(!q.empty()) {
		p = q.front();
		q.pop();
		short int kek = p[p.size() - 1];
		if (kek == T) {
			if (tp == 1) {
				for (short int i = 0; i < ans.size(); i++) {
					timer++;
					res = min(res, tekser(ans[i], p));
				}	
			} else 
			ans.pb(p);			
		}
		for (short int i : G[kek]) {
			if (ch(i, p)) {
				vector <short int> newp(p);
				newp.pb(i);
				q.push(newp);
			}
		}
	}	
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    short int n = readInt(), m = readInt();
    for (int i = 1; i <= m; i++) {
		short int u = readInt(), v = readInt();
		G[u].pb(v);   
    }
    short int S = 1;
    short int T = 2;
    go(S, T, 0);
    go(T, S, 1);
    
    cout << res;
    return 0;
}
