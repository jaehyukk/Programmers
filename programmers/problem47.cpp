#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> car;
    map<string, int> total_time;
    map<string, int> inout;
    string time, number, situation;
    
    for(int i = 0; i < records.size(); i++){
        istringstream iss(records[i]);
        iss >> time >> number >> situation;
        int cal_time = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        
        if(situation == "IN"){
            car[number] = cal_time;
            inout[number] = 1;
        }
        else{
            total_time[number] += cal_time - car[number];
            inout[number] = 0;
        }
    }
    
    for(auto iter : car){
        if(inout[iter.first] == 1){
            total_time[iter.first] += 1439 - car[iter.first];
        }
    }
    
    for(auto iter : car){
        if(total_time[iter.first] <= fees[0]){
            answer.push_back(fees[1]);
        }
        else{
            int money = ceil(double(total_time[iter.first] - fees[0]) / fees[2]) * fees[3] + fees[1];
            cout << total_time[iter.first] <<  ' ';
            answer.push_back(money);
        }
    }
    
    
    return answer;
}
