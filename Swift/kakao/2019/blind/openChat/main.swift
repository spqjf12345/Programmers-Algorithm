//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/02.
//

import Foundation
//var inputDic:[String: String] = [:]
//var answer = [(String, String)]()
//
//func reName(_ id: String, _ name: String) {
//    if inputDic.keys.contains(id) { // id가 저장된 사람이라면
//        for (idx, i) in answer.enumerated() {
//            if i.1 == id {
//                answer[idx].0 = i.0.replacingOccurrences(of: "\(inputDic[i.1]!)", with: "\(name)")
//            }
//        }
//    }
//    inputDic[id] = name
//
//}
//
//func solution(_ record:[String]) -> [String]{
//    let array = record.split(separator: ",")[0].map { String($0) }
//
//    for line in array {
//        let l = line.split(separator: " ").map { String($0) }
//        let command = l[0]
//        let id = l[1]
//
//
//        switch command {
//        case "Enter":
//            let name = l[2]
//            reName(id, name)
//            answer.append(("\(name)님이 들어왔습니다.", id))
//        case "Leave":
//
//            answer.append(("\(inputDic[id]!)님이 나갔습니다.", id))
//        case "Change":
//            let name = l[2]
//            reName(id, name)
//        default:
//            print("")
//        }
//    }
//    return answer.map { $0.0 }
//}
//print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))

func solution(_ record:[String]) -> [String]{
    var inputDic:[String: String] = [:]
    var answer = [String]()
    for line in record {
        let l = line.components(separatedBy: " ")
        if l.count > 2 {
            inputDic[l[1]] = l[2]
        }
    }
    
    for line in record {
        let l = line.components(separatedBy: " ")
        let command = l[0]
        let id = l[1]
        
        switch command {
        case "Enter":
            answer.append("\(inputDic[id]!)님이 들어왔습니다.")
        case "Leave":
            answer.append("\(inputDic[id]!)님이 나갔습니다.")
        default:
            print("")
        }
    }
    return answer
}
