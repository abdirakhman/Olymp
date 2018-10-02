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

struct treap {
    ll cnt;
    ll x;
    ll y;
    treap *l, *r;
    treap(ll x): y(rand() << 16 + rand()), cnt(1), l(NULL), r(NULL), x(x) {}
};

typedef treap* ptreap;


ll getcnt(ptreap t) {
	return (t ? t -> cnt : 0);
}

void upd(ptreap &t) {
    if(t == NULL) return;
    t -> cnt = 1 + getcnt(t -> l) + getcnt(t -> r);
}

pair <ptreap, ptreap> split_imp(ptreap t, ll k) {
    if(t == NULL) return {NULL, NULL};
    if(getcnt(t -> l) + 1 <= k) {
        pair<ptreap, ptreap> tt = split_imp(t -> r, k - getcnt(t -> l) - 1);
        t -> r = tt.first;
        upd(t);
        return {t, tt.second};
    } else {
        pair<ptreap, ptreap> tt = split_imp(t -> l, k);
        t -> l = tt.second;
        upd(t);
        return {tt.first, t};
    }
}

pair <ptreap, ptreap> split(ptreap t, ll k) {
    if(t == NULL) return {NULL, NULL};
    if(t -> x > k) {
        pair<ptreap, ptreap> tt = split(t -> l, k);
        t -> l = tt.second;
        upd(t);
        return {tt.first, t};
    } else {
        pair<ptreap, ptreap> tt = split(t -> r, k);
        t -> r = tt.first;
        upd(t);
        return {t, tt.second};
    }
}

ptreap merge(ptreap a, ptreap b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a -> y > b -> y) {
        a -> r = merge(a -> r, b);
        upd(a);
        return a;
    } else {
        b -> l = merge(a, b -> l);
        upd(b);
        return b;
    }
}

void inorder(ptreap t) {
    if(t == NULL) return;
    inorder(t -> l);
    cout << t -> x << " ";
    inorder(t -> r);
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    
    return 0;
}