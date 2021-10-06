#include<conio.h> //input output lib
#include<iostream> //header files and objs included
#include<fstream> //used to operate on files
#include<Windows.h> //used to include the header file for the program
#include<dos.h> // includes functions for handling interrupts
#include<cctype> // includes functions to clasify of transform individual characters
#include<sstream> //enables stream interoperation between stream buffer and stream objects
#include<string>  // introduces string types
using namespace std;
bool check = true;
struct node    //structure of node //
{
 char name[20];              // Student name
 char discipline[20];        // Branch of student
 int rollNo;                 // Roll no. of the student
 char section;               // division of the student
 node *next;                 //points to the next node 
}*head,*lastptr;              //objects or pointers of struct node

void add()    //Adds record of student//     // if input x=1 add new record
{
 node *p;                       //pointer
 p=new node;
 cout<<"Enter name of student:"<<endl;
 gets(p->name);                // stores the object "name" in the buffer reader (only characters)
 fflush(stdin);               //used to flush/clear the output buffer
 cout<<"Enter discipline of student:"<<endl;
 gets(p->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>p->rollNo;              // stores float/int data type
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>p->section;
 fflush(stdin);
 p->next=NULL;                //Showing the end of the list i.e the last node is section

 if(check)             
 {
  head = p;                   //begining of the list
  lastptr = p;                //last node of the list
  check = false;              //when head and lastptr=p list is empty
 }
 else
 {
  lastptr->next=p;             //All fields like name,rollno,etc. entered entered
  lastptr=p;
 }
 cout<<endl<<"Recored Entered";
 getch();                       //return value
}
void modify()   //modifies record of student//
{
 node *ptr;
 node *prev=NULL;       //start of the list
 node *current=NULL;    
 int roll_no;
 cout<<"Enter Roll Number to search:"<<endl;
 cin>>roll_no;
 prev=head;            //to begin traversal from head
 current=head;         //current will keep traversing forward until the searched roll no is found
 while(current->rollNo!=roll_no)    //to search the rollno.
 {
  prev=current;
  current=current->next;           //Doubt
 }
 ptr=new node;
 fflush(stdin);             //clearing the previous information of the node , corresponding to the searched roll no. and entering all details again
 
 cout<<"Enter name of student:"<<endl;
 gets(ptr->name);         //returns object value
 fflush(stdin);
 cout<<"Enter discipline of student:"<<endl;
 gets(ptr->discipline);
 fflush(stdin);
 cout<<"Enter Roll Number of student:"<<endl;
 cin>>ptr->rollNo;
 fflush(stdin);
 cout<<"Enter section of student:"<<endl;
 cin>>ptr->section;
 fflush(stdin);
 prev->next=ptr;                 
 ptr->next=current->next;
 current->next=NULL;
 delete current;                // Joining ptr to current next and deleting current node
 cout<<endl<<"Recored Modified";
 getch();
}
void search()   //searches record of student//
{
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to search:"<<endl;
 cin>>roll_no;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;
  current=current->next;   //traversing until searched rollno found
 }
 cout<<"\nname: ";
 puts(current->name);      // picking the name using current pointer
 cout<<"\nRoll No:";
 cout<<current->rollNo;      
 cout<<"\nDiscipline:";
 puts(current->discipline);  // picking the discipline  using current pointer
 cout<<"\nSection:";
 cout<<current->section;
 getch();
}
void del()    //deletes record of a student//
{
 node *ptr=NULL;
 node *prev=NULL;
 node *current=NULL;
 int roll_no;
 cout<<"Enter Roll Number to Delete:"<<endl;
 cin>>roll_no;
 prev=head;
 current=head;
 while(current->rollNo!=roll_no)
 {
  prev=current;                 //Conditions used to traverse the list
  current=current->next;        //Conditions used to traverse the list
 }
 prev->next = current->next;
 current->next=NULL;             //storing the link section in prv's next and deleting current
 delete current;
 cout<<endl<<"Recored Deleted";
 getch();
}

int main()
{
 char x;     //used to take user input to know what operation he wants to perform
 cout<<"\t\t ********************************* \t\t\t"<<endl;
 cout<<"\t\t ****STUDENT MANAGEMENT SYSTEM**** \t\t\t"<<endl;
 cout<<"\t\t ********************************* \t\t\t"<<endl;


 cout<<"\n\nPress Any Key To Continue . . . ."<<endl;
 getch();
 do
 {
  system("cls");   //clear screen
  cout<<"1--->Press '1' to add New record:"<<endl;
  cout<<"2--->Press '2' to search a record:"<<endl;
  cout<<"3--->Press '3' to modify a record:"<<endl;
  cout<<"4--->Press '4' to delete a record:"<<endl;
  cout<<"5--->Press '5' to exit:"<<endl;
  x=getch();
  if(x=='1')           // if input x=1 add new record
  {
   system("cls");
   add();              // calling add() class
  }
  else if(x=='2')      // if input x=2 search a record
  {
   system("cls");
   search();
  }
  else if(x=='3')       // if input x=3 modify a record record
  {
   system("cls");
   modify();
  }
  else if(x=='4')       // if input x=4 delete a record
  {
   system("cls");
   del();
  }
  else if(x=='5')       // if input x=5 exit
  {
   exit(0);
  }
  else
  {
  }
 }while(x != 27);
 getch();
}
