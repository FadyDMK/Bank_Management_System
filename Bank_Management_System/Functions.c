#include"Functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 #define _GNU_SOURCE


//structure for desired date format
struct date
{
    int day,month,year;
};





//this represents the different data of a client
struct client
{
    int AccountNumber;
    char Name[10];
    struct date DOB;
    char Citizenship[10];
    char Address;
    int balance;
    
};

//this function delays the output on the terminal by using two loops
void delay(int j){
    int i,k;
    for (i=0; i<j;i++)
        for(k=0;k<i;k++){}
}



//this function displays the operations that the program can perform
void menu(){
    int choice;
    system("clear");
    printf("\t\t  Bank Management System\n");
    printf("################ Welcome To The Main Menu #######################\n");
    printf("#################################################################\n");
    printf("\n\t1)New Client Registration\n\t2)Show Info of An existing Account\n\t3)Make A Transaction\n\t4)Change Details For An Existing Account\n\t5)Close an Account \n\t6)Show All The Existing Clients And Their data\n\t0)Exit");
    printf("\n#################################################################\n");
    printf("#################################################################\n\n");
    printf("\nselect your choice: ");
    scanf("%d",&choice);



    if (choice==1){reg();}
    //else if (choice==2){info();}
    //else if (choice==3){Trans();}
    //else if (choice==4){mod();}
    //else if (choice==5){close();}
    else if (choice==6){list();}
    else if (choice==0){system("exit");}
    else {printf("\nInvalid!!\n"); delay(50000);system("exit");}
    
}


//list the info of all existing clients
void list(){
    system("clear");

    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    char *line = NULL;
    size_t len = 0;
    size_t read;
    int ne=1;

    //print the contents of the file line by line (-1 marks the end of the file )
    while (((read = getline(&line, &len, pfile)) != -1 ) ) {
        printf("%s",line);
    }

    free(line);
    fclose(pfile);

    while (ne!=0){    
        printf("Press 0 to return to the main menu: ");
        scanf("%d", &ne);
    }
    if (ne==0){menu();}

}




//error handling in the file  
int noFile(FILE *pfile) {
    if (pfile==NULL){    
        printf("error opening the file");
        exit(1);
    }
    }



//This function lets us register a new client
void reg(){
    struct client cl;
    struct client ch;
    FILE *pfile = fopen("database.txt","r");


    noFile(pfile);


    //fprintf(pfile,"%s %s\t%s\t%s\t%s\t%s","Account","Number","Name","Date of Birth","Citizenship","Address");
    
    system("clear");
    printf("\t\t  Bank Management System\n");
    printf("############## Welcome To The Account Creation Tool #############\n");
    printf("#################################################################\n");
    printf("#################################################################\n\n");
    delay(5000);
    
    printf("\nEnter the account number for client: ");
    scanf("%d",&cl.AccountNumber);

  
    

    printf("\nEnter the name of the client: ");
    scanf("%c",cl.Name);

    

    fclose(pfile);
}

