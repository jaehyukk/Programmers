#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	int sum = 0;			// 숫자 합
	int num = n / 2 + 1;	// 최초 인수 정해주기

	if (n == 1 || n == 2) return answer + 1;	// n=1, 2인 경우는 1로 출력

	while (num != 0) {
		int temp = num;
		for (int i = temp; i > 0; i--) { // 지정된 숫자부터 1까지 더해주는 반복문
			sum += i;
			if (sum == n) {		// 합이 n과 같은 경우
				answer++;
				break;
			}
			else if (sum > n) {	// 합이 n보다 큰 경우
				break;
			}
		}
		num--;
		sum = 0;
	}
	answer++;					// 자기 자신을 포함하는 경우
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution(15) << endl;
	return 0;
}
