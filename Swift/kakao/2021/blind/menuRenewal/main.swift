//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/04.
//

import Foundation

var staticCombiArray = [String]()

func combi(_ start: Int, _ r: Int, input: [String], arr: [String]) {
    if arr.count == r {
        staticCombiArray.append(arr.sorted(by: <).joined(separator: ""))
        return
    }else {
        for i in start..<input.count {
            combi(i+1, r, input: input, arr: arr + [input[i]])
        }
    }
}
func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var answer = [String]()
    for i in course { // orders.count C i
        for j in orders {
            combi(0,i, input: j.map { String($0) }, arr: [])
        }
    }
    for i in course {
        let arr = staticCombiArray.filter { $0.count == i }
        
        print(arr)
        var orderCountDic: [String: Int] = [:]
        for j in arr {
            orderCountDic[j, default: 0] += 1
        }
        let maxCnt = orderCountDic.values.max()
        if maxCnt == 1 { continue }
        for i in orderCountDic.keys.filter { orderCountDic[$0] == maxCnt } {
            print("i \(i)")
            answer.append(i)
        }
    }
    print(staticCombiArray)
    return answer.sorted(by: <)
}

print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
