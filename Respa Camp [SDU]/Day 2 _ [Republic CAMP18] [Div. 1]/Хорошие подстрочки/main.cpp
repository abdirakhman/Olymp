/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

const long long MOD = 1e9 + 7;
const long long MAXN = 5551;
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

const long long  MOD1 = 1e9 + 7;
const long long  MOD2 = 1e9 + 9;
const long long P = 127;
vector<long long> p2, p1, h2, h1;
long long Hash(const long long & l, const long long & r, const long long & mod, vector <long long> & h, vector <long long> & p) {
    return (h[r] - (h[l] * p[r - l]) % mod + (2 * mod)) % mod;
}


int main() {

	#ifndef ONLINE_JUDGE
	//freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    #endif
    string s1;
    cin >> s1;
    string bad;
    cin >> bad;
    int k = readInt();
	p2.resize(MAXN);
	p1.resize(MAXN);
	h1.resize(MAXN);
	h2.resize(MAXN);    
	h2[0] = 0;
    h1[0] = 0;
    p2[0] = 1;
    p1[0] = 1;
    for (int i = 1; i < 2000; i++) {
        p2[i] = (p2[i - 1] * P) % MOD1;
        p1[i] = (p1[i - 1] * P) % MOD2;
    }
    for (int i = 1; i <= s1.size(); i++) {
        h2[i] = (h2[i - 1] * P) % MOD1;
        h2[i] = (h2[i] + s1[i - 1]) % MOD1;
        h1[i] = (h1[i - 1] * P) % MOD2;
        h1[i] = (h1[i] + s1[i - 1]) % MOD2;
    }
	set <pair <long long, long long> > s;
	for (int i = 0; i < s1.size(); i++) {	
		int cnt = 0;
		for (int j = i; j < s1.size(); j++) {
			if (bad[s1[j] - 'a'] == '0') {
				cnt ++;
			}
			if (cnt > k) break;
			s.insert({Hash(i, j + 1, MOD2, h1, p1), Hash(i, j + 1, MOD1, h2, p2)});
		}	
	}	
	cout << s.size();
	return 0;
}
///Hash(l1 - 1, r1, MOD1, h, p) 
