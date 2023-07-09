#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "0";      // 10진수 0일 때 미리 넣어둠

    for(int i = 1; i <= t * m; i++){  // 나올 수 있는 모든 숫자를 진수에 맞춰 담기
        int num = i, mod = 0;
        string str_num = "";
        
        // 10진수 숫자를 n진수로 나눈 나머지를 하나씩 저장하는 방식
        while(1){
            if(num == 0) break;
            
            mod = num % n;
            num /= n;
            
            if(n >= 10 && mod >= 10){   // 10진수 이상이거나 나머지가 10보다 큰 경우, 알파벳 변환
                str_num += char(mod + 55);
            }
            else{
                str_num += to_string(mod);
            }
        }
        reverse(str_num.begin(), str_num.end());    // 바꾼 10진수 숫자마다 문자열 바꾸기
        temp += str_num;          // n진수로 바꾼 문자열 추가
    }
    
    // 원하는 순서마다 숫자 뽑아내는 반복문
    int cnt = p;
    for(int i = 1; i <= t * m; i++){
        if(i == cnt){
            answer += temp[i - 1];
            cnt += m;
        }
    }
    
    return answer;
}
