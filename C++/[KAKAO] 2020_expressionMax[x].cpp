//
//  [KAKAO]expression_maximum.cpp
//  SOMA๐ฉ๐ปโ๐ป
//
//  Created by JoSoJeong on 2021/04/26.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

#define MAX 100
string expression;


vector<char> operators;
vector<char> location;
vector<int> N;

string s;
queue <char> makeInt;

// *, -, / ์์์ ์ฐ์  ์์ ๊ตฌํ๊ธฐ
// ๊ตฌํ๋ฉด ๊ด๋ จ ํผ์ฐ์ฐ์๋ ์ด๋ป๊ฒ ์์ง ?? -> next_permutation์ ํตํด์ ํ๊ธฐ

void divide_num_operator(){
   
    for(int i = 0; i< expression.length(); i++){
        //์ซ์
        if(expression[i] != '-' && expression[i] != '*' && expression[i] != '+'){
            makeInt.push(expression[i]);
        }else{
            //์์
            operators.push_back(expression[i]);
            location.push_back(expression[i]);
            
            while(!makeInt.empty()){
                s += makeInt.front();
                makeInt.pop();
            }
            if(makeInt.empty()){
                N.push_back(stoi(s));
            }
            s = "";
        }
    }
    while(!makeInt.empty()){
        s += makeInt.front();
        makeInt.pop();
    }
    
    if(makeInt.empty()){
        N.push_back(stoi(s));
        s = "";
    }
}

int find_max_money(){
    int money = 0;
    sort(operators.begin(), operators.end());
    
    do {
        vector<int> tmp_num = N;
        vector<char> tmp_loc = location;
        for(int i =0; i < operators.size(); i++){
            for(int j =0; j < tmp_loc.size(); j++){
                if(operators[i] == tmp_loc[j]){
                    if(tmp_loc[j] == '+'){
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    }else if(tmp_loc[j] == '-'){
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    }else if(tmp_loc[j] == '*'){
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];
                    }
                    
                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;
                }
            }
        }
        if(money < abs(tmp_num[0])){
            money = abs(tmp_num[0]);
        }
    } while(next_permutation(operators.begin(), operators.end()));
    return money;
    
}

int main(){
    cin >> expression;
    divide_num_operator();
    int money = find_max_money();
    cout << money << '\n';
    return 0;
}

