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

struct line {
	long double k, b, id;
	line() { }
	line(ll k, ll b, ll id) : k(k), b(b), id(id) { }
	long double get(ll x){
		return k * x + b;
	}
	bool operator < (const line &p)const{
		return make_pair(k, b) < make_pair(p.k, p.b);
	}
};
struct convex_hull {
	vector <line> a;
	bool bad(int id_l1, int id_l2, line l){
		return (a[id_l1].k - a[id_l2].k) * (l.b - a[id_l2].b) <= (a[id_l2].k - l.k) * (a[id_l2].b - a[id_l1].b);
	}
	void Sal(line l){
    	while(a.size() >= 2 && bad(a.size() - 2, a.size() - 1, l))
      		a.pop_back();
    	a.pb(l);
	}
  	long double Find(int x){
		int l = 0, r = a.size() - 2, res = 0;
		while (l <= r) {
			int mid = l + r >> 1;                              
			if (a[mid].get(x) <= a[mid + 1].get(x)) res = mid + 1, l = mid + 1;
			else r = mid - 1;
		}
		return a[res].get(x);
  	}
};


int K[MAXN];

int B[MAXN];

long double dp[MAXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
	for (int i = 1; i <= n; i++) {
		K[i] = readInt();
	}	
	for (int i = 1; i <= n; i++) {
		B[i] = readInt();
	}	
	convex_hull tmp;
	tmp.Sal({-B[1], -dp[1], 1});
	for (int i = 2; i <= n; i++) {
		long double ans = tmp.Find(K[i]);
		dp[i] = -ans;
		tmp.Sal(line(-B[i], -dp[i], i));		
	}
	cout <<fixed<<setprecision(0)<< dp[n];
    return 0;      
}