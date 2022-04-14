//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/13.
//

import Foundation

func check(_ s: String) -> Bool {
    for i in s {
        if i.isLetter == false {
            return false
        }
    }
    return true
}

func solution(_ str1:String, _ str2:String) -> Int {
    var str1Set = [String]()
    var str2Set = [String]()
    let str1 = str1.lowercased()
    let str2 = str2.lowercased()
    for i in 1..<str1.count {
        let target = str1.substring(from: i-1, to: i)
        if check(target) {
            str1Set.append(target)
        }
        
    }
    
    for i in 1..<str2.count {
        let target = str2.substring(from: i-1, to: i)
        if check(target) {
            str2Set.append(target)
        }
    }

    var sum = str1Set.count + str2Set.count
    
    var inter = 0
    //교집합
    for i in str1Set.indices {
        for j in str2Set.indices {
            if str1Set[i] == str2Set[j] {
                inter += 1
                str2Set.remove(at: j)
                break
            }
        }
    }
    
    //합집합
    sum -= inter

    if sum == 0 { return 65536 }
   

    return Int(Double(inter) / Double(sum) * 65536)
}

extension String {
    func substring(from: Int, to: Int) -> String {
        guard from < count, to >= 0, to - from >= 0 else {
            return ""
        }
        // Index 값 획득
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to + 1) // '+1'이 있는 이유: endIndex는 문자열의 마지막 그 다음을 가리키기 때문
        
        // 파싱
        return String(self[startIndex ..< endIndex])
    }
}
print(solution("aa1+aa2", "AAAA12"))
