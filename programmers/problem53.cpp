#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct filelist{
    string head;
    int number;
    int index;
};
vector<filelist> vec;

bool cmp(filelist &f1, filelist &f2){
    if(f1.head == f2.head){
        if(f1.number == f2.number){
            return f1.index < f2.index;
        }
        else return f1.number < f2.number; 
    }
    else return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    bool check = false;
    
    for(int i = 0; i < files.size(); i++){
        int index_temp, cnt = 0;
        string temp1 = "", temp2 = "";
        for(int j = 0; j < files[i].size(); j++){
            if(files[i][j] >= '0' && files[i][j] <= '9'){
                if(check == false){
                    for(int k = 0; k < j; k++){
                        temp1 += tolower(files[i][k]);
                    }
                    index_temp = j;
                    check = true;
                }
                cnt++;
            }
        }
        temp2 = files[i].substr(index_temp, cnt);
        check = false;
        cnt = 0;
        
        filelist f;
        f.head = temp1;
        f.number = stoi(temp2);
        f.index = i;
        vec.push_back(f);
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < vec.size(); i++){
        answer.push_back(files[vec[i].index]);
    }
    
    return answer;
}
