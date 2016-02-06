#include <iostream>
#include <cstring>
using namespace std;

//Data type text, the basic data that will be used by both the stack and queue
struct text
{
    char * sender;
    char * message;
    bool doNotDist;
};

//nodes for the stack ADT
struct s_node
{
    text * textMessages;
    s_node * next;
};

//nodes for the queue ADT
struct q_node
{
    text textMessage;
    q_node * next;
};

//class for managing new texts
class Stack
{
public:
    Stack();
    ~Stack();
    int push(text &textMessage);
    int pop();
    int s_peak(text &textMessage);
private:
    s_node * head;
    int top_index;
};

//class for managing saved texts
class Queue
{
public:
    Queue();
    ~Queue();
    int enqueue(text &textMessage);
    int dequeue();
    int q_peak(text &textMessage);
private:
    q_node * rear;
};

//Class for managing new and saved text messages
class Messenger
{
public:
    Messenger();
    ~Messenger();
    int recieveText(text &textMessage);
    int viewNewText();
    //int viewSavedText();
    //int saveNew();
private:
    int viewNewHelper(text &textMessage);
    //int saveNewHelper(text &textMessage);

    Stack newTexts;
    Queue savedTexts;
};
