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
    int arr[n+1];
    memset(arr, 0, sizeof(arr));


    for(int i = 0; i < stations.size(); i++){
        int start = stations.at(i) - w;
        int end = stations.at(i) + w;
        while(start <= end){
            arr[start] = 1;
            start++;
        }
    }
    
    
    vector<pair<int, int>> segment;

    int s = 0, d = 0;
    int j = 1;
    while(j <n){
        if(arr[j] == 0){
            if(s == 0){
                s = j;
            }else{
                d = j;
            }
        }else{
            if(s != 0){
                d = j;
                segment.push_back({s, d});
                s = 0; d = 0;
            }
        }
        j++;
    }
    //0으로 끝났을 때
    if(s != 0){
        d = j;
        segment.push_back({s, d});
    }

    int antenaCount = 0;


    for(int i =0; i <segment.size(); i++){
        float segLength = (float)segment.at(i).second - (float)segment.at(i).first;
        antenaCount += ceil(segLength / (1+ 2*w));
    }
    cout << antenaCount << '\n';
    
    return 0;
}
