#include "testlib.h"
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  int l = atoi(argv[1]);
  int r = atoi(argv[2]);
  int n = rnd.next(l, r);
  int q = rnd.next(r+l);
	cout << n << endl;
  for (int i = 1; i <= n; i++) {
	int x = rnd.next(1, 100);
	cout << x;
	if (i != n) {
		cout << ' ';
	}
  }
  cout << endl;
  cout << q << endl;
	for (int i = 1; i <= q; i++) {
		int L = rnd.next(1, n);
		int R = rnd.next(L, n);
		cout << L << ' ' << R << endl;		
	}  
}
