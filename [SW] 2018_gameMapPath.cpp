//
//  [SW] 2018_gameMapPath.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/30.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };


int arr[101][101] = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1}, {1,1,1,0,0} ,{0,0,0,0,1}};

//{{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}}
int visit[101][101];

int make_dfs(){
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = 1;
    
    while(!q.empty()){
        pair<int, int> now = q.front();
        int x = now.first;
        int y = now.second;
        q.pop();
        
        if(x == 4 and y == 4){
            return visit[x][y];
        }
        
        for(int i =0; i< 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=5 || ny >= 5 || nx < 0 || ny < 0) continue;
//            cout << "nx ny 1: " << nx << " " << ny << '\n';
            if(visit[nx][ny] == false && arr[nx][ny] == 1){
//                cout << "nx ny 2: " << nx << " " << ny << '\n';
                visit[nx][ny] = visit[x][y] + 1;
                q.push({nx, ny});
            }
        }
        
    }
    return -1;
}

int main() {
   memset(visit, false, sizeof(visit));
    cout << make_dfs() << '\n';
    return 0;
}
