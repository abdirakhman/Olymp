/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>
 
#define F first
#define S second
 
const long long MOD = 1e9 + 7;
const long long MAXN = 600;
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
        if (ch < '0' | ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}
 
int n;
 
int dp[2*MAXN * MAXN + MAXN];
 
int a[MAXN];
 
int sum = 0;
 
int N;
 
inline void add(int v) {
    for (int i = sum; i >= 0; i--) {
        dp[i + v] += dp[i];
        if (dp[i + v] >= MOD) {
            dp[i + v] -= MOD;
        }
    }
    sum += v;
}
 
inline void del(int v) {
    sum -= v;
    for (int i = 0; i <= sum; i++) {
        dp[i + v] = (dp[i + v] - dp[i] + MOD);
        if (dp[i + v] >= MOD) {
            dp[i + v] -= MOD;
        }
    }
}
 
int main() {
    freopen("bootfall.in", "r", stdin);
    freopen("bootfall.out", "w", stdout);
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        add(a[i]);
    }
    if (sum % 2 || !dp[sum / 2]) {
        printf("0");
        return 0;
    }
    N = sum;
    vector <int> ans;
    for (int i = 1; i <= N; i++) {
        ans.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        del (a[i]);
        for (int j = ans.size() - 1; j >= 0; j--) {
            if ((sum + ans[j]) % 2) {
                swap(ans[j], ans[ans.size() - 1]);
                ans.pop_back();
            } else if (!dp[(sum + ans[j]) / 2]) {
                swap(ans[j], ans[ans.size() - 1]);
                ans.pop_back();
            }
        }
        add(a[i]);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}