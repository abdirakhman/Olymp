/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

/*
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif
*/

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


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

char prv(char x) {
	if (x == 'a')  return 'h';
	if (x == 'r') return 'a';
	if (x == 'd') return 'r';
	assert(0);
}

char nxt(char x) {
	if (x == 'h') return 'a';
	if (x == 'a') return 'r';
	if (x == 'r') return 'd';
	assert(0);
}

map <char, int> birinwi;
map <char, int> last;
int cand1[MAXN];


map <char, multiset<int> > ans;

int res[65];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
	string s;
	cin >> s;
	int basi = 0;
	int soni = s.size() - 1;
	while(basi < s.size() && s[basi] !='h') {
		basi++;
	}
	if (basi == s.size()) {
		cout << 0;
		return 0;
	}
	while(basi > 0 && s[soni] !='d') {
		soni++;
	}
	if (soni == -1) {
		cout << 0;
		return 0;
	}
	birinwi['h'] = birinwi['a'] = birinwi['r'] = birinwi['d'] = MOD;
	for (int i = basi; i <= soni; i++) {
		if (s[i] == 'h') {
			cand1[i] = 1;	
			birinwi[s[i]] = min(birinwi[s[i]], i);
		} else if (s[i] == 'a') {
			if (birinwi[prv(s[i])] <= i) {
				cand1[i] = 1;
				birinwi[s[i]] = min(birinwi[s[i]], i); 
			}
		} else if (s[i] == 'r') {
			if (birinwi[prv(s[i])] <= i) {
				cand1[i] = 1;
				birinwi[s[i]] = min(birinwi[s[i]], i);
			}
		} else if (s[i] == 'd') {
			if (birinwi[prv(s[i])] <= i) {
				cand1[i] = 1;
				birinwi[s[i]] = min(birinwi[s[i]], i);
			}
		}
	}
	last['h'] = last['a'] = last['r'] = last['d'] = -MOD;
	for (int i = soni; i >= basi; i--) {
		if (!cand1[i]) continue;
		if (s[i] == 'd') {
			last[s[i]] = max(last[s[i]], i);			
		} else if (s[i] == 'r') {
			if (i <= last[nxt(s[i])]) {
				cand1[i] = 1;
				last[s[i]] = max(last[s[i]], i);
			} else {
				cand1[i] = 0;
			}
		} else if (s[i] == 'a') {
			if (i <= last[nxt(s[i])]) {
				cand1[i] = 1;
				last[s[i]] = max(last[s[i]], i);
			} else {
				cand1[i] = 0;
			}
		} else if (s[i] == 'h') {
			if (i <= last[nxt(s[i])]) {
				cand1[i] = 1;
				last[s[i]] = max(last[s[i]], i);
			} else {
				cand1[i] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i] = readInt();
		if (cand1[i]) {
			ans[s[i]].insert(a[i]);
		}
	}	
	int sz = min(ans['h'].size(), min(ans['a'].size(), min(ans['r'].size(), ans['d'].size())));
	if (sz == 0) {
		cout << 0;
		return 0;
	}


	while(!ans['h'].empty()) {
		int x = *ans['h'].begin();
		res['h'] += x;
		ans['h'].erase(ans['h'].begin());	
	}
	while(!ans['a'].empty()) {
		int x = *ans['a'].begin();
		res['a'] += x;
		ans['a'].erase(ans['a'].begin());	
	}

	while(!ans['r'].empty())  {
		int x = *ans['r'].begin();
		res['r'] += x;
		ans['r'].erase(ans['r'].begin());	
	}
	while(!ans['d'].empty())  {
		int x = *ans['d'].begin();
		res['d'] += x;
		ans['d'].erase(ans['d'].begin());	
	}	
	cout << min(res['h'], min(res['a'], min(res['r'], res['d'])));
	return 0;
}