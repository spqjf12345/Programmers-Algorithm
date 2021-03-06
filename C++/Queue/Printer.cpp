//
//  Printer.cpp
//  SOMA๐ฉ๐ปโ๐ป
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
        q.push({priorities[i], i}); // ๋ฌธ์, ์ธ๋ฑ์ค
        pq.push(priorities[i]);
    }

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        if(current.first == pq.top()){
            pq.pop();
            answer+= 1;
            
            if(current.second == location){ // ์ํ๋ index์ ๋ฌธ์๋ผ๋ฉด answer ์ถ๋ ฅ
                break;
            }
        }else { // ์๋์ ๋ค์ ๋ฃ๋๋ค.
            q.push(current);
        }
    }

    return answer;
}
