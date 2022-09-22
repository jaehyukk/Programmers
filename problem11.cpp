#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	vector<string> e_jin;					// 이진 변환값 저장
	vector<int> new_string;					// 0 제거 후의 string
	int length = 0, var_ejin = 0;			// new_string의 길이, 이진수 한 비트
	int cnt_zero = 0, cnt_trans = 0;		// 결과값

	while (1) {
		for (int i = 0; i < s.size(); i++) {	// 0 제거하기, 제거한 횟수 카운트
			if (s[i] == '1') new_string.push_back(1);
			else if (s[i] == '0') cnt_zero++;
		}
		s.clear();							// 문자열 초기화
		length = new_string.size();
		while (length != 0) {				// 이진수 변환
			var_ejin = length % 2;
			e_jin.push_back(to_string(var_ejin));
			length /= 2;
		}
		new_string.clear();					// 0 제거 후의 string 초기화
		for (int j = e_jin.size() - 1; j >= 0; j--) {	// 이진 변환한 새로운 문자열 만들기
			s += e_jin.at(j);
		}
		cnt_trans++;						// 변환 카운트 증가
		e_jin.clear();
		if (s.size() == 1) break;			// 최종 변환이 1이 되면 반복문 탈출
	}
	answer.push_back(cnt_trans);
	answer.push_back(cnt_zero);
	// cout << answer[0] << ' ' << answer[1] << endl;
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	solution("1111111");
	return 0;
}
