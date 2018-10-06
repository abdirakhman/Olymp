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

#define ld long double

#define double ld

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


const double eps = 1e-18;
const double EPS = 1e-8;
const ll INF = 1e7;

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}



int x[MAXN];
int y[MAXN];
int n;

double dist(double X, double Y, int i) {
	return sqrt((X - 1.0 * x[i]) * (X - 1.0 * x[i]) + (Y - 1.0 * y[i]) * (Y - 1.0 * y[i]));
}

double f(double X, double Y) {
	double res = 0.0;
	for (int i = 1; i <= n; i++) {
		if (greaterThan(dist(X, Y, i), res)) {
			res = dist(X, Y, i);
		}
	}
	if (greaterThan(Y, res)) {
		res = Y;
	}
	return res;
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
     n = readInt();
    bool Kek = 0, keK = 0;
    for (int i = 1; i <= n; i++) {
    	x[i] = readInt(), y[i] = readInt();
    	if (y[i] > 0) Kek = 1;
    	else keK = 1;
    }
    if (Kek && keK) {
    	cout << -1;
    	return 0;
    }	
    if (keK) {
    	for (int i = 1; i <= n; i++) {
    		y[i] = -1;
    	}
    }
	double L_x = -INF, R_x = INF;
	double L_y = -INF, R_y = INF;
	int oper = 500;
	while(oper--) {
		double x_mid = (L_x + R_x) / 2.0;
		double y_mid = (L_y + R_y) / 2.0;
		double res = f(x_mid, y_mid);
		if (notEqual(L_x, R_x)) {
			double res1 = f(x_mid+EPS,y_mid);	
			if (lessThan(res, res1)) {
				R_x = x_mid;
			} else {
				L_x = x_mid;
			}
		}
		if (notEqual(L_y, R_y)) {
			double res1 = f(x_mid,y_mid +EPS);	
			if (lessThan(res, res1)) {
				R_y = y_mid;
			} else {
				L_y = y_mid;
			}			
		}
	}
	cout << fixed << setprecision(10)  << R_y;
   	return 0;
}