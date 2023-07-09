#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	vector<pair<int, int>> temp;					// num의 곱셈 case 저장할 동적배열
	int num = brown + yellow;						// brown과 yellow 더하기
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {							// 경우의 수 만들기 ex) 12 = 3 * 4
			int quote = num / i;					
			if (quote - 2 > 0 && i - 2 > 0) {
				temp.push_back({ i, quote });
			}
		}
	}
	for (int j = 0; j < temp.size(); j++) {			// 뽑아낸 경우의 수들에서 판별
		if ((temp[j].first - 2) * (temp[j].second - 2) == yellow) {		// (4 - 2) * (3 - 2) = 2 = yellow
			int one = max(temp[j].first, temp[j].second);		// 가로 길이
			int two = min(temp[j].first, temp[j].second);		// 세로 길이
			answer.push_back(one);
			answer.push_back(two);
			break;
		}
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	solution(24, 24);
	return 0;
}
