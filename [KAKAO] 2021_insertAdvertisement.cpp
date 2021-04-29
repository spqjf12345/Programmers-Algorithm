//
//  [KAKAO] 2021_insertAdvertisement.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/04/29.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;
int ad[360000];

int strToSec(string s){
    int result = 0;
    string h = s.substr(0, 2);
    string m = s.substr(3, 2);
    string c = s.substr(6, 2);
    
    result += stoi(h)*60*60;
    result += stoi(m)*60;
    result += stoi(c);
    return result;
}

string secToStr(int n){
    string result = "";
    int s = n%60; n/= 60;
    int m = n%60; n/= 60;
    int h = n;
    
    if(h < 10) result +="0";
    result += to_string(h);
    result +=":";
    
    if(m<10) result+="0";
    result +=to_string(m);
    result +=":";

    if(s<10) result+="0";
    result +=to_string(s);

    return result;
}

int main(){
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    string logs[5] = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
    
    for(string s : logs){
        int start = strToSec(s.substr(0,8));
        int end = strToSec(s.substr(9, 8));
        
        for(int i = start; i < end; i++) ad[i]++;
    }
    
    int N = strToSec(play_time); // 전체 구간 길이
    int len = strToSec(adv_time); // 광고 구간 길이
    
    cout << N << "\n";
    cout << len << "\n";

    int idx=0;
    long long sum=0;
    long long maxSum=0;
    
    queue<int> q;
    
    for(int i =0;i < len; i++){
        sum += ad[i]; // i시간만큼 본 시청자수
        q.push(ad[i]);
    }
    maxSum = sum;
    cout << maxSum << '\n';
    
    for(int i = len; i< N; i++){ //855 ~ 7435
        sum += ad[i];
        q.push(ad[i]);
        sum -= q.front();
        q.pop();
        if(sum > maxSum){ // 시청자 수가 더 많다면
            idx = i - len + 1; //구간합이 최대인 구간의 첫 인덱스
    
            maxSum = sum;
        }
    }
    
    string answer = secToStr(idx);
    cout << answer << '\n';
    
    return 0;
}

