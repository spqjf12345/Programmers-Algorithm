//
//  dfs_network.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/04.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
stack<int> s;


int visit[201];


void make_dfs(vector<int> computers){
    for(int i =0; i < computers.size(); i++){
        if(computers[i] == 1){
            s.push(i);
            visit[i] = true;
            
        }
    }

  
}

int main(){
    vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int n = 3;
    int result = n;
    
    for(int i = 0 ; i< computers.size(); i++){
        computers[i][i] = 0;
    }
    
    for(int i = 0 ; i< computers.size(); i++){
        make_dfs(computers[i]);
    }
    cout << result << '\n';
    
    
    return 0;
}
