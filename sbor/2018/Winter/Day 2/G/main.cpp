#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 77;
vector <int> t[MAXN * 4];
int b[MAXN];
vector <int> bitti;
int a[MAXN];
vector<int> g[MAXN];

vector <int> Merge(vector <int> & a, vector <int> & b) {
    bitti.clear();
    int temp1, temp2;
    int left1, left2;
    left1 = left2 = 0;
    while(left1 < a.size() || left2 < b.size()) {
        temp1= temp2 = 1e9;
        if (left1 < a.size()) temp1 = a[left1];
        if (left2 < b.size()) temp2 = b[left2];
        if (temp1 < temp2) {
            bitti.push_back(temp1);
            left1++;
        } else {
            bitti.push_back(temp2);
            left2++;
        }
    }
    return bitti;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].push_back(b[tr]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = Merge(t[v * 2], t[v * 2 + 1]);
}
int get(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) {
        return 0;
    }
    if (r == tr && tl == l) {
        int leftdemi = -1, rightdemi = t[v].size();
        while(rightdemi - leftdemi > 1) {
            int middemi = (rightdemi+leftdemi) / 2;
            if (t[v][middemi] < x) {
                leftdemi = middemi;
            } else {
                rightdemi = middemi;
            }
        }
        return t[v].size() - 1 - leftdemi;
    }
    int tm = (tl + tr) / 2;
	return get(v * 2, tl, tm, l, min(r, tm), x) +
					get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}

int Dist(int ll, int rr) {return rr - ll + 1;}

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
        if (g[a[i]].size() > k) {
            b[i] = g[a[i]][g[a[i]].size() - k - 1];
        }
    }
    build(1, 1, n);
    int last = 0;
    int q;
    cin >> q;
    int l, r;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        l = ((x + last) % n) + 1;
        r = ((y + last) % n) + 1;
        if (l > r) swap(l, r);
        last = Dist(l, r) - get(1, 1, n, l, r, l);
        cout << last << endl;
    }
    return 0;
}