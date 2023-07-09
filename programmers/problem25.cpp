#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> temp(elements);
    unordered_map<int, int> um;
    
    // 배열 원형으로 넣어주기 ex) 7 9 1 1 4 7 9 1 1
    for(int i = 0; i < elements.size() - 1; i++){
        temp.push_back(elements[i]);
    }
    
    int sum = 0;
    for(int i = 0; i < elements.size(); i++){
        for(int j = 0; j < elements.size(); j++){
            for(int k = j; k < i + j + 1; k++){     // 길이 별로 연속 부분 합 구하여 map에 넣기
                sum += temp[k];
            }
            um.insert({sum, i});
            sum = 0;
        }
    }
    answer = um.size();
    return answer;
}
