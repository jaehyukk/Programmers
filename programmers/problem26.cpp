#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i = left; i <= right; i++){
        int quote = i / n;
        int mod = i % n;
        
        int result = max(quote, mod) + 1;
        answer.push_back(result);
    }
    
    return answer;
}
