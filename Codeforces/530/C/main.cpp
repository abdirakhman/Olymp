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

int used[MAXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    string s;
    cin >> s;
    int k = readInt();
    int mn = s.size();
    int SZ = s.size();
    bool ok = 0;
    for (int i = 0; i < s.size(); i++) {
    	if (i != 0 && s[i] == '?') {
	        used[i] = 2;
			used[i - 1] = 1;
			SZ--;
		}
    	if (s[i] == '*' && i != 0) {
    		ok = i;
    		used[i - 1] = 1;
    		used[i] = 2;
    		SZ--;
    	}
    }
    for (int i = 0; i < s.size(); i++) {
    	if (used[i]) mn--;
    }
	if (mn > k) {
		cout << "Impossible";
		return 0;
	}
	if (k <= SZ) {
		int diff = SZ - k;
		for (int i = 0; i < s.size(); i++) {
			if (used[i] == 2) {
				continue;
			}
			if (diff && used[i]) {
				diff--;
			} else {
				cout << s[i];
			}
		}
	} else {
		if (!ok) {
			cout << "Impossible";
			return 0;	
		}
		vector <char> ans;
		for (int i = 0; i < ok; i++) {
			if (used[i] == 2) {
				continue;
			}
			if (!used[i]) {			
				k--;
				ans.pb(s[i]);
			}
		}
		vector <char> ans1;
		for (int i = ok + 2; i < s.size(); i++) {
			if (used[i] == 2) {
				continue;
			}
			if (!used[i]) {
				k--;
				ans1.pb(s[i]);
			}
		}
		for (char i : ans) {
			cout << i;
		}
		while(k > 0) {
			k--;
			cout << s[ok + 1];					
		}
		for (char i : ans1) {
			cout << i;
		}
		
	}
    return 0;
}