////
////  main.swift
////  SOMA👩🏻‍💻
////
////  Created by JoSoJeong on 2022/05/06.
////
//
//import Foundation
//
//func solution(_ info:[String], _ query:[String]) -> [Int] {
//    var arr = [[String]]()
//    var answer = [Int]()
//    var query = query
//    for i in info {
//        let line = i.components(separatedBy: " ")
//        arr.append(line)
//    }
//
//    for k in 0..<query.count {
////        while query[k].contains("and") {
////            query[k] = query[k].replacingOccurrences(of: "and", with: "")
////        }
//
//        let q = query[k].components(separatedBy: " ").filter { $0 != "and" }
////        print("q \(q)")
////        print(arr.filter { ($0[0] == q[0] || q[0] == "-") && ($0[1] == q[1] || q[1] == "-") && ($0[2] == q[2] || q[2] == "-") && ($0[3] == q[3] || q[3] == "-") && ($0[4] >= q[4] || q[4] == "-") })
//        answer.append(arr.filter { ($0[0] == q[0] || q[0] == "-") && ($0[1] == q[1] || q[1] == "-") && ($0[2] == q[2] || q[2] == "-") && ($0[3] == q[3] || q[3] == "-") && (Int($0[4])! >= Int(q[4])! || q[4] == "-") }.count)
//    }
//    return answer
//}
//

import Foundation

func solution(_ info:[String], _ query:[String]) -> [Int] {
    var dic: [String : [Int]] = [:]
    var answer = [Int]()
       
   func combination(_ arr: [String], _ curIdx: Int, _ score: Int) {
       if curIdx == arr.count {
           let result = arr.joined()
           
           if dic[result] != nil {
               dic[result]!.append(score)
           } else {
               dic[result] = [score]
           }
       } else {
           var temp = arr
           combination(temp, curIdx + 1, score)
           temp[curIdx] = "-"
           combination(temp, curIdx + 1, score)
       }
       return
   }
    
    func lowerbound(_ arr: [Int], _ score: Int) -> Int {
           var low = 0
           var high = arr.count
           
           while low < high {
               let mid = (low + high) / 2
               if score <= arr[mid] {
                   high = mid
               } else {
                   low = mid + 1
               }
           }
           // low = score 이상의 점수가 처음 등장하는 인덱스
           return arr.count - low
       }
    
    for i in info {
        var line = i.components(separatedBy: " ")
        let score = Int(line[4])!
        line.removeLast()
        combination(line, 0, score)
    }
    
    for (q, s) in dic { // 점수 오름차순으로 정렬
        let sorted = s.sorted(by: <)
        dic[q] = sorted
    }
    
    for k in 0..<query.count {
        var q = query[k].components(separatedBy: " ").filter { $0 != "and" }
        let score = Int(q[4])!
        q.removeLast()
        let key = q.joined()
        if dic[key] == nil {
            answer.append(0)
        }else {
            answer.append(lowerbound(dic[key]!, score))
        }

    }
    return answer
}

print(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"], ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]))
