//
//  [KAKAO] 2021_rankSearch.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/26.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<string> info;
vector<string> query;

vector<int> answer;

set<string> memberSet[50001];
vector<int> memberScore; // 점수 보관용

vector<string> searchQuery[50001];
vector<int> searchScore;

void info_querySetting(){
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");
    
    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");
}

int main(){
    info_querySetting();
    
    for(int i = 0; i< info.size(); i++){
        string s = info[i];
        stringstream ss(s);
        string str;
        int j =0;
        while(ss>>str){
            j++;
            if(j == 5){
                memberScore.push_back(stoi(str));
                continue;
            }
            memberSet[i].insert(str);
        }
    }
    
//    for(int i =0; i < info.size(); i++){
//        for(int j =0; j < memberSet[j].size(); j++){
//
//        }
//    }
    
    for(int i = 0; i < query.size(); i++){
        string s = query[i];
        stringstream ss(s);
        string str;
        int j = 0;
        while(ss>>str){
            j++;
            if(str == "and"){
                continue;
            }
            if(j == 8){
                searchScore.push_back(stoi(str));
                continue;
            }
            
            searchQuery[i].push_back(str);
        }
    }
    
    //for(int i = 0; i < searchScore.size(); i++){ cout << searchScore.at(i) << " ";}

//    for(int i =0; i < query.size(); i++){
//        for (int j = 0; j < searchQuery[i].size(); j++){
//            cout << "searchQuery : " << searchQuery[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    for(int i = 0; i < (int)query.size(); i++){ // query index 6
        int cnt = 0;
        
        for(int j = 0; j < (int)info.size(); j++){ // person index 6
            bool isCondition = true;
            for(int k = 0; k < (int)memberSet[j].size() + 1; k++){
                if(k == 4){
                    if(memberScore.at(j) < searchScore.at(i)){
                        //cout << " " << memberScore.at(j) << " " << searchScore.at(i) << '\n';
                        isCondition = false;
                        break;
                    }else{
                        //cout << "here " << '\n';
                    }
                }else { //k<=3
                    string queryWord = searchQuery[i][k];
                    //cout << "queryWord1 : " << queryWord << '\n';
                    set<string>:: iterator iter;
                    if(queryWord == "-"){
                        continue;
                    }else{
                        iter = memberSet[j].find(queryWord);
                        if(iter != memberSet[j].end()){
                            //isCondition = true;
                            //cout << " queryWord2: " << *iter << '\n';
                        }else {
                            isCondition = false;
                        }
                    }
                }
            }
            
            if(isCondition == true){
//                cout << j << " person " << i << "th " << "is " << isCondition << " condition" << '\n';
                cnt++;
            }else{
//                cout << j << " person " << i << "th " << "is " << isCondition << " condition" << '\n';
            }
        } //until j
        
        answer.push_back(cnt);
    }
    
    
    for(int s = 0; s < answer.size(); s++){
        cout << answer.at(s) << " ";
    }
    
    
    return 0;
}
