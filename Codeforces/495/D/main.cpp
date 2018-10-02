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

int a[MAXN];
int cnt[MAXN];

void del_even(int sz) {
	int res = 1;
	for (int i = 1; i <= sz; i++) {
		cnt[i] -= res;
		if (i < sz / 2)  {
			res++;
		} else if (i == sz / 2) {
			res += 0;
		} else {
			res--;
		}
	}	
}

void del_odd(int sz) {
	int res = 1;
	for (int i = 1; i <= sz; i++) {
		cnt[i] -= res;
		if (i >= (sz+1) / 2) {
			res--;					
		} else {
			res ++;
		}						
	}				
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int t = readInt();
	int MX = 0;
    for (int i = 1; i <= t; i++) {
    	int x = readInt();
    	cnt[x]++;
		MX = max(MX, x);
    }
    int mx1 = MX;  
    if (cnt[1] == 3) {
    	int M = 0;
    	bool ok = 1;
    	for (int i = 0; i <= MX; i ++) {
    		if (cnt[i] == 0) {
    			cout << -1;
    			return 0;
    		}
    		if (ok && cnt[i] == 2 * i + 1) {
    			M = i;
    		} else {
    			ok = 0;
    		}
    	}
		for (int i = 1; i <= M; i++) {
			cnt[i] --;
		}        
		M++;
		int kol_diag = M + (mx1-1) - 1;
		if (kol_diag % 2 == 0) {
			del_even(kol_diag);
			int mx2 = 0;
			for (int i = 1; i <= MX; i++) {
				if (cnt[i] < 0) {
					cout << -1;
					return 0;
				}
				if (cnt[i] > 0) {
					mx2 = max(mx2, i);
				}				
			}
			int kol_diag1 = (mx2-1) + M - 1;
			if (kol_diag1 & 1) {
				del_odd(kol_diag1);	
			} else {
				del_even(kol_diag1);				
			} 
			for (int i = 1; i <= MX; i++) {
				if (cnt[i] != 0) {
					cout << -1;
					return 0;				
				}				
			}
			cout << (mx1-1) + (mx2-1) + 1 << ' ' << M << endl;
			cout << mx1 << ' ' << M << endl;
			return 0;	
		} else {
			del_odd(kol_diag);
			int mx2 = 0;
			for (int i = 1; i <= MX; i++) {
				if (cnt[i] < 0) {
					cout << -1;
					return 0;
				}
				if (cnt[i] > 0) {
					mx2 = max(mx2, i);
				}				
			}
			int kol_diag1 = (mx2-1) + M - 1;
			if (kol_diag1 & 1) {
				del_odd(kol_diag1);	
			} else {
				del_even(kol_diag1);				
			} 
			for (int i = 1; i <= MX; i++) {
				if (cnt[i] != 0) {
					cout << -1;
					return 0;				
				}				
			}
			cout << (mx1-1) + (mx2-1) + 1 << ' ' << M << endl;
			cout << mx1 << ' ' << M << endl;
			return 0;
		}
    } else {
    	if (cnt[MX] == 4) {
    		//SQuare
    		cout << MX + 1 << ' ' << MX + 1 << endl;
    		cout << 
    	} else {
    		
    	} 
    }
    return 0;
}