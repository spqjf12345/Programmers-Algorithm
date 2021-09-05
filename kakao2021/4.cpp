//
//  4.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/08.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>


using namespace std;
int n = 4;
int start = 1;
int end = 4;
vector<vector<int>> roads = {{1, 2, 1}, {3, 2, 1}, {2, 4, 1}};
//vector<pair<int, int>> re_roads[3000];
vector<int> traps = {2, 3};
int answer = 0;
int d[100001]; // 최단 거리 테이블
#define INF 1e9

struct node {
    int start;
    pair<int, int> end;
//    int end;
//    int value;
};

//queue<node> st;
vector<node> re_roads;

bool check(int bomb){
    for(int i =0; i <traps.size(); i++){
        if(traps[i] == bomb){
            return true;
        }
    }
    return false;
}



void dfs(){
    queue<pair<int, int>> q;
    q.push({0, start});
    d[start] = 0;
    while(!q.empty()){
        int begin = start;
        int now = q.front().first;
        if(check(now)){
            q.pop();
            q.push(<#const value_type &__v#>)
        }
    }
    
    
}

int main(){
    for(int i = 0; i < roads.size(); i++){
        re_roads.push_back({roads[i][0], {roads[i][1], roads[i][2]}});
        
    }
    
    
//    for(int i = 0; i < roads.size(); i++){
//        re_roads[roads[i][0]].push_back({roads[i][1],roads[i][2] }); // 출발 -> 도착, 비용
//    }
    
//    for(int i = 0; i < roads.size(); i++){
//        for(int j = 0; j < re_roads[i].size(); j++){
//            cout << re_roads[i][j].first << " " <<  re_roads[i][j].second << '\n';
//        }
//    }
    

    fill(d, d+100001, INF);
    dfs();
    
    
}
