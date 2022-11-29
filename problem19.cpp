#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;

	while (1) {
		a = (a / 2) + (a % 2);
		b = (b / 2) + (b % 2);
		if (a == b)
			return answer;
		else
			answer++;
	}
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution(8, 4, 7) << endl;

	return 0;
}
