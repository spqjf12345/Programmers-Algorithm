//
//  main.swift
//  SOMAð©ð»âð»
//
//  Created by JoSoJeong on 2022/04/08.
//

import Foundation
var leftSet:Set = Set([1, 4, 7])
var rightSet: Set = Set([3, 6, 9])

var answer: String = ""
var now_leftPosition = 10 //*
var now_rightPosition = 12 //#

func solution(_ numbers:[Int], _ hand:String) -> String {
    for i in numbers {
        var target = i
        if(i == 0) { target = 11 } // ê³ì°ì ìí´ 12ë¡ ì¹í
        if leftSet.contains(target) {
            answer += "L"
            now_leftPosition = target
        }else if rightSet.contains(target) {
            answer += "R"
            now_rightPosition = i
        }else { // 2, 5, 8 ,0 ê±°ë¦¬ ê³ì°
            let tempLeft = abs(now_leftPosition - target)
            let tempRight = abs(now_rightPosition - target)
            
            let distLeft = tempLeft / 3 + tempLeft % 3
            let distRight = tempRight / 3 + tempRight % 3
            if(distLeft < distRight){
                answer += "L"
                now_leftPosition = target
            }else if(distLeft > distRight) {
                answer += "R"
                now_rightPosition = target
            }else { // ê±°ë¦¬ê° ê°ì ë
                if(hand == "right"){
                    answer += "R"
                    now_rightPosition = target
                }else {
                    answer += "L"
                    now_leftPosition = target
                }
            }
        }
    }
    return answer
}
