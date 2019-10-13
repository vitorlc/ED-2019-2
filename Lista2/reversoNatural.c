#include <stdio.h>

int reversoNaturais(int num);

int main(){
    int m = 0;
    scanf("%d", &m);
    reversoNaturais(m);
    return 0;
}

int reversoNaturais (int num){
    int reverse=0, check=0;
    check = num%10;
    if (num == 0)
      return num;
    if (check == 0){
        reverse = num/10;
        return reversoNaturais (reverse);
    }else {
        printf("%i",  check);
        return reversoNaturais (num/10);
    }
    }
