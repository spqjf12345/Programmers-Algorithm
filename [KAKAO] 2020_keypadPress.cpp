//
//  [KAKAO] 2020_keypadPress.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/05/02.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    string hand = "right";
    //vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    //vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int rightH = 12;
    int leftH = 10;
    
    string answer = "";

    for(int i =0; i < numbers.size(); i++)
    {
        if(numbers.at(i) == 1 || numbers.at(i) == 4 || numbers.at(i) == 7){
            leftH = numbers.at(i);
            answer+="L";
        }else if (numbers.at(i) == 3 || numbers.at(i) == 6 || numbers.at(i) == 9){
            rightH = numbers.at(i);
            answer+="R";
        }else if(numbers.at(i) == 2 || numbers.at(i) == 5 || numbers.at(i) == 8 || numbers.at(i) == 0){
            if(numbers.at(i) == 0){
                numbers.at(i) = 11;
            }
            
            //매우 신기 ..!
            int temp_left = abs(leftH - numbers.at(i));
            int temp_right = abs(rightH - numbers.at(i));
            
            int distanceL = (temp_left / 3) + (temp_left % 3);
            int distanceR = (temp_right / 3) + (temp_right % 3);
            
            //손잡이로 판단
            if(distanceL == distanceR){
                if(hand == "right"){
                    rightH = numbers.at(i);
                    answer += "R";
                }else if(hand == "left"){
                    leftH = numbers.at(i);
                    answer += "L";
                }
            }else if(distanceL < distanceR){
                leftH = numbers.at(i);
                answer += "L";
            }else{
                rightH = numbers.at(i);
                answer += "R";
            }
        }
    }

    return 0;
}
