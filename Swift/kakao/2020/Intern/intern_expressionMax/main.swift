//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/14.
//

import Foundation
func calc(_ n1: Int64, _ n2: Int64, _ op: String) -> Int64 {
    switch op {
    case "+":
        return n1 + n2
    case "*":
        return n1 * n2
    case "-":
        return n1 - n2
    default:
        return 0
    }
}

func solution(_ expression:String) -> Int64 {
    let priority: [[String]] = [["*", "+", "-"], ["*", "-", "+"], ["+", "*", "-"], ["+", "-", "*"], ["-", "+", "*"], ["-", "*", "+"]]
    var str = expression
    var arr = str.components(separatedBy: ["-", "*", "+"]).map { Int64(String($0))! }
    var op: [String] = []
    
    //op 순서대로 계산
    for i in str {
        if i == "-" {
            op.append("-")
        }else if i == "*" {
            op.append("*")
        }else if i == "+" {
            op.append("+")
        }
    }
    
    var answer:Int64 = 0
    for i in priority {
        var now = i
        var result = arr
        var nowOp = op
        for ii in now {
            while nowOp.contains(ii) {
                if let index = nowOp.firstIndex(of: ii) {
                    result[index] = calc(result[index], result[index+1], ii)
                    result.remove(at: index+1) // 계산한 숫자 지우기
                    nowOp.remove(at: index)
                }
            }
            
        }
        if result.count != 1 { continue }
        if result.first! < 0 { //절대값
            answer = max(answer, -result.first!)
        }else {
            answer = max(answer, result.first!)
        }
        
    }
    return answer
}
//print(solution("100-200*300-500+20"))

