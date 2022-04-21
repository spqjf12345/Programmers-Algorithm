//
//  bucket_left.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/22.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
bool check(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '[' || s[i] == '(' || s[i] == '{'){
            st.push(s[i]);
        }else {
            if st.empty() { return false;}
            if ((s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{') && (s[i] == ')' && st.top() == '(') {
                st.pop();
            }else {
                return false;
            }
        }
    }
    return true;
}
int solution(string s) {
    int answer = 0;
    for(int i = 1; i < s.length(); i++){
        string ss = s.substr(1, s.length() - 1) + s.substr(0, 1);
        if (check(ss)) {
            answer += 1
        }
        s = ss;
    }
    return answer;
}
