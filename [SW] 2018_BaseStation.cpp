//
//  [SW] 2018_BaseStation.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/06.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

//vector<int> stations = {4, 11};
vector<int> stations = {9};
int w = 2;
int n = 16;


int main(){
    int begin = 0; int answer = 0;
           
       for(int i = 0; i < stations.size(); i++){
           int start = stations.at(i) - w - 1;
           int nextStart = stations.at(i) + w - 1;
           if(begin >= start && begin <= nextStart){
               //station 겹치는 부분
               begin = nextStart + 1;
               continue;
           }
           answer += ceil((float)(start - begin)/ (float)(1 + 2*w));
           begin = nextStart + 1;
       }
       
       if(begin < n){
           answer += ceil((float)(n - begin)/ (float)(1 + 2*w));
       }
       cout <<answer << '\n';
    return 0;
}
