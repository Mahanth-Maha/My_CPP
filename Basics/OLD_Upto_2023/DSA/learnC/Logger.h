#pragma once

#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

void logger(float x){
    printf("%f\n",x);
}

void logger(int x){
    printf("%d\n",x);
}

void logger(double x){
    printf("%g\n",x);
}

void logger(char x){
    printf("%c\n",x);
}

void logger(short x){
    printf("%c\n",x);
}

void logger(float* x){
    printf("%f\n",(*x));
}

void logger(int *x){
    printf("%d\n",(*x));
}

void logger(double *x){
    printf("%g\n",(*x));
}

void logger(char *x){
    printf("%c\n",(*x));
}

void logger(short *x){
    printf("%c\n",(*x));
}

void logger(const char *x){
    printf("%s\n",x);
}

void logger(const char *x, int y){
    printf("%s : %d\n",x,y);
}

void logger(const char *x, int *y){
    printf("%s : %d\n",x,(*y));
}

#endif