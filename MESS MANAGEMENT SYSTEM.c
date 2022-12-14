//// **** MESS MANAGEMENT SYSTEM ****

/*
Mentors  ----->>1.Piyush Khairnar.
				2.Dhyaneshwar ware 
				3.Aditya Yadav. 
*/

/////////////////////////////////////////////////////////
/////////////////////////////////
//
// NAME : Yash Tushar Mahajan.
// Date : 05/05/2022.
// Mobile no - 9307887972.
//
////////////////////////////////
/////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<string.h>

#define filename "Mess-Management-records.txt"
#define ENTER 13
#define TAB 9
#define BKSPACE 8
#define SPACE 32

int main_exit = -1;

struct Customer
{
    int  id;
    char name[20];
    char contact[15];
    int AmountPaid;
    int present;
    char date[20];
} s,s1,t;

FILE *fp;
void update();                    ///1
void display();                       ///2
void input();                             ///3
void fordelay(int);
void menu();                                  ///4
void del();                                       ///5
void sortbyid();                                      ///6
void dailyattendance();                                   ///7
void particular();                                            ///8
void main_menu();

int main()
{
   int i = 0;
	for(i=0; i<120; i++)
    {
        printf("\xdb");
    }
	 char pass[10],password[10]="ACSES";

    printf("\n\n\t\tEnter the password to login:");
    i=0;
    char ch = '\0';
    while(1)
    {
    	ch=getch();
    	if(ch==ENTER)
    	{
    		pass[i]='\0';
    		break;
		}
		else if(ch==BKSPACE)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else if(ch==TAB || ch==SPACE)
		{
			continue;
		}
		else
		{
			pass[i]=ch;
			printf("*");
			i++;
		}
	}
    if (strcmp(pass,password)==0) // this is the function in string lab.Compair the string 
        {printf("\n\n\t\tYOU ARE IN !\n\t\tLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf("..");
        }
                system("cls");
            main_menu();
        }
    else
        {   printf("\n\n\t\tWrong password!!\a\a\a");
            login_try:
            printf("\n\t\tEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
            }
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
    return 0;
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void main_menu()
{
	printf("\n\t\t******WELCOME TO MESS MANAGEMENT SYSTEM******\n\n");
    int op;
    while(1)
    {
        system("cls");
        system("COLOR 5E");   //purple-yellow
        printf("\n  Choose any one option        :\n ");
        printf("\n1.New Addimission              :\n ");
        printf("\n2.Modify Customer info         :\n ");
        printf("\n3.Display records              :\n ");
        printf("\n4.Display menu of mess         :\n ");
        printf("\n5.Delete a particular          :\n ");
        printf("\n6.For mess daily attendance    :\n ");
        printf("\n7.About particular info        :\n ");
        printf("\n0.Exit the program             :\n ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            input();
            break;
        case 2:
            update();
            break ;
        case 3:
            display();
            break ;
        case 4:
            menu();
            break ;
        case 5:
            del();
            break;
        case 6:
            dailyattendance();
            break;
        case 7:
            particular();
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid choice... \n\n");
            break;
        }
    }
    system("cls");
    system("COLOR 0A + BLINK ");//GREEN
    printf("Process completed... \n\n");

    return;

}

///   DATA PROCESSING ON FILE
/// CHECKING THE VALIDITY OF INPUTS ///
/// To check validity of id ///

int valid_id(int id)
{
    int i;
    for(i=0; id>0; i++)
        id/=10;
    if(i==0||i>4)
    {
        printf("\nInvalid id (id should be maximum 4 digit number and NO alphabets.)\n");
        return 0;
    }
    else
        return 1;
}
/// to check validity of name ///
int valid_name(char name[])
{
    int i;
    if(!strlen(name))
        return 0;
    for(i=0; i<strlen(name); i++)
    {
        if(!(name[i]>=65&&name[i]<=90||name[i]>=97&&name[i]<=122||name[i]==32 ))
        {
            printf("\nInvalid Customer name\n");
            return 0;
        }
    }
    return 1;
}
/// to check validity of contact ///
int valid_contact(char contact[])
{
    int i;
    if(strlen(contact)==11)
    {
    	if(contact[0]!='0')
    	{
    		printf("Invalid Contact No.\n");
    		return 0;
		}
		if(!(contact[1]=='7' || contact[1]=='8' || contact[1]=='9'))
        {
            printf("\nInvalid Contact no.\n");
            return 0;
        }
	}
	else if(strlen(contact)==10)
	{
        if(!(contact[0]=='7' || contact[0]=='8' || contact[0]=='9'))
        {
            printf("\nInvalid Contact no.\n");
            return 0;
        }
	}
    else if(strlen(contact)!=10)
    {
        printf("\nInvalid Contact no.\n");
        return 0;
    }
    for(i=0; i<strlen(contact); i++)
    {
        if(contact[i]<48||contact[i]>57)
        {
            printf("\nInvalid Contact no.\n");
            return 0;
        }
    }
    return 1;
}
char* camel_case(char *name)
{
    int i=0;
    if(*(name+i)>=97&&*(name+i)<=122)
        *(name+i)=*(name+i)-32;
    i++;
    while(*(name+i))
    {
        if(*(name+i)==32&&*(name+i+1)!=32)
        {
            if(*(name+i+1)>=97&&*(name+i+1)<=122)
                *(name+i+1)=*(name+i+1)-32;
            i++;
        }
        else if(*(name+i)>=65&&*(name+i)<=90)
            *(name+i)=*(name+i)+32;
        i++;
    }
    return name;
}


/// Provide id

int provide_id()
{
    int id=0;
    fp=fopen(filename,"rb+");
    if (!fp)
    {
        system("COLOR 5C");   //purple-yellow
        printf(" File not found or unable to open the input file!!\n\n");
    }
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        id=s.id;
    }


    return ++id;   /// We provide id
}
///  INPUT  DATA

void input()
{
    system("cls");
    system("COLOR 09");   //black-blue
    fp=fopen(filename,"ab");
    if (!fp)
    {
        printf(" File not found or unable to open the input file!!\n");

    }

    s.id=provide_id();
    printf("Enter Customer name     : ");
    fflush(stdin);
    gets(s.name);
    while(!valid_name(s.name))
    {
        printf("Enter Customer name     : ");
        fflush(stdin);
        gets(s.name);
    }
    camel_case(s.name);
    printf("Enter Customer contact  : ");
    fflush(stdin);
    gets(s.contact);
    while(!valid_contact(s.contact))
    {
        printf("Enter Customer contact  : ");
        fflush(stdin);
        gets(s.contact);
    }
    int amt_cpy=0;
    printf("Enter Customer AmountPaid : ");
    fflush(stdin);
    scanf("%d",&amt_cpy);
    while(amt_cpy!=2100){
 	printf("Enter Customer AmountPaid : ");
    fflush(stdin);
    scanf("%d",&amt_cpy);  	
	}
    s.AmountPaid=amt_cpy;
    s.present=0;

    ///Auto-Date-system
    ///Current 

    char CurrDate [20]=  __DATE__ ;
    strcpy(s.date,CurrDate);
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
    system("COLOR 0A");//GREEN

    printf("\nData saved successfully... \n\n");
    printf("\nCustomer Unique Id is %d   \n\n",s.id);     

    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}

///Displaying records of customers 

void display()
{
    system("cls");
    fp=fopen(filename,"rb");
    printf("%-5s %-20s %-15s %-15s %-20s %-10s\n","Id","Name","Contact","AmountPaid","Attendance","Date");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("%-5d %-20s %-15s %-15d %-20d %-10s\n\n",s.id,s.name,s.contact,s.AmountPaid,s.present,s.date);
    }
    fclose(fp);

    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}

