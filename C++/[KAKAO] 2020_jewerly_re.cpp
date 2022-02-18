//
//  [KAKAO] 2020_jewerly_re.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/08/05.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> gemAllList;
vector<pair<int, int>> answer;
vector<int> reanswer;
int cnt = 0;
int sum = 0;
//vector<string> gems = {"A","A","A","B","B"};
vector<string> gems = {"A","B","B","B","B","B","B","C","B","A"};


vector<int> solution(vector<string> gems) {
    if(gems.size() == 1){
        reanswer.push_back(1);
        reanswer.push_back(1);
        return reanswer;
    }
    
    for(int i = 0; i < gems.size(); i++){
        gemAllList[gems[i]] = 1;
    }
    
    int low = 0; int maxInt = 2147483647;  int min_len = maxInt; int min_start = low;
    
    for(int high = 0; high < gems.size(); high++){
        if(gemAllList[gems[high]] > 0){
            cnt++;
        }
        gemAllList[gems[high]]--;
        if(cnt == gemAllList.size()){
            while(low < high && gemAllList[gems[low]] < 0){
                gemAllList[gems[low]]++;
                low++;
            }
            
            if(min_len > high - low) {
                min_len = (high - (min_start = low)) + 1;
                answer.push_back(make_pair(min_start+1, min_start + min_len));
            }
            
            gemAllList[gems[low++]]++;
            cnt--;
        }
    }
    
    int minNum = maxInt;
    int minStart = 0;
    int minEnd = 0;
    
    for(int i = 0; i < answer.size(); i++){
        int start = answer[i].first;
        int end = answer[i].second;
        if(start - end < minNum){
            minNum = start - end;
            minStart = start;
            minEnd = end;
        }
    }
    reanswer.push_back(minStart);
    reanswer.push_back(minEnd);
    
  
    
    return reanswer;
}

int main(){
    
    cout << solution(gems)[0] << '\n';
    cout << solution(gems)[1] << '\n';
    return 0;
}
