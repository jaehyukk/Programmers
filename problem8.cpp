#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	stringstream ss(s);
	string temp;
	int idx = 0, blank = 0;
	// idx : 문자열 s에서 공백을 넣어주기 위해 일일이 카운트할 인덱스
	// blank : 공백 갯수 판별해줄 변수

	while (ss >> temp) {
		for (int i = 0; i < temp.size(); i++) {
			if (i == 0) temp[i] = toupper(temp[i]);		// 첫 글자는 대문자로 바꾸기
			else temp[i] = tolower(temp[i]);			// 첫 글자 제외한 나머지 글자는 소문자로 바꾸기
		}
		idx += temp.size();				// 문자열 s에서 공백있는 인덱스로 이동하기 위함
		while (s[idx] == ' ') {			// 공백 갯수 세어주기
			blank++;					// 공백 1개 씩 증가
			idx++;						// 인덱스도 1씩 증가
		}
		answer = answer + temp;			// 바꾼 문자열 넣기
		for (int j = 0; j < blank; j++) {
			answer += ' ';				// 세준 공백 갯수만큼 넣기
		}
		blank = 0;						// 공백 갯수 초기화
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution("for  the last week ") << '\n';
	return 0;
}
