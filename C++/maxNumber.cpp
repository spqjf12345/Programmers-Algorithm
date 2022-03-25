//
//  maxNumber.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/03/25.
//
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
bool comp(string s1, string s2){
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    
    for(int i = 0; i < numbers.size(); i++){
        num.push_back(to_string(numbers[i]));
    }
    sort(num.begin(), num.end(), comp);
    if (num.at(0) == "0") {
        return "0";
    }
    for(int i = 0; i < numbers.size(); i++){
        answer += num[i];
    }
    
    return answer;
}
