/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

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

int a[MAXN];

int k[MAXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (i == n || i == 1) {
				if (j == 1 || j == m) {
					k[(i-1)*n+j] = 1;
				} else {
					k[(i-1)*n+j] = 2;
				}    		
    		}
    		else if (j == 1 || j == m) {
				k[(i-1)*n+j] = 2;    			
    		} else {
				k[(i-1)*n+j] = 4;    			
    		}
    		a[(i-1)*n+j] = readInt();
    	}       
    }
    int mx1 = 0, mx2 = 0;
	int id_mx1 = 0, id_mx2 = 0;
    int mn1 = 1e9, mn2 = 1e9;
    int id_mn1 = 0, id_mn2 = 0;
	int cur = 0;
	for (int i = 1; i <= n*m; i++) {
		cur += a[i] * k[i];		
		if (i % m == 0) {
			///TODO
			if (cur > mx1) {
				mx2 = mx1;
				id_mx2 = id_mx1;
				mx1 = cur;
				id_mx1 = i / m;
			} else if (cur > mx2) {
				mx2 = cur;
				id_mx2 = i / m;
			}

			if (cur < mn1) {
				mn2 = mn1;
				id_mn2 = id_mn1;
				mn1 = cur;
				id_mn1 = i / m;
			} else if (cur < mn2) {
				mn2 = cur;
				id_mn2 = i / m;
			}
			cur = 0;
		}
	}	
	if (id_mx1 == id_mn1) {
		
	} else {
		
	}
    return 0;
}