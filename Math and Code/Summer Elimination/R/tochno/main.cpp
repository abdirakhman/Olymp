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
//#define S second
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

int n;

int a[MAXN];
int p[4];
int arr[MAXN];

void solve1 () {
	/// 1 2 3
	/// -1 -1 2
	/// aleft < amid < aright
	int ans = MOD;
	set <int> S;
	for (int i = 1; i <= n; i++) {
		auto tmp = S.find(a[i]);
		if (tmp != S.end()) {
			S.erase(a[i]);
			tmp = S.begin();
			S.insert(a[i]);				
		} else {
			tmp = S.begin();
		}		
		if (tmp != S.end()) {
			if (*tmp < a[i])
				arr[i] = *tmp;	
			else {
				arr[i] = MOD;
			}
		} else {
			arr[i] = MOD;
		}
		S.insert(a[i]);
	}
	S.clear();
	for (int i = n; i >= 1; i--) {
		auto tmp = S.upper_bound(a[i]);
		if (tmp != S.end()) {
			ans = min(ans, arr[i] + a[i] + *tmp);
		} 
		S.insert(a[i]);
	}
	cout << (ans == MOD ? -1 : ans);
}

void solve2() {
	/// 1 3 2
	/// -2 1 1
	/// amid > aright > aleft
	set <int> S;
	int ans = MOD;
	for (int i = 1; i <= n; i++) {
		auto tmp = S.find(a[i]);
		if (tmp == S.end()) {
			tmp = S.begin();
		} else {
			S.erase(a[i]);
			tmp = S.begin();
			S.insert(a[i]);
		}		
		if (tmp != S.end()) {
			if (*tmp < a[i]) {
				arr[i] = *tmp;
			} else {
				arr[i] = MOD;
			}
		} else {
			arr[i] = MOD;
		}
		S.insert(a[i]);
	}
	S.clear();
	for (int i = n; i >= 1; i--) {
		auto tmp = S.upper_bound(arr[i]);
		if (tmp != S.end()) {
			if (*tmp < a[i]) {
				ans = min(ans, *tmp + a[i] + arr[i]);
			}
		}
		S.insert(a[i]);
	}
	cout << (ans == MOD ? -1 : ans);
}

void solve3() {
	/// 2 1 3
	/// 1 -2 1
	/// aright > aleft > amid 
	int ans = MOD;
	set <int> S;
	for (int i = 1; i <= n; i++) {
		auto tmp = S.upper_bound(a[i]);
		if (tmp != S.end()) {
			arr[i] = *tmp;
		} else {
			arr[i] = MOD;
		}
		S.insert(a[i]);
	}
	S.clear();
	for (int i = n; i >= 1; i--) {
		auto tmp = S.upper_bound(arr[i]);
		if (tmp != S.end()) {
			ans = min(ans, *tmp + a[i] + arr[i]);
		} 
		S.insert(a[i]);
	}
	cout << (ans == MOD ? -1 : ans);
}            

void solve4() {
	/// 2 3 1
	/// -1 2 -1
	/// aright < aleft < amid
	int ans = MOD;
	set <int> S;
	for (int i = n; i >= 1; i--) {
		auto tmp = S.find(a[i]);
		if (tmp != S.end()) {
			tmp = S.begin();
		} else {
			S.erase(a[i]);
			tmp = S.begin();
			S.insert(a[i]);		
		}
		if (tmp == S.end()) {
			arr[i] = MOD;
		} else {
			if (*tmp < a[i])
				arr[i] = *tmp;
			else {
				arr[i] = MOD;			
			}
		}
		S.insert(a[i]);
	}
	S.clear();
	for (int i = 1; i <= n; i++) {
		auto tmp = S.upper_bound(arr[i]);
		if (tmp != S.end()) {
			if (*tmp < a[i]) {
				ans = min(ans, a[i] + *tmp + arr[i]);
			}	
		} 	
		S.insert(a[i]);
	}
	cout << (ans == MOD ? -1 : ans);
}
void solve5() {
	/// amid < aright < aleft
	int ans = MOD;
	set <int> S;
	for (int i = n; i >= 1; i--) {
		auto tmp = S.upper_bound(a[i]);
		if (tmp == S.end()) {
			arr[i] = MOD;
		} else {
			arr[i] = *tmp;
		}
		S.insert(a[i]);
	}
	S.clear();
	for (int i = 1; i <= n; i++) {
		auto tmp = S.upper_bound(arr[i]);
		if (tmp != S.end()) {
			ans = min(ans, *tmp + arr[i] + a[i]);
		}		
		S.insert(a[i]);
	}
	cout << (ans == MOD ? -1 : ans);
}
void solve6() {
	/// aleft > amid > aright
	set <int> S;
	int ans = MOD;
	for (int i = 1; i <= n; i++) {
		auto tmp = S.upper_bound(a[i]);
		if (tmp != S.end()) {
			arr[i] = *tmp;
		} else {
			arr[i]  = MOD;			
		}
		S.insert(a[i]);
	}
	S.clear();
	for (int i = n; i >= 1; i--) {
		auto tmp = S.find(a[i]);
		if (tmp == S.end()) {
			tmp = S.begin();
		} else {
			S.erase(a[i]);
			tmp = S.begin();
			S.insert(a[i]);			
		}
		if (tmp != S.end()) {
			if (*tmp < a[i])
				ans = min(ans, a[i] + *tmp + arr[i]);
		}
		S.insert(a[i]);
	}
	cout << (ans == MOD ? -1 : ans);
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
   	n = readInt();
    if (n <= 2) {
    	cout << -1;
    	return 0;
    }
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    for (int i = 1; i <= 3; i++) {
    	p[i] = readInt();
    }    
	if (p[1] == 1 && p[2] == 2 && p[3] == 3) {
		solve1();
	} else if (p[1] == 1 && p[2] == 3 && p[3] == 2) {
		solve2();		
	} else if (p[1] == 2 && p[2] == 1 && p[3] == 3) {
		solve3();		        
	} else if (p[1] == 2 && p[2] == 3 && p[3] == 1) {
		solve4();
	} else if (p[1] == 3 && p[2] == 1 && p[3] == 2) {
		solve5();	
	} else if (p[1] == 3 && p[2] == 2 && p[3] == 1) {
		solve6();		
	} else {
		cout << "ne ponyal";
	}
    
    return 0;
}