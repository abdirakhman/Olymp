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
const long long MXN = MAXN;
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


ll t[MXN * 4], to[MXN * 4];
 
void Push(ll v){
    if(to[v] != -1){
        to[v * 2] = to[v * 2 + 1] = to[v], to[v] = -1;
    }
}
 
void Upd(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if(l > r)
        return;
    if(l == tl && r == tr){
        t[v] = (r - l + 1) * x;
        to[v] = x;
    }
    else{
        ll tm = (tl + tr) / 2;
        if(to[v] != -1){
            t[v * 2] = (tm - tl + 1) * to[v];
            t[v * 2 + 1] = (tr - tm) * to[v];
            Push(v);
        }
        Upd(v * 2, tl, tm, l, min(r, tm), x);
        Upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
 
ll Get_Sum(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r)
        return 0;
    if(l == tl && r == tr){
        return t[v];
    } else{
        ll tm = (tl + tr) / 2;
        if(to[v] != -1){
            t[v * 2] = (tm - tl + 1) * to[v];
            t[v * 2 + 1] = (tr - tm) * to[v];
            Push(v);
        }
        return Get_Sum(v * 2, tl, tm, l, min(r, tm))
                    + Get_Sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}


int mx[MAXN];
int nleft[MAXN];
int nright[MAXN];
int mn[MAXN];
int a[MAXN];


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), q = readInt();
    for (int i = 1; i <= q; i ++) {
    	mn[i] = MOD;
    	mx[i] = -1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    	if (a[i] == 0) {
    		cnt = 1;
    		continue;
    	}
    	mn[a[i]] = min(mn[a[i]], i);
    	mx[a[i]] = i;
    }
    if (mn[q] == MOD && !cnt) {
    	cout << "NO";
    	return 0;
    }
    bool z = 0;
    if (mn[1] == MOD) {
    	z = 1;	
    }
    for (int i = 1; i <= q; i ++) {
    	if (mn[i] == MOD) continue;
    	Upd(1, 1, n, mn[i], mx[i], i);	
    }
    vector <int> v;
    v.pb(228);
    for (int i = 1; i <= n; i++) {
		int x = Get_Sum(1, 1, n, i, i);
		if (x != a[i] && a[i] != 0) {
			cout << "NO";
			return 0;			
		} else {
			if (x == 0 && z) {
				x = q;
				z = 0;
			}
			v.pb(x);
		}     	
    }
    cout << "YES" << endl;
    nleft[0] = -1;
   	for (int i = 1; i <= n; i ++) {
   		if (v[i] != 0)
   			nleft[i] = v[i];
		else {
			nleft[i] = nleft[i - 1];
		}
   	}
   	nright[n + 1] = -1;
   	for (int i = n; i >= 1; i--) {
   		if (v[i] != 0) {
   			nright[i] = v[i];
   		} else {
   			nright[i] = nright[i + 1];
   		}
   	}
	int kek = q;	
    for (int i = 1; i <= n; i++) {
    	int x = v[i];
    	if (x == 0) {
    		if (nleft[i] != -1) {
    			cout << nleft[i] << ' ';
    		} else if (nright[i] != -1) {
    			cout << nright[i] << ' ';
    		} else {
    			cout << kek << ' ';
    		}
    	} else {
    		cout << x << ' ';
    	}
    }      
    return 0;
}