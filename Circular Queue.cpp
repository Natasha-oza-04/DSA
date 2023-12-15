# DSA
# Natasha oza .
# DSA Assignment no :- 2 (Circular Queue )  
# SPPU

#include<iostream>
using namespace std;

class CQueue 
{
  int queue[5],front,rear,n;
  
  public:
  CQueue()
  {
      n=5;
      front=-1;
      rear=-1;
  }
  
  void Enqueue(int data);
  int Dequeue();
  void Display();
};

void CQueue:: Enqueue(int data)
{
    if(front==-1 && rear==-1 )
    {
        front=rear=0;
        queue[rear]=data;
    }
    else if (((rear+1)%n) == front )
    {
        cout<<"Queue is full . ";
    }
    else
    {
       rear=(rear+1)%n;
       queue[rear]=data;
    }
}

 int CQueue :: Dequeue ()
{
    int data;
    
    if(front==-1)
    {
        cout<<" \n Underflow .";
    }
    else if (front==rear)
    {
        data=queue[front];
        front=rear=-1;
    }
    else
    {
       data=queue[front];  
       front=(front+1)%n;
    }
    return data;
}

void CQueue :: Display()
{
    int i=front;
    
    if(front==-1 && rear==-1)
    {
        cout<<"\n Queue is empty . ";
    }
    else
    {
        while(i!= rear)
        {
            cout<<queue [i]<<" ";
            i=(i+1)%n;
        }
        cout<<queue[rear];
    }
}

int main ()
{
    int ch , data ;
    
    CQueue q = CQueue();
 do{
        cout<<"\n 1] Enqueue . ";
        cout<<"\n 2] Dequeue . ";
        cout<<"\n 3] Display . ";
        cout<<"\n 4] Exit . ";
        cout<<"\n Enter your choice :: ";
        cin>>ch;
    
    
    switch(ch)
     {
        case 1: 
        cout<<" Enter data ";
        cin>>data;
        q.Enqueue(data);
        break;
        
        case 2:
        data=q.Dequeue();
        cout<<"\n The deleted data is :: " << data;
        break;
        
        case 3: 
        q.Display();
        break;
     }
  } while(ch!=4);
  return 0;
}
