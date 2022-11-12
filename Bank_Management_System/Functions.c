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
    char FirstName[10],FamilyName[10];
    struct date DOB;
    char Citizenship[10];
    char Address;
    int balance;
    
}old;

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
        printf("\nPress 0 to return to the main menu: ");
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

   


    //fprintf(pfile,"%s %s\t%s\t%s\t%s\t%s","AccountNumber","Name","Date of Birth","Citizenship","Address");
    
    system("clear");
    printf("\t\t  Bank Management System\n");
    printf("############## Welcome To The Account Creation Tool #############\n");
    printf("#################################################################\n");
    printf("#################################################################\n\n");

    while(1){
        printf("\nEnter the account number for client(9 digits): ");
        scanf("%d",&cl.AccountNumber);
        if (cl.AccountNumber <1000000000){printf("\nEnter the account number for client(9 digits): ");break;}
    }
    FILE *pfile = fopen("database.txt","r");


    noFile(pfile);


    //checking if the account number is already in use
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship)!= EOF)
        {
            if (cl.AccountNumber==old.AccountNumber)
            {printf("account number already in use !");
            delay(5000);
            system("clear");
            reg();}
        }

    fclose(pfile);



   
    pfile=fopen("database.txt","a");


    fprintf(pfile,"\n%d ",cl.AccountNumber);
    //inputting the name 
    printf("\nEnter the first name of the client: ");
    scanf("%s",cl.FirstName);
    fprintf(pfile,"%s ",cl.FirstName);
    printf("\nEnter the family name of the client: ");
    scanf("%s",cl.FamilyName);
    fprintf(pfile,"%s ",cl.FamilyName);
    printf("\nEnter the client's date of birth(accepted format dd/mm/yyyy): ");
    scanf("%d/%d/%d",&cl.DOB.day,&cl.DOB.month,&cl.DOB.year);
    fprintf(pfile,"%d/%d/%d ",cl.DOB.day,cl.DOB.month,cl.DOB.year);
    printf("\nEnter the citizenship :");
    scanf("%s",cl.Citizenship);
    fprintf(pfile,"%s ",cl.Citizenship);
    fclose(pfile);

    printf("\nAccount has been created successfully!/n");
}

