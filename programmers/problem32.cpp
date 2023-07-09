#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> value;
    queue<int> q;
    int cnt = 0;
    
    for(int i = 0; i < progresses.size(); i++){ // queue와 vector에 progresses 담기
        q.push(progresses[i]);
        value.push_back(progresses[i]);
    }
    
    while(!q.empty()){  // q가 비어 있지 않을 동안
        for(int i = 0; i < q.size(); i++){
            if(value[i] >= 100) continue;   // 기능 값이 100 이상이면
            value[i] += speeds[i];
        }
        
        //int size = q.size();
        for(int i = 0; i < q.size(); i++){
            if(value[0] < 100) break;
            else if(value[0] >= 100){   // 맨 앞만 100 이상인지 탐색
                q.pop();
                value.erase(value.begin());
                speeds.erase(speeds.begin());
                cnt++;
            }
        }
        if(cnt > 0){
            answer.push_back(cnt);
            cnt = 0;
        }
    }
    
    return answer;
}
