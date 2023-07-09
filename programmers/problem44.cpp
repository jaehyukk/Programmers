#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    string temp = "";
    
    for(int i = 65; i < 91; i++){   // 사전 만들기, 아스키코드 활용
        temp += char(i);
        dic.insert({temp, i - 64});
        temp = "";
    }
    
    for(int i = 0; i < msg.size(); i++){
        temp = "";
        int cnt = 0;
        while(1){
            if(i + cnt >= msg.size()) break;
            
            temp += msg[i + cnt];
            if(dic.find(temp) == dic.end()){
                //cout << temp << dic.size() + 1 << endl;
                dic.insert({temp, dic.size() + 1});
                temp.erase(temp.size() - 1, 1);
                break;
            }
            cnt++;
        }
            answer.push_back(dic[temp]);
            i += temp.size() - 1;
    }
    
    return answer;
}
