#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> vec;		// 한 숫자씩 저장할 동적배열
	stringstream ss(s);		// 공백마다 숫자 자르기 위함
	int num;				// 자른 하나의 숫자를 임시로 담을 변수

	while (ss >> num) {
		vec.push_back(num);		// 자를 때마다 숫자를 동적배열에 대입
	}
	sort(begin(vec), end(vec));	// 내림차순 정렬
	int start = vec[0];					// 가장 작은 값 저장
	int finish = vec[vec.size() - 1];	// 가장 큰 값 저장
	answer = to_string(start) +  ' ' + to_string(finish);	// 최종 출력값 저장

	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	string str = "123 -123 12345";

	cout << solution(str) << '\n';
	return 0;
}
