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

int check(int x) {
    int ans = x;
    if (x == 0) return 1;
    int tot = 0;
    while(ans) {
        if (ans % 10 == 0 || ans % 10 == 6 || ans % 10 == 9) tot ++;
        if (ans % 10 == 8) tot += 2;
        ans /= 10;
    }    
    return tot;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    int mx = check(a);
    int ans = a;
    for (int i = a; i <= b; i++) {
        if (mx < check(i)) {
            mx = check(i);
            ans = i;
        }
    }
    cout << ans;
}
