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

int a[MAXN];
int n;

void kos() {
	a[n]++;
	for (int i = n; i >= 1; i--) {
		if (a[i] == 26) {
			a[i] = 0;
			a[i - 1]++;
		}	
	}
	if (a[0]) {
		cout << -1;
		exit(0);
	}
}

int used[MAXN];

int cnt[MAXN];

int b[MAXN];

int timer = 1;

bool check() {
	timer++;
	for (int i = 1; i <= n ; i++) {
		if (0 <= a[i] <= 25 && used[a[i]] < timer) {
			used[a[i]] = timer;
		} else {
			return 0;
		}
	}
	return 1;
}

bool larger() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			return a[i] > b[i];
				
		}
	}
	assert(0);
}

int main() {
	#ifdef IZI_KATKA      
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
    	cnt[s[i] - 'a'] ++;
    }
    for (int i = 0; i < 26; i++) {
    	if (!cnt[i]) {
    		cout << s << char(i + 'a');
    		return  0;
    	}
    }
    n =  s.size();
	for (int i = 0; i < s.size(); i++) {
		a[i + 1] = s[i] - 'a';
		b[i+1] = s[i] - 'a';
	}    
	while(true) {
		kos();
		if (check() && larger()) {
			for (int i = 1; i <= n; i++) {
				cout << char(a[i] + 'a');
			}
			return 0;
		}
	}
	cout << -1;
    return 0;
}