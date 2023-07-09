#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[201] = {false, };

void dfs(vector<vector<int>> &vec, int x){
    for(int i = 0; i < vec[i].size(); i++){
        if(vec[x][i] == 1 && visited[i] == false){
            visited[i] = true;
            dfs(vec, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            dfs(computers, i);
            answer++;
        }
    }
    
    return answer;
}
