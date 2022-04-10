//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/08.
//

import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var repost_list: [String: String] = [:]
    var count_list: [String: Int] = [:]
    var result: [Int] = Array(repeating: 0, count: id_list.count)
    
    for i in report {
        let arr = i.split(separator: " ").map { String($0) }
        repost_list[arr[0]] = arr[1] // muzi : [frodo, neo]
        count_list[arr[1], default: 0] += 1
    }
    print(count_list)
    for (idx, i) in id_list.enumerated() {
        if let report = count_list[i] {
            print("\(i) \(report) \(idx)")
            if(report >= k) { // k번 이상 신고된 유저면
                //i(신고된 유저)를 키로 가지고 있는 사람의 인덱스에 +1
//                if let key = repost_list.someKey(forValue: i) {
//                    for j in repost_list {
//
//                    }
//                    result[index] += 1
//                }

            }
        }

    }

    return result
}

extension Dictionary where Value: Equatable {
    func someKey(forValue val: Value) -> Key? {
        return first(where: { $1 == val })?.key
    }
}

print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))
