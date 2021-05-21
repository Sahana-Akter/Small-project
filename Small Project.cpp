//Sahana Akter
// C193209


#include<bits/stdc++.h>
using namespace std;
int a[100],n;
void display();

void ran()
{
    int randomN,i;
    cout<<"Enter the number of element::";
    cin>>n;
    srand((unsigned) time(0));
    for(i=1;i<=n;i++)
    {
        randomN=((rand()%100)+1);
        a[i]=randomN;
    }
    cout<<"Random value::"<<endl;
    display();

}
void Sort()
{
    int i,j,temp;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"Sorted value:::"<<endl;
    display();
}
int menu(void)
{
    int choice;
    do
    {
        cout<<"\n1-Insert\n2-Delete\n3-Search\n4-Display\n5-Exit\n";
        cout<<"Enter the your choice::: ";
        cin>>choice;
        if(choice<1||choice>5)
        {
            cout<<"\nWrong.........Choice again\n";
        }
    }
    while(choice<1||choice>5);
    return(choice);
}
void Insert()
{
    int i,item;
    cout<<endl<<"Enter the element ::: ";
    cin>>item;
    i=n;
    while(a[i]>=item)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=item;
    n=n+1;
    display();



}
void Delete()
{
   int item,i,c,j,k;
   cout<<endl<<"Enter element  to be Delete::: ";
   cin>>item;
    int b=1;
    int e=n;
   int  m=(b+e)/2;
    while(b<=e && a[m]!=item)
    {
        if(item<a[m])
        {
            e=m-1;
        }
        else
        {
            b=m+1;

        }
        m=(b+e)/2;
    }
    if(a[m]==item)
    {
        k=m;
        for(i=k;i<n;i++)
        {
            a[i]=a[i+1];
        }
        n=n-1;
    }
    else
    {
        cout<<"Element not found.....!!!"<<endl;
    }
   display();
}
void Search()
{
    int item,l,b,e,m,p,c=0;
    cout<<endl<<"Enter the element you want to search::";
    cin>>item;
    b=1;
    e=n;
    m=(b+e)/2;
    while(b<=e && a[m]!=item)
    {
        if(item<a[m])
        {
            e=m-1;
        }
        else
        {
            b=m+1;

        }
        m=(b+e)/2;
    }
    if(a[m]==item)
    {
        p=m;
        cout<<"Element ="<<item<<"  is in location="<<p<<endl;
    }
    else
    {
        cout<<"Element not found...........!!!"<<endl;
    }

}

void display()
{
    int i;
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    ran();
    Sort();
    int choice;
    do
    {
        choice=menu();
        switch(choice)
        {
        case 1:
           Insert();
           break;
        case 2:
            Delete();
            break;
     case 3:
           Search();
            break;
        case 4:
            cout<<"Display Array Element::"<<endl;
            display();
            break;
        case 5:
            cout<<"End of operation"<<endl;
            break;
        }
    }
    while(choice!=5);
    return 0;

}

