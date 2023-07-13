#include<iostream>
#include<cstring>
void create();
void menu();
void display();
void insertfront();
void deletebeg();
void deleteend();
void reverse();
void exit();
void counts();
using namespace std;
struct node
{
   int SSN, sal, phno;
   string  name, dept,designation;
   node *next;
   node *back;
};
node *head=0,*tail=0;
int main()
{
    menu();
}
void menu()
{
    cout << "\nWhat do you want to perform:(1.Create list 2.Display 3.Insertion end 4.Insertion front \n 5.Deletion end 6.Deletion front 7.Count nodes 8. Reverse list 9.Exit)\n";
    int choice;
    cin >>choice;
    switch(choice)
    {
        case 1: create();
                break;
        case 2: display();
                break;
        case 3: create();
                break;
        case 4: insertfront();
                break;
        case 5: deleteend();
                break;
        case 6: deletebeg();
                break;
        case 7: counts();
                break;
        case 8: reverse();
                break;
        case 9: exit();
                break;
    }
}
void create()
{
    int SSN, sal, phno;
    string  name, dept,designation;
    node* newnode;
    newnode=new node();
    node*temp;
    temp=head;
    cout << "Enter ssn:";
    cin >> SSN;
    newnode->SSN=SSN;
    cout << "Enter name:";
    cin >> name;
    newnode->name=name;
    cout << "Enter dept:";
    cin >> dept;
    newnode->dept=dept;
    cout << "Enter designation:";
    cin >> designation;
    newnode->designation=designation;
    cout << "Enter sal:";
    cin >> sal;
    newnode->sal=sal;
    cout << "Enter phoneno:";
    cin >> phno;
    newnode->phno=phno;
    if(head==0)
    {
        newnode->back=0;
        newnode->next=0;
        tail=head=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->back=tail;
        tail=newnode;
        newnode->next=0;
    }
    menu();
}
void display()
{
    node *temp;
    temp=head;
    if(head==0&&tail==0)
    {
        cout << "\nEMPTY";
    }
    while(temp!=0)
    {
        cout << temp->SSN << "," << temp->name<< ","<< temp->dept << ","<< temp->designation<< ","<< temp->sal << "," << temp->phno << " -> ";
        temp=temp->next;
    }
    menu();
}
void counts()
{
    int count=0;
    node*temp;
    temp=head;
    if(head==0)
    {
        cout << "\nEmpty";
    }
    else
    {
        while(temp!=0)
        {
            count++;
            temp=temp->next;
        }
        cout << "\nNodes are:" << count;
    }
    menu();
}
void insertfront()
{
     int SSN, sal, phno;
    string  name, dept,designation;
    node* newnode;
    newnode=new node();
    node*temp;
    temp=head;
    cout << "Enter ssn:";
    cin >> SSN;
    newnode->SSN=SSN;
    cout << "Enter name:";
    cin >> name;
    newnode->name=name;
    cout << "Enter dept:";
    cin >> dept;
    newnode->dept=dept;
    cout << "Enter designation:";
    cin >> designation;
    newnode->designation=designation;
    cout << "Enter sal:";
    cin >> sal;
    newnode->sal=sal;
    cout << "Enter phoneno:";
    cin >> phno;
    newnode->phno=phno;
    if(head==0&&tail==0)
    {
        newnode->back=0;
        newnode->next=head;
        head=tail=newnode;
    }
    else
    {
    newnode->back=0;
    newnode->next=head;
    head->back=newnode;
    head=newnode;
    }
    menu();
}
void deletebeg()
{
    node* temp;
    temp=head;
    if(head==0&&tail==0)
    {
        cout<< "\nEmpty list\n";
    }
    else if(head==tail)
    {
        head =tail=0;
        cout << "\nList emptied";
    }
    else
    {
        head=head->next;
        head->back=0;
        delete temp;
    }
    menu();
}
void deleteend()
{
    node* temp;
    temp=tail;
    if(head==0&&tail==0)
    {
        cout << "\n Nothing to delete";
    }
    else
    {
        tail=tail->back;
        tail->next=0;
        delete temp;
    }
    menu();
}
void reverse()
{

}
void exit()
{
    cout << "\nEXIT";
}
