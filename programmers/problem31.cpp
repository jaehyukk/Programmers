// 투포인터, 완전탐색
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    map<string, int> temp;
    
    // 각 항목 별로 number 대입
    for(int i = 0; i < want.size(); i++){
        m[want[i]] = number[i];
        temp[want[i]] = number[i];
    }
    
    // 투포인터, 하나씩 탐색하면서 일치하는 품목이면 map 값 1씩 감소
    int start = 0, end = 9;
    for(int i = 0; i < discount.size() - 10 + 1; i++){
        for(int j = start; j <= end; j++){
            if(m.find(discount[j]) != m.end()){
                m[discount[j]]--;
            }
        }
        
        int cnt = 0;
        for(auto iter : m){
            if(m[iter.first] == 0){     // 할인 품목 모두 들어갔으면 0의 값을 가짐
                cnt++;
            }
            m[iter.first] = temp[iter.first];
            if(cnt == m.size()) answer++;
        }
        start++; end++;     // 다음 탐색 범위 조정
    }
    
    return answer;
}
