/*
Idea:
is_treasure[x][y] shows is treasure
can be known by using exclusion inclusion principle
*/
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
#include "treasure.h"

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


int response[111][111];
int is_treasure[111][111];

void findTreasure(int n) {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int N = n;
    int mid = (n / 2);
    for (int i = n; i >= 1; i--) {
    	for (int j = n; j >= 1; j--) {
    		if (i > mid && j > mid) {
				response[i][j] = countTreasure(1, 1, i, j);    			
    		}
    		if (i <= mid && j > mid) {
    			response[i][j] = response[n][j] - countTreasure(i + 1, 1, n, j);
    		}
    		if (i > mid && j <= mid) {
				response[i][j] = response[i][n] - countTreasure(1, j + 1, i, n);
			}
			if (i <= mid && j <= mid) {
				response[i][j] = response[n][j] + response[i][n] - response[n][n] + countTreasure(i + 1, j + 1, n, n);
			}
    	}
    }
   	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(response[i][j] - response[i - 1][j] - response[i][j - 1] + response[i - 1][j - 1] == 1)
				Report(i, j);
		}
	}   
}