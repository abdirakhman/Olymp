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

int main() {
    //freopen("input.txt", "r", stdin);
    int x;
    cin >> x;
    int tmp = x;
    int new_ = 0;
    while (tmp) {
        new_ = new_ * 10 + tmp % 10;
        tmp /= 10;
    }
    cout << (new_ > x);
}
