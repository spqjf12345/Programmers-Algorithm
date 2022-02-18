//
//  functionDevelopment.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/06.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int n = (int)progresses.size();
    vector<int> days;
    vector<int> answer(n, 1);
    vector<int> re_answer;
    
    for(int i = 0; i < n; i++){
        int target = progresses[i];
        int num = speeds[i];
        int day = 0;
        while(target < 100){
            target += num;
            day++;
        }
        days.push_back(day);
    }

    int index = days[0];
    int indexNum = 0;
    for(int i = 1; i < n; i++){
        if(days[i] <= index){
            answer[indexNum] += 1;
            answer[i] = 0;
        }else {
            index = days[i];
            indexNum = i;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(answer[i] > 0) {
          re_answer.push_back(answer[i]);
        }
    }
    
    return re_answer;
}

int main(){
    vector<int> test = {99, 99, 99};
    vector<int> speed = {1,1,1};
    vector<int> answer = solution(test, speed);
    for(int i =0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}
