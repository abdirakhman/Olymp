#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int calc(vector <int> v, int bastau, int MX_SZ) {
	int ans = 0;
	for (int i = bastau + 1; i < v.size(); i ++) {
		if (v[i] == MX_SZ) ans ++;
	} 
	return ans;
}

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  
  string test = inf.readString();
  
  string jans = ans.readString();
  string pans = ouf.readString();
  vector <int> jstr = prefix_function(test + '@' + jans);
  vector <int> pstr = prefix_function(test + '@' + pans);
  int calc_j = calc(jstr, test.size(), jans.size());
  int calc_p = calc(pstr, test.size(), pans.size());
  if (calc_j > calc_p) {
  	quitf(_wa, "Jury malades");
  } else if (calc_j == calc_p) {
	quitf(_ok, "Participant and Jury malades");  	
  }
  quitf(_fail, "SRY BRAT");
}