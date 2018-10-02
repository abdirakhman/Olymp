#include <bits/stdc++.h>

#define f first
#define s second

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

void finally(bool x) {
    if (x == 1) {
        putchar('Y');
        putchar('E');
        putchar('S');
    } else {
        putchar('N');
        putchar('O');
    }
}

int dp[333][333];

int a[333][333];

int main() {
    //freopen("input.txt", "r", stdin);
    int n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> a[i][j];
    	}
    }
    for (int i = n; i >= 1; i--) {
    	for (int j = 1; j <= m; j++) {
    		if (a[i][j]) {
    			dp[i][j]++;
    			dp[i][j] += dp[i+1][j];
    		} else {
    			dp[i][j] = 0;
    		}
    	}
    }   
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cout << dp[i][j] << ' ';
    	}
    	cout << endl;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (a[i][j] == 1) {
    			for (int k = j + 1; k <= m; k++) {
    				if (!a[i][k]) break;
                    if (dp[i][k] > 1) {
                    	mx = max(mx, k-j + dp[i][k]);
                    }
    				if (mx == 5) {
    					cout << i << ' ' << j << ' ' << k << endl;
    				}
    			}
    		}
    	}
    }
    cout << mx;
}
