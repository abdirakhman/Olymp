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

int a[MAXN];
int b[MAXN];
vector <int> t[MAXN * 4], g[MAXN];
vector <int> bitti;

vector <int> Merge(vector <int> & a, vector <int> & b) {
    bitti.clear();
    int temp1, temp2;
    int left1, left2;
    left1 = left2 = 0;
    while(left1 < a.size() || left2 < b.size()) {
        temp1= temp2 = 1e9;
        if (left1 < a.size()) temp1 = a[left1];
        if (left2 < b.size()) temp2 = b[left2];
        if (temp1 < temp2) {
            bitti.push_back(temp1);
            left1++;
        } else {
            bitti.push_back(temp2);
            left2++;
        }
    }
    return bitti;
}


void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].push_back(b[tr]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
	t[v] = Merge(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) {
        return 0;
    }
    if (r == tr && tl == l) {
        int L = -1, R = t[v].size();
        while(R - L > 1) {
            int M = (R + L) / 2;
            if (t[v][M] < x) {
                L = M;
            } else {
                R = M;
            }
        }
        return t[v].size() - 1 - L;
    }
    int tm = (tl + tr) / 2;
	return get(v * 2, tl, tm, l, min(r, tm), x) +
					get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), k = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    	g[a[i]].push_back(i);
        if (g[a[i]].size() > k) {
            b[i] = g[a[i]][g[a[i]].size() - k - 1];
        }    
    }
    build(1, 1, n);
    int last = 0;
    int q;
    cin >> q;
    int l, r;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        l = ((x + last) % n) + 1;
        r = ((y + last) % n) + 1;
        if (l > r) swap(l, r);
        last = (r - l + 1) - get(1, 1, n, l, r, l);
        cout << last << endl;
    }

    return 0;
}