#include "testlib.h"
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll Pans[9];

bool isPrime(int x) {
	if (x <= 1) {
		return 0;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
                        																				
int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  int test = inf.readInt();
  for (int i = 1; i <= 7; i++) {
  	Pans[i] = ouf.readInt();
  } 
  //string jans = ans.readString();
  ll sum = 0;
  for (int i = 1; i <= 7; i++) {
	sum += Pans[i];
  	if (!isPrime(Pans[i])) {
  		quitf(_wa, "One of integers is not Prime");	
  	}
  }
  if (sum != test) {
  	quitf(_wa, "Sum is not equal to n");
  } else {
  	quitf(_ok, "Malades");
  }
  quitf(_fail, "SRY BRAT");
}