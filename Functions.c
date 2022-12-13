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
    
}old,check,rec,old2;


int count(int n){
    int count=0 ;
    do{
        n /=10;
        ++count;
    }while(n!=0);
    return count;
}





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
    printf("\n\t1)New Client Registration\n\t2)Show Info of An existing Account\n\t3)Make A Money Transfer \n\t4)Close an Account \n\t5)Show All The Existing Clients And Their data\n\t6)Make a Deposit or Withdrawal\n\t0)Exit");
    printf("\n#################################################################\n");
    printf("#################################################################\n\n");
    printf("\nselect your choice: ");
    scanf("%d",&choice);



    if (choice==1){reg();}
    else if (choice==2){info();}
    else if (choice==3){Trans();}
    else if (choice==4){close();}
    else if (choice==5){list();}
    else if (choice==6){dep();}
    else if (choice==0){system("exit");}
    else {printf("\nInvalid!!\n"); fflush( stdout ); delay(50000);menu();}
    
}






//this function will show the info about a specific client
void info(){
    system("clear");
    printf("####################### Client Info #############################\n");
    printf("#################################################################\n");
    setbuf(stdout, NULL);  
    printf("type the number of account of the client: ");
    fflush( stdout );
    FILE *pfile = fopen("database.txt","r");
    scanf("%d ",&check.AccountNumber);
    
    //check wether the account number exists in the file or not
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber==check.AccountNumber){
            fflush( stdout );
            printf("\nName of the client: %s %s ",old.FirstName,old.FamilyName);
            fflush( stdout );
            printf("\nDate of birth of the client: %d/%d/%d",old.DOB.day,old.DOB.month,old.DOB.year);
            fflush( stdout );
            printf("\nCitizenship of the client: %s",old.Citizenship);
            fflush( stdout );
            printf("\nCurrent balance in account: %d",old.balance);
            fflush( stdout );
 

        }

    }
 
    printf("\n");
    fflush( stdout );
    fflush(pfile);
    fclose(pfile);

    back();

}


//function to go back to the main menu
void back(){
    int ne;
    printf("\nPress 0 to return to the main menu: ");
    fflush( stdout );
    scanf("%d", &ne);
    while ((getchar()) != '\n');
    if (ne == 0){menu();}
    else {back();}
}


//list the info of all existing clients
void list(){
    int test=0;
    system("clear");
    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    printf("\n\nAccount Number\t|\tFirst Name\t|\tFamily Name\t|\tDate of Birth\t|\tCitizenship\t|\tBalance\n");
    printf("\n");
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        printf("%-14d\t|\t%-11s\t|\t%-11s\t|\t%2d/%2d/%2d\t|\t%-11s\t|\t%-9d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
        test++;
    }
    fclose(pfile);
    if (test==0) {   
        system("clear");
        printf("\nNO RECORDS!!\n");}
    back();

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
        if (count(cl.AccountNumber)!=9){printf("\nInvalid number try again!");}
        else {break;}
    }
    FILE *pfile = fopen("database.txt","r");


    noFile(pfile);


    //checking if the account number is already in use
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
        {
            if (cl.AccountNumber==old.AccountNumber)
            {printf("account number already in use !!!!\n Try Again \n");
            delay(5000);
            system("clear");
            reg();}
        }


    fflush(pfile);
    fclose(pfile);
    
    pfile=fopen("database.txt","a");
    noFile(pfile);
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
    printf("\nEnter the amount to be deposited: ");
    scanf("%d",&cl.balance);
    fprintf(pfile,"%d \n",cl.balance);
    fflush(pfile);
    fclose(pfile);
    printf("\nAccount has been created successfully!\n");

    back();
}

//this function allows us to change the balance of specific accounts
//through withdrawals or deposits
void dep(){
    int c,depi=0;

    system("clear");
    printf("################## Deposit/Withdraw ####################\n");
    printf("#################################################################\n");
    printf("type the number of account of the client: ");
    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    FILE *new = fopen("newdatabase.txt","a");
    noFile(new);
    scanf("%d \n",&check.AccountNumber);
    printf("\n1)Deposit in your account\n2)Withdraw from your account\n0)Exit\n\nYour Choice: \n");
    fflush(stdout);
    scanf("%d",&c);

    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber==check.AccountNumber){
            
            
            if(c==0){menu();}
            
            
            if(c==1){
            do {
                printf("\nhow much do you want to deposit?: \n");
                scanf("%d",&depi);

            }while (depi==0);
            old.balance+=depi;
            fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
            printf("\nDeposit successful!"); }
            
            
            
            if(c==2){
            do {
                printf("\nhow much do you want to withdraw?: \n");
                scanf("%d",&depi);

            }while (depi==0);

            old.balance-=depi;
            fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
            printf("\nWithdrawal successful!"); }

            else {dep();}
            
            
            
            /*if (c==1){
                printf("type the number of account of the receiver: ");
                scanf("%d ",&rec.AccountNumber);
                printf("\nhow much do you want to withdraw?: ");
                scanf("%d",&dep);
                old.balance-=dep;
                fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance); 
                transfer(pfile,new,dep,rec.AccountNumber);
                printf("\n Money successfully transfered!");}*/
        }
        else {fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance); 
}

    }
    
    fflush(pfile);
    fflush(new);
    fclose(pfile);
    fclose(new);
    remove("database.txt");
    rename("newdatabase.txt","database.txt");

    back();

}





//this function makes a money transfer between two accounts that exist in the database

void Trans(){
    int dep;
    system("clear");
    printf("################## Deposit/Withdraw ####################\n");
    printf("#################################################################\n");
    printf("type the number of account of the client: ");
    scanf("%d ",&check.AccountNumber);
    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    FILE *new = fopen("newdatabase.txt","w");
    noFile(new);
    printf("type the number of account of the receiver: ");
    scanf("%d ",&rec.AccountNumber);
   
    do {
                 printf("\nhow much do you want to withdraw?: ");
                scanf("%d",&dep);

            }while (dep==0);


    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber==check.AccountNumber){
            old.balance-=dep;
            fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
        }
        else if (old.AccountNumber==rec.AccountNumber){
            old.balance+=dep;
            fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
        }
        else {fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance); }


    }
    printf("\n Money successfully transfered!");

    fflush(pfile);
    fflush(new);
    fclose(pfile);
    fclose(new);
    remove("database.txt");
    rename("newdatabase.txt","database.txt");

    back();
}



void close(){
    system("clear");
    printf("################## Deposit/Withdraw ####################\n");
    printf("#################################################################\n");
    printf("type the number of account of the client that will be deleted: ");
    fflush( stdout );
    scanf("%d ",&check.AccountNumber);
    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    FILE *new = fopen("newdatabase.txt","a");
    noFile(new);

    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber!=check.AccountNumber){
            fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
        }}
    printf("\nAccount successfully deleted");
    fflush( stdout );
    fflush(pfile);
    fflush(new);
    fclose(pfile);
    fclose(new);
    remove("database.txt");
    rename("newdatabase.txt","database.txt");
    back();
 

}