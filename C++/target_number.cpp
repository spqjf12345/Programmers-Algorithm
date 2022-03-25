//
//  target_number.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/25.
//

#include <vector>
#include <iostream>

using namespace std;
int cnt = 0;

void dfs(vector<int> numbers, int target, int sum, int depth){
   // cout << sum << " " << depth << '\n';
    if(depth == numbers.size()){ // 종료 조건
        if(sum == target){
            cnt++;
        }
        return;
    }else {
        dfs(numbers, target, sum + numbers[depth], depth+1);
        dfs(numbers, target, sum - numbers[depth], depth+1);
    }
    
    
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return cnt;
}
