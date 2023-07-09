// hashmap
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> um;
    
    for(int i = 1; i <= skill.size(); i++){
        um[skill[i - 1]] = i;
    }
    
    for(int i = 0; i < skill_trees.size(); i++){
        int cnt = 1;
        for(int j = 0; j < skill_trees[i].size(); j++){
            if(um[skill_trees[i][j]] == cnt){
                cnt++;
            }
            else if(um[skill_trees[i][j]] > cnt){
                cout << "@" << endl;
                break;
            }
            
            if(j == skill_trees[i].size() - 1){
                answer++;
            }
        }
    }
    
    return answer;
}





/* 완전탐색

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int func(string skill, string skill_tree){
    vector<int> skill_index(skill.size(), 0);   // 각 스킬이 위치한 인덱스를 담을 배열
    
    for(int i = 0; i < skill.size(); i++){  // 스킬트리 하나씩 비교
        for(int j = 0; j < skill_tree.size(); j++){     // skill 하나씩 비교
            if(skill[i] == skill_tree[j]){
                skill_index[i] = j + 1;     // 스킬이 있는 인덱스를 담기
                break;
            }
        }
    }
    
    for(int i = 0; i < skill.size() - 1; i++){
        // 선스킬의 인덱스가 후스킬보다 클 경우
        if(skill_index[i] >= skill_index[i + 1] && skill_index[i + 1] != 0) {
            return 0;
        }
        // 선스킬보다 후스킬이 먼저 나왔을 경우
        if(skill_index[i] == 0 && skill_index[i + 1] != 0){
            return 0;
        }
    }
    return 1;
}


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0; i < skill_trees.size(); i++){
        answer += func(skill, skill_trees[i]);
        cout << endl;
    }
    
    return answer;
}*/
