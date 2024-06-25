#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getName(char const *fname, char arr[]){
    int i = 0;
    while(fname[i] != '.'){
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
        printf("Use : run <main c file> <Rest of C files Sep=' '> ");
        return 0;
    } 
    while(i < argc){
        getName(argv[i],arr);
        strcat(res,"gcc " );
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
