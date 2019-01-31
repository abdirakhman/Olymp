#include "railroad.h"
#include <algorithm>

using namespace std;

const long long INF = 1e15;


const long long N = 17;

long long dp[(1 << N)][N];

long long S[N];
long long T[N];

long long get(int x, int y) {
	if (T[x] > S[y]) {
		return T[x] - S[y];
	} else {
		return 0;
	}
}

long long plan_roller_coaster(std::vector<int> s, std::vector<int> t) {
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
    	S[i] = s[i];
    	T[i] = t[i];
    }
    for (int mask = 0; mask < (1 << n); mask++) {
    	for (int i = 0; i < n; i++) {
    		dp[mask][i] = INF;
    	}
    }
    for (int i = 0; i < n; i++) {
    	dp[(1 << i)][i] = 0;	
    }
	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				for (int j = 0; j < n; j++) {
					if ((mask >> j) & 1) continue;
					dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + get(i, j));
				}
			}
		}
	}
	long long ans = INF;
	for (int i = 0; i < n; i++) {
		ans = min(ans, dp[(1 << n) - 1][i]);     
	}
    return ans;
}
     