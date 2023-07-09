#include <iostream>
#include <string>
#include <vector>
#include <stack>
//#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> s;
    
    // stack에 prices의 인덱스를 넣으며 비교
    for(int i = 0; i < prices.size(); i++){
        while(!s.empty() && prices[s.top()] > prices[i]){   // 가격이 떨어진 주식 시간 계산
            int temp = i - s.top();
            answer[s.top()] = temp;
            s.pop();
        }
        s.push(i);
    }
    
    // 가격이 떨어지지 않은 주식의 시간 계산
    int size = s.size();
    for(int i = 0; i < size; i++){
        if(s.empty()) break;

        int value = s.top();
        answer[value] = prices.size() - value - 1;
        s.pop();
    }
    
    return answer;
    
    
    
    
    
    /*
    queue<int> q;
    for(int i = 0; i < prices.size(); i++){
        q.push(prices[i]);
    }
    
    for(int i = 0; i < prices.size(); i++){
        int temp = q.front();
        int cnt = 0;
        q.pop();
        for(int j = 0; j < q.size(); j++){
            if(temp > prices[j + i]) break;
            cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
    */
}
