//
//  functionDevelopment_queue.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/01/06.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int num = (int)progresses.size();
    vector<int> days;
    vector<int> answer;
    
    queue<int> q;
    
    for(int i = 0; i < num; i++){
        int d = (100 - progresses[i]) / speeds[i];
        if(progresses[i] + d * speeds[i] < 100) { d++; }
        days.push_back(d);
    }
    
    ///initials
    q.push(days[0]);
    for(int i = 1; i< days.size(); i++){
        if(q.front() >= days[i]){
            q.push(days[i]); // 앞의 날짜와 묶어 생각
        }else{
           answer.push_back(q.size());
            while(!q.empty()){
                q.pop();
            }
            q.push(days[i]);
        }
    }
    
    if(!q.empty()) {
        answer.push_back(q.size());
    }
    
    return answer;
}
