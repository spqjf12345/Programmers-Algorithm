//
//  main.swift
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2022/02/18.
//

import Foundation

func solve(phone_book: [String]) -> Bool {
    var book = phone_book
    var answer: Bool = true
    book.sort()
    
    for i in 0..<book.count - 1 {
        var target = book[i]
        let range = book[i+1].startIndex..<book[i+1].endIndex
        if(target == book[i][range]) {
            return false
        }
    }
    return answer;

}


