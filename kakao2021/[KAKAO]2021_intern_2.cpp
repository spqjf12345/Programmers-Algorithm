//
//  [KAKAO]2021_intern_2.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

#include <string>
#include <vector>
#include <queue>


using namespace std;

int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool bfs(int i, int j, vector<string> places){
    queue<pair<int, pair<int, int>>> q; // depth, x, y
    int visit[5][5] = {false, };
    q.push({0, {i, j}});
    visit[i][j] = true;
    
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int depth = q.front().first;
        q.pop();
        
        if(depth == 2){ continue; }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 5 || ny >= 5|| nx < 0 || ny < 0){ continue; }
            if(visit[nx][ny]){ continue; }
            if(places[nx][ny] == 'O') {
                visit[nx][ny] = true;
                q.push({depth+1, {nx, ny}});
            }else if(places[nx][ny] == 'P'){
                return false;
            }
        }
    }
    return true;
}

int find_answer(vector<string> places) {
  
  for(int i = 0; i < places.size(); i++){
        for(int j = 0; j < places[i].size(); j++){
            if(places[i][j] == 'P'){
                if(bfs(i, j, places) == false) {
                    return 0;
                }
            }
        }
    }
    return 1;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
     for(int i =0; i < places.size(); i++){
        answer.push_back(find_answer(places[i]));
    }
    
    return answer;
}
