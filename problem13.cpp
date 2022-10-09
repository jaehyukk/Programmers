#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	int index = 0, cnt = 0, overflow = 0;
	
	while (index < s.size()) {							// 문자열 속 문자 하나 씩 탐색
		if (s[index] == '(') {							// '('이면 1 증가
			cnt += 1;
		}
		else if (s[index] == ')') {						// ')'이면 1 감소
			cnt -= 1;
			if (cnt < 0) overflow++;					// '('없이 ')'만 나올 경우 오버플로우
			if (cnt <= 0) cnt = 0;						// 반례: '))(('인 경우에도 합이 0이 되어 true 출력
		}
		index++;
	}
	if (cnt == 0 && overflow == 0) answer = true;		// 합이 0이고 오버플로우 없을 경우 true
	else answer = false;

	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	solution("(())()");
	return 0;
}
