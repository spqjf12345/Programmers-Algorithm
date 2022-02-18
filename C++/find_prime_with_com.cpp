//
//  make_prime.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/04.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n){
    if (n <= 2) return false;
    int num = sqrt(n);
    for(int i = 2; i <= num; i++){
        if(n % i == 0) return false;
    }
    return true;
}

bool visit[1000];
int answer = 0;

void sum(vector<int> nums){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
          if (visit[i] == true)
          {
              cout <<nums[i] << " ";
              sum += nums[i];
              
          }
    }
    
    if(isPrime(sum)){
        answer++;
    }
    cout << endl;
}

//dfs를 이용해 조합 만들기 nC3
void DFS(vector<int> nums, int idx, int cnt)
{
    if (cnt == 3){
        sum(nums);
        return;
    }
 
    for (int i = idx; i < nums.size(); i++){
        if (visit[i] == true) continue;
        visit[i] = true;
        DFS(nums, i, cnt + 1);
        visit[i] = false;
    }
}



int main(){
    vector<int> nums = {1,2,7,6,4};
    DFS(nums, 0, 0);
    cout << answer << '\n';
    return 0;
}
