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

int pref[MAXN];
int C[MAXN];

int n;

int dist(int l, int r) {
    if (l > r) swap(l, r);
    return min(pref[r] - pref[l - 1] - C[r], pref[n] - pref[r-1] + pref[l-1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    n=  readInt();
    for (int i = 1; i <= n; i++) {
        C[i]  = readInt();
        pref[i] = pref[i-1]+C[i];        
    }
    int id = 1;
    int mn = 1e9;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for(int j = 1; j <= n; j++) {
            mx = max(mx, dist(i, j));
        }
        if (mx < mn) {
            mn = mx;
            id = i;
        }
    }
    cout << id;
}
