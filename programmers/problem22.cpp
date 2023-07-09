#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b){   // 오름차순 정렬
    return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> um;    // <귤 크기, 개수>
    
    // 해쉬 맵에 각 귤 종류마다 1씩 증가시키며 담기
    for(int i = 0; i < tangerine.size(); i++){  
        um[tangerine[i]]++;
    }
    
    // value 기준으로 오름차순 정렬하기 위한 vector
    vector<pair<int,int>> vec(um.begin(), um.end());
    // 오름차순 정렬
    sort(vec.begin(), vec.end(), compare);
    // 가장 개수가 적은 귤부터 하나씩 제거
    for(int j = 0; j < tangerine.size() - k; j++){
        vec[0].second--;
        if(vec[0].second == 0){
            vec.erase(vec.begin());
        }
    }
    answer = vec.size();    // 남은 vec의 크기가 정답
    return answer;
}
