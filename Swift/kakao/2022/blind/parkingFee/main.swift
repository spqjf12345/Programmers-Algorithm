//
//  main.swift
//  SOMA๐ฉ๐ปโ๐ป
//
//  Created by JoSoJeong on 2022/04/19.
//

import Foundation
func timeToSecond(_ s: String) -> Double {
    let dateFormatter = DateFormatter()
    dateFormatter.dateFormat = "HH:mm"
    return Double(dateFormatter.date(from: s)!.timeIntervalSince1970)
}

func cal(_ fees: [Int], _ now: Double) -> Int {
    let defaultCost: Int = fees[1]
    let defaultTime: Double = Double(fees[0])
    if now < defaultTime { return defaultCost }
    let div: Double = Double(fees[2])
    let mul: Double = Double(fees[3])
    return defaultCost + Int(ceil((now - defaultTime) / div) * mul)
}
               
func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var answer = [(String, Int)]() // number : cost
    var stack: [String : Double] = [:] // ์์ฐจ ์ถ์ฐจ ์๊ฐ ๊ณ์ฐ
    var dic: [String: Double] = [:] // car number - ๋์  ์๊ฐ

    for i in records {
        let line = i.split(separator: " ").map { String($0) }
        let secondT: Double = timeToSecond(line[0])
        let number = line[1]
        if (stack[number] != 0) && (line[2] == "IN") {
            // ์ฒ์ ์์ฐจ
            stack[number] = secondT
        }else if line[2] == "OUT" {
            // ์๊ฐ ๊ณ์ฐ
            // stack pop
            let last = stack[number]!
            stack[number] = -1
            // dic์ ๋์ 
            dic[number, default: 0] += (secondT - last) / 60  //์ถ์ฐจ์๊ฐ - ์์ฐจ์๊ฐ
        }
    }
    
    for i in stack {
        if i.value != -1 { // ์์ง ๋น ์ ธ๋๊ฐ์ง x
            let lastT = timeToSecond("23:59")
            dic[i.key, default: 0] += (lastT - i.value) / 60
        }
    }
    
    //stack์ด ๋น์ง ์์๋ค๋ฉด ์์ฐจ๋ ํ์ผ๋ ์ถ์ฐจํ์ง ์์ ๊ฒ
    for i in dic {
        //i.value์ ๋ง๋ ์์น์ ๋ฃ์ด์ฃผ๊ธฐ
        let cost = cal(fees, i.value)
        answer.append((i.key, cost))
    }
    
    answer.sort { $0.0 < $1.0 }
    return answer.map { $0.1 }
    
}

print(solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))

