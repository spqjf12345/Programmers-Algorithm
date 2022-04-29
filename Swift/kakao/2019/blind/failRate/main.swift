//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/28.
//

import Foundation
//시간 초과
func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var arr = [(Int, Double)]()
    for i in 1..<N+1 {
        let people = stages.filter { $0 >= i}
        let parent = Double(people.count)
        let child = Double(people.filter { $0 == i}.count)
        let failRate:Double = Double(child / parent)
        arr.append((i, failRate)) // i단계 실패율
    }

    arr = arr.sorted { (num1, num2) -> Bool in
        if (num1.1 == num2.1) {
            return num1.0 < num2.0
        }
        return num1.1 >= num2.1
    }
    
    return arr.map { Int($0.0) }
}

//let sorted = failures
//        .sorted(by: { (s1, s2) in s1.fail == s2.fail ? s1.stage < s2.stage : s1.fail > s2.fail })
//        .map({ $0.stage })
