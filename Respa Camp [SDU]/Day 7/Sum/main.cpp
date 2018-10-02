/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

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

int n;
struct siziq {
	ll k, b;
	siziq() { }
	siziq(ll k, ll b) : k(k), b(b) { }
	ll get(ll x){
		return k * x + b;
	}
};
struct Dones_korpus{
	vector <siziq> a;
	bool jaman(int id_l1, int id_l2, siziq l){
		return (a[id_l1].k - a[id_l2].k) * (l.b - a[id_l2].b) <= (a[id_l2].k - l.k) * (a[id_l2].b - a[id_l1].b);
	}
	void Sal(siziq l){
    	while(a.size() >= 2 && jaman(a.size() - 2, a.size() - 1, l))
      		a.pop_back();
    	a.pb(l);
	}
  	ll Tap(int x){
    	ll l = -1, r = a.size() - 1;
    	while(l + 1 < r){
      		ll m = (l + r) >> 1;
      		if(a[m].get(x) <= a[m + 1].get(x))
        		l = m;
      		else
        		r = m;
    	}
    	return a[r].get(x);
  	}
};
int pref[MAXN];

int a[MAXN];

Dones_korpus t[4 * MAXN];

line a[MAXN];

Dones_korpus Merge(Dones_korpus & _a, Dones_korpus & _b) {
	int ptr_1 = 0, ptr_2 = 0;
	Dones_korpus res;
	while(ptr_1 < _a.a[ptr_1].size() && ptr_2 < _b.a[ptr_1].size()) {
		if (_a.a[ptr_1].k < _b.a[ptr_2].k) {
			res.a.pb(_b.a[ptr_2].k);
			ptr_2++;
		} else {
			res.a.pb(_a.a[ptr_2].k);			
			ptr_1++;
		}	
	}
	while(ptr_1 < _a.a.size()) {
		res.a.pb(_a.a[ptr_1]);
		ptr_1 ++;		
	}
	while(ptr_2 < _b.a.size()) {
		res.a.pb(_b.a[ptr_2]);
		ptr_2 ++;				
	}
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v].Sal(a[tl]);
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = Merge(t[v*2], t[v*2+1]);
}

Dones_korpus Go(int v, int tl, int tr, int l, int r) {
	if (tr < l || r < tl) {
        return siziq(0, 0);
    }
	if (l <= tl && tr <= r) {
        return t[v];
    } 	
	int tm = (tl + tr) / 2;
    return Merge(Go(v * 2, tl, tm, l, r), Go(v * 2 + 1, tm + 1, tr, l, r));
}


int main(){
    int n = readInt(), q = readInt();
    for (int i = 1; i <= n; i++) {
		int b = readInt(), k = readInt();
		a[i] = line(k, b);				    		
    }
    build(1, 1, n);
	return 0;
}
