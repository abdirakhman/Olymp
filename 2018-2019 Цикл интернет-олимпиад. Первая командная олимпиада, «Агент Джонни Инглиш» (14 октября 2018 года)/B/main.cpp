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
const long long MAXN = 3005;
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

ll pref[MAXN][MAXN];

ll get(ll x1, ll y1, ll x2, ll y2) {
    return pref[x2][y2] + pref[x1][y1] - pref[x2][y1] - pref[x1][y2];
}

ll n, m;

bool check(ll x, ll y) {
    for (int i = 1; i * x <= n; i++) {
        for (int j = 1; j * y <= m; j++) {
            ll res = get(i * x - x, j * y - y, i * x, j * y);
            if (res > 0 && res < x * y) return 0;
        }
    }
    return 1;
}

char a[MAXN][MAXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ll toadd = 0;
            char z;
            cin >> z;
            a[i][j] = z;
            if (z == 'X') toadd++;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + toadd;
        }
    }
    if (pref[n][m] == n * m) {
        cout << "1 1" << endl;
        cout << "X";
        return 0;
    }
    if (pref[n][m] == 0) {
        cout << "1 1" << endl;
        cout << ".";
        return 0;
    }
    ll mx = -1000;
    ll my = -1000;
    ll mn = MAXN * MAXN;
    for (int i = n; i >= 1; i--) {
        if (n % i != 0) continue;
        for (int j = m; j >= 1; j--) {
            if (m % j != 0) continue;
            if (n * m / (i * j) > mn) break;
            if (check(i, j)) {
                mn = n * m / (i * j);
                mx = i;
                my = j;
            }
        }
    }
    cout << n / mx << " " << m / my << endl;
    for (int i = 1; i * mx <= n; i++) {
        for (int j = 1; j * my <= m; j++) {
            cout << a[i * mx][j * my];
        } cout << endl;
    }
    return 0;
}
