#include <bits/stdc++.h>

#define right(x) x << 1 | 1
#define left(x) x << 1
#define mp make_pair
#define pb push_back
#define pf push_front
#define sz(s) (ll)s.size()
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const ll mod = 1e9 + 7;
const ll INF = 1e12 + 1;
const ll N = 7e5;

ll n, m, k, res, a[N], ans[N], cnt[(int)1e6 + 1];
vector<pair<ll, pair<ll, ll>>>v;

inline void add(ll x) {
	if (cnt[x] == 2) {
		res --;
	} 
	cnt[x]++;
	if (cnt[x] == 2) {
		res++;
	}
}

inline void del(ll x) {
 	if (cnt[x] == 2) {
 		res--;
 	}
 	cnt[x] --;
 	if (cnt[x] == 2) {
 		res++;
 	}
}

inline bool cmp(pair<ll, pair<ll, ll>>a, pair<ll, pair<ll, ll>>b) {
 if(a.S.F / k == b.S.F / k) {
  return a.S.S < b.S.S;
 }
 return a.S.F / k < b.S.F / k;
}

main () {
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 cin >> n >> m;
 k = sqrt(n) + 1;
 for(ll i = 1; i <= n; ++i) {
  cin >> a[i];
 }
 for(ll i = 1; i <= m; ++i) {
  ll l, r; cin >> l >> r;
  v.pb(mp(i, mp(l, r)));
 }
 sort(all(v), &cmp);
 add(1);
 ll L = 1, R = 1;
 for(auto i : v) {
  ll l = i.S.F, r = i.S.S;
  while(L < l) {
   del(L++);
  }
  while(L > l) {
   add(--L);
  }
  while(R < r) {
   add(++R);
  }
  while(R > r) {
   del(R--);
  }
  ans[i.F] = res;
 }
 for(ll i = 1; i <= m; ++i) {
  cout << ans[i] << "\n";
 }
 return 0;
}