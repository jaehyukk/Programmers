// 백트래킹->시간초과, dp로 해결
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int size = land.size();
    vector<vector<int>> dp(land);
    
    
    for(int i = 1; i < size; i++){
        dp[i][0] = land[i][0] + max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][3]);
        dp[i][1] = land[i][1] + max(max(dp[i-1][0], dp[i-1][2]), dp[i-1][3]);
        dp[i][2] = land[i][2] + max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][3]);
        dp[i][3] = land[i][3] + max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
    }
    
    for(int i = 0; i < 4; i++){
        answer = max(answer, dp[size - 1][i]);   
    }

    return answer;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = 0, temp = 0;

void dfs(vector<vector<int>> &vec, int row, int col, int score){
    score += vec[row][col];
    temp = vec[row][col];
    
    result = max(result, score);

    if(row + 1 == vec.size()) return;
    
    for(int j = 0; j < 4; j++){
        if(j == col){
            continue;
        }
        dfs(vec, row + 1, j, score);
    }
}


int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    for(int i = 0; i < 4; i++){
        dfs(land, 0, i, 0);
    }
    answer = result;
    
    return answer;
}*/
