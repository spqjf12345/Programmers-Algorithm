//
//  [KAKAO] 2020_stringCompression.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/25.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int n = s.length();
    int answer = 1000;
    if(s.length() == 1){
        return 1;
    }
    
    for(int i = 1; i <= n / 2; i++){ // token 길이 : 1 ~ n/2
        int cnt = 1;
        string res = "";
        string token = s.substr(0, i);
      for(int j = i; j < n; j+= i){
          if(token == s.substr(j, i)){
             cnt++;
          }else {
              if(cnt > 1){
                  res += to_string(cnt);
              }
              res += token;
              token = s.substr(j, i);
              cnt = 1;
          }
      }
        if(cnt > 1){
            res += to_string(cnt);
        }
        res += token;
        if(res.length() < answer) {
            answer = res.length();
        }

    }
    
    return answer;
}
