//
//  [SW] 2018_budget.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/06.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> d = {2,2,3,3};
int budget = 10;
int result = 0;

int main(){
    sort(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++){
        if(budget - d.at(i) >= 0){
            budget -= d.at(i);
            result++;
        }
    }
    cout << result << '\n';
    return 0;
}
