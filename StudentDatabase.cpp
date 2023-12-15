
#include<iostream>
#include<fstream>
using namespace std ;

class Student 
{
  // int roll_no;
   char name[30];
   char address[50];
   char division ;
   
   public:
   void getdata();
   void display();
   int roll_no;
   /*{
       return rollno;
   }*/
    
};

void  Student :: getdata()
{
    cout<<"\n  Enter the name :- ";
    cin>>name;
    cout<<"\n  Enter the roll no :- ";
    cin>>roll_no;
    cout<<"\n  Enter the division :- ";
    cin>>division;
    cout<<"\n  Enter the address  :- ";
    cin>>address;
}

void Student :: display()
{
    cout<<"\n"<<name<<"\n"<<roll_no<<"\n"<<division<<"\n"<<address;
}

//create file named "Student.txt"

void create()
{
    Student s ;
    int n,i;
    
    ofstream out ("Student.txt");
    
    cout<<"Enter how may records you want :- ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        s.getdata();
        out.write((char *)&s,sizeof(s));
    }
    out.close();
}

void display()
{
    Student s;
    ifstream infile("Student.txt");
    while(infile.read((char *)&s,sizeof(s)))
    {
        s.display();
    }
    infile.close();
}

void search()
{
    Student s;
    int flag=0;
    
    ifstream infile("Student.txt");
    int n ;
    cout<<"Enter the record you want to find ? ";
    cin>>n;
    
    ifstream("Student.txt");
    while(infile.read((char *)&s,sizeof(s)))
    {
        if (s.roll_no == n)
        {
            cout<<"\n Record found .";
            cout<<"\n Roll_no :-    Name :-     Division :-     Address :-       ";
            
            s.display();
            flag=1;
            break;
        }
        if(flag=0)
        {
            cout<<"\n Record not found ! ";
        }
        infile.close();
    }
}

void add()
{
    Student s;
    ofstream outfile("Student.txt",ios::app);
    s.getdata();
    
    outfile.write((char *)&s,sizeof(s));
    outfile.close();
    cout<<"\n Record Succesfully added ! ";
}

int main ()
{
    int ch ;
    do{
        cout<<"\n 1] Create Database . ";
        cout<<"\n 2] Display . ";
        cout<<"\n 3] Search  . ";
        cout<<"\n 4] Add . ";
        cout<<"\n 5] Exit . ";
        cout<<"\n Enter your choice  . ";
        cin>>ch;
        
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
             case 3: search();
                     break;        
             case 4: add();
                    break;
        }
    }
    while(ch!=5);
}
