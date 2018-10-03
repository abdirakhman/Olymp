/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
//#include "tile.h"
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

const long long MOD = 2e9;
const long long MAXN = 300111+ 1;
using namespace std;

typedef long long ll;

int kelesi[MAXN][40];
vector <pair <int, int> > v;

int getNumberOfSpecialTiles(int l, int r) {
	int L = upper_bound(v.begin(), v.end(), make_pair(l, -1)) - v.begin();
	int R = upper_bound(v.begin(), v.end(), make_pair(r + 1, -1)) - v.begin();
	if(L == R)
		return 0;
	int ans = 0, cur = L;
	for(int i = 32; i >= 0; i--){
		if(cur != MOD && kelesi[cur][i] < R){
			ans += (1 << i);
			cur = kelesi[cur][i];
		}
	}
	return ans + 1;	
}


int init(int N, int K, int Q, int M, std::vector<int> A) {

    for (int i = 0; i < M; i++) {
		v.pb({A[i], i});		    	
    }
    v.pb({2*N, M});
    for (int i = 0; i < M; i++) {
    	auto z = upper_bound(v.begin(), v.end(), make_pair(A[i] + K, -1));
    	kelesi[i][0] = (z -> S);
    }
    kelesi[M][0] = M;
	for (int i = 1; i < 33; i++) {
		for (int j = 0; j <= M; j++) {
			kelesi[j][i] = kelesi[kelesi[j][i - 1]][i - 1];			
		}
	}    
	return 0;
}