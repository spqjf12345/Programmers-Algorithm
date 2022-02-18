//
//  [SW] 2018_delivery.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/01.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<vector<int>> road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
int d[100001]; // 최단 거리 테이블
vector<pair<int, int>> revect[51];

void del_djikstra(int start){
    priority_queue<pair<int, int>>pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    
    while(!pq.empty()){
        //우선 순위 큐는 가장 큰 원소 top으로 놓으므로
        //거리 작은 정점부터 꺼내지도록 하기
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < revect[now].size(); i++){
            //거쳐서 가는 노드의 비용을 계산
            int cost = dist + revect[now][i].second;
            if(cost < d[revect[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[revect[now][i].first] = cost;
                pq.push(make_pair(-cost, revect[now][i].first));
            }
        }
    }
    
}

int main(){
    int n = 5;
    int k = 3; // 배달 가능한 최대 시간
    int answer = 0;
    fill(d, d+100001, INF);
    for(int i = 0; i < road.size(); i++){
        revect[road[i][0]].push_back({road[i][1], road[i][2]});
    }
    
    del_djikstra(1);// start node
    
    for (int i = 1; i <= n; i++)
    {
        // 도달할 수 없는 경우
        if (d[i] == INF) {
            continue;
        }else if(d[i] < k){
            answer++;
        }
    }
    
    cout << answer + 1 << '\n';
    
    return 0;
}
