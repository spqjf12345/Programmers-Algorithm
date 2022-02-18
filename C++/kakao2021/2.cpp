//
//  2.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/08.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
vector<vector<string>> places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

vector<char> case1[5];
vector<pair<int, int>> person;
int main(){
//    for(int i = 0; i < places.size(); i++){ //TC
//        for(int j = 0; j < places[i].size(); j++){ // 1case
//            for(int k = 0; k < places[i][j].length(); k++){
//                case1[j].push_back(places[i][j][k]);
//                if(places[i][j][k] == 'P'){
//                    person.push_back({j, k});
//                }
//            }
//        }
//    }
    
    for(int k = 0; k < 5; k++){
        for(int j = 0; j < 5; j++){
            
            cout << case1[k][j] << " ";
        }
        cout << '\n';
       
    }
    return 0;
}
