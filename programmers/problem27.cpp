#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> answer_temp;
    
    int length = arr2[0].size();
    int cnt = 0;
    int temp = 0;
    
    for(int i = 0; i < arr1.size(); i++){   // 3
        for(int j = 0; j < length; j++){   // 2
            while(cnt != arr2.size()){
                temp += arr1[i][cnt] * arr2[cnt][j];
                cnt++;
            }
            answer_temp.push_back(temp);
            cnt = 0;
            temp = 0;
        }
        answer.push_back(answer_temp);
        answer_temp.clear();
    }
    return answer;
}
