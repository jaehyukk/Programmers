#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> temp;

int solution(string s) {
	int answer = 0;
	bool flag = false;

	for (int j = 0; j < s.size(); j++) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				temp.push(s[i]);
				flag = true;
			}
			else {
				if (temp.empty()) {
                    flag = false;
                    break;
                }
				else {
					if (s[i] == ')' && temp.top() == '(') {
						temp.pop();
					}
					else if (s[i] == '}' && temp.top() == '{') {
						temp.pop();
					}
					else if (s[i] == ']' && temp.top() == '[') {
						temp.pop();
					}
				}
			}
		}
		if (temp.empty() && flag){
            answer++;
        }
		char char_temp = s.front();
		s.erase(s.begin());
		s.push_back(char_temp);
		flag = false;
	}

	return answer;
}
