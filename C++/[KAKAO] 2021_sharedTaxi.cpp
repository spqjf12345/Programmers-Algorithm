//
//  [KAKAO] 2021_sharedTaxi.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/28.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> vertex[201];


void dijkstra(int d[], int start){
    fill(d, d+201, INF);
    pq.push({0, start});
    d[start] = 0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
   
        for (int i = 0; i< vertex[now].size(); i++) {
            int cost = dist + vertex[now][i].second;
            if(cost <d[vertex[now][i].first]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                d[vertex[now][i].first] = cost;
                pq.push(make_pair(-cost, vertex[now][i].first));
            }

        }
    }

}

int main(){
    // n - 지점의 개수, s - 시작, a - a 도착 , b - b 도착
    int n = 6; int s =4; int a = 5; int b = 6;
//    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    
//    vector<vector<int>> fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
    
    vector<vector<int>> fares = {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}};
    
    for(int i = 0; i < fares.size(); i++){//9
        vertex[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        vertex[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    int sd[201]; //거리의 합
    int id[201]; //거리의 합
    dijkstra(sd, s);
    //따로 갔을때의 비용
    int cost =  sd[a] + sd[b];
    //중간 지점 거쳐 갔을때의 비용
    for(int i = 1; i<= n; i++){
        dijkstra(id, i);
        if (i != s){//4가 아닐때
            if(id[a] == 1000000000 || id[b] == 1000000000 ) continue; //떨어져 있으므로 못감
            
            cost = min(cost, id[a] + id[b] + sd[i]);
        }
    }
    cout << cost << '\n';

    return 0;
}

