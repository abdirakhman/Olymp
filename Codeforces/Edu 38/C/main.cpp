#include<bits/stdc++.h>

#define ll long long
#define Add_Speed ios_base::sync_with_stdio(0);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define sz size()
#define s second
#define all(s) s.begin(), s.end()
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define inf INT_MAX
#define int ll
                                                                                                                                            
using namespace std;

const int maxn = (int)2e5 + 100;
const ll maxM = (ll)1e18 + 100;
const int mod = (int)1e9 + 7;
const int maxlog = (int)20;
const int P = mod;             

int f(int n, int m){
    return n * n - (n / m) * (n / m);
}           
int get(int n, int x){
    int l = 1, r = n, res = -1;
    while(l <= r){
        int mid = (l + r) » 1;
        if(f(n, mid) <= x){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return res;
}
main () {
    int t;
    cin » t;
    while(t--){
        int x;
        cin » x;
        int N = -1, M = -1;
        for(int i = 1; i <= 100000; i++){
            int n = i, m = get(n, x);
            if(m == -1) continue;
            if(f(n, m) == x){
                N = n; M = m;
                break;
            }
        }                   
        if(N == -1 || M == -1 || f(N, M) != x) cout « "-1\n";
        else cout « N « " " « M « endl;
    }
}