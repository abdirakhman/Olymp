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

#define int __int64_t

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

struct item {
	int key, prior;
	item * l, * r;
	int mn;
	item() { }
	item (int key) : key(key), prior(((rand() << 16) + rand())), l(NULL), r(NULL), mn(key) { }
};
typedef item * pitem;

int getmn(pitem t) {
	return t ? t -> mn : MOD;
}

void updmn(pitem t) {
	if (t) {
		t -> mn = min(t-> key, min(getmn(t -> l), getmn(t -> r)));	
	}
}

void split (pitem t, int key, pitem & l, pitem & r) {
	if (!t)
		l = r = NULL;
	else if (key < t->key)
		split (t->l, key, l, t->l),  r = t;
	else
		split (t->r, key, t->r, r),  l = t;
	updmn(t);
}

void insert (pitem & t, pitem it) {
	if (!t)
		t = it;
	else if (it->prior > t->prior)
		split (t, it->key, it->l, it->r),  t = it;
	else
		insert (it->key < t->key ? t->l : t->r, it);
	updmn(t);	
}

void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	updmn(t);
}

void erase (pitem & t, int key) {
	if (t->key == key)
		merge (t, t->l, t->r);
	else
		erase (key < t->key ? t->l : t->r, key);
	updmn(t);	
}

void output (pitem t) {
	if (!t)  return;
	output (t->l);
	cout << t->key << ' ';
	output (t->r);
}


int n;
int a[MAXN];
int p[5];
int L[MAXN];                                         	
int R[MAXN];

void solve1() {
    ///1 2 3
    ///-1 -1 2
    /// aleft < amid < aright
    int ans = MOD;
    pitem S = NULL;
    for (int i = 1; i <= n; i++) {
		pitem L1 = NULL, R1 = NULL;
		split(S, a[i] - 1, L1, R1);
		int tmp = getmn(L1);
		L[i] = tmp;
		merge(S, L1, R1);
		insert(S, new item (a[i]));
    } 
    S = NULL;
	for (int i = n; i >= 1; i--) {
		pitem L1 = NULL, R1 = NULL;
		split(S, a[i], L1, R1);
		int tmp = getmn(R1);
		R[i] = tmp;
		merge(S, L1, R1);
		insert(S, new item (a[i]));
	}
	for (int i = 1; i <= n; i++) {
		ans = min(ans, L[i] + R[i] + a[i]);	
	}
	cout << (ans >= MOD ? -1 : ans);
} 
void solve2() {
	/// 1 3 2
	/// -2 1 1
	/// amid > aright > aleft
	int ans = MOD;
	pitem S = NULL;
	pitem L1 = NULL, R1 = NULL;
	
	for (int i = 1; i <= n; i++) {
	    ///85-90
		split(S, a[i] - 1, L1, R1);
		L[i] = getmn(L1);
		merge(S, L1, R1);    	
		L1 = NULL, R1 = NULL;
    	insert(S, new item(a[i]));
    }
    S = NULL;
    
    for (int i = n; i >= 1; i--) {
    	split(S, L[i], L1, R1);
    	R[i] = getmn(R1);
    	if (R[i] >= a[i]) R[i] = MOD;
    	merge(S, L1, R1);
		L1 = NULL, R1 = NULL;
    	insert(S, new item(a[i]));
    }
    for (int i = 1; i <= n; i++) {
    	ans = min(ans, L[i] + R[i] + a[i]);
    }
    cout << (ans >= MOD ? -1 : ans);
}
void solve3() {
	///	2 1 3
	/// 1 -2 1
	/// aright > aleft > amid
	int ans = MOD;
	pitem S = NULL;
	for (int i = 1; i <= n; i++) {
		pitem L1 = NULL, R1 = NULL;
		split(S, a[i], L1, R1);
		L[i] = getmn(R1);
		merge(S, L1, R1);
		insert(S, new item (a[i]));
	}	
	S = NULL;
	for (int i = n; i >= 1; i--) {
		pitem L1 = NULL, R1 = NULL;
		split(S, L[i], L1, R1);
		R[i] = getmn(R1);
		merge(S, L1, R1);
		insert(S, new item(a[i]));
	}
	for (int i = 1; i <= n; i++) {
		ans = min(ans, a[i] + L[i] + R[i]);
	}
	cout << (ans >= MOD ? -1 : ans);
}
void solve4() {
	cout << 228;
}
void solve5() {
    cout << 228;
}
void solve6() {
 	cout << 228;
}

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    srand(time(0));
	n = readInt();
    if (n <= 2) {
    	cout << -1;
    	return 0;
    }
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    for (int i = 1; i <= 3; i++) {
    	p[i] = readInt();
    }    
	if (p[1] == 1 && p[2] == 2 && p[3] == 3) {
		solve1();
	} else if (p[1] == 1 && p[2] == 3 && p[3] == 2) {
		solve2();		
	} else if (p[1] == 2 && p[2] == 1 && p[3] == 3) {
		solve3();		        
	} else if (p[1] == 2 && p[2] == 3 && p[3] == 1) {
		solve4();
	} else if (p[1] == 3 && p[2] == 1 && p[3] == 2) {
		solve5();	
	} else if (p[1] == 3 && p[2] == 2 && p[3] == 1) {
		solve6();		
	} else {
		cout << -228;
	}
    return 0;
}