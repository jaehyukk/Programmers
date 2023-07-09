#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    int cnt = 0;
    while(!pq.empty()){
        if(pq.size() == 1 && pq.top() < K) return -1;   // 모든 음식의 지수를 K 이상으로 못 만드는 경우
        if(pq.top() >= K) break;
        
        int one = pq.top();
        pq.pop();
        int two = pq.top();
        pq.pop();
        
        int standard = one + (two * 2);
        pq.push(standard);
        cnt++;
    }
    answer = cnt;
    
    return answer;
}
