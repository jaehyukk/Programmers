#include <iostream>

using namespace std;

int solution(int n)
{
	int ans = 0;
	int place = 0, mod = 0;

	while (n != 0) {
		mod = n % 2;
		n /= 2;
		ans += mod;
	}
	return ans;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cout << solution(5) << endl;

	return 0;
}


/*
#include <iostream>
#include <queue>

using namespace std;

long graph[100] = { 0, };
queue <pair<int, int>> q;

int bfs(int x, int y) {
	int place, use_battery = 0;

	q.push({ x, 0 });
	while (!q.empty()) {
		place = q.front().first;
		use_battery = q.front().second;
		q.pop();

		if (place == y) break;

		int case_place[2] = { place + 1, place * 2 };

		for (int i = 0; i < 2; i++) {
			if (graph[case_place[i]] == 0) {
				if (i == 0) {
					q.push({ case_place[0], use_battery + 1 });
					graph[case_place[0]] = 1;

				}
				else {
					q.push({ case_place[1], use_battery });
					graph[case_place[1]] = 1;
				}
			}
		}
	}
	return use_battery;
}


int solution(int n)
{
	int ans = 0;
	ans = bfs(0, n);

	return ans;
}
*/
