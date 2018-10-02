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

struct trie {
	long long nxt[2];
	long long cnt;
	trie();
} t[4*MAXN];


trie::trie() {
	nxt[0] = nxt[1] = -1;
	cnt = 0;
}

long long sz = 0;

void add(long long x) {
    long long v = 0, c;
	for (long long i = 31; i >= 0; i--) {
		c = (x >> i) & 1;
		if (t[v].nxt[c] == -1) {
			t[v].nxt[c] = ++sz;		                      			
		}
		v = t[v].nxt[c];
		t[v].cnt++;
	}                           
}



long long MEX(long long k) {
	long long v = 0;
	long long ans = 0;
	for (long long i = 31; i >= 0; i--) {
		int c = (k >> i) & 1;
		if (t[v].nxt[c] == -1) break;
		if (t[t[v].nxt[c]].cnt == (1 << i)) {
			ans += (1LL << i);
			if (t[v].nxt[c^1] == -1) break;
			v = t[v].nxt[c^1];							
		} else {
			v = t[v].nxt[c];
		}                        	
	}
	return ans;
}

map <int, int> maps;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    long long n = readInt(), m = readInt();
	while(n--) {
		long long x = readInt();
		if (!maps.count(x))
			add(x);
		maps[x] = 1;
	}	
	long long k = 0;
    while(m--) {
    	long long x = readInt(); 
		k ^= x;
    	cout << MEX(k) << endl;
    }
    return 0;
}