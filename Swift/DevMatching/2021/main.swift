//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/04/08.
//

import Foundation
// pride = 7 - 맞춘 개수

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var maxScore = 0
    var minScore = 0
    var iCount = 0

    var win = Set(win_nums)
    for i in lottos {
        if(i == 0) { // 지워진 숫자 처리
            iCount += 1
        }
        if(win.contains(i)){ // 맞춤
            maxScore += 1
            minScore += 1
            win.remove(i)
        }
    }
    
    if(win.count - iCount >= 0){ // 채울수 있을만큼 맞추기
      maxScore += iCount
    }
    
    return [min(7 - maxScore, 6),  min(7 - minScore, 6)] // 등수
}
