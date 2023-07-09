#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> &a, pair<int, string> &b){
    return b.first > a.first;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int, string>> temp;     
    // int: 자른 문자열 크기 저장, string: 자른 문자열 저장
    string token;
    unordered_map<string, int> tuple;
    stringstream ss(s);
    
    while(getline(ss, token, '}')) {    // '}' 기준으로 문자열 자르기
        temp.push_back({token.size(), token});
    }
    sort(temp.begin(), temp.end(), compare);    // 원소 개수 대로 오름차순 정렬
    token = "";     // token 원소 재사용을 위해 초기화
    
    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp[i].first; j++){
            char temp_char = temp[i].second[j];
            if(temp_char != '{' && temp_char != ','){   // 숫자일 경우
                token += temp_char;
            }
            else{   // '{' 또는 ',' 일 경우
                if(token != ""){ // 문자열 마지막에 '}}'일 경우 방지
                    if(tuple.find(token) == tuple.end()) {  // tuple에 숫자가 없을 경우
                        tuple.insert({token, i});
                        answer.push_back(stoi(token));
                        token = "";
                    }
                    else {  // tuple에 숫자가 있을 경우
                        token = "";
                        continue;
                    }
                }
            }
        }
        // 튜플에 마지막 숫자를 넣기 위한 조건문
        if(i == temp.size() - 1 && token != "" && answer.size() != temp.size() - 1){
            answer.push_back(stoi(token));
        }
    }
    
    return answer;
}
