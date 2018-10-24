#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;


vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int calc(vector <int> v, int bastau, int MX_SZ) {
	int ans = 0;
	for (int i = bastau; i < v.size(); i ++) {
		if (v[i] == MX_SZ) ans ++;
	} 
	return ans;
}
                        																				
int main(int argc, char* argv[]) {
  
  registerTestlibCmd(argc, argv);
 
  string test = inf.readString();
 
  string jans = ans.readString();
  string pans = ouf.readString();
	if (pans.size() == 0) {
		quitf(_wa, "no file");	
	}
  vector <int> jstr = z_function(jans + '@' + test);
  vector <int> pstr = z_function(pans + '@' + test);
  int calc_j = calc(jstr, jans.size(), jans.size());
  int calc_p = calc(pstr, pans.size(), pans.size());
  if (calc_j > calc_p) {
  	quitf(_wa, "Jury malades");
  } else if (calc_j == calc_p) {
	quitf(_ok, "Participant and Jury malades");  	
  }
  quitf(_fail, "SRY BRAT");
}