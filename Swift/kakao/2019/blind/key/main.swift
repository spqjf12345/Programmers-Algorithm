//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/29.
//

import Foundation

//var combi = [[Int]]()
//var arr = [Int]()
/// 틀린 코드
//func solution(_ relation:[[String]]) -> Int {
//    var answer = 0
//    for i in 0..<relation[0].count {
//        combination(i, relation[0].count)
//    }
//    combi.sort{ $0.count < $1.count }
//
//    var i = 0
//    while(i < combi.count) {
//        var arr: [String] = [] // 중복 체크 배열
//        for line in relation.indices {
//            var str = ""
//            for j in 0..<combi[i].count { // 0, 1, 2, 3, [0, 1]
//                str += relation[line][combi[i][j]]
//            }
//            if !arr.contains(str) {
//                arr.append(str)
//            }else {
//                break
//            }
//        }
//        print("arr \(arr)")
//        if arr.count == relation.count { // 중복 x -> 후보키
//            answer += 1
//            var newCombi = [[Int]]()
//            for k in combi {
//                var isTrue = true
//                for tar in 0..<combi[i].count {
//                    if k.contains(combi[i][tar]) {
//                        isTrue = false
//                    }
//                }
//                if isTrue {
//                    newCombi.append(k)
//                }
//            }
//            combi = newCombi
//            print("target \(combi)")
//        }else {
//            combi.remove(at: i)
//            i += 1
//        }
//
//    }
//
//    return answer
//}
//


/// 수정한 코드
var combi = [[Int]]()
var arr = [Int]()
func solution(_ relation:[[String]]) -> Int {
    var answer = 0
    for i in 0..<relation[0].count {
        combination(i, relation[0].count)
    }
    combi.sort{ $0.count < $1.count }

    var i = 0
    while(i < combi.count) {
        var arr: [String] = [] // 중복 체크 배열
        for line in relation.indices {
            var str = ""
            for j in 0..<combi[i].count { // 0, 1, 2, 3, [0, 1]
                str += relation[line][combi[i][j]]
            }
            if !arr.contains(str) {
                arr.append(str)
            }else {
                break
            }
        }

        if arr.count == relation.count { // 중복 x -> 후보키
            //answer += 1
            //var newCombi = [[Int]]()
            var c = 0
            while(c < combi.count) {
                var cnt = 0

                //var isTrue = true
                for tar in 0..<combi[i].count {
                    if combi[c].contains(combi[i][tar]) {
                        cnt += 1
                    }
                }
                if combi[i] != combi[c] && cnt == combi[i].count {
                    combi.remove(at: c)
                }else { c += 1 }
            }
            i += 1
            //combi = newCombi
        }else {
            //i += 1
            combi.remove(at: i)
        }

    }

    return combi.count
}

func combination(_ start:Int, _ cnt: Int) { // 0, 4
    if start == cnt {
        combi.append(arr)
        return
    }
    for i in start..<cnt {
        arr.append(start)
        combination(i+1, cnt)
        arr.removeLast()
    }
}
func combination(_ start:Int, _ cnt: Int) { // 0, 4
    if start == cnt {
        combi.append(arr)
        return
    }
    for i in start..<cnt {
        arr.append(start)
        combination(i+1, cnt)
        arr.removeLast()
    }
}

print(solution([["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]))
