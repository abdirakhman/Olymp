#include<bits/stdc++.h>
#define REEEPEPPE(i, a, n) for (int i = a; i <= n; ++i)
using namespace std;
typedef long long ll;
const int MAXN = (int)5e5+228;
int n, p[MAXN], s[MAXN], a[MAXN];
ll res;
vector<int>g[MAXN];
void dfs(int v, int pr, int depth)
{
    if(s[v] == -1) s[v] = s[pr];
    else if(s[p[pr]] > s[v]) cout << -1, exit(0);
    for(auto &to : g[v])
    {
        if(to == pr) continue;
        a[v] = s[v]-s[pr];

        dfs(to, v, depth+1);
        a[v] = s[v]-s[pr];

    }
}
int main()
{
    cin >> n;
    REEEPEPPE(i, 2, n)
    {
        cin >> p[i];
        g[p[i]].push_back(i);
    }
    REEEPEPPE(i, 1, n) cin >> s[i];
    dfs(1, 0, 1);
    REEEPEPPE(i, 2, n) res += a[i];
    cout << res+s[1];
    return 0;
}
