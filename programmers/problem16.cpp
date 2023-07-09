#include <iostream>
#include <stack>
using namespace std;

stack<char> temp;

int solution(string s)
{
	int answer = -1;
	int i = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			temp.push(s[0]);
		}
		else {
			if (temp.empty() || temp.top() != s[i]) {
				temp.push(s[i]);
			}
			else {
				temp.pop();
			}
		}
	}
	if (temp.empty()) answer = 1;
	else answer = 0;

	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution("baabaa") << endl;
	return 0;
}
