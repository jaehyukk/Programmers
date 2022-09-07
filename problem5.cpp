#include<iostream>
using namespace std;

long long gcd(int x, int y) {	// 최대공약수 구하기
	long long num = 0;
	while (x % y != 0) {		// 유클리드 호제법 이용
		long long temp = 0;
		temp = x % y;
		x = y;
		y = temp;
	}
	num = y;
	return num;
}

long long solution(int w, int h) {
	long long answer = 1;
	long long divisor = gcd(w, h);

	long long nw = w / divisor;		// 만들 수 있는 가장 작은 비의 가로 길이
	long long nh = h / divisor;		// 만들 수 있는 가장 작은 비의 세로 길이
	long long cnt = nw + nh - 1;	// 규칙 : 가로 + 세로 - 1
	long long sub = cnt * divisor;	// 반복된 횟수 만큼 곱하기
	answer = (long long)w * h - sub;	// 전체 정사각형 갯수 - 사용할 수 없는 정사각형 갯수

	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution(8, 12) << '\n';
	return 0;
}
