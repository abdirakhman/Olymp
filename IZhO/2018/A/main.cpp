/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>
 
#define F first
#define S second
#define endl '\n'
#define pb push_back
 
#define int __int64_t
 
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
 
int n, k;
 
pair <pair <int, int> ,pair <int, int> > a[MAXN];
/* 
int check(int v) {
	int kvad = v * v;
	int kolvo_1 = (n/v) / 2;
	int kolvo_2 = ((n/v)+1) / 2;
	int ans_1 = kvad * (kolvo_1 * kolvo_1 + kolvo_2 * kolvo_2); /// BLACK First
	int ans_2 = kvad * (kolvo_1 * kolvo_2 + kolvo_2 * kolvo_1); /// WHITE First
	
	for (int i = 1; i <= k; i++) {
		int x = a[i].first.first;                              
		int y = a[i].first.second;
		int num_x = (x + v - 1) / v;
		int num_y = (y + v - 1) / v;
		if ((num_x + num_y) % 2 == 0) {
			ans_1 --;
			ans_2 ++;
		} else {
			ans_1 ++;
			ans_2 --;
		}
	}
	return min(ans_1, ans_2);
}
*/

long long get(long long x, long long len){
	if(x <= 0) return 0;
	long res = (x / len) / 2 * len;
	if(((x / len) & 1) == 1) res += x % len + 1;
	return res;
}

int check(int len){
    long long odd = 0ll, even = 0ll;
	for(int i = 1; i <= k; i++){
		long long x1 = a[i].first.first;
		long long x2 = a[i].second.first;
		long long y1 = a[i].first.second;
		long long y2 = a[i].second.second;		
		long long o1 = get(y2, len) - get(y1 - 1, len);
		long long e1 = (y2 - y1 + 1) - o1;
		long long o2 = get(x2, len) -  get(x1 - 1, len);
		long long e2 = (x2 - x1 + 1) - o2;
		long long od = o1 * e2 + e1 * o2;
		long long ev = (x2 - x1 + 1) * (y2 - y1 + 1) - od;
		odd += od;
		even += ev;
	}
	long long cnt =  (n / len) * (n / len);
	long long res = min(cnt / 2 * len * len + even - odd, (cnt + 1) / 2 * len * len + odd - even);
	return res; 
}

 
main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), k = readInt();
	for (int i = 1; i <= k; i++) {
		a[i] = {{readInt()-1, readInt()-1}, {readInt()-1, readInt()-1}};
	}
	check(1);                                                              
	int ans = 4e18;
	ans = min(check(1), ans);
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans = min(ans, check(i));
			ans = min(ans, check(n/i));						 
		}
	}
	cout << ans;
    return 0;
}