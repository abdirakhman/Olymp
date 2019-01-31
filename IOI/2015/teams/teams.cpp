#include "teams.h"

using namespace std;

const int MAXN = 5e5 + 777;

const int LIM = 5e5;



void init(int N, int A[], int B[]) {
	for (int i = 0; i < N; i++) {
		pref[A[i]]++;
		pref[B[i] + 1]--;		
	}	
	for (int i = 1; i <= LIM; i++) {
		pref[i] += pref[i - 1];
	}
}

int can(int M, int K[]) {
	sort(K, K + M);
	return 0;
}
