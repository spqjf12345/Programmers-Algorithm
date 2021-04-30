//
//  [SW] 2018_enEnding.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/01.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
//vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};

//vector<string> words = {"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};

vector<string> words = {"hello", "one", "even", "never", "now", "world", "draw"};


int main(){
    int n = 2;
    set <string> s;
    vector<int> answer;
    s.insert(words[0]);
    int i = 0;
    for(i = 1; i < words.size(); i++){
        if(s.find(words[i]) == s.end()){ // 전에 말했던 단어가 아니어야 함
            int size = (int)words[i - 1].length();
            //cout << "size " << size << '\n';
            if(words[i - 1][size-1] == words[i][0]){ // 끝나는 글자와 시작하는 글자가 같아야 함
                //cout << "words " << words[i] << '\n';
                s.insert(words[i]);
                continue;
            }
        }
        //cout << "i is " << i << '\n';
        
        // 그렇지 않은 경우 짐
        int person = i % n + 1;
        int order = (i / n) + 1;
        answer.push_back(person);
        answer.push_back(order);
        break;
        
    }
    
    if(i == words.size()){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    for(int i =0; i < answer.size(); i++){
        cout << answer.at(i) << " ";
    }
    
    return 0;
}
