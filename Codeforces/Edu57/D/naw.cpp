/*int basi = 0;
	int soni = s.size() - 1;
	while(basi < s.size() && s[basi] !='h') {
		basi++;
	}
	if (basi == s.size()) {
		cout << 0;
		return 0;
	}
	while(basi > 0 && s[soni] !='h') {
		soni++;
	}
	if (soni == -1) {
		cout << 0;
		return 0;
	}
	for (int i = basi; i <= soni; i++) {
		if (s[i] == 'h') {
		    vec.pb(i);
			used[s[i]] = 1;
		} else if (s[i] == 'a') {
			if (!used['h']) {
				continue;
			}
			vec.pb(i);
			used[s[i]] = 1;				
		} else if (s[i] == 'r') {
			if (!used['a']) {
				continue;
			}
			vec.pb(i);
			used[s[i]] = 1;
		} else if (s[i] == 'd') {
			if (!used['r']) {
				continue;
			}
			vec.pb(i);
			used[s[i]] = 1;		
		} else {
			continue;			
		}	
	}
	*/
	