#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGx(x) printf("%d\n",(x));
#define LOGs(x) printf("%s\n",(x));
#define LOGsx(s,x) printf("%s : %d\n",(s),(x));

#define N 100
typedef struct St { char *s;int top;} Stack;

Stack* initStack(){
    Stack *S = malloc(sizeof(Stack));
    S->s = malloc(sizeof(char)*N); 
    for(int i = 0 ; i < N ; i ++) S->s[i] = 0;
    S->top = -1;
    return S;
}
void push(Stack *S,char d) {if(S->top != N-1) S->s[++S->top] = d ;}
char pop(Stack *S){ return (S->top != -1) ?S->s[S->top--]:'\0'; }
char peek(Stack *S){ return (S->top != '\0') ?S->s[S->top]:-1; }


int main(int argc, char const *argv[])
{
    char str[1000],*p = str,c;
    while((c = getchar()) != '\n'){
        *p = c;
        ++p;
    }
    *p = '\n';
    Stack *S = initStack(); 
    p = str;
    int err = 0;
    while(*p){
        if(*p == '('|| *p == '{' || *p == '[') push(S,*p);
        else if (*p == ')'|| *p == '}' || *p == ']'){
            char d =pop(S);
            if(d == '\0') {err = 1;break;}
            if(*p == ')') if(d != '(') {err= 1;break;}
            if(*p == '}') if(d != '{') {err= 1;break;}
            if(*p == ']') if(d != '[') {err= 1;break;}
        }
        p++;
    }
    if(!err){
        if(pop(S) =='\0') err = 1;
    }
    if(err) {
        LOGs("Error while parsing");
    } else {
        LOGs("Valid String : NO Error while parsing");
    }
    return 0;
}