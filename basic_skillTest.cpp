//
//  basic_skillTest.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/30.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int answer = 0;
    for(int i =0; i < d.size(); i++){
        if(budget >= 0){
            if(budget < d[i]){
                answer -= 1;
            }
            budget -= d[i];
            answer += 1;
        }
        
    }
    
    return answer;
}
