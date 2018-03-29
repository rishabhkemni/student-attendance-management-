#include <iostream>

    #include <cstdio>

    #include <cstring>

    #include <cstdlib>

    #include <conio.h>

    #include <iomanip>



using namespace std;
int main() {

    FILE *fp, *ft;

    char another, choice;



struct student {

        char first_name[50], last_name[50];
        int roll_num; //new code added
        char course[100];
        char section[20];
    };

    struct student e;
    char xfirst_name[50], xlast_name[50];
    int xroll_num ; // new code added
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL) {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
             puts("Cannot open file");
             return 0;
        }
    }


 recsize = sizeof(e);

 while(1) {
     system("cls");

     cout << "\t\t     ====== STUDENT INFORMATION SYSTEM ======";
     cout <<"\n\n                                          ";
     cout << "\n\n";
     cout<<" \n\t\t\t======================";
     cout << "\n \t\t\t  1. Add    Records";
     cout << "\n \t\t\t  2. List   Records";
     cout << "\n \t\t\t  3. Modify Records";
     cout << "\n \t\t\t  4. Delete Records";
     cout << "\n \t\t\t  5. Exit   Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     fflush(stdin);
     choice = _getche();
     switch(choice)
     {
      case '1' :
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                  system("cls");
                cout << "Enter the First Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course    : ";
                cin >> e.course;
                cout << "Enter the Section   : ";
                cin >> e.section;
                cout << "Enter the roll number :";
                cin >> e.roll_num;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
      case '2':
            system("cls");
           rewind(fp);
           cout << "---> View the Records in the Database <---";
           cout << "\n";
           while (fread(&e,recsize,1,fp) == 1){
           cout << "\n";
           cout <<"\nName     :: " <<e.first_name <<" "<<e.last_name;
           //cout << "\n";
           cout <<"\nRoll Number :: " << e.roll_num ;
           cout <<"\nCourse   :: " <<e.course ;
           cout <<"\nSection  :: "<<e.section;
           }
           cout << "\n\n";
           system("pause");
           break;

       case '3' :
            system("cls");
          another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
         //     cout << "\n Enter the last name of the student : ";
              cout << "\n Enter the Roll number of the student : ";
              cin >> xroll_num;

            rewind(fp);
            while (fread(&e,recsize,1,fp) == 1)
            {
                //if (strcmp(e.last_name,xlast_name) == 0)
                if(e.roll_num == xroll_num )
                {
                cout << "Enter the new Firt Name : ";
                cin >> e.first_name;
                cout << "Enter the new Last Name : ";
                cin >> e.last_name;
                cout << "Enter the new Roll Number : ";
                cin >> e.roll_num;
                cout << "Enter the new Course    : ";
                cin >> e.course;
                cout << "Enter the new Section   : ";
                cin >> e.section;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
                }
                else
                cout<<"record not found";
            }
            cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


         case '4':
       system("cls");
           another = 'Y';
          while (another == 'Y'|| another == 'y')
          {
           //   cout << "\n Enter the last name of the student to delete : ";
              cout <<"\n Enter the roll number of the student to delete : ";
              cin >> xroll_num;

              ft = fopen("temp.dat", "wb");

              rewind(fp);
              while (fread (&e, recsize,1,fp) == 1)

                // if (strcmp(e.last_name,xlast_name) != 0)
                    if(e.roll_num == xroll_num )
                {
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
              }

              break;

              case '5':
              fclose(fp);
              cout << "\n\n";
              cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
              cout << "\n\n";
              exit(0);
          }
          }
     system("pause");
return 0;
}
//MADE BY RISHI...:)))))))
