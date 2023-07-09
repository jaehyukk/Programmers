#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 50;
bool check[51] = {false, };

void dfs(string begin, string target, vector<string> &words, int cnt){
    if(begin == target){
        answer = min(answer, cnt);
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        int temp = 0;
        for(int j = 0; j < words[i].size(); j++){
            if(begin[j] == words[i][j]) temp++;
        }
            if(temp == words[i].size() - 1){
                if(check[i] == false){
                    check[i] = true;
                    dfs(words[i], target, words, cnt + 1);
                    check[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {    
    dfs(begin, target, words, 0);
    if(answer == 50) answer = 0;
    
    return answer;
}
