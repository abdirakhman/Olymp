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

int n, m;
char a[555][555];	

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

int get(int x, int y) {
	int L = 1;
	while(1) {
		L ++;
		if (x + L - 1 > n || y + L - 1 > m) {
			break;
		}
		for (int i = x; i < x + L - 1; i++) {
			if (a[i][y + L - 1] != 0) {
				return L - 1;
			}
		}
		for (int j = y; j < y + L - 1; j++) {
			if (a[x + L - 1][j] != 0) {
				return L - 1;
			}
		}
	}
	return L - 1;
}

bool can(char C, int x, int y) {
	for (int k = 0; k < 4; k++) {
		int next_i = x + dx[k], next_j = y + dy[k];
		if (next_i < 1 || next_i > n || next_j < 1 || next_j > m) continue;
		if (a[next_i][next_j] == C) return false;
	}
	return true;
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] != 0) continue;
			char tmp = 'A';
			while (1) {
				bool ok = 0;
				for (int k = 0; k < 4; k++) {
					int next_i = i + dx[k], next_j = j + dy[k];
					if (next_i < 1 || next_i > n || next_j < 1 || next_j > m) continue;
					if (a[next_i][next_j] == tmp) {
						ok = 1;
						tmp++;
						break;
					}	
				}
				if (!ok) break;
			}
			if (tmp == 'A') {
				int sz = get(i, j);
                for (int J = j + 1; J < j + sz; J++) {
                    if (!can(tmp, i, J)) {
                        sz = J - j;
                        break;
                    }
                }
                for (int I = i; I < i + sz; I++)
                    for (int J = j; J < j + sz; J++)
                        a[I][J] = tmp;
			} else if (tmp == 'B') {
				int sz = get(i, j);
				for (int J = j + 1; J < j + sz; J++) {
					if (can('A', i, J)) {
						sz = J - j;
						break;
					}						
				}
				for (int I = i; I < i + sz; I++) {
					for (int J = j; J < j + sz; J++) {
						a[I][J] = tmp;    
					}
				}
			} else {
				a[i][j] = tmp;
			}
		}
    }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
    return 0;
}