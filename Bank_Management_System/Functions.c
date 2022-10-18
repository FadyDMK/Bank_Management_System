#include"Functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//this function delays the output on the terminal by using two loops
void delay(int j){
    int i,k;
    for (i=0; i<j;i++)
        for(k=0;k<i;k++){}
}



//this function displays the operations that the program can perform
void menu(){
    int choice;
    system("cls");
    printf("\t\t  Bank Management System\n");
    printf("################ Welcome To The Main Menu #######################\n");
    printf("#################################################################\n");
    printf("\n\t1)New Client Registration\n\t2)Show Info of An existing Account\n\t3)Make A Transaction\n\t4)Change Details For An Existing Account\n\t5)Close an Account \n\t0)Exit");
    printf("\n#################################################################\n");
    printf("#################################################################\n\n");
    printf("\nselect your choice: ");
    
    scanf("%d",&choice);
    if (choice==1){reg();}
    //else if (choice==2){info();}
    //else if (choice==3){Trans();}
    //else if (choice==4){mod();}
    //else if (choice==5){close();}
    else if (choice==0){system("exit");}
    else {printf("\nInvalid!!"); delay(50000);menu();}
    
}





//This first function lets us register a new client
void reg(){
    FILE *pfile = fopen("C:\\Users\\fadid\\OneDrive\\Desktop\\Bank_Management_System\\database.txt","w");
    system("cls");
    fprintf(pfile,"%s %s\t%s\t%s\t%s\t%s","Account","Number","Name","Date of Birth","Citizenship","Address");
    fclose(pfile);  
    printf("\t\t  Bank Management System\n");
    printf("############## Welcome To The Account Creation Tool #############\n");
    printf("#################################################################\n");
    printf("#################################################################\n\n");
    delay(50000);

}

