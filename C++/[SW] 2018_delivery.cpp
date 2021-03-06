//
//  [SW] 2018_delivery.cpp
//  SOMAπ©π»βπ»
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
int d[100001]; // μ΅λ¨ κ±°λ¦¬ νμ΄λΈ
vector<pair<int, int>> revect[51];

void del_djikstra(int start){
    priority_queue<pair<int, int>>pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    
    while(!pq.empty()){
        //μ°μ  μμ νλ κ°μ₯ ν° μμ topμΌλ‘ λμΌλ―λ‘
        //κ±°λ¦¬ μμ μ μ λΆν° κΊΌλ΄μ§λλ‘ νκΈ°
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < revect[now].size(); i++){
            //κ±°μ³μ κ°λ λΈλμ λΉμ©μ κ³μ°
            int cost = dist + revect[now][i].second;
            if(cost < d[revect[now][i].first]) // λΉμ©μ΄ λ μλ€λ©΄ μ΅λ¨κ²½λ‘ νμ΄λΈ κ°μ κ°±μ .
            {
                d[revect[now][i].first] = cost;
                pq.push(make_pair(-cost, revect[now][i].first));
            }
        }
    }
    
}

int main(){
    int n = 5;
    int k = 3; // λ°°λ¬ κ°λ₯ν μ΅λ μκ°
    int answer = 0;
    fill(d, d+100001, INF);
    for(int i = 0; i < road.size(); i++){
        revect[road[i][0]].push_back({road[i][1], road[i][2]});
    }
    
    del_djikstra(1);// start node
    
    for (int i = 1; i <= n; i++)
    {
        // λλ¬ν  μ μλ κ²½μ°
        if (d[i] == INF) {
            continue;
        }else if(d[i] < k){
            answer++;
        }
    }
    
    cout << answer + 1 << '\n';
    
    return 0;
}
