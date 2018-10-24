#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
typedef long long ll;
using namespace std;

#define sqr(x) ((x) * (x))

const double inf = 1e100, eps = 1e-12;
const ll MAXN = +100500;

struct point {
    double x, y;
    ll ind;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    double r() {
        return sqrt(x*x+y*y);
    }
    void print() {
        printf("%lf %lf\n", x, y);
    }
    bool operator<(const point& r) const {
        if (x < r.x) return 1;
        if (x > r.x) return 0;
        return y < r.y;
    }
    point operator-(point& r) {
        point res = {x - r.x, y - r.y};
        return res;
    }
    double slope() {
        if (x == 0.0 && y == 0.0) return -inf;
        if (x == 0.0) return inf;
        return y/x;
    }
    bool operator==(const point&r) {
        return x == r.x && y == r.y;
    }
    double operator*(const point& r) {
        return x*r.y - y*r.x;
    }
    double dist_to(point& r) {
        return sqrt(sqr(x-r.x)+sqr(y-r.y));
    }
};

point O; // left-most lower point
bool BY_SLOPE(point l, point r) {
    double ls = (l-O).slope(),  rs = (r-O).slope();
    if (ls < rs) return 1;
    if (ls > rs) return 0;
    return l.dist_to(O) < r.dist_to(O);
}
// pre: N >= 0, [p, p + N) - points
vector<point> convex_hull(point *p, int N) {
    if (N <= 2) return vector<point>(p, p + N);
    sort(p, p + N);
    O = p[0];
    sort(p + 1, p + N, BY_SLOPE);
    vector<point> hull;
    for (int i = 0 ; i < N ; i ++) {
        if (i < 3) hull.push_back(p[i]);
        else {
            int sz = hull.size();
            while (sz >= 2 && ((p[i] - hull[sz-2])*(hull[sz-1]-hull[sz-2]) >= 0 || (p[i] - hull[sz - 2]).slope() == (p[i] - hull[sz - 1]).slope()))
                hull.pop_back(), sz --;
            hull.push_back(p[i]);
        }
    }
    return hull;
}// post: convex hull in hull, given in ccw order

double trg(point a, point b, point c) {
    double A = a.dist_to(b);
    double B = b.dist_to(c);
    double C = c.dist_to(a);
    double S = (A+B+C)/2.0;
    return sqrt(S * (S-A) * (S-B) * (S-C));
}

vector<point> v;
int  n;
point P[111100];

bool used[MAXN];

const double INF = 1e18;

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i ++) {
        P[i].read();
        P[i].ind = i + 1;
    }
    v = convex_hull(P, n);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].ind << " ";
    } cout << endl;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur == v.size()) break;
        if (v[cur] == P[i]) {
            used[i] = true;
            cur++;
        } else {
            cout << 1 << endl;
            cout << P[i].ind;
            return 0;
        }
    }
    double mn = INF;
    ll id = -1;
    for (int i = 0; i < v.size(); i++) {
        if (mn > trg(v[i], v[(i + 1) % v.size()], v[(i + 2) % v.size()])) {
            mn = trg(v[i], v[(i + 1) % v.size()], v[(i + 2) % v.size()]);
            id = v[i].ind;
        }
    }
    cout << 1 << endl << id;
    return 0;
}
