#include <bits/stdc++.h>

#define f first
#define s second

const long long MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

ll a[200001], cnt[200001], last[200001], ans[200001], t[4 * 200001], num = 1;
map <int, int> m;
vector < vector <pair <int, int> > > v(200001);

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



void build(long long n) {
    while(n > num) {
        num *= 2;
    }
}

long long getsum(long long l, long long r) {
    long long sum = 0;
    l += num - 1;
    r += num - 1;
    while(l <= r) {
        if(l % 2 == 1) {
            sum += t[l];
            l++;
        } if(r % 2 == 0) {
            sum += t[r];
            r--;
        } l /= 2;
        r /= 2;
    } return sum;
}

void upd(long long pos, long long val) {
    pos += num - 1;
    t[pos] = val;
    pos /= 2;
    while(pos) {
        t[pos] = t[pos * 2] + t[pos * 2 + 1];
        pos /= 2;
    }
}


int main() {
    long double beg = clock();
    ll n = readInt();
    for (int i = 1; i <= n; i++) {
        a[i] = readInt();
        if (m.count(a[i])) {
            last[i] = m[a[i]];
        } else {
            last[i] = -1;
        } m[a[i]] = i;
    } build(n);
    ll m = readInt();
    for (int i = 1; i <= m; i++) {
        int x = readInt(), y = readInt();
        v[y].push_back({x, i});
    } for (int i = 1; i <= n; i++) {
        if (last[i] != -1){
            upd(last[i], 0);
        } upd(i, 1);
        for (int j = 0; j < v[i].size(); j++) {
            ans[v[i][j].second] = getsum(v[i][j].first, i);
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
}
