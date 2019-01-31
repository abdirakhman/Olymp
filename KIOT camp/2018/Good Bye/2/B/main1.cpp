#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int MAXN = 1e5 + 7;
#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

 
ll ret = 1e18;
priority_queue<pii, vector<pii>, greater<pii> > pq;
vector<pii> g[MAXN];
 
int n, m, k, a[10];
ll d[6][MAXN];
ll dp[6][6][MAXN];
 
void go(int s, int e){
	for(int i = 1; i <= n; i++){
		pq.push(pii(d[s][i] + d[e][i], i));
		dp[s][e][i] = d[s][i] + d[e][i];
	}
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		if(dp[s][e][t.second] < t.first) continue;
		for(auto &i : g[t.second]){
			if(dp[s][e][i.second] > dp[s][e][t.second] + i.first){
				dp[s][e][i.second] = dp[s][e][t.second] + i.first;
				pq.push(pii(dp[s][e][i.second], i.second));
			}
		}
	}
 
}
 
void dijkstra(int start, ll *d){

	d[start] = 0;
	pq.push(pii(0, start));
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		if(d[t.second] < t.first) continue;
		for(auto &i : g[t.second]){
			if(d[i.second] > d[t.second] + i.first){
				d[i.second] = d[t.second] + i.first;
				pq.push(pii(d[i.second], i.second));
			}
		}
	}
}
 



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

 
int main(){
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
   
	n = readInt(), k = readInt(), m = readInt();
	for(int i=1; i<=k; i++) a[i] = readInt();
	sort(a + 1, a + k + 1);
	k = unique(a + 1, a + k + 1) - a - 1;
	for(int i = 1; i <= m; i++){
		int v = readInt(), u = readInt(), c = readInt();
		g[v].pb({c, u});
		g[u].pb({c, v});
	}
	memset(d, 0x3f, sizeof(d));
	for(int i = 1; i <= k; i++){
		dijkstra(a[i], d[i]);
	}
	if(k == 1){
		cout << 0;
		return 0;
	}
	if(k == 2){
		cout << d[1][a[2]];
		return 0;
	}
	if(k == 3){
		for(int i = 1; i <= n; i++){
			ret = min(ret, d[1][i] + d[2][i] + d[3][i]);
		}
		cout << ret;
		return 0;
	}
	if(k == 4){
		for(int i = 1; i <= k; i++){
			for(int j = i + 1; j <= k; j++){
				go(i, j);
			}
		}
		int perm[4] = {1, 2, 3, 4};
		do{
			if(perm[0] < perm[1] && perm[2] < perm[3] && perm[0] < perm[2]){
				for(int i = 1; i <= n; i++){
					ret = min(ret, dp[perm[0]][perm[1]][i] + dp[perm[2]][perm[3]][i]);
				}
			}
		}while(next_permutation(perm, perm + 4));
		cout << ret;
		return 0;
	}
	if(k == 5){
		for(int i = 1; i <= k; i++){
			for(int j = i + 1; j <= k; j++){
				go(i, j);
			}
		}
		int perm[5] = {1, 2, 3, 4, 5};
		do{
			if(perm[0] < perm[1] && perm[2] < perm[3] && perm[0] < perm[2]){
				for(int i = 1; i <= n; i++){
					ret = min(ret, dp[perm[0]][perm[1]][i] + dp[perm[2]][perm[3]][i] + d[perm[4]][i]);
				}
			}
		}while(next_permutation(perm, perm + 5));
		cout << ret;
		return 0;
	}
}
