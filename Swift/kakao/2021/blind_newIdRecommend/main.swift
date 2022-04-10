import Foundation

func solution(_ new_id:String) -> String {
    var answer = ""
    //1차 소문자로 치환
    var id = new_id
    id = id.lowercased()
    //2차 다른 특수 문자 제거
    for i in id {
        if(i == "-" || i == "_" || i == "." || i.isLetter || i.isNumber){
            answer.append(i)
        }
    }
    
    //3차
    while answer.contains("..") {
        answer = answer.replacingOccurrences(of: "..", with: ".")
    }
    //4차
    if(answer.hasPrefix(".")){
        answer.removeFirst()
    }
    if(answer.hasSuffix(".")){
        answer.removeLast()
    }
    
    //5차
    if answer == "" {
        answer = "a"
    }
    
    //6차
    if answer.count >= 16 {
        let index = answer.index(answer.startIndex, offsetBy: 15)
        answer = String(answer[answer.startIndex..<index])
        answer[idex].isUppercase
        if(answer.hasSuffix(".")){
            answer.removeLast()
        }
    }
    
    //7차
    if answer.count <= 2 {
        var l = answer.last!
        while(answer.count != 3){
            answer = answer + String(l)
        }
    }
    answer.en
    return answer
    

}
