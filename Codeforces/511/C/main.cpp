#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define mp make_pair
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)

const long long MXN = 1.5 * 1e7;
const long long MNN = 3 * 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long OO = 1e9 + 500;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

int mn = OO, x, y, n, b[MNN];
vector<int> v[MNN];

int spf[MXN]; 

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MXN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<MXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
  
void getFactorization(vector <int>&v, int x) 
{  
    while (x != 1) 
    { 
        v.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
	return; 
} 


int main(){
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    ios;
    cin >> n;
    sieve();
    for(int i = 1; i <= n; i++){
        cin >> b[i];
		getFactorization(v[i], b[i]);        
    }
    for(int i = MXN; i >= 1; i--){
        if(v[i].size() == n){
            break;
        }if(v[i].size() >= 1) mn = min(n - (int (v[i].size())), mn);
    }if(mn == OO) return cout << -1, 0;
    cout << mn;
    return 0;
}
