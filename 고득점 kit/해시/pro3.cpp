// hash, 완전탐색
// 첫 번째 시도 : 시간초과
// hash 하나로 key에 genres, value에 vector 형태로 sum과 plays를 대입
// 두 번째 시도 : hash 1개, vector 1개 이용
// 총 소요 시간 : 2h 56m
// hash와 vec를 모두 정렬 후, 원래 주어지는 genres와 연결지어 완전탐색할 생각을 못함

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um;  // genres, sum
vector<pair<int, int>> vec;     // index, plays

bool comp2(pair<string, int> &a, pair<string, int> &b){
    return a.second > b.second;
}

bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int size = genres.size();
    // hash와 vector에 각 정보 담기
    for(int i = 0; i < size; i++){
        string temp = genres[i];
        um[temp] += plays[i];
        vec.push_back({i, plays[i]});
    }
    
    // temp에 hash 정보 옮기기(sort를 위함)
    vector<pair<string, int>> temp(um.begin(), um.end());
    sort(vec.begin(), vec.end(), comp);
    sort(temp.begin(), temp.end(), comp2);
    
    // 가장 sum 높은 것부터 탐색
    for(auto iter : temp){
        int cnt = 0;
        // 인덱스와 genres의 인덱스 비교 => 이미 vec에서 정렬, 먼저 찾는게 plays 우선순위
        for(auto iter2 : vec){
            if(iter.first == genres[iter2.first]){
                answer.push_back(iter2.first);
                cnt++;
                // 2개까지만 담기
                if(cnt == 2) break;
            }
        }
    }
    
    return answer;
}
