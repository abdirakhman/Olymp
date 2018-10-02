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
const long long MAXN = 2e5+ 1;
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
int nxt[MAXN];

int dp[MAXN][222];
int pos[MAXN][222];

int kelesi[MAXN][222];

int K = 450;

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    //int n = readInt(), t = readInt ();
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++) {
    	//a[i] = readInt();
    	scanf("%d", &a[i]);
    }
    nxt[n + 1] = n + 1;    
    for (int i = n; i >= 1; i--) {
    	if (a[i]) {
			nxt[i] = i;    		
    	}
    	else {
    		nxt[i] = nxt[i + 1];
    	}
    }
    for (int i = n; i >= 1; i--) {  //-2^31..2^31-1
    	for (int k = 1; k <= 50; k++) {
			if (a[i]) {
				if ((nxt[i] + k) / K != (i) / K) {
					dp[i][k] = 1;				
					kelesi[i][k] = nxt[i] + k; 
				}
				else {
					dp[i][k] = dp[nxt[i] + k][k] + 1;
					kelesi[i][k] = kelesi[nxt[i] + k][k];
				}       	
			} else {
				if ((nxt[i])/K != (i) / K) {
					dp[i][k] = 0;
					kelesi[i][k] = nxt[i];
				} else {
					dp[i][k] = dp[nxt[i]][k];
					kelesi[i][k] = kelesi[nxt[i]][k];
				}
			}    		
    	}
    }
    //int q = readInt();
    int q;
    scanf("%d", &q);
    int res = 0;
    while(q--) {
    	//int A = readInt(), B = readInt(), C = readInt();
    	int A, B, C;
    	scanf("%d%d%d", &A, &B, &C);
    	int l = (A ^ (t * res)) % n;
    	int r = (B ^ (t * res)) % n;
    	int k = ((C ^ (t * res)) % n) + 1;
    	if (l > r) {
    		swap(l, r);
    	}
    	l++;
    	r++;
    	int ans = 0;
    	if (r - l + 1 <= K || 50 < k) {
    		while (l <= r) {
    			if (a[l]) {
    				l += k;
    				ans ++;
    			} else {
    				l = nxt[l];
    			}
    		}
    	} else {
    		while(l <= r && l / K != r / K) {
    			int klsi = l;
    			klsi = kelesi[klsi][k];
    			ans += dp[klsi][k];
    		}
    		while(l <= r) {
    			if (a[l]) {
    				l += k;
    				ans ++;
    			} else {
    				l = nxt[l];
    			}
    		}
    	}
    	//cout << ans << endl;
    	printf("%d\n", ans);
    	res = ans;
    }
    return 0;
}
