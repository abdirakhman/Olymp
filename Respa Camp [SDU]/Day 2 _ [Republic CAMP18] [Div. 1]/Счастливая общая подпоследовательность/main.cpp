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

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int dp[101][101][101];

int smth[101][101];

pair <int, pair <int, int> > opt[101][101][101];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
	#endif
   	string a, b, c;
    cin >> a >> b >> c;
	string s = "";
	for (int i = 0; i < c.size(); i++) {
		for (int j = 0; j < 26; j++) { 
			string x = c;
			x += '#';
			x += s;
			x += char(j + 'A');
			vector <int> Z = prefix_function(x);							
			smth[i][j] = Z[x.size() - 1];
		}
		s += c[i];
	}
	dp[0][0][0] = 1;
	opt[0][0][0] = {-228, {-228, -228}};
	for (int i = 0; i <= a.size(); i++) {
		for (int j = 0; j <= b.size(); j++) {
			for (int k = 0; k <= c.size(); k++) {
				if (!dp[i][j][k]) continue;
				if (i < a.size() && dp[i][j][k] > dp[i+1][j][k]) {
					dp[i+1][j][k] = dp[i][j][k];
					opt[i+1][j][k] = {i, {j, k}};
				} 
				if (j < b.size() && dp[i][j][k] > dp[i][j+1][k]) {
					dp[i][j+1][k] = dp[i][j][k];
					opt[i][j+1][k] = {i, {j, k}};
				}
				if (i < a.size() && j < b.size() && k < c.size() && a[i] == b[j] && dp[i][j][k] + 1 > dp[i+1][j+1][smth[k][a[i] - 'A']]) {
					dp[i+1][j+1][smth[k][a[i] - 'A']] = dp[i][j][k] + 1; 
					opt[i + 1][j + 1][smth[k][a[i] - 'A']] = {i, {j, k}};
				}
			} 			
		}
	}
	int ind = 0;
	for (int i = 0; i < c.size(); i++) {
		if (dp[a.size()][b.size()][ind] < dp[a.size()][b.size()][i]) {
			ind = i;
		}
	}
	if (dp[a.size()][b.size()][ind] == 1) {
		cout << "0";
		return 0;
	}
	string S = "";
	for (pair <int, pair <int, int> > it = {a.size(),{b.size(), ind} }; it.first >= 0 && it.second.first >= 0; it = opt[it.first][it.second.first][it.second.second]) {
		int i = opt[it.first][it.second.first][it.second.second].first;
		int j = opt[it.first][it.second.first][it.second.second].second.first;
		if (i + 1 == it.first && j + 1 == it.second.first) {
			if (i >= 0 && i < a.size())
			S = a[i] + S;
		}
	}
	cout << S;
    return 0;
}