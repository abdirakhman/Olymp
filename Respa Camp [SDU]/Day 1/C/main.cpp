/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define last v1.size()-1
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

int a[MAXN], n;

void TrY(int x, int y) {
	vector <int> v1, v2;
	if (x + 1 == y) {
		v1.pb(a[x]);
		v1.pb(a[y]);		
	}
	else {
		v1.pb(a[x]);
		v1.pb(a[y]);	
	}
	for (int i = y + 1; i <= n; i++) {
		if (v1[last] - v1[last - 1] == a[i] - v1[last]) {
			v1.pb(a[i]);
		}
	}
	v1.pop_back();
	int L = 0;
	for (int i = 1; i <= n; i++) {
		if (L < v1.size() && v1[L] == a[i]) L++;
		else v2.pb(a[i]);
	}
	for (int i = 2; i < v2.size(); i++)
		if (v2[i] - v2[i - 1] != v2[i - 1] - v2[i - 2]) {
			return;
		}	
	for (int i : v1) {
		cout << i << ' ';
	}
	cout << "\n";
	for (int i : v2) {
		cout << i << ' ' ;
	}
	exit(0);
}

void go(int x, int y) {
	vector <int> v1, v2;
	if (x + 1 == y) {
	    if (x == 2) {
	    	v2.pb(a[1]);
	    }
		v1.pb(a[x]);
		v1.pb(a[y]);		
	}
	else {
		v1.pb(a[x]);
		v1.pb(a[y]);
		v2.pb(a[x+1]);	
	}

	for (int i = y + 1; i <= n; i++) {
		if (v1[last] - v1[last - 1] == a[i] - v1[last]) {
			v1.pb(a[i]);
		}else {
			v2.pb(a[i]);
			if (v2.size() > 2) {
				if (v2[v2.size() - 1] - v2[v2.size() - 2] != v2[v2.size() - 2] - v2[v2.size() - 3]) {
					TrY(x, y);
		        	return;
				}				
			}
		}
	}
	for (int i : v1) {
		cout << i << ' ';
	}
	cout << "\n";
	for (int i : v2) {
		cout << i << ' ' ;
	}
	exit(0);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
	n = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    if (n <= 2) {
    	cout << a[1] << '\n' << a[2];
    	return 0;
    }
	go(1, 3);
    go(1, 2);
    go(2, 3);

    cout << "No solution";
    return 0;
}