#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> dp;		// 각 피보나치 값 저장할 동적배열	
	dp.push_back(0);	// f(0) = 0
	dp.push_back(1);	// f(1) = 1
	for (int i = 2; i < 100001; i++) {		// 동적배열 채우기
		int temp = (dp[i - 1] + dp[i - 2]) % 1234567;  // (A + B) % C = ((A % C) + (B % C)) % C
		dp.push_back(temp);
	}

	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution(100000) << '\n';
	return 0;
}
