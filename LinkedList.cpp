#include "LinkedList.h"

using namespace std;

void insertAfter(vector<int>& values, int num, int inserted) 
{
    for (int i = 0; i < values.size(); i++) 
    {
        if (values[i] == num) 
        {
            values.insert(values.begin() + i + 1, inserted);
            i++;
        }
    }
}

LinkedList::LinkedList() : head(nullptr){}

void LinkedList::addNode(int num) 
{
    if (head == nullptr) 
    {
        head = new Node{num, 1, nullptr};
    }
    else 
    {
        Node* curr = head;
        while (curr->next != nullptr && curr->value != num)
        {
            curr = curr->next;
        }
        if (curr->value == num) 
        {
            curr->count++;
        }
        else 
        {
            curr->next = new Node{num, 1, nullptr};
        }
    }
}

bool LinkedList::removeNode(int num) 
{
    Node* curr = head;
    Node* prev = nullptr;
    while (curr != nullptr && curr->value != num)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
    {
        return false;
    }
    if (curr->count > 1) 
    {
        curr->count--;
    }
    else 
    {
        if (prev == nullptr) 
        {
            head = curr->next;
        }
        else {
            prev->next = curr->next;
        }
        delete curr;
    }
    return true;
}

void LinkedList::printList() const 
{
    Node* curr = head;
    while (curr != nullptr) 
    {
        cout << curr->value << "(" << curr->count << ") ";
        curr = curr->next;
    }
    cout << endl;
}

int LinkedList::sumNodes() const 
{
    Node* curr = head;
    int sum = 0;
    while (curr != nullptr) 
    {
        sum += curr->value * curr->count;
        curr = curr->next;
    }
    return sum;
}

void LinkedList::createList(const std::vector<int>& values) 
{
    for (int value : values) 
    {
        addNode(value);
    }
}


LinkedList::~LinkedList() 
{
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() 
{

    int num;
    cout << "Enter the amount of numbers: ";
    cin >> num;
    vector<int> values(num);

    cout << "Enter " << num << " numbers: \n";
    for (int i = 0; i < num; i++) 
    {
        cin >> values[i];
    }


    int first, second;
    cout << "Enter the first and second values for insertAfter function: \n";
    cout << "Enter the first value: ";
    cin >> first;
    cout << "Enter the second value: ";
    cin >> second;


    insertAfter(values, first, second);
    LinkedList list;
    list.createList(values);


    cout << "\nLinkedList: \n";
    list.printList();
    cout << "\nSum of LinkedList: " << list.sumNodes() << endl;


    int removed;
    cout << "Enter a value to remove from the linked list: ";
    cin >> removed;

    if (list.removeNode(removed)) 
    {
        cout << "LinkedList after removal: ";
        list.printList();
        cout << "Sum of nodes: " << list.sumNodes() << endl;
    }
    else 
    {
        cout << removed << " not found in the linked list." << endl;
    }

    return 0;
}