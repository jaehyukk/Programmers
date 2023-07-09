#include <string>
#include <map>
#include <iostream>
using namespace std;

map<pair<pair<int, int>, pair<int, int>>, bool> visited;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;   // 시작 지점을 (0,0)이 아닌 (5,5)로 지정
    int nx = 0, ny = 0; // 이동 후의 좌표
    
    for(int i = 0; i < dirs.size(); i++){
        if(dirs[i] == 'R'){     // 오른쪽 이동
            nx = x + dx[0];
            ny = y + dy[0];
        }
        else if(dirs[i] == 'L'){    // 왼쪽 이동
            nx = x + dx[1];
            ny = y + dy[1]; 
        }
        else if(dirs[i] == 'D'){    // 아래쪽 이동
            nx = x + dx[2];
            ny = y + dy[2]; 
        }
        else if(dirs[i] == 'U'){    // 위쪽이동
            nx = x + dx[3];
            ny = y + dy[3]; 
        }
        
        if(ny < 0 || nx < 0 || ny > 10 || nx > 10) continue;    // 그래프를 벗어날 경우
        
        if(visited[{{x,y},{nx,ny}}] != true){   // 양쪽 정점 기준으로 간선 등록
            visited[{{x,y},{nx,ny}}] = true;
            visited[{{nx,ny},{x,y}}] = true;
            answer++;
        }
        x = nx; y = ny;
    }
    
    return answer;
}
