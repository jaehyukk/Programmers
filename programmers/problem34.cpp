#include <string>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
    map<string, pair<int, int>> m;
    int answer = 0, same = 0;
    
    // 문자열 대문자 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    // str1 문자열 2개씩 자르기
    int cnt1 = 0; // 집합 str1 원소 개수
    for(int i = 0; i < str1.size() - 1; i++){
        string temp1 = str1.substr(i, 2);
        if(isalpha(temp1[0]) && isalpha(temp1[1])){ // 모두 알파벳인 경우
            m[temp1].first++;
            cnt1++;
        }
        else continue;
    }
    int cnt2 = 0; // 집합 str2 원소 개수
    for(int j = 0; j < str2.size() - 1; j++){
        string temp2 = str2.substr(j, 2);
        if(isalpha(temp2[0]) && isalpha(temp2[1])){
            m[temp2].second++;
            cnt2++;
            if(m[temp2].first > 0){ // 교집합인 경우
                if(m[temp2].first < m[temp2].second){ // 중복 문자열 중 교집합 개수 초과한 경우
                    continue;
                }
                same++; // 교집합 원소 개수 증가
            }
        }
        else continue;
    }
    int sum = cnt1 + cnt2 - same; // 합집합

    if(same == 0 && sum == 0) answer = 65536;
	else answer = 65536 * same / sum;
    
    return answer;
}
