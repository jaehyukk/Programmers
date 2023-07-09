#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include<tuple>
using namespace std;

vector<string> solution(vector<string> record) {
	string doing, id, name;
	vector<string> answer;
	vector<tuple<string, string, string>> vec;				// 행동, id, 이름 저장
	map<string, string> user;								 // id, 이름 저장

	for (int i = 0; i < record.size(); i++) {
		istringstream iss(record[i]);
		iss >> doing >> id >> name;							// 공백 기준으로 나누기

		if (doing != "Leave") user[id] = name;
		if (doing != "Change") vec.push_back({ doing, id, user[id] });
	}

	for (int i = 0; i < vec.size(); i++) {
		get<2>(vec[i]) = user[get<1>(vec[i])];				// change로 인해 바뀐 이름이 있다면 바꿔줌
	}

	for (int i = 0; i < vec.size(); i++) {					// answer에 출력할 문자열들 저장
		if (get<0>(vec[i]) == "Enter") {
			answer.push_back(get<2>(vec[i]) + "님이 들어왔습니다.");
		}
		else if (get<0>(vec[i]) == "Leave") {
			answer.push_back(get<2>(vec[i]) + "님이 나갔습니다.");
		}
	}
	return answer;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	vector<string> in = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

	vector<string> result = solution(in);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}
