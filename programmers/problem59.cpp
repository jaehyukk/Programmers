// dp
// 첫 번째 시도 : 완전탐색으로 풀었다가 시간초과
// 두 번째 시도 : 각 인덱스 별로 답을 넣고 피보나치 형태로 더하가는 방식

#include <string>
#include <vector>

using namespace std;

long long dp[60001] = {0, };

int solution(int n) {
    long long answer = 0;
    
    // n이 1일 때와 2인 경우 값 대입
    dp[1] = 1;
    dp[2] = 2;
    
    // 나머지 n의 경우 모두 대입
    for(int i = 3; i < 60001; i++){
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
    }
    answer = dp[n];
    
    return answer;
}
