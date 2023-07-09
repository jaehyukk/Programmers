#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(int i = 0; i < works.size(); i++){
        pq.push(works[i]);
    }
    for(int i = 0; i < n; i++){
        int temp = pq.top();
        if(temp == 0) break;
        
        pq.pop();
        temp -= 1;
        pq.push(temp);
    }
    
    int size = pq.size();
    for(int i = 0; i < size; i++){
        int temp = pq.top();
        answer += temp * temp;
        pq.pop();
    }
    
    return answer;
}
