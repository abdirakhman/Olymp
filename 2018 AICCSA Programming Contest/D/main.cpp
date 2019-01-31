
#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;

using namespace std;

const ll MAXN = +100500;

void sol() {
    ll n, k;
    cin >> n >> k;
    multiset <ll> a;
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    vector <ll> b;
    for (int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        if (a.find(tmp) != a.end()) a.erase(a.find(tmp));
        else b.pb(tmp);
    }
    if (b.size() > 1 || (b.size() == 1 && abs(b[0] - *a.begin()) > k)) {
        cout << "NO";
    } else cout << "YES";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++) sol();
}

