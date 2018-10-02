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

const long long MOD = 1e9 + 9;
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

int cord[MAXN];
int type[MAXN];
int prob[MAXN];
int a[MAXN];
int h[MAXN];
int l[MAXN];
int r[MAXN];
int b[MAXN];
int cnt[MAXN];

int z[MAXN];

bool cmp(int x, int y) {
	if (cord[x] != cord[y]) 
		return cord[x] < cord[y]; 
	return type[x] > type[y];
}

void change(int pos, int val) {
  cnt[pos] += val;
}

double go() {
  double res = 1;
  for (int i = 1; i <= 99; i++) {
    res = res * pow((double)i / 100, cnt[i]);
  }
  return res;
}



int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt();
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		a[i] = readInt(), h[i] = readInt(), l[i] = readInt(), r[i] = readInt();
		v.pb(v.size() + 1);		
		cord[v.size()] = a[i] - h[i]; prob[v.size()] = l[i]; type[v.size()] = 1;
    	v.pb(v.size() + 1);		
    	cord[v.size()] = a[i] - 1; prob[v.size()] = l[i]; type[v.size()] = -1;
    	v.pb(v.size() + 1);		
    	cord[v.size()] = a[i] + 1; prob[v.size()] = r[i]; type[v.size()] = 1; 
		v.pb(v.size() + 1);		    	
    	cord[v.size()] = a[i] + h[i]; prob[v.size()] = r[i]; type[v.size()] = -1; 
	}
	for (int i = 1; i <= m; i++) {
    	b[i] = readInt(), z[i] = readInt();
    	v.pb(v.size() + 1);
    	cord[v.size()] = b[i]; prob[v.size()] = z[i]; type[v.size()] = 0;  	
    }
	sort(v.begin(), v.end(), cmp);
	double ans = 0;
  	for (int i = 0; i < v.size(); i++) {
    	if (type[v[i]] == 1) {
      		change(100 - prob[v[i]], 1);
    	} else if (type[v[i]] == -1) {
      		change(100 - prob[v[i]], -1);
    	} else {
      		if (cnt[0] == 0) {
        		ans += prob[v[i]] * go();
      		}
    	}
  	}
  	cout <<fixed << setprecision(9) << ans;
    return 0;                     
}