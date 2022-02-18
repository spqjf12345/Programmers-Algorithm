//
//  PhoneList.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++){
        string target = phone_book[i];
      if(target == phone_book[i + 1].substr(0, phone_book[i].size())){ return false; }
    }
    // for(int i = 0; i < phone_book.size(); i++){
    //     string target = phone_book[i];
    //     for(int j = 0; j < phone_book.size(); j++){
    //         if(i == j) { continue; }
    //         if(phone_book[j].find(target) != string::npos){
    //             return false;
    //         }
    //     }
    // }
    return answer;
}
