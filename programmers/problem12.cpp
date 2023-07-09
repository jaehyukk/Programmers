#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());					// A 배열 오름차순 정렬
	sort(B.begin(), B.end(), greater<int>());	// B 배열 내림차순 정렬
	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];					// 각 배열 원소마다 곱하여 최종값에 더하기
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	vector<int> a = { 1, 2 };
	vector<int> b = { 3, 4 };

	solution(a, b);
	return 0;
}
