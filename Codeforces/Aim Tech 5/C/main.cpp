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





int n;

struct point {
	int x1, x2;
	int y1, y2;
};

point a[MAXN];

bool intersect(point rec1, point rect2) {
	x_overlap = max(0, min(rect1.x2, rect2.x2) - max(rect1.x1, rect2.x1));
	y_overlap = max(0, min(rect1.y2, rect2.y2) - max(rect1.y1, rect2.y1));
	return (x_overlap * y_overlap) > 0;
}


bool normal(point P) {
	return (P.x1 < P.x2 && P.y1 < P.y2);
}
                 
bool check(int pos) {  
	point cand = a[pos];
	int kek = 0;
	for (int i = 1; i <= n; i++) {
		if (pos == i) {
			continue;		
		}
		if (intersect((a[i]), cand)) {
			cand.x2 = min(a[i].x2, cand.x2);
			cand.x1 = max(a[i].x1, cand.x1);
			cand.y2 = min(a[i].y2, cand.y2);
			cand.y1 = max(a[i].y1, cand.y1);
			if (!normal(cand)) {
				return 0;
			}
		} else {                          
			if (kek != 0) {
				return 0;
			}
			kek = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (pos == i) {
			continue;
		}
		if (!intersect((a[i]), cand)) {
			continue;
		} else {
			
		}
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
     n = readInt();
    set <pair<int, int>> Set;
    for (int i = 1; i <= n; i++) {
    	a[i].x1 = readInt(), a[i].x2 = readInt(), a[i].y1 = readInt(), a[i].y2 = readInt();
    	
    	Set.insert({(a[i].x2 - a[i].x1) * (a[i].y2 - a[i].y1), i})
    }
    int oper = 500;
    for (auto i : Set) {
    	if(check(i.S)) {
    		return 0;
    	}
    	if (oper == 0) {
    		break;
    	}
    }
    return 0;
}