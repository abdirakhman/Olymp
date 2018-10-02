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

inline void writeInt(long long x, char END) {
	if (x < 0)
		putchar('-'), x = -x;
	char s[65];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		putchar(s[n]);
	if (END)
		putchar(END);
}

vector <int> g[MAXN];
int n, m, J;
int tin[MAXN];
char a[101][101];
int used[MAXN];
int ans = 0;
int getID(int i, int j) {
	return (m * (i-1) + j);
}                 

int timer = 0;
void dfs(int i) {
	int id = i;
	used[id] = 1;
	tin[id] = timer++;
	if (used[g[id][0]] == 1) {
		ans += abs(tin[g[id][0]] - tin[id]) + 1;		
		
	} else if (!used[g[id][0]]) {
		dfs(g[id][0]);
	}
	used[id] = 2;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    n = readInt(), m = readInt(), J = readInt();
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];	
    		if (a[i][j] == 'S') {
    			g[getID(i, j)].pb(getID(i + 1, j));
    		} 
    		if (a[i][j] == 'E') {
    			g[getID(i, j)].pb(getID(i, j + 1));
    		}
    		if (a[i][j] == 'W') {
    			g[getID(i, j)].pb(getID(i, j - 1));
    		}
    		if (a[i][j] == 'N') {
    			g[getID(i, j)].pb(getID(i - 1, j));
    		} 
    	}                      
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (!used[getID(i, j)]) {
    			dfs(getID(i, j));
    		}
    	}
    }
    cout << ans;
    return 0;
}
