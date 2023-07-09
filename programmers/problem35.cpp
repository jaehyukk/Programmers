#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int result = 0;
    int temp = k;
    
    sort(dungeons.begin(), dungeons.end());     // 오름차순 정렬
    
    // 각 경우의 수마다 탐색
    do{
        int cnt = 0;
        for(int i = 0; i < dungeons.size(); i++){
            int sub = dungeons[i][1];
            if(k < dungeons[i][0]) break;
            else{
                k -= sub;
                cnt++;
            }
        }
        answer = max(answer, cnt);
        k = temp;
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    
    
    return answer;
}
