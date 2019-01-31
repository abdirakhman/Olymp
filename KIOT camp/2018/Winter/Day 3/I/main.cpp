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

/*
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif
*/

const long long MOD = 1e9 + 7;
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


string s;
int k;
int n;
int ans = 0;

bool dp[111][2][111][222];
int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    cin >> s;
    n = s.size();
    s = '#' + s;
    k = readInt();
	///go(0, 1, 0, 0);
	///cout << ans;
	///dp[i][dir][k][x] = true false
	dp[0][0][0][100] = 1;
	for (int i = 0; i < n; i++) {
		for (int juris = 0; juris <= k; juris++) {
			for (int dir = 0; dir <= 1; dir++) {
				for (int pos = 0; pos <= 200; pos++) {
					if (!dp[i][dir][juris][pos]) {
						continue;
					}

					if (s[i + 1] == 'T') {
						///rev
						dp[i + 1][dir ^ 1][juris][pos] |= dp[i][dir][juris][pos];
						dp[i + 1][dir][juris + 1][pos + (dir ? +1 : -1)] |= dp[i][dir][juris][pos];
					} else  {
						///front
						dp[i + 1][dir ^ 1][juris + 1][pos] |= dp[i][dir][juris][pos];
						dp[i + 1][dir][juris][pos + (dir ? +1 : -1)] |= dp[i][dir][juris][pos];
					}
				}
			} 
		}
	}
	for (int juris = 0; juris <= k; juris++) {
		if ((k - juris) % 2 == 0) {		
			for (int dir = 0; dir <= 1; dir++) {
				for (int pos = 0; pos <= 200; pos++) {
					if (dp[n][dir][juris][pos]) {
						ans = max(ans, abs(pos - 100));
					}
				}	
			}
		}
	}
	cout << ans;
	return 0;
}