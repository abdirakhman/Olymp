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

int ans[MAXN];
int a[MAXN];
int used[MAXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), k = readInt();
	int tmp = 1;
	if (n==1) {
		cout << "YES\n1";
		return 0;
	}
	if (k == 1) {
		cout << "NO";
		return 0;
	}
	for (int  i = 1; i <= k; i ++) {
		a[i] = readInt();
		ans[a[i]] = tmp;
		used[a[i]] = 1;
		tmp++;
	}
	int kek = n;
	for (int i = 1; i <= n; i++) {
		if (!ans[i]) {
			ans[i] = kek;
			kek--;
		}
	}
//	for (int i = 1; i <= n; i++) {
///		cout << ans[i] << ' ';
//	}

	a[0] = 0;
	a[k+1] = n+1;	
	ans[0] = 0;
	ans[n+1]= n+1;
	int mx = 0;
	int id1 = -1;
	for (int i = 0; i <= k; i++) {	
		for (int j = a[i] + 1; j < a[i+1]; j++) {
			 if (ans[a[i]] < ans[j] && ans[j] < ans[a[i + 1]]) {
//			    deb(ans[a[i]]);
//			    deb(ans[j]);
//			    deb(ans[a[i + 1]]);
			    if (id1 != -1) {
			    	cout << "NO";
			    	return 0;
			    }
			    mx = ans[j] - ans[a[i]];
			 	id1 = a[i];
			 	//cout << "found" << endl;
			 } 
		}
		//cout << endl;
	}
	//cout << id1 << endl;
//	cout << mx << endl;
	if (id1 != -1) {
		for (int i = 1; i <= n; i++) {	
			if (used[i])
			ans[i] += mx;
		}
		int cnt = 0;
		for (int i = id1; i <= n; i++) {
			if (!used[i]) {			
				ans[i] = 0;
			    cnt ++;
			}
		} 
		//cout <<id1 << endl;
		for (int i = id1; i <= n; i++) {
			if (!used[i] && !ans[i]) {			
				ans[i] = cnt;
				cnt--;
			}
		}
	}
	cout << "YES\n";

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}


    return 0;
}