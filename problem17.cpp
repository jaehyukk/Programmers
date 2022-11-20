#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	map<string, int> temp;
	
	for (int i = 0; i < words.size(); i++) {
		if (i == 0) {
			temp[words[0]]++;
		}
		else {
			if (temp[words[i]] || words[i - 1].back() != words[i].front()) {
				answer.push_back(i % n + 1);
				answer.push_back(i / n + 1);
				return answer;
			}
			else {
				temp[words[i]]++;
			}
		}
	}
	answer.push_back(0);
	answer.push_back(0);
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	vector<string> sample = { "hello", "one", "even", "never", "now", "world", "draw" };

	solution(1, sample);
	return 0;
}
