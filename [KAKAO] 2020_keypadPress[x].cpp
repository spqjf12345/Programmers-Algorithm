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

    for(int i =0; i < numbers.size(); i++){
        cout << "numbers : " << numbers.at(i) << '\n';
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
            
            int leftPos = (leftH -1)/3, rightPos = (rightH - 1) /3, centerPos = (numbers.at(i) - 1)/3;
            
            cout << "leftPos rightPos centerPos is " <<  leftPos << " " << rightPos << " " << centerPos << '\n';
            
            if(rightPos != centerPos && (abs(leftPos - centerPos) < abs(rightPos - centerPos))){
                cout << "leftPos and centerPose" << '\n';
                if(leftPos == centerPos && ((numbers.at(i) - 3) == rightH || (numbers.at(i) + 3) == rightH )){
                    if(hand == "right"){
                        rightH = numbers.at(i);
                        cout << "same dis r is " <<  i << " " << numbers.at(i)<< " " << '\n';
                        answer += "R";
                    }else if(hand == "left"){
                        leftH = numbers.at(i);
                        answer += "L";
                    }
                }else{
                    leftH = numbers.at(i);
                    answer+= "L";
                }

            }else if(leftPos != centerPos && (abs(leftPos - centerPos) > abs(rightPos - centerPos))){
                cout << "rightPos and centerPose" << '\n';
                if(rightPos == centerPos && ((numbers.at(i) - 3) == leftH || (numbers.at(i) + 3) == leftH)){
                    if(hand == "right"){
                        rightH = numbers.at(i);
                        cout << "same dis l is " <<  i << " " << numbers.at(i)<< " " << '\n';
                        answer += "R";
                    }else if(hand == "left"){
                        leftH = numbers.at(i);
                        answer += "L";
                    }
                }else {
                    rightH = numbers.at(i);
                    cout << "here1 i is " <<  i << " " << numbers.at(i)<< " " << '\n';
                    answer += "R";
                }
                
            }else if(leftPos == rightPos == centerPos){
                if(hand == "right"){
                    rightH = numbers.at(i);
                    cout << "here2 i is " <<  i << " " << numbers.at(i)<< " " << '\n';
                    answer += "R";
                }else if(hand == "left"){
                    leftH = numbers.at(i);
                    answer += "L";
                }
            }else if((leftH == 2 ||leftH == 5 || leftH == 8 || leftH == 11) && (rightH == 3 ||rightH == 6 || rightH == 9 || rightH == 12)){
                answer+= "L";
            }
            else if((rightH == 2 ||rightH == 5 || rightH == 8 || rightH == 11) && (leftH == 1 ||leftH == 4 || leftH == 7 || leftH == 10)){
                answer+= "R";
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
