//그리디, 3진법
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string solution(int n) {
	string answer = "";
	vector<string> temp;		// 숫자 하나씩 저장할 동적배열

	while (n != 0) {
		int remainder = n % 3;	// 나머지로 들어갈 숫자 알아보기
		if (remainder == 0) n--; // 반례) 24 => 422 나옴

		string char_remainder = to_string(remainder);
		if (char_remainder == "0") temp.push_back("4"); // 나머지가 0이면 숫자 4 대입
		else if (char_remainder == "1" || char_remainder == "2") temp.push_back(char_remainder); // 나머지가 1 또는 2면 해당 숫자 대입
		n /= 3;					// 다시 3 나누기
	}

	for (int i = temp.size() - 1; i >= 0; i--) {	// 숫자열 answer에 합치기
		answer += temp[i];	
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution(24) << '\n';
	return 0;
}
