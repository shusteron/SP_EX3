#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define WORD 30


int getword(char w[]){

    int count=0;
    
    for(int i=0; i<WORD ;i++){
        scanf("%c",&w[i]);

        if(w[i]!=' ' && w[i]!='\n' && w[i]!='\t'){
            count++;
        }
    }
    return count;

}

int substring(char *str1, char *str2){

    int index=0;
    
    if(strlen(str2)>strlen(str1)){
        return 0;
    }
    for(int i=0;i<strlen(str1); i++){
        if(str1[i]==str2[index]){
            index++;
            if(index==strlen(str2)){
                return 1;
            }
        }else{
            index=0;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n){

    int index=0;
    int skip=0;

    if(strlen(t)>strlen(s)){
        return 0;
    }

    for(int i=0;i<strlen(s);i++){
        if(s[i]==t[index]){
            index++;
        }else{
            skip++;
        }
    }
    printf("skip= %d    index=%d\n",skip,index);
    if(skip==n && index==strlen(t)){
        return 1;
    }
    return 0;
}

int get_line(char s[]){
    int count=0;
    for(int i=0; i<LINE  ;i++){ 
        scanf("%c",&s[i]);
        count++;
        if( s[i]=='\n' ){
            break;
        }
    }
    s[count+1]='\0';
    puts(s);
    

    return count+1;
}

void print_lines(char *str){
    char line[LINE]={'\0'};
    for(int i=0; i<250;i++){
       if(get_line(line)==0){
            break;
       }
       if(substring(line,str)==1){
            puts(line);
       }
    }
}

int main(){
   
   
    return 0;
}