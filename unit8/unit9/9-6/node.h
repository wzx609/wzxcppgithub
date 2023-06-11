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
class oederlist {
private:
    Node<T>* front;     
    Node<T>* rear; 
    Node<T>* prevPtr;
    Node<T>* currPtr;  
    int size;  
    int position; 
    Node<T>* newNode(const T& item, Node<T>* ptrNext = nullptr);
    void freeNode(Node<T>* p);
    void copy(const oederlist<T>& L);
public:
    oederlist();
    oederlist(const oederlist<T>& L);
    ~oederlist();
    oederlist<T>& operator=(const oederlist<T>& L);
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
    void insert(oederlist<T>& a,oederlist<T>& b);
};

template<class T>
Node<T>* oederlist<T>::newNode(const T& item, Node<T>* ptrNext)
{
    Node<T>* p;
    p = new Node<T>(item, ptrNext);
    assert(p);
    return p;
}

template<class T>
void oederlist<T>::freeNode(Node<T>* p)
{
    delete p;
}

template<class T>
void oederlist<T>::copy(const oederlist<T>& L)
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
oederlist<T>::oederlist():front(nullptr),rear(nullptr),prevPtr(nullptr),currPtr(nullptr),size(0),position(0)
{

}

template<class T>
oederlist<T>::oederlist(const oederlist<T>& L):front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(0)
{
    copy(L);
}

template<class T>
oederlist<T>::~oederlist()
{
    clear();
}

template<class T>
oederlist<T>& oederlist<T>::operator=(const oederlist<T>& L)
{
    clear();
    copy();
    return *this;
}

template<class T>
int oederlist<T>::getSize()
{
    return size;
}

template<class T>
bool oederlist<T>::isEmpty() const
{
    return size == 0;
}

template<class T>
void oederlist<T>::reset(int pos)
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
void oederlist<T>::next()
{
    position++;
    prevPtr = currPtr;
    if (currPtr)
        currPtr = currPtr->nextNode();
}

template<class T>
bool oederlist<T>::endOfList() const
{
    return currPtr == nullptr;
}

template<class T>
int oederlist<T>::currentPosition() const
{
    return position;
}

template<class T>
void oederlist<T>::insertFront(const T& item)
{
    front = newNode(item, front);
    if (isEmpty())
        rear = front;
    size++;
    reset(++position);
}

template<class T>
void oederlist<T>::insertRear(const T& item)
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
void oederlist<T>::insertAt(const T& item)
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
void oederlist<T>::insertAfter(const T& item)
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
T oederlist<T>::deleteFront()
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
void oederlist<T>::deleteCurrent()
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
T& oederlist<T>::data()
{
    if (!currPtr)
    {
        cerr << "Current node is invalid!" << endl;
        exit(1);
    }
    return currPtr->data;
}

template<class T>
const T& oederlist<T>::data() const
{
    if (!currPtr)
    {
        cerr << "Current node is invalid!" << endl;
        exit(1);
    }
    return currPtr->data;
}

template<class T>
void oederlist<T>::clear()
{
    while (isEmpty())
        deleteFront();
}

template<class T>
void oederlist<T>::insert(oederlist<T>& a,oederlist<T>& b)
{  
    a.reset();
    b.reset();
    while(b.currPtr!=NULL){
        while(a.currPtr!=NULL){
        if(b.data()<a.data()){
            a.insertAt(b.data());
            break;
            }
            if(a.currPtr==a.rear){
            a.insertAfter(b.data());
            break;
            }
            a.next();
        }
            b.next();
            a.reset();
    }

}