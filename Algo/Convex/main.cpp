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
	ll k, b, id;
	line() { }
	line(ll k, ll b, ll id) : k(k), b(b), id(id) { }
	ll get(ll x){
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
  	line Find(int x){
		int l = 0, r = a.size() - 2, res = 0;
		while (l <= r) {
			int mid = l + r >> 1;                              
			if (a[mid].get(x) <= a[mid + 1].get(x)) res = mid + 1, l = mid + 1;
			else r = mid - 1;
		}
		return a[res];
  	}
};

convex_hull t[4 * MAXN]; 

int K[MAXN];

int B[MAXN];

convex_hull Merge(convex_hull ein, convex_hull dva) {
	vector <line> v(ein.a.size() + dva.a.size());
	merge(ein.a.begin(), ein.a.end(), dva.a.begin(), dva.a.end(), v.begin());
	convex_hull tmp;
	for(auto &i : v){
		tmp.Sal(i);
	}
	return tmp;		
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v].Sal(line(K[tl], B[tr], tl));
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = Merge(t[v * 2], t[v* 2 + 1]);
}

line maxi(line a, line b, int x) {
	if (a.get(x) >= b.get(x)) return a;
		return b;
}


line getmax(int v, int tl, int tr, int l, int r, int x) {
	if (l <= tl && tr <= r) {
		return t[v].Find(x);	
	}	
	int tm = (tl + tr) / 2;
	if (r <= tm) return getmax(v * 2, tl, tm, l, r, x);
	if (tm + 1 <= l) return getmax(v * 2 + 1, tm + 1, tr, l, r, x);
	return maxi(getmax(v * 2, tl, tm, l, r, x), getmax(v * 2 + 1, tm + 1, tr, l, r, x), x);
}              

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt();
	for (int i = 1; i <= n; i++) {
		B[i] = readInt(), K[i] = readInt();
	}	
	build(1, 1, n);
	while(m--) {
		int l = readInt(), r = readInt(), x = readInt();
		cout << getmax(1, 1, n, l, r, x).id << endl;
	}
    return 0;      
}