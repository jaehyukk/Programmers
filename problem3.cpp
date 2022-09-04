#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[101][101];
int number_of_area;
int max_size_of_one_area;
int size_of_one_area;
int temp;

bool dfs(int y, int x, int m, int n) {
	if (y < 0 || x < 0 || y >= m || x >= n) return false;

	if (graph[y][x] == 0) return false;

	if (graph[y][x] == temp) {
		graph[y][x] = 0;
		size_of_one_area++;
		dfs(y + 1, x, m, n);
		dfs(y - 1, x, m, n);
		dfs(y, x - 1, m, n);
		dfs(y, x + 1, m, n);
		return true;
	}
	return false;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> area;
	number_of_area = 0;
	max_size_of_one_area = 0;
	size_of_one_area = 0;
	temp = 0;
	fill(&graph[0][0], &graph[m][n], 0);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = picture[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp = graph[i][j];
			if (dfs(i, j, m, n)) {
				number_of_area++;
				area.push_back(size_of_one_area);
				size_of_one_area = 0;
			}
		}
	}
	sort(begin(area), end(area), greater<int>());
	max_size_of_one_area = area.at(0);

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	vector<vector<int>> vec = { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} };

	vector<int> result = solution(6, 4, vec);
	cout << result[0] << ' ' << result[1] << endl;
	return 0;
}
