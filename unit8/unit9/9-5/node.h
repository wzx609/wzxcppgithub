#include <bits/stdc++.h>
using namespace std;
template<class T>
class Node {
private:
    Node<T>* next;
public:
    T data;
public:
    Node(const T& data, Node<T>* next = 0);
    void insertAfter(Node<T>* p);
    Node<T>* deleteAfter();
    Node<T>* nextNode();
    const Node<T>* nextNode() const;
};

template<class T>
Node<T>::Node(const T& data, Node<T>* next)
:data(data), next(next)
{

}

template<class T>
void Node<T>::insertAfter(Node<T>* p)
{
    p->next = next;
    next = p;
}

template<class T>
Node<T>* Node<T>::deleteAfter()
{
    Node<T>* tempPtr = next;
    if (!next)
        return 0;
    next = tempPtr->next;
    return tempPtr;
}

template<class T>
Node<T>* Node<T>::nextNode()
{
    return next;
}

template<class T>
const Node<T>* Node<T>::nextNode() const
{
    return next;
}

template<class T>
class LinkedList {
private:
    Node<T>* front;     
    Node<T>* rear; 
    Node<T>* prevPtr;
    Node<T>* currPtr;  
    int size;  
    int position; 
    Node<T>* newNode(const T& item, Node<T>* ptrNext = nullptr);
    void freeNode(Node<T>* p);
    void copy(const LinkedList<T>& L);
public:
    LinkedList();
    LinkedList(const LinkedList<T>& L);
    ~LinkedList();
    LinkedList<T>& operator=(const LinkedList<T>& L);
    int getSize();
    bool isEmpty() const;
    void reset(int pos = 0);
    void next();
    bool endOfList() const;
    int currentPosition() const;
    void insertFront(const T& item);
    void insertRear(const T& item);
    void insertAt(const T& item);
    void insertAfter(const T& item);
    T deleteFront();
    void deleteCurrent();
    T& data();
    const T& data() const;
    void clear();
};

template<class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T>* ptrNext)
{
    Node<T>* p;
    p = new Node<T>(item, ptrNext);
    assert(p);
    return p;
}

template<class T>
void LinkedList<T>::freeNode(Node<T>* p)
{
    delete p;
}

template<class T>
void LinkedList<T>::copy(const LinkedList<T>& L)
{
    if (L.size == 0)
        return;
    front = rear = newNode(L.front->data);
    for (Node<T>* srcNode = L.front->nextNode(); srcNode != nullptr; srcNode = srcNode->nextNode()) {
        Node<T>* p = newNode(srcNode->data);
        rear->insertAfter(p);
        rear = p;
    }
    size = L.size;
    reset(position = L.currentPosition());
}

template<class T>
LinkedList<T>::LinkedList():front(nullptr),rear(nullptr),prevPtr(nullptr),currPtr(nullptr),size(0),position(0)
{

}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L):front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(0)
{
    copy(L);
}

template<class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& L)
{
    clear();
    copy();
    return *this;
}

template<class T>
int LinkedList<T>::getSize()
{
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0;
}

template<class T>
void LinkedList<T>::reset(int pos)
{
    if (pos >= 0 && pos <= size)
    {
        position = 0;
        prevPtr = nullptr;
        currPtr = front;
        while (pos--)
            next();
    }
    else
    {
        position = pos;
        prevPtr = nullptr;
        currPtr = nullptr;
    }
}

template<class T>
void LinkedList<T>::next()
{
    position++;
    prevPtr = currPtr;
    if (currPtr)
        currPtr = currPtr->nextNode();
}

template<class T>
bool LinkedList<T>::endOfList() const
{
    return currPtr == nullptr;
}

template<class T>
int LinkedList<T>::currentPosition() const
{
    return position;
}

template<class T>
void LinkedList<T>::insertFront(const T& item)
{
    front = newNode(item, front);
    if (isEmpty())
        rear = front;
    size++;
    reset(++position);
}

template<class T>
void LinkedList<T>::insertRear(const T& item)
{
    Node<T>* p = newNode(item);
    if (isEmpty())
    {
        front = rear = p;
    }
    else
    {
        rear->insertAfter(p);
        rear = p;
    }
    size++;
    reset(position);
}

template<class T>
void LinkedList<T>::insertAt(const T& item)
{
    if (currPtr)
    {
        Node<T>* p = newNode(item, currPtr);
        if (prevPtr)
            prevPtr->insertAfter(p);
        else
        {
            front = prevPtr = p;
        }
        size++;
        reset(++position);
    }
}

template<class T>
void LinkedList<T>::insertAfter(const T& item)
{
    if (currPtr)
    {
        Node<T>* p = newNode(item, currPtr->nextNode());
        currPtr->insertAfter(p);
        if (rear == currPtr)
            rear = p;
        size++;
    }
}

template<class T>
T LinkedList<T>::deleteFront()
{
    assert(!isEmpty());
    Node<T>* p = front;
    front = front->nextNode();
    if (--size == 0)
        rear = nullptr;
    reset(--position);
    T item = p->data;
    freeNode(p);
    return item;
}

template<class T>
void LinkedList<T>::deleteCurrent()
{
    if (currPtr)
    {
        if (front == currPtr)
            front = currPtr->nextNode();
        if (rear == currPtr)
            rear = prevPtr;
        if (prevPtr)
            prevPtr->deleteAfter();
        freeNode(currPtr);
        size--;
        reset(position);
    }
}

template<class T>
T& LinkedList<T>::data()
{
    if (!currPtr)
    {
        cerr << "Current node is invalid!" << endl;
        exit(1);
    }
    return currPtr->data;
}

template<class T>
const T& LinkedList<T>::data() const
{
    if (!currPtr)
    {
        cerr << "Current node is invalid!" << endl;
        exit(1);
    }
    return currPtr->data;
}

template<class T>
void LinkedList<T>::clear()
{
    while (isEmpty())
        deleteFront();
}