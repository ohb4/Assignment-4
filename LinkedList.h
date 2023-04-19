#include <vector>
#include <iostream>

using namespace std;

struct Node 
{
    int value;
    int count;
    Node* next;
};

class LinkedList 
{
    private:
        Node* head;
    public:
        LinkedList();
        void addNode(int);
        bool removeNode(int);
        void printList() const;
        void createList(const std::vector<int>&);
        int sumNodes() const;
        ~LinkedList();
};
