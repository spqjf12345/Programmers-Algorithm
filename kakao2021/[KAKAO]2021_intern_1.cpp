//
//  1.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/08.
//

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <set>

using namespace std;
set<string> ss;
//enum Digit{
//    zero = 0,
//    one,
//    two,
//    three,
//    four,
//    five,
//    six,
//    seven,
//    eight,
//    nine
//};

int main(){
    ss = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string re = "";
    string s = "23four5six7";
    string result = "";
    for(int i =0; i < s.length(); i++){
        if( 48 <= s[i] and s[i] <= 57 ){
            result += s[i];
            continue;
        }
        re += s[i];
        if(ss.find(re) != ss.end()){
            if(re == "zero"){
                result += "0";
            }else if(re == "one"){
                result += "1";
            }else if(re == "two"){
                result += "2";
            }else if(re == "three"){
                result += "3";
            }else if(re == "four"){
                result += "4";
            }else if(re == "five"){
                result += "5";
            }else if(re == "six"){
                result += "6";
            }else if(re == "seven"){
                result += "7";
            }else if(re == "eight"){
                result += "8";
            }else if(re == "nine"){
                result += "9";
            }
            
            re = "";
        }
        
    }
    cout << result << '\n';
    
    return 0;
}
