#include <bits/stdc++.h>
 
using namespace std;

#define pb push_back
 
int n, m;
int a[1000][1000];
long long pref[1000][1000];

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

 
void precalc() {
    pref[0][0] = a[0][0];
 
    for (int i = 1; i < n; i++) {
        pref[i][0] = pref[i - 1][0] + a[i][0];
    }
 
    for (int i = 1; i < m; i++) {
        pref[0][i] = pref[0][i - 1] + a[0][i];
    }
 
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
}
 
long long query(int x1, int y1, int x2, int y2) {
    return pref[x2][y2]
         - (x1 ? pref[x1 - 1][y2] : 0)
         - (y1 ? pref[x2][y1 - 1] : 0)
         + (x1 && y1 ? pref[x1 - 1][y1 - 1] : 0);
}

struct node {
	int fx, fy;
	int ex, ey;
	int num;
};

bool is_in(node x, node y) {
	int X = x.fx;
	int Y = x.fy;
	int A = x.ex;
	int B = x.ey;
	int X1 = y.fx;
	int Y1 = y.fy; 
	int A1 = y.ex;
	int B1 = y.ey;
	if (A<X1 || A1<X || B<Y1 || B1<Y)
    	return 0;
    return 1;
}

                                 
int main() {
    cin >> n >> m;
    int q = readInt(), K = readInt();
    while(q--) {
    	int x = readInt(), y = readInt();
    	a[x-1][y-1]++;
    } 
	precalc();
    vector <node> v;
    int ans = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int i1 = i+1; i1 < n; i1++) {
				for (int j1 = j+1; j1 < m; j1++) {
					node X;
					X.fx = i;
					X.fy = j;
					X.ex = i1;
					X.ey = j1;
					X.num = query(i, j, i1, j1);
					if (X.num == K) {
						v.pb(X);					
					}																
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (!is_in(v[i], v[j])) {
				node X = v[i];
				node Y = v[j];
				ans = min(ans, 2*(X.ey - X.fy + 1) + 2*(X.ex - X.fx + 1) + 2*(Y.ey - Y.fy + 1)+ 2* (Y.ex - Y.fx + 1));
			}
		}        
	}
	if (ans == 1e9) {
		cout << "NO";
	} else {
		cout << ans;
	}
}