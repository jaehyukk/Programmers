#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, maxi = 0;
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < size; i++){
        for(int j = 0; j < size; j++){
            if(j == 0){
                int sum = triangle[i][j] + dp[i-1][j];
                dp[i][j] = sum;
            }
            else if(j == triangle[i].size() - 1){
                int sum = triangle[i][j] + dp[i-1][j-1];
                dp[i][j] = sum;
            }
            else{
                int sum1 = triangle[i][j] + dp[i-1][j-1];
                int sum2 = triangle[i][j] + dp[i-1][j];
                dp[i][j] = max(sum1, sum2);
            }
        }
    }
    
    for(int i = 0; i < size; i++){
        maxi = max(maxi, dp[size - 1][i]);
    }
    answer = maxi;
    
    return answer;
}
