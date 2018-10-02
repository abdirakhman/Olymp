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
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define pb push_back

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

int a_cnt[MAXN];
int b_cnt[MAXN];

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    string a;
    string b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
		a_cnt[i+1] += a_cnt[i] + (a[i] == 'A');
    }
    for (int i = 0; i < b.size(); i++) {
		b_cnt[i+1] += b_cnt[i] + (b[i] == 'A');    	
    }
	int q =readInt();
	while(q--) {
		int L1 = readInt(), R1 = readInt(), L2 = readInt(), R2 = readInt();
		int cnt_A_a = a_cnt[R1] - a_cnt[L1 - 1]; 
		int cnt_B_a = R1-L1+1 - cnt_A_a;
		int cnt_A_b = b_cnt[R2] - b_cnt[L2 - 1];
		int cnt_B_b = R2-L2+1 - cnt_A_b;
		int mn;
		mn = min(cnt_A_a, cnt_B_a);
		cnt_A_a -= mn;
		cnt_B_a -= mn;
		mn = min(cnt_A_b, cnt_B_b);
		cnt_A_b -= mn;
		cnt_B_b -= mn;
		cnt_A_a %= 3;
		cnt_A_b %= 3;
		cnt_B_a %= 3;
		cnt_B_b %= 3;
		if (cnt_A_a == cnt_A_b && cnt_B_b == cnt_B_a) {
			cout << "YES\n";
			continue;
		}
		if ((cnt_A_a + cnt_B_a * 2) % 3 == (cnt_A_b + cnt_B_b * 2) % 3) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
    return 0;
}