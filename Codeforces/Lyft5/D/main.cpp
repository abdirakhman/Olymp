#include <bits/stdc++.h>
#define sanyes ios_base::sync_with_stdio(0), cout.tie(0); cin.tie(0);
#define llong long long
#define pb push_back
#define bpc __builtin_popcount
 
const llong mxn = 1e5 + 7;
const llong mod = 998244353;
const llong inf = 1e18 + 9;
 
using namespace std;
 
llong n;
llong a[mxn];
 
llong cnt[mxn];
llong sz = 1;
 
map < llong, llong > is;
 
llong used[mxn];
 
map < llong, int > was;
map < llong, int > is2;
 
llong m;
llong b[mxn];
 
llong C[mxn];
 
llong d[mxn];
 
llong GCD(llong a, llong b){
    while(a > 0 && b > 0){
        if(a > b) a %= b;
        else b %= a;
    }
    return a + b;
}
 
int main(){
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        if(was[b[i]] == 0){
            a[++n] = b[i];
            is2[b[i]] = n;
        }
        was[b[i]] ++;
        C[is2[b[i]]] = was[b[i]];
    }
    for(int i = 1; i <= n; i++){
        llong l = 2, r = 40000;
        while(r - l > 1){
            llong mid = (l + r) / 2;
            if(mid * mid * mid * mid <= a[i]) l = mid;
            else r = mid;
        }
        if(l * l * l * l == a[i]){
            if(is[l]){
                cnt[is[l]] += 4 * C[i];
                used[i] = 1;
                continue;
            }
            is[l] = sz;
            cnt[sz] += 4 * C[i];
            sz++;
            used[i] = 1;
        } else if(r * r * r * r == a[i]){
            if(is[r]){
                cnt[is[r]] += 4 * C[i];
                used[i] = 1;
                continue;
            }
            is[r] = sz;
            cnt[sz] += 4 * C[i];
            sz++;
            used[i] = 1;
        } else{
            l = 2, r = 130000;
            while(r - l > 1){
                llong mid = (l + r) / 2;
                if(mid * mid * mid <= a[i]) l = mid;
                else r = mid;
            } if(l * l * l == a[i]){
                if(is[l]){
                    cnt[is[l]] += 3 * C[i];
                    used[i] = 1;
                    continue;
                }
                is[l] = sz;
                cnt[sz] += 3 * C[i];
                sz++;
                used[i] = 1;
            } else if(r * r * r == a[i]){
                if(is[r]){
                    cnt[is[r]] += 3 * C[i];
                    used[i] = 1;
                    continue;
                }
                is[r] = sz;
                cnt[sz] += 3 * C[i];
                sz++;
                used[i] = 1;
            } else{
                l = 2, r = 1500000000;
                while(r - l > 1){
                    llong mid = (l + r) / 2;
                    if(mid * mid <= a[i]) l = mid;
                    else r = mid;
                } if(l * l == a[i]){
                    if(is[l]){
                        cnt[is[l]] += 2 * C[i];
                        used[i] = 1;
                        continue;
                    }
                    is[l] = sz;
                    cnt[sz] += 2 * C[i];
                    sz++;
                    used[i] = 1;
                } else if(r * r == a[i]){
                    if(is[r]){
                        cnt[is[r]] += 2 * C[i];
                        used[i] = 1;
                        continue;
                    }
                    is[r] = sz;
                    cnt[sz] += 2 * C[i];
                    sz++;
                    used[i] = 1;
                }
            }
        }
    }
 
    for(int i = 1; i <= n; i++){
        if(used[i]) continue;
        int ch = 0;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            llong c = GCD(a[i], a[j]);
            if(c != 1 && c != a[i]){
                if(is[c] == 0){
                    is[c] = sz;
                    cnt[sz] += C[i];
                    sz++;
                } else{
                    cnt[is[c]] += C[i];
                }
                if(is[a[i] / c] == 0){
                    is[a[i] / c] = sz;
                    cnt[sz] += C[i];
                    sz ++;
                } else{
                    cnt[is[a[i] / c]] += C[i];
                }
                ch = 1;
                break;
            }
        }
        if(ch == 0){
            cnt[sz] += C[i];
            cnt[++sz] += C[i];
            sz++;
        }
    }
    llong ans = 1;
    for(int i = 1; i <= sz; i++){
        ans = ans * (cnt[i] + 1) % mod;
    }
    cout << ans;
    return 0;
}
