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

map<int,int>cnt1,cnt2;

string s;
string a;

int kek;
int dp[3000][3000];

int calc(int l, int r) {  
   	for (int i = 0; i < a.size(); i++) 
      	dp[i][i] = 1; 
  	for (int len = 2; len <= a.size(); len++) { 
        for (int i = 0; i < a.size() - len + 1; i++) { 
            int j = i + len - 1; 
            if (a[i] == a[j] && dp[i + 1][j - 1] <= 99) 
               dp[i][j] = dp[i+1][j-1] + 2; 
			dp[i][j] = max(dp[i][j-1], max(dp[i][j], dp[i+1][j])); 
        } 
    } 
   return dp[l][r];
}
  
vector <int> ans;
map <int,int>cnt;
                         
void vost(int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (kek >= 100) {
			cerr <<"wtf";
			return;
		}
		ans.pb(l);
		return;
	}
	if (a[l] == a[r] && dp[l][r] == dp[l + 1][r - 1] + 2) {
		ans.pb(l);
		vost(l + 1, r - 1);
		ans.pb(r);
	}
	else if (dp[l][r] == dp[l + 1][r])
		vost(l + 1, r);
	else
		vost(l, r - 1);
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    string s;
    cin >> s;
    a = s;
    int n = s.size();
    s = '#' + s;
	if (n >= 2600) {
		///pigeonhole principle
		for (int i = 0; i < s.size();i++) {
			cnt[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (cnt[s[i]] >= 100) {
				for (int j = 1; j <= 100; j++) {
					cout << s[i];
				}	
				return 0;
			}
		}
		return 0;
	} else {
		memset(dp, 0, sizeof(dp));
		kek = calc(0, a.size() - 1);
		vost(0, a.size() - 1);
		for (int i = 0; i < ans.size(); i ++) {
			cout << a[ans[i]];
		}
	}
    return 0;
}