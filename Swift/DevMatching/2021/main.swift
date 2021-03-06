//
//  main.swift
//  SOMAð©ð»âð»
//
//  Created by JoSoJeong on 2022/04/08.
//

import Foundation
// pride = 7 - ë§ì¶ ê°ì

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var maxScore = 0
    var minScore = 0
    var iCount = 0

    var win = Set(win_nums)
    for i in lottos {
        if(i == 0) { // ì§ìì§ ì«ì ì²ë¦¬
            iCount += 1
        }
        if(win.contains(i)){ // ë§ì¶¤
            maxScore += 1
            minScore += 1
            win.remove(i)
        }
    }
    
    if(win.count - iCount >= 0){ // ì±ì¸ì ììë§í¼ ë§ì¶ê¸°
      maxScore += iCount
    }
    
    return [min(7 - maxScore, 6),  min(7 - minScore, 6)] // ë±ì
}
