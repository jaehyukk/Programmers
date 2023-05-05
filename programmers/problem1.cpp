#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str, temp, result;

int solution(string s) {
	int answer, ans, cnt = 1;
	int length = s.size();
	answer = length;

	for (int i = 1; i <= length / 2; i++) {
		temp = s.substr(0, i); // 첫 문자열 자르기
		cnt = 1; // 반복 횟수 저장
		for (int j = i; j < length; j += i) { // 문자열 비교
			if (temp == s.substr(j, i)) { // 두 문자열이 같다면
				cnt++;
			}
			else {
				if (cnt > 1) { // 반복된 횟수를 숫자 문자열로 저장
					result += to_string(cnt);
				}
				result += temp; // 나머지 문자열 그대로 결과 문자열로 이동
				temp = s.substr(j, i); // 해당 문자열을 기준으로 함(이후 다시 비교를 위함)
				cnt = 1;
			}
		}
		if (cnt > 1) result += to_string(cnt); // 끝 문자열도 결과 문자열로 저장하기 위함
		result += temp;

		int result_length = result.size();
		answer = min(result_length, answer); // 최솟값 출력
		result.clear();
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	getline(cin, str); // 문자열 입력
	cout << solution(str) << '\n';

	return 0;
}