/// Update  customer's  information

void update()
{
    system("COLOR 5E");   //purple-yellow
    int  f=0;
    int id1=0;
    printf("Enter Id To Update: ");
    fflush(stdin);
    scanf("%d",&id1);

    fp=fopen(filename,"rb+");
    if (!fp)
    {
        system("COLOR 5C");   //purple-yellow
        printf(" File not found or unable to open the input file!!\n\n");

    }

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(id1==s.id)
        {
            f=1;

            printf("Enter New Name    : ");
            fflush(stdin);
            gets(s.name);

            while(!valid_name(s.name))
            {
                printf("Enter New Name    : ");
                fflush(stdin);
                gets(s.name);
            }
            camel_case(s.name);

            printf("Enter Contact     : ");
            fflush(stdin);
            scanf("%s",s.contact);

            while(!valid_contact(s.contact))
            {
                printf("Enter Contact     : ");
                scanf("%s",s.contact);
            }

            printf("Enter New AmountPaid: ");
            scanf("%d",&s.AmountPaid);
            s.present=s.present%30;
            char CurrDate[20] =  __DATE__ ;
            strcpy(s.date,CurrDate);
            fseek(fp,-sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
            fclose(fp);
            break;
        }
    }
    if(f==0)
    {
        system("cls");
        system("COLOR 5C");   //purple-yellow
        printf("\n\nRecord Not Found...\n\n");
    }
    else
    {
        system("cls");
        printf("\n\nModified Successfully...\n\n");
        printf("\nCustomer Unique Id is %d   \n\n",id1);
    }

    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);

}

