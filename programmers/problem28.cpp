#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
deque<string> cache;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0){
        answer = cities.size() * 5;
        return answer;
    }
    
    for(int i = 0; i < cities.size(); i++){
        // 소문자 변환
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        auto iter = find(cache.begin(), cache.end(), cities[i]);
        
        if(iter == cache.end()){    // cache miss
            if(cache.size() == cacheSize){
                cache.pop_front();
            }
            cache.push_back(cities[i]);
            answer += 5;
        }
        else{                        // cache hit
            cache.erase(iter);
            cache.push_back(cities[i]);
            answer += 1;
        }
    }
    return answer;
}
