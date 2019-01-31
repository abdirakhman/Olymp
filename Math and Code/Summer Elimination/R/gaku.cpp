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
const long long MAXN = 1e6 + 100;
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

int L[MAXN], R[MAXN];
int a[MAXN];
int p[5];

void solve1() {
	/// aleft < amid < aright
	int ans = MOD;
	set <int> pref, suff;
	for (int i = 1; i <= n; i++) {
		auto tmp1 = pref.begin();
		if (tmp1 == pref.end())	{
        	L[i] = -1;
        	pref.insert(a[i]);
        	continue;        
        }        
        ///IF na ravenstvo
        if (*tmp1 > a[i]) {
        	L[i] = -1;
			pref.insert(a[i]);
        	continue;         	
        }
        L[i] = *tmp1;
        pref.insert(a[i]);
        continue;
	}
	for (int i = n; i >= 1; i--) {
		auto tmp1 = suff.upper_bound(a[i]);
		if (tmp1 == suff.end()) {
			R[i] = -1;
			suff.insert(a[i]);
			continue;
		}
		R[i] = *tmp1;
		suff.insert(a[i]);
		continue;
	}
	for (int i = 1; i <= n; i++) {
		if (L[i] != -1 && R[i] != -1) {
			ans = min(ans, a[i] + L[i] + R[i]);
		}
	}
	cout << (ans == MOD ? -1 : ans);
}

void solve2() {
	/// amid > aright > aleft
	int ans = MOD;
	set <int> pref, suff;      
	for (int i = 1; i <= n; i++) {
		auto tmp = pref.find(a[i]);
		if (tmp == pref.end()) {
			tmp = pref.begin();
			if (tmp == pref.end()) {
				L[i] = -1;
				pref.insert(a[i]);
				continue;
			}
			if (*tmp > a[i]) {
				L[i] = -1;
				pref.insert(a[i]);
				continue;
			}
		} else {
			pref.erase(a[i]);
			tmp = pref.begin();
			pref.insert(a[i]);
			if (tmp == pref.end()) {
				L[i] = -1;
				pref.insert(a[i]);
				continue;
			}
			if (*tmp > a[i]) {
				L[i] = -1;
				pref.insert(a[i]);
				continue;
			}
		}
		L[i] = *tmp;
		pref.insert(a[i]);
	}
	for (int i = n; i >= 1; i--) {
		if (L[i] == -1) {
			suff.insert(a[i]);
			continue;
		}	
		auto tmp = suff.upper_bound(L[i]);
		if (tmp == suff.end()) {
			R[i] = -1;
			suff.insert(a[i]);
			continue;		
		} 
		///Proverka na bolwe ili ravno
		if (*tmp >= a[i]) {
			R[i] = -1;
			suff.insert(a[i]);
			continue;
		}
		R[i] = *tmp;    
		suff.insert(a[i]);
	}                 
	for (int i = 1; i <= n; i++) {
		if (L[i] != -1 && R[i] != -1) {
			ans = min(ans, a[i] + L[i] + R[i]);
		}
	}
	cout << (ans == MOD ? -1 : ans);
}

