#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int temp = 0;

    sort(citations.begin(), citations.end(), greater<int>());
    for(int i = 1; i <= citations.size(); i++){
        if(i > citations[i - 1]) break;
        answer++;
    }

    return answer;
}
