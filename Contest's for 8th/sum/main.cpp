#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define ull unsigned ll

#define f first
#define s second
#define pii pair < ll, ll >

#define pb push_back
#define mp make_pair

#define ios ios_base::sync_with_stdio(0)
#define pi 3.14159265358979323846264
#define y1 abacaba

using namespace std;

const int MXN = 1e6 + 1;
const int MAXN = 1e3 + 1;
const ll INF = 1e16;
const int MOD = 65000;
const int MAX = 1e2;
const double EPS = 1e-9;

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

ll n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        char q;
        cin >> q;
        if (q == '1') {
            ll l, r, x;
            scanf("%I64d%I64d%I64d", &l, &r, &x);
            Upd(1, 1, n, l, r, x);
        } else {
            ll l, r;
            scanf("%I64d%I64d", &l, &r);
            printf("%I64d\n", Get_Sum(1, 1, n, l, r));
        }
    }
    return 0;
}