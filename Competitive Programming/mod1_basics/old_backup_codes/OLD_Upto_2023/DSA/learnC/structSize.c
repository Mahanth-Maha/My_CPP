#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "Logger.h"

#define LOG(x) printf("%d\n",x);

typedef struct { int i;  char a; } K ;
typedef struct { int i;  long long l; } L ;
typedef struct { long long l;  char a; } M ;
typedef struct { long long l;  char a; int i; } N ;
typedef struct { char a;  long long l; int i; } N2 ;
typedef struct { long long l;  int i; char a; } N3 ;

int main(int argc, char const *argv[])
{
    K p = {3,'k'};
    L q = {3, 234l};
    M r = {34252l,'k'};
    N s = {34252l,'k',34};
    N2 s2 = {'d',34252l,34};
    N3 s3 = {34252l,34,'s'};
    LOG(sizeof(int));
    LOG(sizeof(long long));
    LOG(sizeof(char));
    LOG(sizeof(p));
    LOG(sizeof(q));
    LOG(sizeof(r));
    LOG(sizeof(s));
    LOG(sizeof(s2));
    LOG(sizeof(s3));
    return 0;
}