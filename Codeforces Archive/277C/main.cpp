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
#define int __int64
#endif


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

int n, m, k;

struct aaa {
	int l, r, id;
};

vector <aaa> col;
vector <aaa> row;

bool cmp(aaa a, aaa b) {    
	if (a.id != b.id) {
		return a.id < b.id;
	}
	if (a.l != b.l) {
		return a.l < b.l;
	} else {
	    return a.r < b.r;
	}
}

bool inter(int a, aaa b) {
	if (a >= b.l) return 1;
	return 0;	
}

int F(vector <aaa> & srch, int dist, int bignum) {
	bignum -= min(dist, srch[0].l);
	for (int i = 0; i < srch.size();) {
        int next = i;
        int mx = srch[i].r;
		while (next + 1 < srch.size() && inter(mx, srch[next + 1])) {
			next++;			
			mx = max(mx, srch[next].r);
		}
		int sz = mx - srch[i].l;
		bignum -= sz;
		if (next + 1 < srch.size()) {
			if (srch[next + 1].l <= dist) {
				bignum -= (srch[next + 1].l - mx);
			} 
			else if (mx < dist && srch[next + 1].l >= dist) {
				bignum -= (dist - mx);			
			}
		} else {
			if (mx < dist) {
				bignum -= (dist - mx);
			}
		}
		
		i = next + 1;
    }
    return bignum;
}

void make_and_do_col(int x, int res, bool kzk, int LEN) {
	cout << 0 << ' ' << x << ' ';
	if (kzk) {
		cout << res << ' ' << x << endl;
		return;
	}		
	vector <aaa> srch;
	for (aaa i : col) {
		if (i.id == x) {
			srch.pb(i);
		}
	}
	
	int l = 1, r = n;
	while(r - l > 1) {
		int M = (r + l) / 2;
		if (F(srch, M, n) <= res) {
			r = M;
		} else {
			l = M;
		}
	}	
	if (F(srch, r, n) == res) {
		cout << r << ' ' << x;
		return;		
	} 
	if (F(srch, l, n) == res) {
		cout << l << ' ' << x;		
		return;
	}
	assert(0);
}                                  

void make_and_do_row(int x, int res, bool kzk, int LEN) {
	cout << x << ' ' << 0 << ' ';
	if (kzk) {
		cout << x << ' ' << res;
		return;
	}
	vector <aaa> srch;		
	for (aaa i : row) {
		if (i.id == x) {
			srch.pb(i);
		}		
	}
	int l = 1, r = m;
	while(r - l > 1) {
		int M = (r + l) / 2;
		if (F(srch, M, m) <= res) {
			r = M;
		} else {
			l = M;
		}	
	}
	if (F(srch, r, m) == res) {
		cout << x << ' ' << r;
		return;		
	} 
	if (F(srch, l, m) == res) {
		cout << x << ' ' << l;		
		return;
	}
	assert(0);	 
}

map <int, int> MAP;

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt(), k = readInt();
    for (int i = 1; i <= k; i++) {
		int xb = readInt(), yb = readInt(), xe = readInt(), ye = readInt();
		if (xb == xe) {
			aaa tmp;
			tmp.l = min(yb, ye);
			tmp.r = max(yb, ye);
			tmp.id = xb;
			row.pb(tmp);
		} else {
			aaa tmp;
			tmp.l = min(xb, xe);
			tmp.r = max(xb, xe);
			tmp.id = yb;
			col.pb(tmp);				
		} 
    }
    sort(row.begin(), row.end(), cmp);
    sort(col.begin(), col.end(), cmp);
   	vector <pair<int, int> > heap_row;
   	vector <pair<int, int> > heap_col;
    for (int i = 0; i < row.size();) {
        if (i == 0 || row[i - 1].id != row[i].id)
        	heap_row.pb({m, row[i].id});
        int next = i;
        int mx = row[i].r;
		while (next + 1 < row.size() && inter(mx, row[next + 1]) && row[next].id == row[next + 1].id) {
			next++;			
			mx = max(mx, row[next].r);
		}
		int sz = mx - row[i].l;
		heap_row[heap_row.size() - 1].F -= sz;
		i = next + 1;
    }
    for (int i = 0; i < col.size();) {
        if (i == 0 || col[i - 1].id != col[i].id)
        	heap_col.pb({n, col[i].id});
        int next = i;
        int mx = col[i].r;
		while (next + 1 < col.size() && inter(mx, col[next + 1]) && col[next].id == col[next + 1].id) {
			next++;			
			mx = max(mx, col[next].r);
		}		
		int sz = mx - col[i].l;
		heap_col[heap_col.size() - 1].F -= sz;
		i = next + 1;
    }
    int ans = 0;
    if (((n - 1) - heap_row.size()) & 1) {
		ans ^= m;    	
    }
    if (((m - 1) - heap_col.size()) & 1) {
		ans ^= n;    	
    }
    for (pair<int,int> i : heap_col) {
		ans ^= i.F;	
    }
    for (pair<int,int> i : heap_row) {
    	ans ^= i.F;
    }
    if (ans == 0) {
    	cout << "SECOND";
        return 0;
    } else {
    	cout << "FIRST\n";
   		if (n - 1 - heap_row.size() > 0 && m > (m ^ ans)) { 
			//do_and_make_col(find_x(), ..., 1);    		
    		for (pair <int, int> i : heap_row) {
    			MAP[i.S] = 1;
    		}
    		int i = 1;
    		while(MAP[i] == 1) i++;
    		make_and_do_row(i, m - (ans^m), 1, 0);
    		return 0;
    	}
    	if (m - 1 - heap_col.size() > 0 && n > (n ^ ans)) {
    		//do_and_make_row(find_x(), ..., 1);
    		for (pair <int, int> i : heap_col) {
    			MAP[i.S] = 1;
    		}
    		int i = 1;
    		while(MAP[i] == 1) i++;

    		make_and_do_col(i, n - (ans^n), 1, 0);
    		return 0;
    	}
    	for (pair <int, int> i : heap_row) {
    		if ((ans ^ i.F) < i.F) {
				make_and_do_row(i.S, (ans^i.F), 0, i.F);    			
    			return 0;
    		}
    	}
    	for (pair<int,int> i : heap_col) {
    		if ((ans ^ i.F) < i.F) {
    			make_and_do_col(i.S, (ans^i.F), 0, i.F);
    			return 0;		
    		}
    	}
    	
    }
    return 0;
}