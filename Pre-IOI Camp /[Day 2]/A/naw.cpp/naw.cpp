#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define mp make_pair
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()

const long long MXN = 5e5 + 1;
const long long MNN = 1e3 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;

using namespace std;

int n, m, res, mn = OO;
char ch[MNN][MNN];
pair<int, int> st;
bool used[MNN][MNN];

int d1[4] = {0, 0, 1, -1};
int d2[4] = {1, -1, 0, 0};

bool check(int x, int y){
    if(x >= 1 && y >= 1 && x <= n && y <= n && used[x][y] == 0){
        return true;
    }return false;
}

char side(int x, int y){
    if(x == 1 && y == 0){
        return 'R';
    }if(x == -1 && y == 0){
        return 'L';
    }if(x == 0 && y == -1){
        return 'D';
    }if(x == 0 && y == 1){
        return 'U';
    }
}

/*int ans(vector<char> &q){
    vector<int> v;
    int cnt = 1;
    for(int i = 0; i < q.size(); i++){
        if(q[i] == q[i - 1]){
            cnt++;
        }else{
            v.pb(cnt);
            cnt = 1;
        }
    }if(q[q.size() - 1] == q[q.size() - 2]){
        v.pb(cnt);
    }sort(all(v));
    reverse(all(v));
    cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(i == 0 || i == 1){
            cnt += 1;
        }else{
            cnt += v[i];
        }
    }return cnt;
}
*/
void dfs(int x, int y, vector<char> &q){
    /*bool ok = 0;
    if(ch[x][y] == 'C'){
        mn = min(ans(q), mn);
    }*/
    /*for(int i = 0; i < 4; i++){
        if(check(x + d1[i], y + d2[i])){
            ok = 1;
        }
    }if(ok == 0){
        mn = min(ans(q), mn);
    }*/for(int i = 0; i < 4; i++){
        if(check(x + d1[i], y + d2[i])){
            q.pb(side(d1[i], d2[i]));
            dfs(x + d1[i], y + d2[i], q);
            q.pop_back();
        }
    }
}

int main(){
    ios;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> ch[i][j];
            if(ch[i][j] == '#'){
                used[i][j] = 1;
            }if(ch[i][j] == 'S'){
                st = mp(i, j);
            }
        }
    }vector<char> q;
    dfs(st.F, st.S, q);

    return 0;
}
