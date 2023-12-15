/******** Circular queue ***********/
#include&lt;iostream&gt;
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
void enqueue(int data);
int dequeue();
void display();
};
void CQueue::enqueue(int data)
{
if(front==-1 &amp;&amp; rear==-1)
{
front=rear=0;
queue[rear]=data;
}
else if(((rear+1)%n)==front)
{
cout&lt;&lt;&quot;queue is full&quot;;
}
else
{
rear=(rear+1)%n;
queue[rear]=data;
}
}
int CQueue::dequeue()
{
int data;
if(front==-1)
{
cout&lt;&lt;&quot;Underflow&quot;;
} else if(front==rear)
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
void CQueue::display()
{
int i=front;
if(front==-1 &amp;&amp; rear==-1)
{
cout&lt;&lt;&quot;\n queue is empty&quot;;
}
else
{
while(i!=rear)
{
cout&lt;&lt;queue[i]&lt;&lt;&quot; &quot;;
i=(i+1)%n;
}
cout&lt;&lt;queue[rear];
}
}
int main()
{
int ch,data;
CQueue q=CQueue();
do
{
cout&lt;&lt;&quot;\n 1. Enqueue(insertion)&quot;;
cout&lt;&lt;&quot;\n 2. Dequue(deletion&quot;;
cout&lt;&lt;&quot;\n 3. Display&quot;;
cout&lt;&lt;&quot;\n 4. Exit&quot;;
cout&lt;&lt;&quot;\n enter your choice: &quot;;
cin&gt;&gt;ch;
switch(ch)
{
case 1:
cout&lt;&lt;&quot;\n enter data: &quot;;
cin&gt;&gt;data;
q.enqueue(data);
break;
case 2:
data=q.dequeue();
cout&lt;&lt;&quot;\n deleted data is: &quot;&lt;&lt;data;
break;
case 3:
q.display();
break;
}

}while(ch!=4);
return 0;
}
