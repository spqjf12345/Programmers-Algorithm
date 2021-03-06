//
//  [SW] 2018_skillTree.cpp
//  SOMAπ©π»βπ»
//
//  Created by JoSoJeong on 2021/04/30.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

int main(){
    int answer = 0;
    string skill = "CBD";
    vector<string> skillTree = {"BACDE", "CBADF", "AECB", "BDA","OPQ", "CED"};
    vector<char> re_skillTree;
    
    for(int i =0; i < skillTree.size(); i++){
        
        for(int j = 0; j < skillTree[i].size(); j++){
            if(skill.find(skillTree[i][j]) != string::npos){
                re_skillTree.push_back(skillTree[i][j]);
            }
        }
        
        //μ£Όμ΄μ§ μ€ν¬ μ‘°κ±΄μ΄ νλλ μμ΄λ μ λ΅
        if(re_skillTree.size() == 0){
            answer++;
        }else{
            //μμΌλ©΄ μμ λΉκ΅
            int k = 0; int n = 0;
            for(int i = 0; i < re_skillTree.size(); i++){
                if(re_skillTree[n] == skill[k++]){
                    n++;
                }else{
                    break;
                }
            }
            if(k != 0 && n != 0 && k == n){
                answer++;
            }
        }
        
        re_skillTree.clear();

    }

    cout << answer << '\n';
    return 0;
}
