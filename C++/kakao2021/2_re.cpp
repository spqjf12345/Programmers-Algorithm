//
//  2_re.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/05.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool bfs(int i, int j, vector<string> places){
    int visit[5][5] = { false, };
    queue<pair<pair<int, int>, int>> q; // i, j, depth
    q.push({{i, j}, 0});
    visit[i][j] = true;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int depth = q.front().second;
        q.pop();
        
        if(depth == 2){ continue; }
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 5 || ny >= 5|| nx < 0 || ny < 0){ continue; }
            if(visit[nx][ny] == false && places[nx][ny] == 'O'){
                visit[nx][ny] = true;
                q.push({{nx, ny}, depth + 1});
            }else if(visit[nx][ny] == false && places[nx][ny] == 'P'){
                return false;
            }
        }
    }
    return true;
}

int find_answer(vector<string> places){
    for(int i =0; i < places.size(); i++){
        for(int j = 0; j < places[i].size(); j++){
            if(places[i][j] == 'P'){
                if(bfs(i, j, places) == false){
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> find(vector<vector<string>> places){
    vector<int> result;
    for(int i =0; i < places.size(); i++){
        result.push_back(find_answer(places[i]));
    }
    return result;
       
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    answer = find(places);

    return answer;
}
