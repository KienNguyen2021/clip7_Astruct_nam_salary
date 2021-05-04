#include<iostream>

using namespace std;

struct Staff
{
    string name;
    int salary;

    Staff ()
    {
        name = " ";
        salary = 0;
    }
    Staff (string Name, int Salary)
    {
        name = Name;
        salary = Salary;
    }

};

struct Node
{
    Staff datum;
    Node* pNext;

    Node()
    {
        datum.name = " ";
        datum.salary = 0;
        pNext = nullptr;
    }

    Node(Staff staff, Node* link)
    {
        datum = staff;
        pNext = link;
    }

};

class SortedLinkedList
{
private:
    Node* pHead;

public:
    SortedLinkedList()
    {
        pHead = nullptr;
    }

    SortedLinkedList(Node* link)
    {
        pHead = link;
    }

    bool isEmpty()
    {
        return (pHead == nullptr);
    }

    void CreateList()
    {
        cout<<"Enter the number of nodes that you want to have in the list"<<endl;
        int numberOfNodes;
        cin>>numberOfNodes;

        Node* pCurrentNode;
        Node* pNewCode;

        cout<<"Enter the value to store in the 0th node: "<<endl;
        Staff staff0;
        string inputName;
        int inputSalary;
        cin>>inputName;
        cin>>inputSalary;

        staff0.name = inputName;
        staff0.salary = inputSalary;

        pNewCode = new Node(staff0, nullptr);
        pHead = pNewCode;
        pCurrentNode = pHead;

        int count = 0;

        while(count != (numberOfNodes-1))
        {
            cout<<"Enter the name and salary to store in the "
            <<count+1<< " node"<<endl;
            cin>>inputName;
            cin>>inputSalary;
            staff0.name = inputName;
            staff0.salary = inputSalary;

            pNewCode = new Node(staff0, nullptr);
            pCurrentNode->pNext = pNewCode;
            pCurrentNode = pNewCode;
            count++;
        }

    }

    void printLinkedList()
    {
        cout<<"Our linked list is as follows: "<<endl;
        for(const Node* p = pHead; p!=nullptr; p=p->pNext)
        {
            cout<<p->datum.name<< " "<<p->datum.salary<<endl;
        }
        cout<<endl;

    }

};

int main()
{
    SortedLinkedList list1;

    list1.CreateList();
    list1.printLinkedList();

//    cout<<list1.isEmpty()<<endl;


    return 0;

}