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

typedef long long ll;
using namespace std;

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;


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


int main() {
    ll n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        string s;
        cin >> s;
        ll a = 0;
        ll b = 0;
        ll c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i]) && islower(s[i])) a++;
            else if (isalpha(s[i]) && isupper(s[i])) b++;
            else c++;
        }
        if (a == 0 && b != 0 && c != 0) {
            for (int i = 0; i < s.size(); i++) {
                if (isalpha(s[i]) && isupper(s[i]) && b > 1) {
                    s[i] = 'a';
                    break;
                }
                if (isdigit(s[i]) && c > 1) {
                    s[i] = 'a';
                    break;
                }
            }
        } else if (a != 0 && b == 0 && c != 0) {
            for (int i = 0; i < s.size(); i++) {
                if (isalpha(s[i]) && islower(s[i]) && a > 1) {
                    s[i] = 'A';
                    break;
                }
                if (isdigit(s[i]) && c > 1) {
                    s[i] = 'A';
                    break;
                }
            }
        } else if (a != 0 && b != 0 && c == 0) {
            for (int i = 0; i < s.size(); i++) {
                if (isalpha(s[i]) && islower(s[i]) && a > 1) {
                    s[i] = '1';
                    break;
                }
                if (isalpha(s[i]) && isupper(s[i]) && b > 1) {
                    s[i] = '1';
                    break;
                }
            }
        } else if (a == 0 && b == 0) {
            s[0] = 'A';
            s[1] = 'a';
        } else if (a == 0 && c == 0) {
            s[0] = 'a';
            s[1] = '0';
        } else if (b == 0 && c == 0) {
            s[0] = 'A';
            s[1] = '0';
        }
        cout << s << endl;
    }
}