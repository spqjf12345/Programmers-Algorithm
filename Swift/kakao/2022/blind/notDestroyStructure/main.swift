//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/05/02.
//

import Foundation

//func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
//    var map = board
//    var answer = 0
//    for i in skill {
//        let type = i[0]
//        let r1 = i[1]
//        let c1 = i[2]
//        let r2 = i[3]
//        let c2 = i[4]
//        let degree = i[5]
//
//
//        if type == 1 { // 적군
//
//            for i in stride(from: r1, to: r2+1, by: 1) {
//                for j in stride(from: c1, to: c2+1, by: 1){
//                    map[i][j] -= degree
//                }
//            }
//        }else { // 아군
//            for i in stride(from: r1, to: r2+1, by: 1) {
//                for j in stride(from: c1, to: c2+1, by: 1){
//                    map[i][j] += degree
//                }
//            }
//        }
//    }
//
//    for i in map {
//        answer += i.filter { $0 >= 1 }.count
//    }
//    return answer
//}
func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
    var cnt = 0
    var arr = Array(repeating: Array(repeating: 0, count: board[0].count + 1), count: board.count + 1)
    for i in skill {
        let type = i[0] == 2 ? true : false
        let r1 = i[1]
        let c1 = i[2]
        let r2 = i[3]
        let c2 = i[4]
        let degree = type == true ? i[5] : -i[5]
        arr[r1][c1] += degree
        arr[r2+1][c2+1] += degree
        arr[r2+1][c1] -= degree
        arr[r1][c2+1] -= degree
    }
    
    for i in 1..<arr.count { // row -> botton
        for j in 0..<arr[0].count {
            arr[i][j] += arr[i-1][j]
        }
    }
    
    for i in 1..<arr[0].count {
        for j in 0..<arr.count{
            arr[j][i] += arr[j][i-1]
        }
    }
    
    for i in 0..<board.count {
        for j in 0..<board[i].count {
            arr[i][j] += board[i][j]
            if arr[i][j] > 0 { cnt += 1 }
        }
    }
    

    return cnt
    
}
print(solution([[5, 5, 5, 5, 5], [5, 5, 5, 5, 5], [5, 5, 5, 5, 5], [5, 5, 5, 5, 5]], [[1, 0, 0, 3, 4, 4], [1, 2, 0, 2, 3, 2], [2, 1, 0, 3, 1, 2], [1, 0, 1, 3, 3, 1]]))
