//
//  [SW] 2018_numberGame.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/06.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int answer = 0;
    vector<int> A = {5,1,3,7};
    vector<int> B = {2,2,6,8};
    
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);

    if(A[A.size() - 1] >= B[0]){
        return 0;
    }
    
    int iterA = 0;
    int iterB = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[iterA] < B[iterB]){
            answer++;
            iterB++;
        }
        iterA++;
    }

    cout << answer << '\n';
    return 0;
}
