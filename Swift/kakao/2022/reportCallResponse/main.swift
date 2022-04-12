//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/08.
//

import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var report_list: [String: Set<String>] = [:]
    var count_list: [String: Int] = [:]
    var result: [Int] = Array(repeating: 0, count: id_list.count)
    var idNumber:[String:Int] = [:]
    
    //index 번호
    for (idx, i) in id_list.enumerated() {
        idNumber[i] = idx
    }
    for i in report {
        let arr = i.split(separator: " ").map { String($0) }
        if report_list[arr[0]] != nil {
            if !report_list[arr[0]]!.contains(arr[1])  {
                count_list[arr[1], default: 0] += 1
            }
            report_list[arr[0]]!.insert(arr[1])
        }else {
            report_list[arr[0]] = [arr[1]]
            count_list[arr[1], default: 0] += 1
        }
        
        
    }
    
    count_list = count_list.filter { $0.value >= k }
    for i in report_list {
        for j in count_list {
            if i.value.contains(j.key) {
                result[idNumber[i.key]!] += 1
            }
        }
    }
//    for i in repost_list {
//        if i.value.count >= k {
//            for j in i.value {
//                result[
//            }
//        }
//    }

//    for (idx, i) in id_list.enumerated() {
//        if let report = count_list[i] {
//            print("\(i) \(report) \(idx)")
//            if(report >= k) { // k번 이상 신고된 유저면
//                let filter = repost_list.filter { $0.value == "\(i)" }
//                for i in filter {
//                    let index = id_list.firstIndex(of: i.key)!
//                    result[index] += 1
//                }
//                //i(신고된 유저)를 키로 가지고 있는 사람의 인덱스에 +1
////                if let key = repost_list.someKey(forValue: i) {
////                    for j in repost_list {
////
////                    }
////                    result[index] += 1
////                }
//
//            }
//        }
//
//    }

    return result
}


print(solution(["con", "ryan"], ["ryan con", "ryan con", "ryan con", "ryan con"], 3))
