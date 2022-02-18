#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string ss = "zero one two three four five six seven eight nine";
    string re = "";
    string result = "";
    for(int i =0; i < s.length(); i++){
        if( 48 <= s[i] and s[i] <= 57 ){ // 숫자
            result += s[i];
            continue;
        }
        re += s[i];
        if(ss.find(re) != string::npos){
            if(re == "zero"){
                result += "0";
                re = "";
            }else if(re == "one"){
                result += "1";
                re = "";
            }else if(re == "two"){
                result += "2";
                re = "";
            }else if(re == "three"){
                result += "3";
                re = "";
            }else if(re == "four"){
                result += "4";
                re = "";
            }else if(re == "five"){
                result += "5";
                re = "";
            }else if(re == "six"){
                result += "6";
                re = "";
            }else if(re == "seven"){
                result += "7";
                re = "";
            }else if(re == "eight"){
                result += "8";
                re = "";
            }else if(re == "nine"){
                result += "9";
                re = "";
            }
            
        }
        
    }
    
    return stoi(result);
}