///  Delete Customer's record of particular 

void del()
{
    int f=0;
    int  id1=0;
    system("COLOR B0");   //    -Black
    printf("\nEnter mess id  to delete: ");
    fflush(stdin);
    scanf("%d",&id1);

    FILE *ft;
    fp = fopen(filename,"rb");
    ft = fopen("temp.txt","ab");

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        if(id1==s.id)
        {
            f=1;
        }
        else
        {
            fwrite(&s,sizeof(s),1,ft);
        }

    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    //  rename("temp.txt",filename);
    fp = fopen(filename,"wb");
    ft = fopen("temp.txt","rb");

    while(fread(&s,sizeof(s),1,ft)==1)
    {

        fwrite(&s,sizeof(s),1,fp);

    }
    fclose(fp);
    fclose(ft);
    remove("temp.txt");

    if(f==0)
    {
        system("cls");
        system("COLOR BC");   //purple-yellow
        printf("\n\nRecord Not Found...\n\n");
    }
    else
    {
        system("cls");
        system("COLOR 5A");   //purple-yellow
        printf("\n\nRecord Deleted Successfully...\n\n");
    }

    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);

}

///  Mess Menu
///Mess protocols- Ethics 
void menu()
{
    system("cls");
    system("COLOR 30");   //purple-yellow

    printf("\n****************************************************************************************************************************************************************");
    printf("\n****************************************************************************************************************************************************************");
    printf("\n  W       W       W  EEEEEE L      CCCCCC OOOOOO  M               M  EEEEEE");
    printf("\n  W      W W      W  E      L      C      O    O  M M           M M  E");
    printf("\n  W     W   W     W  E      L      C      O    O  M  M         M  M  E");
    printf("\n  W    W     W    W  EEEEEE L      C      O    O  M   M       M   M  EEEEEE");
    printf("\n  W   W       W   W  E      L      C      O    O  M    M     M    M  E");
    printf("\n  W  W         W  W  E      L      C      O    O  M     M   M     M  E");
    printf("\n  W W           W W  E      L      C      O    O  M      M M      M  E");
    printf("\n  W               W  EEEEEE LLLLLL CCCCCC OOOOOO  M       M       M  EEEEEE");
    printf("\n\n****************************************************************************************************************************************************************");
    printf("\n****************************************************************************************************************************************************************");
    ///INFO- ASTER MESS
    system("COLOR 3E");
    printf("\n\n\t\t\t\t\t MESS MENU \n\n\n");
    printf("***About Food ->\n");
    printf("Sunday    : Non-veg and  Veg\n");
    printf("Monday    : Veg\n");
    printf("Tuesday   : Veg\n");
    printf("Wednesday : Non-Veg and Veg\n");
    printf("Thursday  : Veg\n");
    printf("Friday    : Veg\n");
    printf("Saturday  : Veg\n");
    ///RULES

    printf("\n\t\t\t\t\t\t\t\t\t\n\n RULES \n\n\n");
    //printf("***About Food ->\n");
    printf("1->Students are instructed to come to mess within the alloted time.\n\n");
    printf("2->Get your attendance marked at the counter daily.\n\n");
    printf("3->Inform 2 days before you go for holidays, otherwise payment would not be altered.\n\n");
    printf("4->Payment should be done before the due date.\n\n");         /// Write rules here
    printf("5->No one can take meal to the room. For the sick person, food will be brought to the room by a mess worker \nand the same worker will bring back those utensils.\n\n");
    printf("6->DON'T WASTE FOOD,take the food according to your requirement.\n\n");

    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}

