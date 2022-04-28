//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/23.
//

import Foundation

//func solution(_ numbers:[Int64]) -> [Int64] {
//    var answer: [Int64] = []
//    for i in numbers {
//        if i % 2 == 0 { // 짝수
//            answer.append(i+1)
//        }else { //i보다 크면서 비트 차이 1, 2로 나는 것 찾기
//            var binaryBit = String(i, radix: 2)
//            for j in i+1...100000 {
//                let target = String(j, radix: 2)
//                while binaryBit.count < target.count { // 자릿 수 차이 나면
//                    binaryBit.insert("0", at: binaryBit.startIndex)
//                }
//                var cnt = 0
//                let targetArr = Array(target)
//                let bitArr = Array(binaryBit)
//                for i in 0..<targetArr.count {
//                    if bitArr[i] != targetArr[i] {
//                        cnt += 1
//                    }
//                }
//                if cnt <= 2 {
//                    answer.append(j)
//                    break
//                }
//            }
//        }
//
//
//
//    }
//
//    return answer
//}

func solution(_ numbers:[Int64]) -> [Int64] {
    var answer: [Int64] = []
    for i in numbers {
        if i % 2 == 0 { answer.append(i+1) }
        else {
            let last = (~i) & (i+1)
            let result = (i | last) & ~(last >> 1)
            answer.append(result)
        }
    }
    return answer

}

print(solution([2, 7]))


