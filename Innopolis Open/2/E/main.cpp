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

string s;


int calc(int left, int right) {
	//cout << left + 1 << ' ' << right + 1 << endl;
	if (left > right) return 2;
	//cout << s.substr(left, right - left + 1) << endl;
	if (right == left) {
		if (isdigit(s[left])) {
			return s[left] - 48;
		} else {
			assert(0);
		}
	}
	if (s[left] == '(') {
		int kek = 0;
		int closed = 0;
		for (int j = left;; j++) {
			if (s[j] == '(') kek++;
			if (s[j] == ')') kek--;
			if (!kek) {
				closed = j;
				break;
			}	
		}
		//deb(closed);
		if (closed == right) {
			return calc(left + 1, closed - 1);
		}
		if (s[closed + 1] == '&') {
			return (calc(left + 1, closed - 1) & calc(closed + 2, right));
		} else if (s[closed + 1] == '|') {   
		    return (calc(left + 1, closed - 1) | calc(closed + 2, right));
		} else if (s[closed + 1] == '^') {
			return (calc(left + 1, closed - 1) ^ calc(closed + 2, right));		
		}
	} else if (s[left] == ')') {
		assert(false);
	} else if (isdigit(s[left])) {
		if (isdigit(s[left + 2])) {
			if (s[left + 1] == '&') {
				return ((s[left] - '0')&(s[left + 2] - '0'));
			} else if (s[left + 1] == '|') {
				return ((s[left] - '0')|(s[left + 2] - '0'));			
			} else if (s[left + 1] == '^') {
				return ((s[left] - '0')^(s[left + 2] - '0'));				
			}
		} else {
			if (s[left + 1] == '&') {
				return ((s[left] - 48) & calc(left + 3, right - 1));
			} else if (s[left + 1] == '|') {   
			    return ((s[left] - 48) | calc(left + 3, right - 1));
			} else if (s[left + 1] == '^') {
				return ((s[left] - 48) ^ calc(left + 3, right - 1));		
			}		
		}
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    cin >> s;
   	cout << calc(0, s.size() - 1);
    int m = readInt();
	while(m--) {
		int pos = readInt();
		char c;
		cin >> c;
		s[pos - 1] = c;
		cout << (calc(0, s.size() - 1) & 1);
	}
    return 0;
}