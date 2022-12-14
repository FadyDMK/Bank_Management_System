#include"Functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    int balance;
    
}old,check,rec,old2;

//check if the account number exists in the text file
int CheckNum(int AccNum){
    FILE *pfile = fopen("database.txt","r");
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber==AccNum){
            return 1;
            fclose(pfile);
            break;}

        if (feof(pfile)==1){fclose(pfile);return 0;}
    }
}


//counts the number of digits in a number
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
int menu(){
    int choice=0;
    system("clear");

    printf("\t\t  Bank Management System\n");
    printf("################ Welcome To The Main Menu #######################\n");
    printf("#################################################################\n");
    printf("\n\t1)New Client Registration\n\t2)Show Info of An existing Account\n\t3)Make A Money Transfer \n\t4)Close an Account \n\t5)Show All The Existing Clients And Their data\n\t6)Make a Deposit or Withdrawal\n\t0)Exit");
    printf("\n#################################################################\n");
    printf("#################################################################\n\n");
    printf("\nselect your choice: ");
    scanf("%d",&choice);



    /*if (choice==1){reg();}
    else if (choice==2){info();}
    else if (choice==3){Trans();}
    else if (choice==4){close();}
    else if (choice==5){list();}
    else if (choice==6){dep();}
    else if (choice==0){system("exit");}
    else {printf("\nInvalid!!\n");  delay(50000);menu();}*/

    switch(choice)
    {
        case 1:
            reg();
            break;
        case 2:
            info();
            break;
        case 3:
            Trans();
            break;
        case 4:
            close();
            break;
        case 5:
            list();
            break;
        case 6:
            dep();
            break;
        case 0:
            exit(0);
        default:
            printf("\nInvalid!!\n");
            menu();


    }
    
}






//this function will show the info about a specific client
void info(){
    system("clear");
    printf("####################### Client Info #############################\n");
    printf("#################################################################\n");
    printf("type the number of account of the client: ");
    scanf(" %d",&check.AccountNumber);


    FILE *pfile = fopen("database.txt","r");
    //check wether the account number exists in the file or not
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber==check.AccountNumber){
            
            fclose(pfile);
            
            printf("\nName of the client: %s %s ",old.FirstName,old.FamilyName);
            
            printf("\nDate of birth of the client: %d/%d/%d",old.DOB.day,old.DOB.month,old.DOB.year);

            printf("\nCitizenship of the client: %s",old.Citizenship);

            printf("\nCurrent balance in account: %d",old.balance);
            
            break;}

        if (feof(pfile)==1){fclose(pfile);printf("\nThis Account Does not Exist");}
        

    }
 
    printf("\n");
    back();

}


//function to go back to the main menu
void back(){
    int ne;

    fprintf(stderr,"\nPress 0 to return to the main menu: ");
    scanf("%d", &ne);
    getc(stdin);
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
        exit(0);
    }
    }



//This function let's us register a new client
void reg(){
    struct client cl;
    
    system("clear");
    printf("\t\t  Bank Management System\n");
    printf("############## Welcome To The Account Creation Tool #############\n");
    printf("#################################################################\n");
    printf("#################################################################\n\n");


    // Check whether the Account number is unique and has 9 digits
    while(1){
        printf("\nEnter the account number for client(9 digits): ");
        scanf("%d",&cl.AccountNumber);
        if ((count(cl.AccountNumber)!=9)){printf("\nInvalid number try again!");}
        else if (CheckNum(cl.AccountNumber)) {printf("This Account Number Already Exists. PLease Write Another One!");}
        else if ((count(cl.AccountNumber)==9)&&!((CheckNum(cl.AccountNumber)))) {break;}
    }//You need to enter a unique 9-Digit ID for the new client.
    
    
    FILE *pfile = fopen("database.txt","a");
    noFile(pfile);
    fprintf(pfile,"\n%d ",cl.AccountNumber);
    //inputting the name 
    printf("\nEnter the first name of the client: ");
    scanf("%s",cl.FirstName);
    fprintf(pfile,"%s ",cl.FirstName);
    printf("\nEnter the family name of the client: ");
    scanf("%s",cl.FamilyName);
    fprintf(pfile,"%s ",cl.FamilyName);

    char dat[11];

    /*while(1){
        printf("\nEnter the client's date of birth(accepted format dd/mm/yyyy): ");
        
        scanf("%d/%d/%d",&cl.DOB.day,&cl.DOB.month,&cl.DOB.year);
        
        
        if ((cl.DOB.day<=31)&&(cl.DOB.month<=12)&&(cl.DOB.year>1900)&&(cl.DOB.year<2023)){break;}
        else {printf("The date's format is wrong please try again");}
    }*/
    // Check that the date is in the correct form(dd/mm/yyyy)
    while(1){
        printf("\nEnter the client's date of birth(accepted format dd/mm/yyyy): ");
        char date_str[11];
        scanf("%s", date_str);          
        // Check if the date_str contains a forward slash
        char *first_slash = strchr(date_str, '/');
        char *last_slash = strrchr(date_str, '/');
        if (first_slash != NULL && last_slash != NULL && first_slash != last_slash)
            {
                // Check if the date_str contains more than two forward slashes
                if (strchr(first_slash+1, '/') != last_slash){
                    printf("The date's format is wrong please try again");}
                else {// Split the date_str into day, month, and year
                        char *day_str = strtok(date_str, "/");
                        char *month_str = strtok(NULL, "/");
                        char *year_str = strtok(NULL, "/");
                        // Convert the day, month, and year strings to integers
                        cl.DOB.day = atoi(day_str);
                        cl.DOB.month = atoi(month_str);
                        cl.DOB.year = atoi(year_str);
                        // Check if the numbers are correct
                        if ((cl.DOB.day<=31)&&(cl.DOB.month<=12)&&(cl.DOB.year>1900)&&(cl.DOB.year<2023)){break;}}}
                    
        else {printf("The date's format is wrong please try again");}
    }

   



    fprintf(pfile,"%d/%d/%d ",cl.DOB.day,cl.DOB.month,cl.DOB.year);
    printf("\nEnter the citizenship : ");
    scanf("%s",cl.Citizenship);
    fprintf(pfile,"%s ",cl.Citizenship);
    do{
        printf("\nEnter the amount to be deposited in this account: ");
        scanf("%d",&cl.balance);
    }while (cl.balance<0);// Verify that the money is a positive integer

    fprintf(pfile,"%d",cl.balance);
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

    while(1){
        printf("\ntype the number of account of the client: \n");
        scanf(" %d",&check.AccountNumber);
        if (!(CheckNum(check.AccountNumber))){printf("This Account Does Not Exist. Please Try Again!\n");}
        else {break;}
    }
    
    printf("\n1)Deposit in your account");
    printf("\n2)Withdraw from your account");
    printf("\n0)Exit\n");
    printf("\nYour Choice: ");

    do{  
        scanf("%d",&c);
            
    }while ((c!=0) && (c!=1) && (c!=2));


    if(c==0){menu();}
    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    FILE *pfile2 = fopen("database2.txt","a");
    noFile(pfile2);
    
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF){      
        // Look for the desired account and change its balance
        if(old.AccountNumber==check.AccountNumber){
            printf("Current balance in this account: %d",old.balance);
            if (c==1){
                printf("\nHow much money would you like to deposit: ");
                scanf(" %d",&depi);
                old.balance+=depi;}
            if (c==2 && old.balance>=depi){
                printf("\nHow much money would you like to Withdraw: ");
                scanf(" %d",&depi);
                old.balance-=depi;
            }
            else if (c==2 && old.balance>=depi){printf("Insufficient funds in this account!");fclose(pfile);fclose(pfile2);back();}
        }
        
        fprintf(pfile2,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
 

    }


    fflush(pfile);
    fflush(pfile2);
    fclose(pfile);
    fclose(pfile2);
    remove("database.txt");
    rename("database2.txt","database.txt");
    back();

}





