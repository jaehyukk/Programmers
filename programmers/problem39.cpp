#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<pair<int, int>> q;
int bfs(vector<int> &numbers, int y){
    int result = 0;
    q.push({numbers[0], 0});
    q.push({numbers[0] * (-1), 0});
    
    while(!q.empty()){
        int x = q.front().first;
        int index = q.front().second;
        q.pop();
        
        if(index == numbers.size() - 1){
            if(x == y){
                result++;
            }
        }
        else{
            q.push({x + numbers[index + 1], index + 1});
            q.push({x - numbers[index + 1], index + 1});
        }
    }
    return result;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = bfs(numbers, target);
    
    return answer;
}
