/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
#define pb push_back

const long long MOD = 1e9 + 7;
const long long MAXN = 3333;
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

int lvl[(int)2e5 + 777];

vector <int> g[(int)2e5 + 777];
                 
void dfs(int v, int par) {
	lvl[v] = lvl[par] + 1;
	for (int i : g[v]) {
		if (i != par) {
			dfs(i, v);			
		}
	}	
}


int a[(int)2e5 + 777];

long long dp[MAXN][3222];
vector <pair <long long,int> > Push[MAXN];

void DFS(int v, int par) {
	for (int I = 0; I < Push[v].size(); I++) {
		pair <long long, int> i = Push[v][I];
		if (i.second == 0) {
			dp[v][i.first / 64] |= (1ll << (i.first % 64));
			swap(Push[v][Push[v].size() - 1], Push[v][I]);
			Push[v].pop_back();
			I--;
		}		
	}
	for (int i : g[v]) {
		if (i != par) {
			for (auto I : Push[v]) {
				Push[i].pb({I.first, I.second - 1});
			}
			DFS(i, v);								
		}
	}
}

bool EMPTYYY(int j) {
	for (int i = 0; i <= 3221; i++) { 
		if (dp[j][i] != 0) {return 0;}
		
	}
	return 1;
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n =  readInt();
    bool ok = 0;
   	for (int i = 2; i <= n; i ++) {
		int x = readInt();
		if (x != i-1){
			ok = 1;
		}
		g[i].pb(x);
		g[x].pb(i);   		
   	}
   	if (!ok) {
	   	int m = readInt();
	   	dfs(1, 0);
	   	bool ok = 0;
	   	for (int i = 1; i <= m; i++) {
	   		int x = readInt(), y = readInt();
			a[lvl[x] + y] = 1;
	   	}
	   	int lst = 0;
	   	for (int i = 1; i <= n; i++) {
	   		if (a[i] && !ok) {
	   			cout << i << ' ';
	   			ok = 1;
	   		}
   			if (a[i]) {
   				lst = i;
   			}
	   	}
   		cout << lst;
   	} else {
   		int m = readInt();
   		for (int i = 1; i <= m; i++) {
			int x = readInt(), y = readInt();
			Push[x].pb({i-1, y});			   			
   		}
   		DFS(1, 0);
   		bool f = 0;
   		int L = 1;
   		while(EMPTYYY(L)) {
   			L++;
   		}
   
   		for (int i = L; i <= n; i++) {
   			for (int j = 0; j <= 3200; j++) {
				if (dp[i][j] != dp[i+1][j]) {
					cout << i << ' ';
					f = 1;
					break;
				}
   			}
   			if (f) {
   				break;
   			}
   		}
   		int R = n;
		while(EMPTYYY(R)) {
			R--;
		}
   		for (int i = R; i >= 1; i--) {
   			for (int j = 0; j <= 3200; j++) {
				if (dp[i][j] != dp[i-1][j]) {
					cout << i << ' ';
					return 0;
				}
   			}
   		}
   	}
    return 0;
}