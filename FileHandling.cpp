#include<iostream>
#include<fstream>

using namespace std;
class student
{ 
    int rollno; 
    char name [30];
    char division;
    char address[50];
    public:
    void getdata();
    void display();
    int roll_no()
    {
        return rollno;
    }
};
 void student::getdata()
 {
      cout<<"enter the student roll no";
      cin>>rollno;
      cout<<"enter the student name";
       cin>>name;
         cout<<"enter the student division";
       cin>>division;
         cout<<"enter the student adrres";
       cin>>address;
 }

 void student::display()
 {
   
   cout<<"\t   "<<rollno<<"\t  "<<name<<"  \t "<<division<<"\t      "<<address;
     
 }
 void create()
 {
     student s;
     int n,i;
     ofstream out("student.txt");
     cout<<"how many record do you want to be enter";
     cin>>n;
     for(int i=0; i<n; i++)
     {
          s.getdata();
          out.write((char *)&s,sizeof(s));
     }
     out.close();
 }
  void display()
 {
     student s;
     ifstream infile("student.txt");
     while(infile.read((char *)&s,sizeof(s)))
     {
         s.display();
         
     }
     infile.close();
 }
 void serach()
 {
      student s;
      int flag=0;
   ifstream infile("student.txt");
      int n;
      cout<<"enter the roll no to be search";
      cin>>n;
      ifstream("student.txt");
      while (infile.read((char *)&s,sizeof(s)))
      {
          if (s.roll_no()==n)
          {
              cout<<"record found";
              cout<<"\n rollno  name   division  address";
              s.display();
              flag=1;
              break;
          }
          if (flag==0)
          {
              cout<<"record is not found";
          }
          infile.close();
      }
 }
 void add()
 {
      student s;
      ofstream outfile("student.txt",ios::app);
       s.getdata();
       outfile.write((char *)&s,sizeof(s));
        outfile.close();
        cout<<"succesfuly add ";
      
 }
 int main()
 {
     int ch;
     do{
         cout<<"1.create database";
         cout<<"2.display  ";
         cout<<"3. search";
         cout<<"4. add";
         cout<<"5.exit";
         cout<<"\nEnter your choice";
         cin>>ch;
         switch(ch)
         {
             case 1:
                create();
                break;
             case 2:
                 display();
                break;
            case 3:
               serach();
                break;
            case 4:
                add();
                break; 
                
                
         }
         
     }
     while(ch!=5);
 }
