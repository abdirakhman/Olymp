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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define pb push_back

const long long MOD = 1e9 + 9;
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
int F[MAXN];
int pref_F[MAXN];
int block_sum[MAXN];
int push[MAXN];
int n, m;
int sum[MAXN];

vector <pair <int, int> > pushed;


void go() {
	for (int i = 1; i <= n; i++) {
		push[i] += push[i - 1];
		if (i > 1) {
			push[i] += push[i - 2];
		}
		push[i] %= MOD;
		a[i] += push[i];
		a[i] %= MOD;
	}	
	memset(push, 0, sizeof(push));
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
		sum[i] %= MOD;
	}
}
               
int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    	sum[i] = sum[i-1] + a[i];
    	sum[i] %= MOD;
    }
    F[1] = F[2] = 1;
	for (int i = 3; i <= n; i++) {
		F[i] = F[i - 1] + F[i - 2];
		F[i] %= MOD;
	}    
	int block_Sz = 514;
	for (int i = 1; i <= n; i++) {
		pref_F[i] = pref_F[i - 1] + F[i];
		pref_F[i] %= MOD;
	}       
	for (int k = 1; k <= m; k++) {
		if (pushed.size() % block_Sz == 0) {
			go();
			pushed.clear();
		}
		int type = readInt(), l = readInt(), r = readInt();
		if (type & 1) {
			push[l] += F[1];
			push[l] %= MOD;
			push[r+1] -= F[r-l+2];
			push[r+1] += MOD;
			push[r+1] %= MOD;
			push[r+2] -= F[r-l+1];
			push[r+2] += MOD;
			push[r+2] %= MOD;
			pushed.pb({l, r});			
		} else {
			int res = sum[r] - sum[l - 1];
			for (int i = 0; i < pushed.size(); i++) {
				int mx1 = max(pushed[i].F, l);
				int mx2 = min(pushed[i].S, r);
				if (mx1 > mx2) {
					continue;
				}
				int L = mx1 - pushed[i].F + 1;
				int R = mx2 - pushed[i].F + 1;
				res += (pref_F[R] - pref_F[L - 1] + MOD);
				res %= MOD;				
			}
			cout << res << endl;
		}
	} 
	return 0;           
}