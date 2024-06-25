#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(s1,s2,x,y) printf("%4s ? %4s \t=> %2d <=> %2d : diff %2d\n",s1,s2,x,y,x-y);

int mstrcmp(char *s1,char *s2){
    while(*s1 == *s2 && ((*s1) != '\0') && (*s2 != '\0')){
        s1++;
        s2++;
    }
    if(((*s1) == '\0') && ((*s2) != '\0')){return -1;}
    else if(((*s1) != '\0') && ((*s2) == '\0')){return 1;}
    else if(((*s1) == '\0') && ((*s2) == '\0')){return 0;} 
    else if(s1 > s2){return 1;} 
    else if(s1 < s2){return -1;} 
    return -2;
}

int main(int argc, char const *argv[])
{
    char *s1 = "Abc";
    char *s2 = "abc";
    LOG(s1,s2,strcmp(s1,s2),mstrcmp(s1,s2));
    s1 = "abc";
    s2 = "Abc";
    LOG(s1,s2,strcmp(s1,s2),mstrcmp(s1,s2));
    s1 = "aha";
    s2 = "aha";
    LOG(s1,s2,strcmp(s1,s2),mstrcmp(s1,s2));
    s1 = "Ab";
    s2 = "Abc";
    LOG(s1,s2,strcmp(s1,s2),mstrcmp(s1,s2));
    s1 = "Abc";
    s2 = "Ab";
    LOG(s1,s2,strcmp(s1,s2),mstrcmp(s1,s2));
    s1 = "";
    s2 = "Abc";
    LOG(s1,s2,strcmp(s1,s2),mstrcmp(s1,s2));
    s1 = "Abc";
    s2 = "";
    LOG(s1,s2,strcmp(s1,s2),mstrcmp(s1,s2));
    return 0;
}