//
//  main.swift
//  SOMAð©ð»âð»
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
            if(check(u)) { // ì¬ë°ë¥¸ ë¬¸ìì´ì¸ì§
                return u + recursive(v)
            }else { // ì¬ë°ë¥¸ ê´í¸ ë¬¸ìì´ì´ ìëë¯ë¡
                let newString = "(" + recursive(v) + ")"
                u.removeFirst()
                u.removeLast()
                //ëë¨¸ì§ ê´í¸ ë°©í¥ ë¤ì§ê¸°
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
        // Index ê° íë
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to + 1)
        
        // íì±
        return String(self[startIndex ..< endIndex])
    }
}
