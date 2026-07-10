#include<stdio.h>
void copy(char s[], char d[]){
    int i=0;
    while(s[i] != '\0'){
        d[i]=s[i];
        i++;
    }
    d[i]='\0';
}
int main(){
    char s[100],d[100];
    printf("Enter a string: ");
    fgets(s,sizeof(s),stdin);
    copy(s,d);
    printf("Copied_string:%s",d);
    return 0;
}