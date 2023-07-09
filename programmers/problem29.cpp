// 경우의 수? 해시?

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> wear;

    for(int i = 0; i < clothes.size(); i++){
        if(wear.find(clothes[i][1]) == wear.end()) wear.insert({clothes[i][1], 1});
        else wear[clothes[i][1]]++;
    }
    for(auto iter = wear.begin(); iter != wear.end(); iter++){
        if(answer == 0) answer += iter->second;
        else answer += iter->second + (iter->second * answer);
    }
    
    return answer;
}
