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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define pb push_back

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


char a[55][55];


int used_r[55];
int used_c[55];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
    	for (int j= 1; j <= m; j++) {
    		cin >> a[i][j];
    	}
    }
    for (int i = 1; i <= n; i++) {
    	if (used_r[i]) continue;
    	for (int j = 1; j <= n; j++) {
    		if (used_c[j]) continue;
    		if (a[i][j] == '#') {
    			used_r[i]++;
    		    used_c[j]++;
    		    if (i+1 <= n)
				for (int k = i + 1; k <= n; k++) {
					if (a[k][j] == '#') {
					    used_r[k] ++;
						for (int l = 1; l <= m; l++) {
							if (l == j) continue;
							if (a[k][l] =='#' && a[i][l] != '#') {
								cout << "No";
								return 0;
							}
						}
					}
				}
				if (j+1<=m)
				for (int k = j+1; k <= m; k++) {
					if (a[i][k] == '#') {
						used_c[k]++;						
						for (int l = 1; l <= n; l++) {
							if (l == i) continue;
							if (a[l][k] =='#' && a[l][j] != '#')  {
								cout << "No";
								return 0;
							}
						}
					}
				} 
    		}
    	}
    }
    for (int i = 1; i <= n; i++) {
    	if (used_r[i] > 1) {
    		cout << "No";
    		return 0;
    	}
    }
    for (int i = 1; i <= m; i++) {
    	if (used_c[i] > 1) {
    		cout << "No";
    		return 0;
    	}
    }
    cout << "Yes";
    return 0;
}