//
//  3_re.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/09/09.
//

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

//vector<int> reV;
set<int> ss;


string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> s;
    for(int i = 0; i < n; i++){
        ss.insert(i);
    }
    
    set<int> :: iterator it,temp;
    it = ss.begin();
    
    //초기 위치 값 설정
    while(k--){
        it++;
    }

   for(int i =0; i < cmd.size(); i++){
       string str = cmd[i];

       //c cmd 수행
       if(str == "C"){// 삭제
           s.push(*it); // 원소 값
           temp = it;
           temp++;
           if(temp == ss.end()){ // 마지막
               temp = it;
               --temp;
           }
           ss.erase(it);
           it = temp;
        //z cmd 수행
       }else if(str == "Z"){
          ss.insert(s.top());
           s.pop();
       }else{
           if(str[0] == 'D'){
               string ss = str.substr(2);
                int val = stoi(ss);
               while(val--){
                   ++it;
               }
           }else if(str[0] == 'U'){
               string ss = str.substr(2);
                int val = stoi(ss);
               while(val--){
                   --it;
               }
           }
    }

   }
    
    int idx=0;
    for(it = ss.begin(); it!=ss.end();it++){
        int val = *it;
        if(val==idx){
            answer+='O';
        }
        else{
            while(idx<val){
                answer+='X';
                idx++;
            }
            answer+='O';
        }
        idx++;
    }
    while(idx<n){        //"OOOXX" 같은 예외 잡아주기 위함
        answer+='X';
        idx++;
    }

    return answer;
}