//this function makes a money transfer between two accounts that exist in the database

void Trans(){
    int dep;
    system("clear");
    printf("################## Transfer Menu ####################\n");
    printf("#################################################################\n");
    while(1){
        printf("\ntype the number of account of the Sender: \n");
        scanf(" %d",&check.AccountNumber);
        if (!(CheckNum(check.AccountNumber))){printf("This Account Does Not Exist. Please Try Again!\n");}
        else {break;}
    }
 
  

    while(1){
        printf("\ntype the number of account of the Receiver: \n");
        scanf(" %d",&rec.AccountNumber);
        if (!(CheckNum(rec.AccountNumber))){printf("This Account Does Not Exist. Please Try Again!\n");}
        if (check.AccountNumber==rec.AccountNumber) {printf("The Receiver Can't Be The Sender!\n");}
        else {break;}
    }


    do {
            printf("\nhow much do you want to withdraw? (has to be a positive integer): ");
            fflush(stdout);
            scanf(" %d",&dep);
            fflush(stdout);
    }while (dep<=0);


    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    FILE *new = fopen("newdatabase.txt","a");
    noFile(new);

    int cond=0;
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber==check.AccountNumber && old.balance>=dep){
                old.balance-=dep;
                cond++;
                fprintf(new,"%d %s %s %d/%d/%d %s %d",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
    }}

    //if the account has insufficient funds to make the transfer it won't go through
    if (!cond) {printf("this account has insuffficient funds to make this transfer \nor this account does not exit");fflush(stdout);fclose(pfile);fclose(new);back();}

    //Reset the pointer to the start of the file
    rewind(pfile);
    
    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if (old.AccountNumber==rec.AccountNumber){
             old.balance+=dep;
             fprintf(new,"\n%d %s %s %d/%d/%d %s %d",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
        }
        if(old.AccountNumber!=rec.AccountNumber && old.AccountNumber!=check.AccountNumber) {fprintf(new,"\n%d %s %s %d/%d/%d %s %d",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance); }
    }

    printf("\n Money successfully transfered!");
    fflush(stdout);
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

    scanf(" %d",&check.AccountNumber);
    FILE *pfile = fopen("database.txt","r");
    noFile(pfile);
    FILE *new = fopen("newdatabase.txt","w");
    noFile(new);

    while(fscanf(pfile,"%d %s %s %d/%d/%d %s %d",&old.AccountNumber,old.FirstName,old.FamilyName,&old.DOB.day,&old.DOB.month,&old.DOB.year,old.Citizenship,&old.balance)!= EOF)
    {
        if(old.AccountNumber!=check.AccountNumber){
            fprintf(new,"%d %s %s %d/%d/%d %s %d\n",old.AccountNumber,old.FirstName,old.FamilyName,old.DOB.day,old.DOB.month,old.DOB.year,old.Citizenship,old.balance);
        }}
    
   
    
    fflush(pfile);
    fflush(new);
    fclose(pfile);
    fclose(new);
    remove("database.txt");
    rename("newdatabase.txt","database.txt");

    printf("\nAccount successfully deleted");
    fflush(stdout);

    back();
 
}