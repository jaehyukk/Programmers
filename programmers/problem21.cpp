#include <iostream>

using namespace std;
long long dp[2001];

void fibonacci(int num) {
	if (num == 0) dp[0] = 1;
	else if (num == 1) dp[1] = 1;
	else {
		dp[num] = dp[num - 1] + dp[num - 2];
		dp[num] %= 1234567;
	}
}

long long solution(int n) {
	long long answer = 0;
	
	for (int i = 0; i <= n; i++) {
		fibonacci(i);
	}
	answer = dp[n];

	return answer;
}
