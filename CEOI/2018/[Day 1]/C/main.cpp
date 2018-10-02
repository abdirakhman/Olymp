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


vector <int> v[2000];

int a[MAXN];

int n, l;

int calc(int x, int y) {
	int ans = 0;
	for (int i = 1; i <= l; i++) {
		ans += (a[x + i - 1] != a[y + i - 1]);
	}
	return ans;
}

int dp[2222][2222];
int cnt[2222];
int dist[2222][2222];

//vector <pair <int, int> > Q;

void go(int pos) {
	int tmp = calc(pos, 1);
    //cout << 1 << ' ' << pos << ' ' << tmp << endl;
	//g[1][pos] = tmp;
	//g[pos][1] = tmp;
	pos += 1;
	//cnt[tmp]++;
	dist[pos][j] = tmp;
	for (int j = 2; j + l - 1 <= n && pos + l - 1 <= n; j++, pos++) {
		tmp += ((a[j + l - 1] != a[pos + l - 1]));
		tmp -= ((a[pos - 1] != a[j - 1]));		
		//cout << pos << ' ' << j << ' ' << tmp << endl;;
		//cnt[tmp]++;	
		dist[pos][j] = tmp;
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), l = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    	//cout <<  a[i] <<  ' ';
    }
    //cout << endl;
	for (int i = 1; i <= n - l + 1; i++) {
		memset(cnt, 0, sizeof(cnt));
		go(i);
		//cout << endl;
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {			
			dp[i][g[i][j]]++;
			dp[j][g[i][j]]++;		
	    	assert(g[i][j] == g[j][i]);
		}
	}*/
	//cout << endl;
	//for (int i = 1; i <= n; i++) {
//		for (int k = 0; k <= l; k++) {
//			cout << i << ' ' << k << ' '<<dp[i][k] << endl; 		
//		}
//	}
	int q = readInt();

	
    return 0;
}