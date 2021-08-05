//
//  [KAKAO] 2019_tuple.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/06/24.
//

#include <string>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> vec[100];
bool check[101];
vector<int> answer;

int main(){
    int vecIndex = 0;
    memset(check, false, sizeof(check));
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    int i = 1;
    while(i < s.length() - 1){
        if(s[i] == '{'){
            vecIndex++;
            cout << vecIndex << '\n';
            i++;
            while(s[i] != '}'){
                if(s[i] == ','){
                    i++;
                    continue;
                }
                vec[vecIndex].push_back(s[i] - '0');
                i++;
            }
        }
        if(s[i] == ','){
            i++;
            continue;
        }
        i++;
    }

    
    while(true){
        int min = 1;
        if(vec[i].size() == min){
            for(int j = 0; j < vec[i].size(); j++){
                if(check[vec[i][j]] == false){
                    answer.push_back(vec[i][j]);
                    check[vec[i][j]] = true;
                }
            }
            min++;
        }
        
        cout << '\n';
    }
    
    return 0;
}
