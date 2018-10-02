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


const int N = 5005;

int usti[N];
int asti[N];
int onni[N];
int soli[N];

int USTI[N];
int ASTI[N];
int ONNI[N];
int SOLI[N];

char letter[N];
int num[5001][5001];
char a[5001][5001];


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int K = 0;
    int n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
        	if (a[i][j] != '.') {
        		K++;
        		num[i][j] = K;
        		letter[K] = a[i][j];
        		
        	}
    	}
    }
    int tmp;
    for (int i = 1; i <= n; i++) {
    	tmp = -1;
    	for (int j = 1; j <= m; j++) {
    		if (a[i][j] != '.') {
    			soli[num[i][j]] = tmp, tmp = num[i][j];
    		}
    	}
    	tmp = -1;
    	for (int j = m; j >= 1; j--) {
    		if (a[i][j] != '.') {
    			onni[num[i][j]] = tmp, tmp = num[i][j];
    		}
    	} 
    }
    for (int j = 1; j <= m; j++) {
		tmp = -1;
		for (int i = 1; i <= n; i++) { 
			if (a[i][j] != '.') {
				usti[num[i][j]] = tmp, tmp = num[i][j];
			}
		}
		tmp = -1;
		for (int i = n; i >= 1; i--) {
			if (a[i][j] != '.') {
				asti[num[i][j]] = tmp, tmp = num[i][j];
			}
		}
	}
	int mx = 0;
	int res = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			SOLI[j] = soli[j], ONNI[j] = onni[j], USTI[j] = usti[j], ASTI[j] = asti[j];
		}
		int cnt = 0;
		for (int z = i, j; z != -1; z = j) {
			if (letter[z] == 'L') j = SOLI[z];
			if (letter[z] == 'R') j = ONNI[z];
			if (letter[z] == 'U') j = USTI[z];
			if (letter[z] == 'D') j = ASTI[z];
			if (ONNI[z] != -1) SOLI[ONNI[z]] = SOLI[z];
			if (SOLI[z] != -1) ONNI[SOLI[z]] = ONNI[z];
			if (USTI[z] != -1) ASTI[USTI[z]] = ASTI[z];
			if (ASTI[z] != -1) USTI[ASTI[z]] = USTI[z];
			cnt++;
		}
		if (cnt > mx) mx = cnt, res = 0;
		if (cnt == mx) res++;
	}
	cout << mx << ' ' << res;
    return 0;
}