void solve3() {
	/// aright > aleft > amid
	int ans = MOD;
	set <int> pref, suff;
	for (int i = 1; i <= n; i++) {
		auto tmp = pref.upper_bound(a[i]);
		if (tmp == pref.end()) {
			L[i] = -1;
			pref.insert(a[i]);	
			continue;
		}               
		L[i] = *tmp;
		pref.insert(a[i]);
	}
	for (int i = n; i >= 1; i--) {
		if (L[i] == -1) {
			suff.insert(a[i]);
			continue;
		}
		auto tmp = suff.upper_bound(L[i]);
		if (tmp == suff.end()) {
			R[i] = -1;
			suff.insert(a[i]);
			continue;
		}
		R[i] = *tmp;
		suff.insert(a[i]);
	}        
	for (int i = 1; i <= n; i++) {
		if (L[i] != -1 && R[i] != -1) {
			ans = min(ans, L[i] + R[i] + a[i]);
		}
	}
	cout << (ans == MOD ? -1 : ans);
}
void solve4() {  
	/// aright < aleft < amid
	int ans = MOD;
	set <int> pref, suff;
	for (int i = n; i >= 1; i--) {
		auto tmp1 = suff.begin();
		tmp1 = suff.find(a[i]);
		if (tmp1 == suff.end()) {
		    tmp1 = suff.begin();
		    if (tmp1 == suff.end()) {
		    	R[i] = -1 ;
		    	suff.insert(a[i]);
		    	continue;
		    }
		    if (*tmp1 > a[i]) {
		    	R[i] = -1;
		    	suff.insert(a[i]);
				continue;
		    }
		} else { 
			suff.erase(a[i]);
			tmp1 = suff.begin();
			suff.insert(a[i]);
			if (tmp1 == suff.end()) {
				R[i] = -1;
				suff.insert(a[i]);
				continue;
			}
			if (*tmp1 > a[i]) {
				R[i] = -1;
				suff.insert(a[i]);
				continue;
			}		
		}          
		R[i] = *tmp1;
		suff.insert(a[i]);
		continue;
	}
	///Rdi duristau
	for (int i = 1; i <= n; i++) {
		if (R[i] == -1) {
			pref.insert(a[i]);
			continue;
		}	
		auto tmp1 = pref.find(a[i]);
		if (tmp1 == pref.end()) {
		    tmp1 = pref.upper_bound(R[i]);
		    if (tmp1 == pref.end()) {
		    	L[i] = -1;
		    	pref.insert(a[i]);
				continue;
		    }
		    if (*tmp1 > a[i]) {
				L[i] = -1;
				pref.insert(a[i]);
				continue;		    	
		    }
		} else {
			pref.erase(a[i]);
			tmp1 = pref.upper_bound(R[i]);
		    pref.insert(a[i]);
		    if (tmp1 == pref.end()) {
		    	L[i] = -1;
		    	pref.insert(a[i]);
				continue;
		    }
		    if (*tmp1 > a[i]) {
		    	L[i] = -1;
		    	pref.insert(a[i]);
				continue;
			}			
		}		
		L[i] = *tmp1;
		pref.insert(a[i]);
		continue;
	}
	for (int i = 1; i <= n; i++) {
		if (L[i] != -1 && R[i] != -1) {
			ans = min(ans, L[i] + R[i] + a[i]);
		}
	}
	cout << (ans == MOD ? -1 : ans);

};
void solve5() {
	/// amid < aright < aleft
	int ans = MOD;
	set <int> pref, suff;
	for (int i = n; i >= 1; i--) {
		auto tmp = suff.upper_bound(a[i]);
		if (tmp == suff.end()) {
			R[i] = -1;
			suff.insert(a[i]);
			continue;
		}
		R[i] = *tmp;
		suff.insert(a[i]); 
	}
	for (int i = 1; i <= n; i++) {
		if (R[i] == -1) {
			pref.insert(a[i]);
			continue;
		}
		auto tmp = pref.upper_bound(R[i]);
		if (tmp == pref.end()) {
			L[i] = -1;
			pref.insert(a[i]);
			continue;
		}
		L[i] = *tmp;
		pref.insert(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (L[i] != -1 && R[i] != -1) {
			ans = min(ans, a[i] + L[i] + R[i]);
		}
	}
	cout << (ans == MOD ? -1 : ans);
};
void solve6() {
	/// aleft > amid > aright
	int ans = MOD;
	set <int> pref, suff;
	for (int i = 1; i <= n; i++) {
		auto tmp = pref.upper_bound(a[i]);
		if (tmp == pref.end()) {
			L[i] = -1;
			pref.insert(a[i]);
			continue;	
		}
		L[i] = *tmp;
		pref.insert(a[i]);
	}       
	for (int i = n; i >= 1; i--) {
		if (L[i] == -1) {
			suff.insert(a[i]);
			continue;
		}
		auto tmp = suff.find(a[i]);
		if (tmp == suff.end()) {
		    tmp = suff.begin();
		    if (tmp == suff.end()) {		    	
		    	R[i] = -1;
		    	suff.insert(a[i]);
		    	continue;
		    }
		    if (*tmp > a[i]) {
		    	R[i] = -1;
		    	suff.insert(a[i]);
		    	continue;
		    }
		} else {
			suff.erase(a[i]);
			tmp = suff.begin();
			suff.insert(a[i]);
			if (tmp == suff.end()) {
				R[i] = -1;
				suff.insert(a[i]);
				continue;
			}
			if (*tmp > a[i]) {
				R[i] = -1;
				suff.insert(a[i]);
				continue;
			}
		}
		R[i] = *tmp;
		suff.insert(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (L[i] != -1 && R[i] != -1) {
			ans = min(ans, L[i] + R[i] + a[i]);
		}
	}
	cout << (ans == MOD ? -1 : ans);
};

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