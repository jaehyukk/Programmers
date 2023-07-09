#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
	int answer = 0;
	int lcm = 0; int temp = 0;
	for (int i = 0; i < arr_len - 1; i++) {
		temp = gcd(arr[i], arr[i + 1]);
		lcm = (arr[i] * arr[i + 1]) / temp;
		arr[i + 1] = lcm;
	}

	answer = lcm;
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int sample[4] = { 2, 6, 8 ,14 };

	cout << solution(sample, 4) << endl;
	return 0;
}
