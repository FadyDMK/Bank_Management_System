#include<stdio.h>

void menu();
void reg();
void info();
void Trans();
void dep();
void close();
void list();
int noFile(FILE *pfile);
void delay(int j);
void back();
int count(int n);
void transfer(FILE *old, FILE *new,int a,int AccNum);
int VerfDate(char dates);