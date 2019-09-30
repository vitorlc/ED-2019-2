#include <stdio.h>

int fatorialDuplo(int num);

int main(){
    int num = 0, resp;
    scanf("%d", &num);
    resp = fatorialDuplo(num);
    printf("%d", resp);
    return 0;
}

int fatorialDuplo (int num ){
    if(num <= 1) {
        return 1;
    }
    
    if(num%2 == 0 && num !=0){
        return fatorialDuplo (num - 1);
    }else {
        return  num * fatorialDuplo (num - 2);
    }
    
    
}