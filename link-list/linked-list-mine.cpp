#include <iostream>
using namespace std;

template <class D>
class Node
{
public:
    D data;
    Node *next;
    Node *before;

    Node()
    {
        next = NULL;
        before = NULL;
    }
    Node(D data)
    {
        this->data = data;
        next = NULL;
        before = NULL;
    }
};
//.................................................................................................

template <class D>
class Linker
{
private:
    Node<D> *head;

public:
    Linker() { head = NULL; }

    void insertNode(D);
    void deleteNode(int);
    void printList();
};

template <class D>
void Linker<D>::insertNode(D data)
{
    Node<D> *newNode = new Node<D>(data);

    // first data
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node<D> *temp = head;

    // finding last Node
    while (temp->next != NULL)
        temp = temp->next;

    // put the data
    newNode->before = temp;
    temp->next = newNode;
}

template <class D>
void Linker<D>::deleteNode(int n)
{
    if (head == NULL)
    {
        cout << "list empty";
        return;
    }

    Node<D> *temp = head;
    Node<D> *tempB, *tempN;

    int i = 1;
    while (i < n)
    {
        i++;
        temp = temp->next;
    }
    tempB = temp->before;
    tempN = temp->next;

    if (n == 1)
    {
        head = temp->next;
        if (head != NULL)
            head->before = NULL;
        delete temp;
        return;
    }

    if (temp->next == NULL)
    {
        tempB->next = NULL;
        delete temp;
        return;
    }

    tempB->next = temp->next;
    tempN->before = temp->before;
    delete temp;
}

template <class D>
void Linker<D>::printList()
{
    if (head == NULL)
    {
        cout << "list empty." << endl;
        return;
    }

    int i = 0;
    Node<D> *temp = head;

    while (temp != NULL)
    {
        i++;
        cout << i << "- " << temp->data << endl;
        temp = temp->next;
    }
}
//...............................................................................................................

int main()
{
    Linker<string> list;
    char swicher = 'S';
    string data;
    short int number;

    cout << "Commands:\nI = Insert new node\tD = Delete a node\tP = Print all nodes\tH = Help\tE = Exit" << endl;
    while (swicher != 'E')
    {
        cout << "Enter your command: ";
        cin >> swicher;
        switch (swicher)
        {
        case 'I':
            cout << "Enter your data: ";
            cin >> data;
            list.insertNode(data);
            cout << "data saved.\n";
            break;
        case 'D':
            list.printList();
            cout << "which node do u want to delete? ";
            cin >> number;
            list.deleteNode(number);
            cout << "Deleted.\n";
            break;
        case 'P':
            list.printList();
            break;
        case 'H':
            cout << "Commands:\nI = Insert new node\tD = Delete a node\tP = Print all nodes\tH = Help\tE = Exit" << endl;
            break;
        case 'E':
            break;
        }
    }
    return 0;
}