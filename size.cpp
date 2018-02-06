#include <iostream>
#include <cstddef>
using namespace std;
using std::cout;
using std::endl;
/* definition of the list node class */
class Node
{
    friend class LinkedList;
private:
    int _value; /* data, can be any data type, but use integer for easiness */
    Node *_pNext; /* pointer to the next node */
    
public:
    /* Constructors with No Arguments */
    Node(void)
    : _pNext(NULL)
    { }
    
    /* Constructors with a given value */
    Node(int val)
    : _value(val), _pNext(NULL)
    { }
    
    /* Constructors with a given value and a link of the next node */
    Node(int val, Node* next)
    : _value(val), _pNext(next)
    {}
    
    /* Getters */
    int getValue(void)
    { return _value; }
    
    Node* getNext(void)
    { return _pNext; }
};

/* definition of the linked list class */
class LinkedList
{
private:
    /* pointer of head node */
    Node *_pHead;
    /* pointer of tail node */
    Node *_pTail;
    
public:
    /* Constructors with No Arguments */
    LinkedList(void);
    /* Constructors with a given value of a list node */
    LinkedList(int val);
    /* Destructor */
    ~LinkedList(void);
    
    /* Function to append a node to the end of a linked list */
    void tailAppend(int val);
    /* Function to calculate the number of elements in the list */
    int size();
    
};

LinkedList::LinkedList()
{
    /* Initialize the head and tail node */
    _pHead = _pTail = NULL;
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    _pHead = new Node(val);
    _pTail = _pHead;
}

LinkedList::~LinkedList()
{
    /*
     * Leave it empty temporarily.
     * It will be described in detail in the example "How to delete a linkedlist".
     */
}

void LinkedList::tailAppend(int val)
{
    /* The list is empty? */
    if (_pHead == NULL) {
        /* the same to create a new list with a given value */
        _pTail = _pHead = new Node(val);
    }
    else
    {
        /* Append the new node to the tail */
        _pTail->_pNext = new Node(val);
        /* Update the tail pointer */
        _pTail = _pTail->_pNext;
    }
}

int LinkedList::size()
{
    int cnt = 0; /* counter */
    Node* pNode = _pHead;
    /* traverse the list */
    while (pNode != NULL) {
        /* Update the counter */
        cnt++;
        /* move along to the next node */
        pNode = pNode->_pNext;
    }
    return cnt;
}

int main(int argc, const char * argv[])
{
    /* Create an empth list */
    LinkedList list;
    cout << "Created an empty list" << endl;
    /* Calculate and print the size */
    cout << "Calculating the size..." << endl;
    cout << "The size of the list is " << list.size() << endl;
    /* Add 4 nodes to the list */
    list.tailAppend(1);
    list.tailAppend(2);
    list.tailAppend(3);
    list.tailAppend(4);
    
    cout << "Added 4 nodes into the list" << endl;
    
    /* Calculate and print the size */
    cout << "Calculating the size..." << endl;
    cout << "The size of the list is " << list.size() << endl;
    
    
    
    return 0;
}

