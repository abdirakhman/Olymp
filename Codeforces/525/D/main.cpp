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


int get_response(int a, int b) {
	cout << "? "<<a << ' ' << b << endl;
	fflush(stdout);
	int response;
	cin >> response;	
   	return response;
}

const int Z = 3;

int main() {
	
    int kek = 0;
    for (int i = Z; i >= 0; i--) {
    	int response = get_response(0, (kek | (1 << i)));
		if (response == -1) {
			continue;			
		} else if (response == +1) {
			kek |= (1 << i);
		} else if (response == 0){
			kek |= (1 << i);
			break;		
		} else {
			return 0;
		}
    }
    int a = 0;
    int b = 0;
	for (int i = Z; i >= 0; i --) {
		if ((kek >> i) & 1) {
			a |= (1 << i);
			b |= (1 << i);
			int check_a = kek;
			int check_b = (1 << i);
			int response = get_response(check_a, check_b);
			if (response == -1) {
			    b ^= (1 << i);
			} else if (response == +1) {
				a ^= (1 << i);					
			} else if (response == 0) {
				continue;
			}	
		} else {
			a |= (1 << i);                              
			b |= (1 << i);
			int check_a = kek | (1 << i);
			int check_b = 0;
			int response = get_response(check_a, check_b);
			if (response == -1) {
				continue;
			} else if (response == +1) {
				a ^= (1 << i);					
				b ^= (1 << i);
			} else if (response == 0) {
				continue;
			} 
		}
	}
	cout << "! " << a << ' ' <<  (kek ^ a) << endl;
    fflush(stdout);
    return 0;
}   