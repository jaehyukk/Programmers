#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;

bool compare(int d1, int d2){
    return d1 > d2;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i = 0; i < operations.size(); i++){
        if(operations[i][0] == 'I'){
            if(operations[i][2] == '-'){
                int num = stoi(operations[i].substr(3, operations[i].size() - 1)) * (-1);
                dq.push_back(num);
            }
            else{
                int num = stoi(operations[i].substr(2, operations[i].size() - 1));
                dq.push_back(num);
            }
        }
        else if(operations[i][0] == 'D'){
            if(dq.empty()) continue;
            if(operations[i][2] == '-'){
                dq.pop_back();
            }
            else{
                dq.pop_front();
            }
        }
        sort(dq.begin(), dq.end(), compare);
    }
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.front());
        answer.push_back(dq.back());
    }
    
    return answer;
}
