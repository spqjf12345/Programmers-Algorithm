//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/14.
//

import Foundation

func solution(_ s:String) -> [Int] {
    var str = s
    var reArr = Array(repeating: [Int](), count: 501)
    str.removeFirst()
    str.removeLast()
    var arr = Array(str)
    var result = [Int]()
    var i = 0
    var length = 0
    
    while i < arr.count {
        if arr[i] == "{" {
            length += 1
            var number = ""
            while arr[i] != "}"{
                i += 1
                if arr[i] == "}" {
                    reArr[length].append(Int(number)!)
                }
                else if arr[i] == "," {
                    reArr[length].append(Int(number)!)
                    number = ""
                }

                if 48 <= arr[i].asciiValue! && arr[i].asciiValue! < 57 {
                    number += "\(arr[i])"
                }
            }
        }
        i += 1
    }
    reArr = reArr.filter { !$0.isEmpty }
    reArr.sort { $0.count < $1.count }
    
    print(reArr)
    for i in reArr {
        if i.isEmpty { continue }
        if i.count == 1 { result.append(i[0]) }
        else {
            for num in i {
                if !result.contains(num) {
                    result.append(num)
                }
            }
        }
    }
    return result
}

print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))
