#include <iostream>
using namespace std;
class node
{
public:
    int pos, value;
    node *next;
    node()
    {
        pos = 0;
        value = 0;
        next = NULL;
    }
    node(int pos, int value)
    {
        this->pos = pos;
        this->value = value;
        next = NULL;
    }
};
class list
{
public:
    node *head, *curr;
    int length = 0;
    list()
    {
        head = NULL;
        length = 0;
    }
    void append(node *n)
    {

        if (n->pos < 1 || n->pos > length + 1)
        {
            cout << "Invalid Position\n";
        }
        else if (head == NULL)
        {
            head = n;
            length++;
            curr = head;
            cout << "Node Appended as head node\n";
        }
        else
        {
            curr->next = n;
            curr = curr->next;
            length++;
            cout << "Node Appended\n";
        }
    }
    void swap(int pos1, int pos2)
    {
        node *temp1, *temp2, *temp3, *temp4, *temp5, *temp6, *ptr = head;

        for (int i = 0; i < length; i++)
        {
            if (ptr->pos == pos1)
            {
                temp1 = ptr;
                temp3 = temp1->next;
            }
            else if (ptr->pos == pos2)
            {
                temp2 = ptr;
                temp4 = temp2->next;
            }
            else if (ptr->pos == pos1 - 1)
            {
                temp5 = ptr;
            }
            else if (ptr->pos == pos2 - 1)
            {
                temp6 = ptr;
            }
            ptr = ptr->next;
        }
        temp1->next = temp4;
        temp2->next = temp3;
        temp6->next = temp1;
        temp5->next = temp2;
    }
    void showList()
    {
        if (head == NULL)
        {
            cout << "No linked list connected\n";
        }
        else
        {
            node *ptr = head;
            cout << "List is\n";
            while (ptr != NULL)
            {
                cout << "( " << ptr->pos << "," << ptr->value << " ) --> ";
                cout << "Current Node position is " << curr->pos << endl;
                ptr = ptr->next;
            }
        }
    }
};
int main()
{
    list s;
    int key1, data1;
    for (int i = 0; i < 6; i++)
    {
        cout << "\nEnter the key\n";
        cin >> key1;
        cout << "Enter the data\n";
        cin >> data1;
        node *n1 = new node(key1, data1);
        s.append(n1);
        s.showList();
        if (i == 5)
        {
            /* code */
            s.swap(3, 6);
            s.showList();
            delete n1;
            cout<<"Memory Cleared\n";
        }
    }
    return 0;
}