#include "molecules.h"
#define pb push_back
#include <algorithm>

#define ll long long
using namespace std;

const ll MAXN = 2e5 + 77;

vector<pair <ll, ll>> W;

vector<int> find_subset(int L, int R, vector<int> w) {
	ll n = w.size();	
	for (int i = 0; i < n; i++) {
		W.pb({w[i], i});
	}
	sort(W.begin(), W.end());				
    
    int r = 0;
    ll sum = W[0].first;
	for (int l = 0; l < n; l++) {
		while (r + 1 < n && sum <= L) {
			r++;
			sum += W[r].first;			
		}
		while (L <= sum - W[l].first && sum - W[l].first <= R) {
			sum -= W[l].first;
			l++;
		}
		if (L <= sum && sum <= R) {
			vector <int> ans;
			for (int i = l; i <= r; i++) {
				ans.pb(W[i].second);
			}
			return ans;
		}
		sum -= W[l].first;
	}
    return vector<int>(0);
}
