#include <bits/stdc++.h>

using namespace std;

int K;
int N;

// 100 for N, 9+1 for possible digit range, +2 for padding
double Y[100+1][9+3];

int main() {
	double* dp[100];
	for (int i=0; i<100; i++)
		dp[i] = &(Y[i][1]);


    // I really learnt this idea from githuby
	while(scanf("%d %d", &K, &N) > 0) {
		if (K==0) {
			printf("%f\n", 100.0);
			continue;
		}


		for (int i=0; i<=K; i++) dp[0][i] = 1;

        // Get it to zero
		dp[0][-1] = dp[0][K+1] = 0;

		for (int i=1; i<N; i++) {
			for (int j=0; j<=K; j++) dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
			dp[i][-1] = dp[i][K+1] = 0;
		}

		double curr = 0;
		for (int i=0; i<=K; i++)
			curr += dp[N-1][i];

		double toDivide = pow(K+1, N);

		printf("%.12f\n", 100.0*curr/toDivide);
	}

    return 0;
}

