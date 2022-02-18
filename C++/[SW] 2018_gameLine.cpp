//
//  W] 2018_gameLine.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/30.
//

#include <stdio.h>
#include <stack>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

string dirs[3] = {"ULURRDLLU", "LRLRL", "LULLLLLLU" };


void make_line_dfs(){
    int cnt = 0;
    map<pair<pair<int, int>, pair<int, int>>, bool> edge;
    
    int dx = 5;
    int dy = 5;
    
    for(int i = 0; i < dirs[0].length(); i++){
       int priorX = dx;
       int priorY = dy;
       switch (dirs[0][i]) {
           case 'U':
               if( dy + 1 > 10){
                   continue;
               }
               dy += 1;
               break;
           case 'D':
                if(dy - 1 < 0){
                   continue;
               }
               dy -= 1;
              
               break;
           case 'R':
               if(dx + 1 > 10){
                   continue;
               }
               dx += 1;
               break;
           case 'L':
               if(dx - 1 < 0){
                   continue;
               }
               dx -= 1;
               break;
           default:
               break;
        }
        //cout << "dx : " <<dx << " dy : " << dy << '\n';
        
        if(dx < 0 || dy < 0 || dx >= 10 || dy >= 10) continue;
        if(edge[make_pair(make_pair(priorX, priorY), make_pair(dx, dy))] == true) continue;
        
        //false 이면
        cout << " true dx : " <<dx << " dy : " << dy << '\n';
        edge[make_pair(make_pair(priorX, priorY), make_pair(dx, dy))] = true;
        edge[make_pair(make_pair(dx, dy), make_pair(priorX, priorY))] = true;
        cnt++;
       

        
    }
    cout << "cnt : " << cnt << '\n';
        
    }
    
    
    
    

int main(){
    make_line_dfs();

    
    int answer = 0;
    
    return 0;
}
