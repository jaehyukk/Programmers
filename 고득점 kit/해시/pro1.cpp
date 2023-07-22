// hash
// 소요시간 : 10m 20s

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> vec = { 3, 3, 3, 2, 2, 4 };
unordered_map<int, int> um;

int solution(vector<int> nums) {
	int answer = 0;

	int size = nums.size();

	// 각 nums 원소마다 map에 넣어주기
	for (int i = 0; i < size; i++) {
		int temp = nums[i];

		// map에 없는 원소일 경우
		if (um.find(temp) != um.end()) {
			um[temp] = 0;
		}

		// map에 있는 원소일 경우
		else {
			um[temp]++;
		}
	}
	answer = um.size();

	// map의 크기가 N/2보다 크거나 같을 경우
	if (answer >= size / 2) answer = size / 2;

	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution(vec) << '\n';

	return 0;
}
