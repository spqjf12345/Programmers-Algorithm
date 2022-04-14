//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/14.
//

import Foundation

func check(_ s: String) -> Bool {
    if s.isEmpty { return true }
    var s = s
    var stack = [String]()
    
    while !s.isEmpty {
        let x = String(s.removeFirst())
        if stack.isEmpty {
            stack.append(x)
        }else if stack.last! == "(" && x == ")" {
            stack.removeLast()
        }else {
            stack.append(x)
        }
    }
    return stack.isEmpty
}

func recursive(_ p: String) -> String {
    if p.isEmpty { return "" }
    else if check(p) {
        return p
    }
    
    var leftCnt = 0
    var rightCnt = 0
    var u = ""
    var v = ""
    for (idx, i) in p.enumerated() {
        if i == "(" {
            leftCnt += 1
            u += "("
        }else if i == ")" {
            rightCnt += 1
            u += ")"
        }
       
        if leftCnt == rightCnt {
            v = p.substring(from: idx+1, to: p.count-1)
            if(check(u)) { // 올바른 문자열인지
                return u + recursive(v)
            }else { // 올바른 괄호 문자열이 아니므로
                let newString = "(" + recursive(v) + ")"
                u.removeFirst()
                u.removeLast()
                //나머지 괄호 방향 뒤집기
                u = u.map {
                    if $0 == "(" { return ")" }
                    else { return "(" }
                }.reduce(""){$0 + $1}
                return newString + u

            }
        }
    }
    
    return ""
}

func solution(_ p:String) -> String {
    return recursive(p)
}

extension String {
    func substring(from: Int, to: Int) -> String {
        guard from < count, to >= 0, to - from >= 0 else {
            return ""
        }
        // Index 값 획득
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to + 1)
        
        // 파싱
        return String(self[startIndex ..< endIndex])
    }
}
