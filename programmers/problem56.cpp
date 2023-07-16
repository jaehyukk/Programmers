// bfs 
// 1번째 시도 : 시간 초과
// 상대 팀 진영에 도달하지 못하는 경우 추가
// 2번째 시도 : 효율성 테스트 실패
// 상대 팀 진영에 도달하지 못하는 경우, 도달했을 경우에서 코드 수정
// 도달했을 경우에 더이상 bfs를 진행하지 않고 바로 return하여 값 반환하는 것이 포인트!


#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

queue<tuple<int, int, int>> q;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int graph[101][101] = { 0, };
bool visited[101][101] = { false , };
int dis = 201;


int bfs(int x, int y, int cnt, int n, int m) {
	q.push({ x, y, cnt });
	visited[y][x] = true;
	
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();

		// 목표 지점에 도달했을 경우
		if (y == n - 1 && x == m - 1) {
			return cnt;
		}

		// 상하좌우 탐색
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 맵을 벗어났을 경우
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

			// 벽이거나 이미 방문한 칸일 경우
			if (graph[ny][nx] == 0 || visited[ny][nx] == true) continue;

			// 그 외 경우
			if (graph[ny][nx] == 1) {
				visited[ny][nx] = true;
				q.push({ nx, ny, cnt + 1});
			}
		}
		// 상대팀 진영에 도달하지 못하는 경우
		if (q.empty()) return -1;
	}
	return dis;
}

int solution(vector<vector<int>> maps) {
	int answer = 0;
	int xsize = maps[0].size();
	int ysize = maps.size();

	// 맵에 값 대입
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			graph[i][j] = maps[i][j];
		}
	}

	// 아니라면 bfs 돌리기
	answer = bfs(0, 0, 1, ysize, xsize);

	cout << answer << '\n';

	return answer;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin.sync_with_stdio(false);

	vector<vector<int>> map{
	{1,0,1,1,1}, {1,0,1,0,1}, {1,0,1,1,1}, {1,1,1,0,1},{0,0,0,0,1}
	};

	solution(map);

	return 0;
}


