// brute force
// 수학적 규칙 찾아서 해결
// 1시간 10분 소요

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

unordered_map<char, int> m;
int multiplier[5] = { 781, 156, 31, 6, 1 };

void alpha_insert() {
    m.insert({ 'A', 1 });
    m.insert({ 'E', 2 });
    m.insert({ 'I', 3 });
    m.insert({ 'O', 4 });
    m.insert({ 'U', 5 });

    return;
}

int solution(string word) {
    int answer = 0;
    int size = word.size();

    alpha_insert();
    for (int i = 0; i < size; i++) {
        answer += (m[word[i]] - 1) * multiplier[i];
    }
    answer += size;
    return answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    cin.sync_with_stdio(false);

    cout << solution("AAAAE") << '\n';

    return 0;
}
