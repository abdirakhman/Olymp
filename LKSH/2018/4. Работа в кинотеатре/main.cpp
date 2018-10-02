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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;

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


vector <int> v;

int col[MAXN][3];
int id[MAXN];
  
pair <int, int> t[MAXN * 4][3];

void upd(int v, int tl, int tr, int x, int val, int q){
	if(tl == tr){
		t[v][q].F = tl;
		t[v][q].S = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if(x <= tm){
		upd(v * 2, tl, tm, x, val, q);
	}
	else{
		upd(v * 2 + 1, tm + 1, tr, x, val, q);
    }                           
    t[v][q] = (t[v * 2][q].F < t[v * 2 + 1][q].F ? t[v * 2][q] : t[v * 2 + 1][q]);
}                     

pair <int, int> get(int v, int tl, int tr, int l, int r, int q){
	if (tr < l || r < tl){
		return {MOD, 0};
	}
	if (l <= tl && tr <= r){	
		return t[v][q];
	}
	int tm = (tl + tr) / 2;
	pair <int, int> a = get(v * 2, tl, tm, l, r, q);
	pair <int, int> b = get(v * 2 + 1, tm + 1, tr, l, r, q);
	return (a.F < b.F ? a : b);
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
    	col[i][1] = readInt(), col[i][2] = readInt(), id[i] = readInt();
    	v.pb(col[i][1]);
    	v.pb(col[i][2]);
    }
    sort(v.begin(), v.end());

   	for (int i = 1; i <= MAXN * 4 - 1; i++) t[i][2].F = t[i][1].F = MOD;

    for (int i = 1; i <= n; i++){
    	col[i][1] = lower_bound(v.begin(), v.end(), col[i][1]) - v.begin() + 1;
    	col[i][2] = lower_bound(v.begin(), v.end(), col[i][2]) - v.begin() + 1;
    }
    for(int i = 1; i <= n; i++){
    	pair <int, int> j = get(1, 1, n, col[i][id[i]], n, id[i]);
    	cout << j.F  << ' ' << j.S << endl;
    	upd(1, 1, n, col[i][1], i, 1);
    	upd(1, 1, n, col[i][2], i, 2);
    }
    return 0;
}