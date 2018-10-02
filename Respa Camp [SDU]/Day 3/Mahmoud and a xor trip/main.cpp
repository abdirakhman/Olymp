/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
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

vector <int> g[MAXN];
int used[MAXN];
int sz[MAXN];
string s;
int k;
int ans;  
int a[]


int centroid(int v, int par, int m) {
	for (int i : g[v]) {
		if (!used[i] && i != par && sz[i] > (m/2)) {
			return centroid(i, v, m);
		}		
	}
	return v;
}

int CalcSZ(int v, int par) {
	sz[v] = 1;
	for (int i : g[v]) {
		if (i != par && !used[i]) {
			sz[v] += CalcSZ(i, v);
		}
	}
	return sz[v];
}


void Find(int v, int par, int dist) {
	
	for (int i = 0; i <= 20; i++) {
		if ((dist >> i) & 1) {
			ans += cnt[i][0] * (1 << i);
		} else {
			ans += cnt[i][1] * (1 << i);
        }                
	}	
	for (int i : g[v]) {
		if (!used[i] && i != par) {
			Find(i, v,  dist);
		}
	}
}

void Fill(int v, int par, int dist) {
    dist ^= a[v];
    for (int i = 0; i <= 20; i++) {
		if ((dist >> i) & 1) {
			cnt[i][1]++;
		} else {
			cnt[i][0]++;
		}
	}
	
	for (int i : g[v]) {
		if (!used[i] && i != par) {
			Fill(i, v,  dist);
		}
	}
}


void find_centroid(int v, int par = 0) {
	int m = CalcSZ(v, v);
	int C = centroid(v, v, m);
	used[C] = 1;
	for (int i = 0; i <= 20; i++) {
		if ((a[C] >> i) & 1) {
			cnt[i][1]++;
		} else {
			cnt[i][0]++;
		}
	}
	for (int i : g[C]) {
		if (!used[i]) {
			Find(i, C, 0);
			Fill(i, C, a[C]);
		}
	}
	for (int i = 0; i <= 20; i++) {
		cnt[i][1] = cnt[i][0] = 0;	
	}
	for (int i : g[C]) {
		if (!used[i]) {
			find_centroid(i, C);
		}
	}
}




int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }       
    for (int i = 1; i < n; i++) {
    	int u = readInt(), v = readInt();
		g[u].pb(v);
		g[v].pb(u);
    }
	cin >> s; 
    find_centroid(1);
	cout << ans;
    return 0;
}