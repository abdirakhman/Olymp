#include<bits/stdc++.h>

using namespace std;         

multiset<int> s;
int a[3], n;
char type[22], com[22];
int main () {
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	int m;
	cin >> m;     
	for(int i = 1; i <= m; i++){
		cin >> type[i] >> com[i];
    }
    for(int i = 1; i < m; i++){
    	if(type[i] == 'b'){
   			if(com[i] == com[i + 1]) s.erase(s.find(*s.begin()));
   			if(com[i] != com[i + 1]) s.erase(s.find(*s.rbegin())); 		
    	}else{
    		ans[com[i]] += *s.rbegin();
    		s.erase(s.find(*s.rbegin()));
    	}
    }
    if(type[m] == 'p') a[com[m]] += *s.rbegin();
	cout << a[1] - a[2];

}