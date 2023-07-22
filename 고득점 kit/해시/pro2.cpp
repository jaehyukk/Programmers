// hash
// 첫 번째 시도 : 완전탐색, 시간 초과
// 두 번째 시도 : 해시

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // map에 참가자 대입
    int size1 = participant.size();
    for(int i = 0; i < size1; i++){
        string temp = participant[i];
        if(um.find(temp) == um.end()) um[temp] = 1;
        else um[temp]++;
    }
    
    // 완주자 한 명씩 비교해가며 map에서 삭제
    int size2 = completion.size();
    for(int i = 0; i < size2; i++){
        string temp = completion[i];
        if(um.find(temp) != um.end()) {
            if(um[temp] == 1) um.erase(temp);
            else um[temp]--;
        }
    }
    
    // map에서 남아있는 키값 출력
    answer = um.begin()->first; 
    
    return answer;
}
