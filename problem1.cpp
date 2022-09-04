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
		temp = s.substr(0, i);
		cnt = 1;
		for (int j = i; j < length; j+=i) {
			if (temp == s.substr(j, i)) {
				cnt++;
			}
			else {
				if (cnt > 1) {
					result += to_string(cnt);
				}
				result += temp;
				temp = s.substr(j, i);	
				cnt = 1;
			}
		}
		if (cnt > 1) result += to_string(cnt);
		result += temp;

		int result_length = result.size();
		answer = min(result_length, answer);
		result.clear();
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	getline(cin, str);
	cout << solution(str) << '\n';

	return 0;
}
