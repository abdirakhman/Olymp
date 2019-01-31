
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAXN = +100500;

ll a[MAXN];

void f(ll l, ll r) {
    for (int i = l; i <= r; i++) a[i]++;
    if(l == r) return;
    f(l + 1, r);
    f(l, r - 1);
}

int main() {

}
