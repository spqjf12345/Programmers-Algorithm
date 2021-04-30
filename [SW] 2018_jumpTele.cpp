//
//  [SW] 2018_jumpTele.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/30.
//

#include <stdio.h>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;
queue<int> q;
#define MAX 1000001
int visit[MAX];
int moving[3] = {1, 2}; //walk, jump

void find_min_power(int n){
    int start = 0;
    q.push(start);
    visit[start] = 0;
    
    if(start == n){
        cout << "0" << '\n';
    }
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < 2; i++){
            int next = now;
            int nextCost = 0;
            if(i == 0){
                next += 1; //한칸 이동
                nextCost += 1; //건전지 하나 사용
            }else if(i == 1){
                next = now * 2;
                nextCost = 0;
            }
            if(next < 0 || next > n) continue;
            if(visit[next] != -1) continue;
            
            q.push(next);
            visit[next] = visit[now] + nextCost;
            
            if(next == n){
                  cout << visit[next] -1 << '\n';
                  break;
            }
        }
    }
}

int main(){
    int n = 5000;
    memset(visit, -1, sizeof(visit));
    find_min_power(n);
    return 0;
}

//feat
int solution(int n)
{
    int ans = 0;
    while(n != 0){
        if(n % 2 == 1){
            ans++;
            n -= 1;
        }else{
            n /= 2;
        }
    }
    return ans;
}
