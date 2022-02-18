//
//  basic_skill1.cpp
//  SOMA👩🏻‍💻
//
//  Created by JoSoJeong on 2021/02/23.
//

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main() {
    bool answer = true;
    int n;
    cin >> n;
    
    do{
        int s = n/10;
        int s1 = n%10;
        cout << s <<" " << s1 << endl;
        if(n%(s + s1) !=0){
            answer = false;
        }else{
            
        }
        n=n/10;
    }while((n/10) !=0);
    
    cout << answer << endl;
    return answer;
}
