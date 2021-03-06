//
//  [KAKAO] 2021_sharedTaxi.cpp
//  SOMAπ©π»βπ»
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
            if(cost <d[vertex[now][i].first]) // λΉμ©μ΄ λ μλ€λ©΄ μ΅λ¨κ²½λ‘ νμ΄λΈ κ°μ κ°±μ .
            {
                d[vertex[now][i].first] = cost;
                pq.push(make_pair(-cost, vertex[now][i].first));
            }

        }
    }

}

int main(){
    // n - μ§μ μ κ°μ, s - μμ, a - a λμ°© , b - b λμ°©
    int n = 6; int s =4; int a = 5; int b = 6;
//    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
    
//    vector<vector<int>> fares = {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};
    
    vector<vector<int>> fares = {{2, 6, 6}, {6, 3, 7}, {4, 6, 7}, {6, 5, 11}, {2, 5, 12}, {5, 3, 20}, {2, 4, 8}, {4, 3, 9}};
    
    for(int i = 0; i < fares.size(); i++){//9
        vertex[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        vertex[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    int sd[201]; //κ±°λ¦¬μ ν©
    int id[201]; //κ±°λ¦¬μ ν©
    dijkstra(sd, s);
    //λ°λ‘ κ°μλμ λΉμ©
    int cost =  sd[a] + sd[b];
    //μ€κ° μ§μ  κ±°μ³ κ°μλμ λΉμ©
    for(int i = 1; i<= n; i++){
        dijkstra(id, i);
        if (i != s){//4κ° μλλ
            if(id[a] == 1000000000 || id[b] == 1000000000 ) continue; //λ¨μ΄μ Έ μμΌλ―λ‘ λͺ»κ°
            
            cost = min(cost, id[a] + id[b] + sd[i]);
        }
    }
    cout << cost << '\n';

    return 0;
}

