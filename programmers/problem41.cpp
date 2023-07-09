#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string temp = "";
string number = "";
bool check(string temp) {
    long long temp_int = 0;
    
    // 문자열을 정수형으로 변환
    for(int i = 0; i < temp.size(); i++){
        temp_int += pow(10, i) * (temp[temp.size() - 1 - i] - '0');
    }
    if(temp_int == 1){
        return false;
    }
	for (long long i = 2; i * i <= temp_int; i++) { // 소수 판별
		if (temp_int % i == 0) {
			return false;
		}
	}
	return true;
}

int select() {  // 문자열 처음부터 숫자 하나씩 탐색
	int result = 0;
	for (int i = 0; i < number.size(); i++) {
		if (number[i] == '0') {
			if (temp != "") {
				if (check(temp) == true) {
					result++;
				}
				temp = "";
			}
		}
		else {
			temp += number[i];
            if(i == number.size() - 1){
                if(check(temp) == true) result++;
            }
		}
	}
	return result;
}

void trans(int n, int k) {
	while (n != 0) {    // number 문자열에 저장하기
		int quote = n % k;
		number += to_string(quote);
		n /= k;
	}
	reverse(number.begin(), number.end());     // 문자열 뒤집음
}

int solution(int n, int k) {
	int answer = -1;
	trans(n, k); // 진수로 변환
	answer = select();

	return answer;
}
