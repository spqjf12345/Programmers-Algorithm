//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/28.
//

import Foundation
func checkCnt(_ num: Int) -> Int {
    var radix = 1
    var num = num
    var cnt = 0
    while(radix <= num) {
        if num % radix == 0 {
            cnt += 1
        }
        radix += 1
    }
    return cnt
}

func solution(_ left:Int, _ right:Int) -> Int {
    var l = left
    var r = right
    var answer = 0
    while(l <= r) {
        if l <= 2 {
            if l % 2 == 0 {
                answer += l
            }else{
                answer -= l
            }
        }else {
            var cnt = checkCnt(l)
            if cnt % 2 == 0 {
                answer += l
            }else {
                answer -= l
            }
        }
        
        l += 1
    }
    return answer
}
