#include <iostream>

#include <algorithm>
#include <cmath>
#include <math.h>

#include <string>

#include <sstream>

#include <vector>
#include <set>
#include <map>

#include <list>

#include <cstdio>
#include <iomanip>
#include <time.h>

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define fi first
#define se second

#define pll pair<ll, ll>
#define pii pair<int, int>
#define size(x) ((int) x.size())
#define pb push_back
#define mkp make_pair

#define NI nextInt()
#define NL nextLong()

#define all(x) x.begin(), x.end()
#define show(x) cerr << #x << " = " << x << ", "
#define showln(x) cerr << #x << " = " << x << "\n"

#define by(T, x) [](const T &a, const T &b) {return a.x < b.x;}

#define fname "342E"

using namespace std;

inline void frepik () {
    #ifndef ONLINE_JUDGE
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);
    #endif
}

const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

const int root = (int) 1;
const int N = (int) 1e5 + 1;
const int logN = (int) log2(N) + 1;

const int inf = (int) (1u<<31) - 1u;
const ll INF = (ll) (1ull<<63) - 1ull; 

inline int nextInt () {int e; scanf("%d", &e); return e;}
inline ll nextLong () {ll e; scanf("%I64d", &e); return e;}

int n;

/// LCA
vector <int> adj[N];
int tin[N], tout[N], up[N][logN + 1], timer, depth[N];

void dfs (const int &v, const int &prev = root, const int &curDepth = 1) {
    tin[v] = ++timer;
    up[v][0] = prev;
    depth[v] = curDepth;

    for(int h = 1; h <= logN; h++)
        up[v][h] = up[up[v][h - 1]][h - 1];

    for(const int &u : adj[v])
        if(u != prev)
            dfs(u, v, curDepth + 1);
    tout[v] = timer;
}

inline bool parent (const int &x, const int &y) {return tin[x] <= tin[y] && tout[x] >= tout[y];}

inline int lca (int v, const int &x) {
    if(parent(v, x)) return v;
    if(parent(x, v)) return x;
    for(int h = logN; h >= 0; h--)
        if(!parent(up[v][h], x))
            v = up[v][h];
    return up[v][0];
}

inline int dist (const int &v, const int &u) {return depth[v] + depth[u] - (depth[lca(u, v)] << 1);}
/// LCA

/// CD
int d[N];
int centroidOf[N];
set <int> cadj[N];
int sub[N];


int getCentroid (const int &v, const int &prev, const int &m) {
    for(const int &u : cadj[v])
        if(u != prev && sub[u] > (m >> 1)) 
            return getCentroid(u, v, m);
    return v;
}

int calcSize (const int &v, const int &prev) {  
    sub[v] = 1;
    for(const int &u : cadj[v])
        if(u != prev)
            sub[v] += calcSize(u, v); 
    return sub[v];                                    
}

void go (const int &v, const int &prev = -1) {
    int m = calcSize(v, v);
    int centroid = getCentroid(v, v, m);
    centroidOf[centroid] = prev;
    for(const int &u : cadj[centroid]) {
        cadj[u].erase(centroid);
        go(u, centroid);
    }               
}
/// CD

int main () {            
    frepik();
    scanf("%d", &n);
    int q; scanf("%d", &q);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        cadj[u].insert(v);
        cadj[v].insert(u);
    }
    dfs(root);
    go(root);

    for(int v = 1; v <= n; v++)
        d[v] = depth[v] - 1;            
    while(q--) {
        int t; scanf("%d", &t);
        int v; scanf("%d", &v);
        if(t & 1) {
            d[v] = 0;
            for(int u = v; u != -1; u = centroidOf[u]) 
                d[u] = min(d[u], dist(v, u));                                                
        } else {
            int distance = inf;
            for(int u = v; u != -1; u = centroidOf[u]) 
                distance = min(distance, d[u] + dist(u, v));
            printf("%d\n", distance);                                        
        }
    }                                            
    return 0;

}
	