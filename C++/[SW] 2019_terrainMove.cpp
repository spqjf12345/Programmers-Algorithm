//
//  [SW] 2019_terrainMove.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/02.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;
vector<pair<int, int>> vec[90001];
int visit[301][301];
vector<int> Parent;

int dx[] = { 0, 0, 1, -1 }; //up down left right
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, pair<int, int>>> edge;
int height = 1;
//vector<vector<int>> rands = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
vector<vector<int>> rands = {{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}};

int k = 1; // 같은 그룹인지 판단하는 고유 id

void tie_same_terrain(int i, int j, int k){
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = k; //고유 id 값을 넣어준다
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= rands.size() || ny >= rands.size()) continue;
            if(abs(rands[x][y] - rands[nx][ny]) > height || visit[nx][ny] != 0) continue;
            visit[nx][ny] = k;
            q.push({nx, ny});
        }
    }
}

//1 1 1 1
//1 1 1 1
//2 2 2 2
//2 2 2 3


int Find_Parent(int A)
{
   if (A == Parent[A]) return A;
   return Parent[A] = Find_Parent(Parent[A]);
}

void Union(int A, int B)
{
   A = Find_Parent(A);
   B = Find_Parent(B);
   Parent[B] = A;
}

bool Same_Parent(int A, int B)
{
   A = Find_Parent(A);
   B = Find_Parent(B);
   if (A == B) return true;
   return false;
}




int main(){
    int answer = 0;
    
    memset(visit, 0, sizeof(visit));
    for(int i =0; i < rands.size(); i++){
        for(int j =0; j < rands[i].size(); j++){
           
            if(visit[i][j] == 0){
                tie_same_terrain(i, j, k++);
            }
            
        }
    }
    
//    for(int i =0; i < 4; i++){
//        for(int j =0; j < 4; j++){
//            cout << visit[i][j] << " ";
//        }
//        cout << '\n';
//    }
    
    for(int i =0; i < rands.size(); i++){
        for(int j =0; j < rands[i].size(); j++){
            for(int s = 0; s < 4; s++){
                int nx = i + dx[s];
                int ny = j + dy[s];
                if(nx >= 0 && ny >= 0 && nx < rands.size() && ny < rands.size()){
                    if(visit[i][j] != visit[nx][ny]){
//                        cout << "edge push cost " << abs(rands[nx][ny] - rands[i][j]) << '\n';
//                        cout << "edge push node1 " << visit[i][j] << '\n';
//                        cout << "edge push node1 " << visit[nx][ny] << '\n';
                        edge.push_back({abs(rands[nx][ny] - rands[i][j]), {visit[i][j], visit[nx][ny]}});
                    }
                    
                }
            }
             
        }
    }
    
    //kruskal
    Parent.resize(k);
       sort(edge.begin(), edge.end()); // 최소 비용 순으로 정렬
       for (int i = 1; i < k; i++) Parent[i] = i; //서로 떨어트리기 위해
    
       for (int i = 0; i < edge.size(); i++)
       {
           int N1 = edge[i].second.first; // 첫 노드
           int N2 = edge[i].second.second; //두번째 노드
           int Cost = edge[i].first; // 최소 비용
           //cout << "n1 n2 cost " << N1 << " " << N2 << " " << Cost << '\n';
           
           if(Same_Parent(N1, N2) == false)
           {
               Union(N1, N2);
               answer = answer + Cost;
           }
       }


    
    
    
    cout << answer <<'\n';
    return 0;
}
