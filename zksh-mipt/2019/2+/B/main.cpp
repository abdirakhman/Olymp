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
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64_t
#endif


const long long MOD = 1e18+ 7;
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

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int N = readInt();
    for (int i = 1; i <= N; i++) {
    	a[i] = readInt();
    	//used[a[i]]++;
    	//s.insert(a[i]);
    	
    }
    int A = readInt(), B = readInt();
	int tmp_A = (A % 2 ? A : A + 1);
    int tmp_B = (B % 2 ? B : B - 1); 
    int ans = 0;
    int mn = -MOD;
    int dalb = (tmp_A + tmp_B) / 2;
	if (tmp_A < a[1]) {
		int dist = a[1] - tmp_A;
		if (mn < dist) {
			mn = dist;
			ans = tmp_A;
		}
	}
	if (a[N] < tmp_B) {
		int dist = tmp_B - a[N];
		if (mn < dist) {
			mn = dist;
			ans = tmp_B;
		}
	}
    for (int i = 1; i < N; i++) {
    	if (a[i] <= tmp_A && tmp_A <= a[i + 1]) {
			int dist = min(tmp_A - a[i], a[i + 1] - tmp_A);
    		if (mn < dist) {
    			mn = dist;
    			ans = tmp_A;
    		}
    	}
    	if (a[i] <= tmp_B && tmp_B <= a[i + 1]) {
    		int dist = min(tmp_B - a[i], a[i + 1] - tmp_B);
    		if (mn < dist) {
    			mn = dist;
    			ans = tmp_B;
    		}
    	}
    }

	   
	for (int i = 1; i < N; i++) {
			int dist = (a[i + 1] - a[i]) / 2;
			//dist += a[i];
			if (dist % 2) {
				int D = dist - a[i];
				if (mn < D && A <= dist && dist <= B) {
					mn = D;
					ans = dist;					
				}	
			} else {
				int dist1 = (dist - 1);
				int dist2 = (dist + 1);
				int D1 = min(dist1 - a[i], a[i + 1] - dist1);
				int D2 = min(dist2 - a[i], a[i + 1] - dist2);
				if (mn < D1 && A <= dist1 && dist1 <= B) {
					mn = D1;
					ans = dist1;					
				}
				if (mn < D2 && A <= dist2 && dist2 <= B) {
					mn = D2;
					ans = dist2;					
				}
			}			   
	}
	cout << (ans == 0 ? tmp_A : ans);
	return 0;
}
/*
*/