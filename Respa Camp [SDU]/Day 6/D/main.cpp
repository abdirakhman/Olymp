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

long long a[MAXN];

const long long BLOCK_SZ = 449;

struct AAA {
	long long Sol, On;
	long long pos;
};

vector <AAA> vec;
long long res = 0;
long long ANS[MAXN];
long long cnt[2*MAXN];
long long k;
long long pref[MAXN];

bool cmp(AAA a, AAA b) {
	if (a.Sol / BLOCK_SZ == b.Sol / BLOCK_SZ) {
		return a.On < b.On;
	} else {
		return a.Sol < b.Sol;		
	}	 
}

void add(long long v) {
	res += cnt[pref[v] ^ k];
	cnt[pref[v]]++;
}
void del(long long v) {
	cnt[pref[v]]--;
	res -= cnt[pref[v]^k];
}          



int main() {
	#ifndef ONLINE_JUDGE
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long n = readInt(), m = readInt(); k = readInt();
    for (long long i = 1; i <= n; i++) {
    	a[i] = readInt();
    	pref[i] = pref[i-1] ^ a[i];
    }
    
    for (long long i = 1; i <= m; i++) {
    	long long l = readInt() - 1, r = readInt();
    	AAA node;
    	node.Sol = l;
    	node.On = r;
    	node.pos = i;
    	vec.pb(node);
    }
    sort(vec.begin(), vec.end(), cmp);
    long long L = 0, R = 0;
    add(0);
	for (long long i = 0; i < vec.size(); i++) {
		long long l = vec[i].Sol, r = vec[i].On, pos = vec[i].pos;
		while(L < l) {
		   del(L++);
  		}
	 	while(L > l) {
   			add(--L);
  		}
	  	while(R < r) {
		  	add(++R);
  		}
  		while(R > r) {
   			del(R--);
  		}
  		ANS[pos] = res;
  	}
	for (long long i= 1; i <= m; i++) {
		cout << ANS[i] << '\n';
	}
    return 0;
}