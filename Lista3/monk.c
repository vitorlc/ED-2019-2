#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool vogal(char c);

int main (){
    int n=0, i=0, j=0;
    scanf("%d", &n);
    char resp[n];
    for (i=0;i<n; i++){
        char name[100];
        int count=0;
        scanf("%s",name);
        for(j=0;j<strlen(name);j++){
            if(vogal(name[j])){
                count++;
            }
        }
        resp[i]= count;
    }

    for(i=0;i<n;i++){
        printf("%d\n", resp[i]);
    }
    return 0;
}

bool vogal (char c){
    c = toupper(c);
    if (c =='A'|| c=='E'|| c=='I'|| c=='O'|| c=='U')
        return true;
    else
        return false;
    
}