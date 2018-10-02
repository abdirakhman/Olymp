
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
 
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
 
const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
 
using namespace std;
int n, m;
int dp[10010][2];
int dplen[10010][2];
int last[20010];
int a[10100], b[10100];
int mx[2], cnt[2];
const int mod = 1000 * 1000 * 1000 + 9;
void add(int &v, int u){
	v+=u;
	if(v < 0) v += mod;
	if(v>=mod) v-=mod;
}
void solve(){
	scanf("%d", &n);
	vector<int> li;
	for(int i = 0; i < n ; i++){
		scanf("%d", a + i);
		li.pb(a[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", b + i);
		li.pb(b[i]);
	}
	sort(all(li));
	li.resize(unique(all(li)) - li.begin());
	for(int i = 0; i < n; i++)
		a[i] = lower_bound(all(li), a[i]) - li.begin();
	
	for(int i = 0; i < m; i++)
		b[i] = lower_bound(all(li), b[i]) - li.begin();
		
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 2; j++){
    	    dplen[i][j] = -inf;
    	    dp[i][j] = 0;
    	}
    }
    for(int ind = 0; ind < m; ind++){
    	int el = b[ind];
    	int mx1 = 0;
    	int cnt1 = 1;
    	int mx0 = -inf + 10;
    	int cnt0 = 0;
    	for(int i = 0; i < n; i++)
    		last[a[i]] = -1;
    	for(int i = 0; i < n; i++){
    		if (a[i] == el) {
    			dplen[i][0] = mx1 + 1;
    			dp[i][0] = cnt1;
    			dplen[i][1] = mx0 + 1;
    			dp[i][1] = cnt0;
    		} else if(a[i] < el) {
    			if(last[a[i]] == -1){
    				if(mx0 < dplen[i][0]){
    					mx0 = dplen[i][0];
    					cnt0 = dp[i][0];
    				}
    				else if(mx0 == dplen[i][0]){
    					mx0 = dplen[i][0];
    					add(cnt0, dp[i][0]);
    				}
    			}
    			else {
    				if(mx0 < dplen[i][0]){
    					mx0 = dplen[i][0];
    					cnt0 = dp[i][0];
    				}
    				else if(mx0 == dplen[i][0]){
    					mx0 = dplen[i][0];
    					add(cnt0, dp[i][0]);
    					if(dplen[last[a[i]]][0] == dplen[i][0]){
	    					add(cnt0, -dp[last[a[i]]][0]);
    					}
    				}
    			}
    		}else if(a[i] > el){
    			if(last[a[i]] == -1){
    				if(mx1 < dplen[i][1]){
    					mx1 = dplen[i][1];
    					cnt1 = dp[i][1];
    				}
    				else if(mx1 == dplen[i][1]){
    					mx1 = dplen[i][1];
    					add(cnt1, dp[i][1]);
    				}
    			}
    			else{
    				if(mx1 < dplen[i][1]){
    					mx1 = dplen[i][1];
    					cnt1 = dp[i][1];
    				}
    				else if(mx1 == dplen[i][1]){
    					mx1 = dplen[i][1];
    					add(cnt1, dp[i][1]);
    					if(dplen[last[a[i]]][1] == dplen[i][1]){
	    					add(cnt1, -dp[last[a[i]]][1]);
    					}
    				}
    			}
    		}
    		last[a[i]] = i;
    	}
    }
    int len = 0;
    int ans = 0;
    ll ccc = 0;
    for(int i = 0; i < n;i++){
    	last[a[i]] = -1;
    	len = max(dplen[i][0], len);
    }
    for(int i = n-1; i >= 0; i--){
    	if(last[a[i]] != -1) continue;
    	last[a[i]] = i;
    	if(dplen[i][0] == len) 
    	{
    		add(ans, dp[i][0]);
    	}
    }
    //if(len == 0) ans = 1;
    printf("%d %d\n", len, ans);

}
int main () {
    
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
    solve();
 
    return 0;
}
 

 
