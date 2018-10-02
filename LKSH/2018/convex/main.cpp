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
 
 
const long long MOD = 1e9 + 7;
const long double PI = acos(-1.0);
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
 
 
struct point {
    long double x, y;
};
 
bool cmp(point a, point b) {
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
 
bool eq(point a, point b) {
    return (a.x == b.x && a.y == b.y);
}
 
bool isCCW(point a, point b, point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}
 
void setConvexHull(vector <point> p, vector <point> &h) {
    sort(p.begin(), p.end(), cmp);
    p.erase(unique(p.begin(), p.end(), eq), p.end());
 
    vector <point> up, down;
    point head = p[0], tail = p.back();
 
    up.pb(head); down.pb(head);
 
    for (int i = 1; i < (int) p.size(); i++) {
        if (i == p.size() - 1 || !isCCW(tail, head, p[i])) {
            while ( (int) up.size() >= 2 && isCCW(up[up.size() - 2], up.back(), p[i]) )
                up.pop_back();
            up.pb(p[i]);
        }
        if (i == (int) p.size() - 1 || isCCW(tail, head, p[i])) {
            while ( (int) down.size() >= 2 && !isCCW(down[down.size() - 2], down.back(), p[i]) )
                down.pop_back();
            down.pb(p[i]);
        }
    }
 
    h.clear();
    for (int i = 0; i < (int) up.size(); i++)
        h.pb(up[i]);
    for (int i = (int) down.size() - 2; i > 0; i--)
        h.pb(down[i]);
}
 
long double getangle (point a, point b, point c)
{
   long double x1 = a.x - b.x, x2 = c.x - b.x;
   long double y1 = a.y - b.y, y2 = c.y - b.y;
   long double d1 = sqrt (x1 * x1 + y1 * y1);
   long double d2 = sqrt (x2 * x2 + y2 * y2);
   return acos ((x1 * x2 + y1 * y2) / (d1 * d2));
}
 
 
int main() {
	//assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output", "w", stdout));
    int n = readInt();
    vector <point> P;
    for (int i = 1; i <= n; i++) {
        point tmp;
        cin >> tmp.x >> tmp.y;
        P.pb(tmp);
    }
    vector <point> ans;
    setConvexHull(P, ans);
    long double res = MOD;
    if (ans.size() >= 3) {
        res = min(res, getangle(ans[1], ans[0], ans[ans.size() - 1]));
        res = min(res, getangle(ans[0], ans[ans.size() - 1], ans[ans.size() - 2]));
    }
    for (int i = 1; i < ans.size() - 1; i++) {
        res = min(res, getangle(ans[i - 1], ans[i], ans[i + 1]));
    }
    if (res == MOD) {
        cout << 0;
        return 0;
    }
    res *= 180.0;
    res /= PI;
    cout << fixed << setprecision(16) << res;
}
 