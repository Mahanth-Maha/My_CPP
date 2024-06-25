#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
author   : Mahanth Yalla
Usecase  : To generate my g++ compiler
Working  : takes fname.cpp file and compiles as fname.exe and produces output by running fname.exe 
*/


void getName(char const *fname, char arr[]){
    int i = 0,j = 0;
    while(fname[i] != '\0'){
        if(fname[i] == '.') j = i;
        i++;
    }
    i = 0;
    while(i != j){
        arr[i] = fname[i];
        i++;
    }
    arr[i] = NULL;
}

int main(int argc, char const *argv[])
{
    int i = 1,errCode;
    char arr[1024] = "";
    char res[1024] = "";
    if(argc <= 1){
        printf("Use : run <main c++ file> <Rest of C++ files Sep=' '> ");
        return 0;
    } 
    while(i < argc){
        getName(argv[i],arr);
        strcat(res,"g++ " );
        strcat(res,argv[i]);
        strcat(res," -o ");
        strcat(res,arr);
        strcat(res,".exe");
        // compile 
        errCode= system(res);
        if(errCode){
            printf("\nERROR IN COMPILATION\nErrCode : %d",errCode);
            return 0;
        }
        i++;
        res[0] = '\0';
        arr[0] = '\0';
    }
    // run
    getName(argv[1],arr);
    strcat(res,arr);
    strcat(res,".exe");
    errCode= system(res);
    if(errCode)
        printf("\nERROR IN RUNNING\nErrCode : %d",errCode);


    return 0;
}
