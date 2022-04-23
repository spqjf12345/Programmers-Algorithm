//
//  DiskController.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] > v2[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int taskCnt = 0;
    int curTime = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    
    sort(jobs.begin(), jobs.end()); // 작업 소요시간 짧은 순으로 정렬
    while(taskCnt < jobs.size() || !pq.empty()){
        if (taskCnt < jobs.size() && jobs[taskCnt][0] <= curTime) {
            //요청되는 작업 시간이 현재 시간보다 작아야 작업 수행 가능
            pq.push(jobs[taskCnt++]);
            continue;
        }
        if(!pq.empty()) {
            curTime += pq.top()[1]; //소요 시간
            answer += curTime - pq.top()[0];//요청 시점
            pq.pop();
        }else {
           //  curTime > job[taskCnt] && pq 비어 있는 경우
            // 즉 겹치지 않는 경우 -> 현재 시간 다음 작업이 들어오는 시각으로 변경
            curTime = jobs[taskCnt][0];
        }
    }
    
//    for(int i = 0; i < jobs.size(); i++) {
//        int start = jobs[i][0];
//        int time = jobs[i][1];
//        if (start == 0) { answer += time; }
//    }
    return answer/jobs.size();  // 평균 시간 반환
}

int main(){
    
    return 0;
}
