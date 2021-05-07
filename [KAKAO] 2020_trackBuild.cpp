//
//  [KAKAO] 2020_trackBuild.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/07.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
int nextPay = 0;

//
//vector<vector<int>> board = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
vector<vector<int>> board = {{0,0,1},{1,0,1},{1,0,0}};
int size = (int) board.size();
bool visit[26][26];
int dp[26][26];
int answer = 0;

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

void print_dp(){
    for(int i =0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int calculate_pay(int before, int now){
    if(before == -1){
        return 100;
    }else if((before == 2|| before == 3) &&(now == 0|| now == 1)){
        return 600;
    }else if((before == 0|| before == 1) &&(now == 2|| now == 3)){
        return 600;
    }
    return 100;
}

void make_bfs(int x, int y, int dir, int pay){
    for(int i = 0; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0|| nx >= size || ny > size) continue;
        if(board[nx][ny] == 1 || visit[nx][ny] == true) continue;
        
        pay = calculate_pay(dir, i);
        if(dp[nx][ny] < dp[x][y] + pay){
            continue;
        }
        dp[nx][ny] = dp[x][y] + pay;
        visit[nx][ny] = true;
        make_bfs(nx, ny, i, pay);
        print_dp();
        visit[nx][ny] = false;
        // false가 되고 돌아오는 과정에서 다음 for문을 돌고 그에 대한 더 최적의 값이 있다면 dp에 최소의 값으로 다시 계산되어 저장된다.
        
    }
}


int main(){
    
    // 초기화
    memset(visit, false, sizeof(visit));
    for(int i =0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            dp[i][j] = 10000000;
        }
    }
    
    dp[0][0] = 0;
    make_bfs(0, 0, -1, 0);
    
    cout << dp[size -1][size -1] << '\n';
    
   
    return 0;
}
