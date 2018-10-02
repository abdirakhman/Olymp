#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
int left[101][100001];
int size_s; 
int size_p;
int kek_p[50001];
int kek_s[100001];
int to_del(int right) {
	int cur = size_p;
	int i = right;
	for (; i >= 1 && cur >= 1;) {
		//std::cout << i << "=====>" << left[kek_p[cur]][i] << std::endl;
		int L =	left[kek_p[cur]][i];
		cur--;
		i = L - 1;
	}
	if (cur <= 0) {
		//std::cout << i << ' ' << (size_s - right) - 1 << std::endl;
		return i + 1;
	} else {
		return 0;
	}	
}
long long conta(int S, int s[], int P, int p[]) {
	size_s = S;
	size_p = P;
	for (int i = 0; i < P; i++) {
		kek_p[i + 1] = p[i];
	}
	for (int i = 0; i < S; i++) {
		kek_s[i +1] = s[i];
	}
	for (int i = 1; i <= S; i ++) {
		for (int j = 0; j < 100; j++) {
			if (kek_s[i] == j) {
				left[j][i] = i;
			} else {
				left[j][i] = left[j][i - 1];
			}
		}
	}
	long long ans = 0;
	for (int i = P; i <= S; i++) {
		ans += to_del(i);
	}
	return ans;
}
