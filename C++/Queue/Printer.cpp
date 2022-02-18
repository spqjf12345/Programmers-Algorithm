//
//  Printer.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
     int answer = 0;
    for(int i = 0; i < (int)priorities.size(); i++){
        q.push({priorities[i], i}); // 문서, 인덱스
        pq.push(priorities[i]);
    }

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        if(current.first == pq.top()){
            pq.pop();
            answer+= 1;
            
            if(current.second == location){ // 원하는 index의 문서라면 answer 출력
                break;
            }
        }else { // 아닐시 뒤에 넣는다.
            q.push(current);
        }
    }

    return answer;
}
