#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> number;
    
    sort(phone_book.begin(), phone_book.end()); // 맨앞 숫자 기준으로 오름차순 정렬
    for(int i = 0; i < phone_book.size(); i++){
        number.insert({phone_book[i], phone_book[i].size()});   // hash-map에 순서대로 삽입
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        string temp = "";
        for(int j = 0; j < phone_book[i].size(); j++){  // temp에 문자 하나 씩 넣어가며 비교
            temp += phone_book[i][j];
            if(number[temp] != 0 && temp.size() != number[phone_book[i]]){
                return false;
            }
        }
    }
    
    return answer;
}
