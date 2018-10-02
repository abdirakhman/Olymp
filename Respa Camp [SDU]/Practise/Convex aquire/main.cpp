/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

const long long MAXN = 2e5 + 1;

using namespace std;

long long dp[MAXN];
vector <long long> vec(MAXN);

long long a[MAXN];
long long b[MAXN];

int main() {
	long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
    	cin >> b[i];
    }
    long long ptr = 1;
	long long sz = 0;
    for (int i = 1; i <= n; i++) {
    	while(ptr < sz && b[vec[ptr + 1]] * a[i] + dp[vec[ptr + 1]] <= b[vec[ptr]] * a[i] + dp[vec[ptr]]) ptr++;
    	dp[i] = dp[vec[ptr]] + b[vec[ptr]] * a[i];
    	while(ptr < sz && (dp[vec[sz - 1]] - dp[vec[sz]]) / (b[vec[sz]] - b[vec[sz-1]]+0.0) >= (dp[vec[sz]] - dp[i]) /  (b[i] - b[vec[sz]] + 0.0)) 
		sz--;
		vec[++sz] = i;
    	cout << dp[i] << ' ';
    }
    cout << dp[n];     
    return 0;
}
