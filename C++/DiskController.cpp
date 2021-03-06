//
//  DiskController.cpp
//  SOMAπ©π»βπ»
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
    
    sort(jobs.begin(), jobs.end()); // μμ μμμκ° μ§§μ μμΌλ‘ μ λ ¬
    while(taskCnt < jobs.size() || !pq.empty()){
        if (taskCnt < jobs.size() && jobs[taskCnt][0] <= curTime) {
            //μμ²­λλ μμ μκ°μ΄ νμ¬ μκ°λ³΄λ€ μμμΌ μμ μν κ°λ₯
            pq.push(jobs[taskCnt++]);
            continue;
        }
        if(!pq.empty()) {
            curTime += pq.top()[1]; //μμ μκ°
            answer += curTime - pq.top()[0];//μμ²­ μμ 
            pq.pop();
        }else {
           //  curTime > job[taskCnt] && pq λΉμ΄ μλ κ²½μ°
            // μ¦ κ²ΉμΉμ§ μλ κ²½μ° -> νμ¬ μκ° λ€μ μμμ΄ λ€μ΄μ€λ μκ°μΌλ‘ λ³κ²½
            curTime = jobs[taskCnt][0];
        }
    }
    
//    for(int i = 0; i < jobs.size(); i++) {
//        int start = jobs[i][0];
//        int time = jobs[i][1];
//        if (start == 0) { answer += time; }
//    }
    return answer/jobs.size();  // νκ·  μκ° λ°ν
}

int main(){
    
    return 0;
}
