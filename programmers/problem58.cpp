// DP
// 첫번째 시도 : 시간초과, brute force 사용
// 두번째 시도 : DP 사용, 성공
// 31분 24초 소요, 힌트 참고

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    int size = numbers.size();
    
    for(int i = size - 2; i >= 0; i--){
        int num = numbers[i];
        for(int j = i + 1; j < size; j++){
            int cmp = numbers[j];
            
            // 바로 뒷 큰수일 경우
            if(num < cmp){
                answer[i] = cmp;
                break;
            }
            else{
                // 뒤에 큰 수가 없을 경우
                if(answer[j] == -1) break;
                // 다음 인덱스의 뒷 큰수가 더 큰 경우 
                else if(num < answer[j]){
                    answer[i] = answer[j];
                    break;
                }
            }
        }
    }
    
    return answer;
}