///Daily Attendance

void dailyattendance()

{
    printf("\nEnter id number it will be recorded or -1 to exit ...\n");
    int  id1;
    fflush(stdin);
    scanf("%d",&id1);

    while(id1!=-1)
    {

        fp=fopen(filename,"rb+");
        if (!fp)
        {
            printf(" File not found or unable to open the input file!!\n");

        }
        int f=0;

        while(fread(&s,sizeof(s),1,fp)==1)
        {
            system("cls");
            int id2=(s.id);
            if(id2==id1)
            {
                f=1;
                if(s.present==29)
                {
                    system("COLOR 5C");   //purple-yellow
                    printf("Hi %s today is your last day  of last renewal... \nPlease renew your  mess card ...  ",s.name);
                }
                if(s.present==30)
                {
                    system("COLOR 5E"); //purple-yellow
                    if(s.AmountPaid!=0)
                    {
                        printf("%s today is your first day of renewal...  ",s.name);
                        s.present=0;
                        s.AmountPaid=0;
                    }
                    else
                    {
                        printf("\nPayment due for %d month\n",s.present/30);
                    }
                }
                if(s.present>30)
                {
                    if(s.AmountPaid==0)
                        printf("\nPayment due for %d month\n",s.present/30);
                    else
                        s.present=s.present%30;
                }
                s.present+=1;
                fseek(fp,-sizeof(s),1);
                fwrite(&s,sizeof(s),1,fp);
                fclose(fp);
            }
        }
        if(f==0)
        {
            system("COLOR 5C");   //purple-yellow
            printf("\n\nSorry ID does not found in Record Not Found...\n\n");
        }
        else
        {
            system("COLOR 5A");   //purple-yellow
            printf("\n\nModified Successfully...in %s\n\n",s.name);
        }
        system("COLOR 5E");   //purple-yellow
        printf("\nEnter id number it will be recorded or -1 to exit ...\n");
        fflush(stdin);
        scanf("%d",&id1);
    }

    fclose(fp);

    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}



///    Information  about a particular

void particular()
{
    system("COLOR 5A");   //purple-yellow
    printf("\nEnter id of a particular ...\n");
    int  id1;
    fflush(stdin);
    scanf("%d",&id1);

    fp=fopen(filename,"rb");
    if (!fp)
    {
        printf(" File not found or unable to open the input file!!\n");

    }
    int f=0;

    while(fread(&s,sizeof(s),1,fp)==1)
    {
        int id2=(s.id);
        if(id2==id1)
        {
            f=1;
            system("cls");
            printf("%-5s %-20s %-15s %-15s  %-20s %-10s\n\n","Id","Name","Contact","AmountPaid","Attendance","Date");

            printf("%-5d %-20s %-15s %-15d %-20d %-10s\n\n",s.id,s.name,s.contact,s.AmountPaid,s.present,s.date);

        }

    }
    if(f==0)
        printf("\n\nSorry ID does not found in Record Not Found...\n\n");
    fclose(fp);

    //EXIT option to main menu or out to process
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main_menu();
    else if(main_exit==0)
        exit(0);
}
