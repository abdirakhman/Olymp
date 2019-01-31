
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

const long long MOD = 1e9 + 7;
const long long MAXN = 505;

ll a[MAXN][MAXN];

ll n, m;

const ll INF = 1e18;

ll b[MAXN];
ll c[MAXN];

int main() {
  #ifdef IZI_KATKA
  assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        for (int i = 2; i < m; i++) {
            if (a[1][i] - a[1][i - 1] != a[1][i + 1] - a[1][i] || a[1][i + 1] - a[1][i] == 0 || a[1][i] - a[1][i - 1] == 0) {
                cout << "false";
                return 0;
            }
        }
        if (m >= 2) {
            if (a[1][2] - a[1][1] == 0) {
                cout << "false";
                return 0;
            }
            ll tmp = __gcd(a[1][1], a[1][2]);
            for (int i = 2; i <= m; i++) {
                if (a[1][i] % tmp != 0 || a[1][i] / tmp != a[1][i - 1] / tmp + 1) {
                    cout << "false";
                    return 0;
                }
            }
        }
        cout << "true";
        return 0;
    }
    if (m == 1) {
        for (int i = 2; i < n; i++) {
            if (a[i][1] - a[i - 1][1] != a[i + 1][1] - a[i][1] || a[i][1] - a[i - 1][1] == 0 || a[i + 1][1] - a[i][1] == 0) {
                cout << "false";
                return 0;
            }
        }
        if (n >= 2) {
            if (a[2][1] - a[1][1] == 0) {
                cout << "false";
                return 0;
            }
            if (a[1][1] % (a[2][1] - a[1][1]) != 0) {
                cout << "false";
                return 0;
            }
        }
        cout << "true";
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        b[i] = a[2][i] - a[1][i];
        if (b[i] == 0) {
            cout << "false";
            return 0;
        }
    }
    for (int i = 2; i <= m; i++) {
        if (b[i] != b[i - 1] + 1) {
            cout << "false";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i] = a[i][2] - a[i][1];
        if (c[i] == 0) {
            cout << "false";
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (c[i] != c[i - 1] + 1) {
            cout << "false";
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i][j] - a[i - 1][j] != b[j]) {
                cout << "false";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (a[i][j] - a[i][j - 1] != c[i]) {
                cout << "false";
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] % b[j] != 0) {
                cout << "false";
                return 0;
            }
        }
    }
    cout << "true";
    return 0;
}
