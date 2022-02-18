//
//  [KAKAO] 2020_jewerlyShop.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/01.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
vector<string> germs = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
//vector<string> germs = {"AA", "AB", "AC", "AA", "AC"};

//vector<string> germs = {"XYZ", "XYZ", "XYZ"};
//vector<string> germs = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
vector<string> germs = {"DIA", "EM", "EM", "RUB", "DIA"};

vector<string> len;

//구간 합 순열을 구한 뒤 종류가 가장 많이 다른 길이의 리스트 반환 -> O(n^2)
int find_length(vector<string> len){
    set<string> s;
    for(int i =0; i < len.size(); i++){
        s.insert(len[i]);
    }

    return (int)s.size();
}

int main(){
    int maxNum = 0;
    vector<int> answer;

    
    int priorI = 0, priorJ = (int)germs.size() - 1;
    for(int start = 0; start< germs.size(); start++){
        for(int i = start; i < germs.size(); i++){
            len.push_back(germs.at(i));
        }
        int end = (int)germs.size() - 1;
        while(end >= start){
            int size = find_length(len);
            if(start == 0 && end == ((int)germs.size() - 1) && maxNum <= size && (end - start) <= (priorJ - priorI)){

                answer.clear();
                answer.push_back(start+1);
                answer.push_back(end+1);
                priorJ = end;
                priorI = start;
                maxNum = size;
            }
            if(maxNum <= size && (end - start) < (priorJ - priorI)){

                answer.clear();
                answer.push_back(start+1);
                answer.push_back(end+1);
                priorJ = end;
                priorI = start;
                maxNum = size;
            }
            len.pop_back();
            end--;
        }
        
    }
  
    
    for(int i =0; i <answer.size(); i++){
        cout << answer.at(i) << " ";
    }
    
    
    return 0;
}
