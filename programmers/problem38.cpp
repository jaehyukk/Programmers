#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s) answer.push_back(-1);

    else{
        int quote = s / n;
        int mod = s % n;
        answer.assign(n, quote);

        if(mod != 0){
            for(int i = 0; i < mod; i++){
                answer[n - 1 - i]++;
            }
        }
    }
    
    return answer;
}
