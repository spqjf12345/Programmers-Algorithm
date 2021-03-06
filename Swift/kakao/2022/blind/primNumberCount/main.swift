//
//  main.swift
//  SOMAð©ð»âð»
//
//  Created by JoSoJeong on 2022/04/15.
//

import Foundation
func isPrime(_ number: Int) -> Bool {
    var bool = false
    if number == 2 || number == 3 { return true }
    let maxDivider = Int(sqrt(Double(number)))
    bool = number > 1 && !(2...maxDivider).contains { number % $0 == 0 }
    
    return bool
}

//ì§ì ë³í
func solution(_ n:Int, _ k:Int) -> Int {
    var answer = 0
    let kcimal = String(n, radix: k)
    let arr = kcimal.split(separator: "0")
    for i in arr {
        // iì ë¶ë¶ì§í©
        if isPrime(Int(i)!) {
            answer += 1
        }
        
    }
    return answer
}
