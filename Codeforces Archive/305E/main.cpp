/*
* @Author: ismail_a
* @Date:   2018-08-11 12:08:06
* @Last Modified by:   ismail_a
* @Last Modified time: 2018-08-11 12:08:06
*/
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

const int N = 5009;

int mexx[N];

int g[N];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    string s;
    cin >> s;
	
	for (int i = 1; i < N; i++) {
		memset(mexx, 0, sizeof (mexx));
		for (int j = 0; j < i; j++) {
			int L = max(0, j - 1);
			int R = max(0, i - j - 2);
			int res = (g[L] ^ g[R]);
			if (res < N)
				mexx[res] = 1;
		}
		for (int j = 0;; j++) {
			if (!mexx[j]) {
				g[i] = j;
				break;
			}
		}
	}
	int n = s.size();
	int ans = 0;
	for (int i = 1; i < n - 1; i ++) {
		if (s[i - 1] == s[i + 1]) {
			int j = i;
			while (j + 2 < n && s[j] == s[j + 2]) {
				j++;
			}
			ans ^= (g[j - i + 1]);
			i = j + 1;
		}
	}
	if (ans == 0) {
		cout << "Second";
		return 0;
	} else {
		cout << "First" << endl;
		for (int i = 1; i < n - 1; i ++) {
			if (s[i - 1] == s[i + 1]) {
				int j = i;
				while(j + 2 < n && s[j] == s[j + 2]) {
					j++;
				}
				int len = (j - i + 1);
				int tmp = ans ^ g[len];
				for (int k = 0; k < len; k++) {
					int L = max(0, k - 1);
					int R = max(0, len - k - 2);
					int rez = tmp ^ (g[L] ^ g[R]);
					if (rez == 0) {
						cout << i + k + 1;
						return 0;
					}
				}
				i = j + 1;
			}
		} 
	}
    return 0;
}