#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check = false;     // 제거할 블록이 있는지 체크
    vector<vector<bool>> graph(m, vector<bool>(n, false));  // 제거해야 할 블록 표시용도
    
    while(1){
        // 제거할 블록을 true로 만들어주며 일일이 체크
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char temp = board[i][j];
                if(i + 1 >= m || j + 1 >= n || board[i][j] == '0') continue;
                if(temp == board[i+1][j] && temp == board[i][j+1] && temp == board[i+1][j+1]){
                    graph[i][j] = true;
                    graph[i+1][j] = true;
                    graph[i][j+1] = true;
                    graph[i+1][j+1] = true;
                    check = true;
                }
            }
        }
        if(check == false) break;   // 더이상 제거할 블록이 없을 경우

        // 블록 제거
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(graph[i][j] == true){
                    board[i][j] = '0';
                    graph[i][j] = false;
                    answer++;

                }
            }
        }
        // 블록 빈 공간 채우기(배열 맨 끝부터 거꾸로 탐색)
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(board[i][j] == '0'){
                    for(int k = i; k >= 0; k--){    // 행만 위로 한 칸씩 이동시키며 찾기
                        if(board[k][j] != '0'){
                            board[i][j] = board[k][j];
                            board[k][j] = '0';
                            break;
                        }
                    }
                }
            }
        }

        check = false;
    }  
    return answer;
}
