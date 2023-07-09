#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[101][101];						// picture 원소를 저장할 배열
int number_of_area;
int max_size_of_one_area;
int size_of_one_area;						// 구역별 크기
int temp;

bool dfs(int y, int x, int m, int n) {		// 깊이 우선 탐색 수행
	if (y < 0 || x < 0 || y >= m || x >= n) return false;	// 구역을 벗어날 경우 함수 탈출

	if (graph[y][x] == 0) return false;						// 그림 구역이 아닌 경우 함수 탈출

	if (graph[y][x] == temp) {								// 같은 값일 때 
		graph[y][x] = 0;									// 0 초기화
		size_of_one_area++;									// 구역 넓이 추가
		dfs(y + 1, x, m, n);								// 21 ~ 24 상하좌우로 재귀함수 구현
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
	fill(&graph[0][0], &graph[m][n], 0);		// graph 초기화

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = picture[i][j];		// picture -> graph 값 초기화
		}
	}

	for (int i = 0; i < m; i++) {				
		for (int j = 0; j < n; j++) {
			temp = graph[i][j];						// picture 원소 값을 temp에 저장
			if (dfs(i, j, m, n)) {					// dfs 수행하여 true일 경우
				number_of_area++;					// 구역의 수 1씩 증가
				area.push_back(size_of_one_area);	// 구역의 크기를 area 동적배열에 저장(내림차순 정렬 및 최댓값 출력을 위해)
				size_of_one_area = 0;				// 다시 초기화
			}
		}
	}
	sort(begin(area), end(area), greater<int>());	// 구역 크기에 대한 내림차순 정렬
	max_size_of_one_area = area.at(0);				// 그 중 가장 큰 값을 저장

	vector<int> answer(2);
	answer[0] = number_of_area;						// 구역의 수와 최대 구역 크기 저장
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
