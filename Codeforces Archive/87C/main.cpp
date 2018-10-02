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


const long long MOD = 1e9 + 7;
const long long MAXN = 1e5 + 1;
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

int sum(int l) {
	return (l * (l+1)) / 2;
}

int F(int sum){
	int q = sqrt(sum * 2);
	if(q * (q + 1) == sum * 2){
		return q;
	}
	if(q * (q - 1) == sum * 2){
		return q - 1;
	} 	
	if((q + 2) * (q + 1) == sum * 2){
		return q + 1;
	}
	return -1;
}

int mexx[MAXN][111];

int pref[MAXN];

int g[MAXN];

vector < pair < int, int > > v[MAXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    int mn = 1e9;
    g[1] = g[2] = 0;
    for(int r = 1; r <= n; r++){
    	for(int l = r - 1; l >= 1; l--){
    		if(sum(r) - sum(l - 1) <= n){
    			v[sum(r) - sum(l - 1)].pb({l, r});
    		} else{
    			break;
    		}
    	}
    }
    for (int i = 3; i <= n; i++) {
		for(auto to : v[i]){
			int l = to.F, r = to.S;
   			//deb(l);
   			//deb(r);
   			int x = 0;
   			x = pref[r] ^ pref[l - 1];
   			if (x <= 100)
   				mexx[i][x] = 1;
   			if (n == i && x == 0) {
   				mn = min(mn, r - l + 1);
   			}	
		}
		//cout << "\n=====================\n";
		for (int j = 0; j <= 100; j++) {
			if (!mexx[i][j]) {
				g[i] = j;
				break;
			}
		}
		pref[i] = pref[i-1]^g[i];			    
   	}
   	if (!g[n]) {
   		cout << "-1";	
   		return 0;
   	} else {
		cout << mn;			   		
   	}
    return 0;
}