#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int index(vector<char>& who, char data) {  // row 배열에서 해당 문자가 나타내는 인덱스 찾기
	int number = 0;
	for (int i = 0; i < who.size(); i++) {
		if (who[i] == data) {
			number = i;		// 인덱스를 number 변수에 저장
			break;
		}
	}
	return number;
}

int solution(int n, vector<string> data) {
	vector<char> row = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	int answer = 0; 
	int cnt = 0; // 입력받은 n개 가짓 수 중, 하나의 배열 순서에서 만족하는 가짓수를 나타내는 변수
	do {
		for (int i = 0; i < n; i++) {
			int one = index(row, data[i][0]); // 첫 번째 사람이 있는 인덱스
			int two = index(row, data[i][2]); // 두 번째 사람이 있는 인덱스
			int num = data[i][4] - '0' + 1;   // 두 사람 간의 간격 조건
			char mark = data[i][3];			  // 간격에 대한 부등호 저장
			int compare = abs(one - two);     // 두 사람 간의 간격

			if (mark == '=') {				// 입력받은 조건이 "=" 인 경우
				if (compare != num) break;  // 가짓수 중 하나라도 틀리면 반복문 탈출
				else cnt++;
			}
			else if (mark == '>') {			// 입력받은 조건이 ">" 인 경우
				if (compare <= num) break;
				else cnt++;
			}
			else if (mark == '<') {			// 입력받은 조건이 "<" 인 경우
				if (compare >= num) break;
				else cnt++;
			}
			if (cnt == n) {					// 하나의 배열에서 입력받은 가짓수를 모두 만족하는 경우
				answer++;
				cnt = 0;
			}
		} cnt = 0;
	} while (next_permutation(row.begin(), row.end())); // 순열 이용(모든 경우의 수에서 탐색, 완전탐색)
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	vector<string> str = { "N~F=0", "R~T>2" };
	solution(2, str);

	return 0;
}
