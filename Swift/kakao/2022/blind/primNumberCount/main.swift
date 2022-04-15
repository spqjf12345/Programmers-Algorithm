//
//  main.swift
//  SOMA👩🏻‍💻
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

//진수 변환
func solution(_ n:Int, _ k:Int) -> Int {
    var answer = 0
    var set = Set<Int>()
    let kcimal = String(n, radix: k)
    let arr = kcimal.split(separator: "0")
    for (idx, i) in arr.enumerated() {
        // i의 부분집합
        if isPrime(Int(i)!) {
            answer += 1
        }
        
            
//            let arr = i.map { String($0)}
//            let intArr = subsets(arr)
            
//            for i in intArr {
//                if i.isEmpty { continue }
//                var st = Int(i.joined(separator:""))!
//                if(isPrime(st)) {
//                    answer += 1
//                    set.insert(st)
//                }
//            if !set.contains(st) {
//                if(isPrime(st)) {
//                    answer += 1
//                    //set.insert(st)
//                }
//            }
//        }
//   }
        
    }
    return answer
}

func subsets(_ nums: [String]) -> [[String]] {
    var result: [[String]] = []
    if nums.count == 0 { return result }
    result.append([])
    for i in 0..<nums.count{
        let count = result.count
        for j in 0..<count {
            result.append(result[j] + [nums[i]])
        }
    }
    return result
}


print(solution(437674, 3))
