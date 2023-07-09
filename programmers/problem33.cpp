#include <vector>
#include <queue>

using namespace std;
queue<pair<int,int>> q;
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0;        // 프린트 순서 매기는 변수

    for(int i = 0; i < priorities.size(); i++){ // 큐와 우선순위 큐에 원소 쌓기
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int x = q.front().first;        // 원소의 값
        int check = q.front().second;   // 원소의 인덱스
        int maxi = pq.top();            // 원소 최대값
        
        q.pop();
        if(x < maxi) q.push({x, check});    // 대기 목록 맨 뒤로 보내기
        else {
            cnt++;      // 순서 증가
            pq.pop();
            if(check == location){
                answer = cnt;
                break;
            }
        }
    }
    
    return answer;
}
