//
//  3.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSo; on 2021/05/08.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};
vector<int> reV = v;
int n = 8;
stack<pair<int, int>> s;
int k = 2;
void reVCheck(){
    for(int i = 0; i < reV.size(); i++){
        cout << reV.at(i) << ' ';
    }
    cout << "\n";
}
int main(){

    int moving = k;
    vector<int>::iterator nowArray = reV.begin();
       for(int i =0; i < cmd.size(); i++){
           //reVCheck();
           nowArray = reV.begin() + moving;
           cout << "select " << moving << '\n';

               //c cmd 수행
               if(cmd[i] == "C"){// 삭제
                   cout << "delete 원소" << *nowArray << '\n';
                   s.push({moving, *nowArray});// 삭제 인덱스, 원소 값
                   reV.erase(nowArray);
                   if(*nowArray == 7){ // 마지막
                       moving -=1;
                   }
                   //reVCheck();
                   continue;
            //z cmd 수행
               }else if(cmd[i] == "Z"){
                  
                   if(!s.empty()){
                       int index = s.top().first;
                       int value = s.top().second;
                       reV.insert(reV.begin() + index , value);
                       if(index < moving){
                           moving += 1;
                       }
                       s.pop();
                       cout << "z do" << '\n';
                       reVCheck();
                       
                   }
                   continue;
                   
               }else{
                   if(cmd[i][0] == 'D' && (48 <= cmd[i][2] &&  cmd[i][2] <= 57)){
                        moving += cmd[i][2] - '0';
                   }else if(cmd[i][0] == 'U' && (48 <= cmd[i][2] &&  cmd[i][2] <= 57)){
                        moving -= cmd[i][2] - '0';
                   }
            }
              
           
           
           
           
//           for(int j = 0; j < cmd[i].size(); j++){
//               if(isspace(cmd[i][j])){
//                   continue;
//               }
//               if(cmd[i][j] > 57) { // 명령어
//                   if(cmd[i][j] == 'D'){
//                       cout << "here D" << '\n';
//                       oper = '+';
//                   }else if(cmd[i][j] == 'U'){
//                       cout << "here U" << '\n';
//                       oper = '-';
//                   }
//               }
//               if(48 <= cmd[i][j] and cmd[i][j] <= 57 ){
//                   if(oper == '+'){
//                       cout << "here num + " << '\n';
//                       moving += cmd[i][j] - '0';
//                   }else if(oper == '-'){
//                       cout << "here num - " << '\n';
//                       moving -= cmd[i][j] - '0';
//                   }
//
//               }
//               cout << "j" << '\n';
//           }
          
       }
    string answer = "00000000";
    while(!s.empty()){
        cout << s.top().second << ' ' ;
        answer.at(s.top().first) = 'X';
        s.pop();
    }
//    int t = 0;
//    for(int i = 0 ; i < v.size(); i++){
//        if(v.at(i) == reV.at(t)){
//            answer += "O";
//            t++;
//        }else{
//            answer += "X";
//        }
//    }
    cout << answer << '\n';
       
       return 0;
}
