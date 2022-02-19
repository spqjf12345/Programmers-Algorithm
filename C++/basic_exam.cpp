//
//  basic_exam.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/19.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> re;
    
    int oneCount = 0;
    int twoCount = 0;
    int threeCount = 0;
    
    int one[5] = {1, 2, 3, 4, 5};
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < (int)answers.size(); i++){
        if(answers[i] == one[i % 5]){
            oneCount++;
        }
        if(answers[i] == two[i % 8]){
           twoCount++;
        }
        if(answers[i] == three[i % 10]){
          threeCount++;
        }
    }
    
    int maxCount = max(oneCount, max(twoCount, threeCount));
    if(maxCount == oneCount) re.push_back(1);
    if(maxCount == twoCount) re.push_back(2);
    if(maxCount == threeCount) re.push_back(3);

    return re;
}
