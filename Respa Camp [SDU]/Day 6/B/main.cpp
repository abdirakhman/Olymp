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
long long k;
long long res = 0;
long long b[MAXN];
long long ANS[MAXN];
long long pref[MAXN];
long long pref1[MAXN];
long long LEFT[MAXN];
long long RIGHT[MAXN];
long long timer = 0;
long long cnt[MAXN];
unordered_map <long long, long long> maps;
                           
long long Get(long long v)
{
    if (!maps.count(v)) maps[v] = ++timer;
    return maps[v];
}            


bool cmp(AAA a, AAA b) {
	if (a.Sol / BLOCK_SZ == b.Sol / BLOCK_SZ) {
		return a.On < b.On;
	} else {
		return a.Sol < b.Sol;		
	}	 
}

void add(long long v, bool type) {
	if (type) {
		res += cnt[LEFT[v]];
		cnt[pref[v]]++;
	} else {
		res += cnt[RIGHT[v]];
		cnt[pref[v]]++;		
	}
}
void del(long long v, bool type) {
	if (type) {
		cnt[pref[v]]--;	
		res -= cnt[LEFT[v]];
	} else {
		cnt[pref[v]]--;			
		res -= cnt[RIGHT[v]];
	}	
}          



int main() {
	#ifndef ONLINE_JUDGE
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
	#endif

    long long n = readInt(); k = readInt();
    for (long long i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    pref[0] = Get(0);
    RIGHT[0] = Get(k);
	for (long long i = 1; i <= n; i++) {
		b[i] = readInt();
		pref1[i] = pref1[i - 1] + (a[i] == 1 ? 1 : -1) * b[i];
		pref[i] = Get(pref1[i]);
		LEFT[i] = Get(pref1[i] - k);
		RIGHT[i] = Get(pref1[i] + k);		
	}    
	long long q = readInt();
    for (long long i = 1; i <= q; i++) {
    	long long l = readInt() - 1, r = readInt();
    	AAA node;
    	node.Sol = l;
    	node.On = r;
    	node.pos = i;
    	vec.pb(node);
    }
    sort(vec.begin(), vec.end(), cmp);
    long long L = 1, R = 1;
    cnt[pref[1]]++;	
    for (long long i = 0; i < vec.size(); i++) {
		long long l = vec[i].Sol, r = vec[i].On, pos = vec[i].pos;
		while(L < l) {
		   del(L++, 0);
  		}
	 	while(L > l) {
   			add(--L, 0);
  		}
	  	while(R < r) {
		  	add(++R, 1);
  		}
  		while(R > r) {
   			del(R--, 1);
  		}
  		ANS[pos] = res;
	}
	for (long long i= 1; i <= q; i++) {
		cout << ANS[i] << '\n';
	}
    return 0;
}