#include "text_messenger.h"

//*******************Stack ADT functions************************
Stack::Stack()
{
    head = NULL;
    top_index = 0;
}

Stack::~Stack()
{   
    //Loop used to cycle through the list
    while(head)
    {
        s_node * temp = head;
        head = head->next;
        //If the index is passed the bounds, set it to the last possible index
        if(top_index == 5) top_index = 4;
        //Loop through the array started at the bottom and working back to top
        while(top_index >= 0)
        {
            //text messages have dynamic memory, delete this memory
            delete [] temp->textMessages[top_index].sender;
            delete [] temp->textMessages[top_index].message;
            //Move the index back
            --top_index;
        }
        //Once all dynamic memory in the array has been deleted, delete array
        delete [] temp->textMessages;
        //If there is another node to delete from, set index to the last
        //element, otherwise set it top_index to 0;
        if(head) top_index = 4;
        if(!head) top_index = 0;
    }
}

//Pushes a text message onto the stack TODO
int Stack::push(text &textMessage)
{
    //If the stack is empty, make a new node, add the text to the array, shift
    //and  then index
    if(!head)
    {
        head = new s_node;
        head->textMessages = new text[5];
        head->next = NULL;
        head->textMessages[top_index] = textMessage;
        ++top_index;
        return 1;
    }
    
    //If the stack has nodes, but the head's array is full, create a new node
    //append data to that node, connect the new node to the list, make the new
    //node head.
    if(top_index >= 5)
    {
        top_index = 0;
        s_node * temp = new s_node;
        temp->textMessages = new text[5];
        temp->next = head;
        temp->textMessages[top_index] = textMessage;
        head = temp;
        ++top_index;
        return 1;
    }

    //If there is data and the current array is not full append a text message
    //to the array and increment top_index
    if(top_index < 5)
    {
        head->textMessages[top_index] = textMessage;
        ++top_index;
        return 1;
    }

    //failure case, somehow no cases were met and the data is not pushed onto
    //the stack
    return 0;
}

//pops a data item off of the stack. TODO
int Stack::pop()
{
    //if head is empy nothing is there
    if(!head) return 0;

    //Check if the array only has 1 item
    if(top_index == 0)
    {
        delete head->textMessages[top_index].sender;
        delete head->textMessages[top_index].message;
        delete [] head->textMessages;
        
        //If that was the last item in the stack, the stack is now empty
        if(!head->next)
        {
            delete head;
            head = NULL;
            return 1;
        }

        //If there are more nodes in the stack, shift to that node and the 
        //last element in that node's array
        if(head->next)
        {
            s_node * temp = head;
            head = head->next;
            delete temp;
            top_index = 4;
            return 1;
        }
        return 0;
    }
    
    //The case where we are not at the 0th item in the node's array
    //TODO possible memory problem. The text is not deleted from the array
    //If we popped once, and then pushed onto the stack I'm not sure if the
    //pushed text message would overwrite the previous popped text message
    if(top_index <= 5)
    {
        if(top_index == 5) top_index = 4;
        delete head->textMessages[top_index].sender;
        delete head->textMessages[top_index].message;
        --top_index;
        return 1;
    }

    //If no cases were met, base case will return 0 for failure
    return 0;
}

//*******************Queue ADT Functions************************
Queue::Queue()
{
    rear = NULL;
}

Queue::~Queue()
{

}

//Adds a data item to the queue. TODO
int Queue::enqueue(text &textMessage)
{
    //Case if the list is empty when trying to add
    if(!rear)
    {
        rear = new q_node;
        rear->textMessage = textMessage;
        rear->next = rear;
        return 1;
    }
    
    //Case where there is data to append to
    if(rear->next)
    {
        q_node * temp = new q_node;
        temp->next = rear->next;
        temp->textMessage = textMessage;
        rear->next = temp;
        rear = temp;
        return 1;
    }

    //If neither of the above cases were met, default to failure.
    return 0;
}

//removes a data item from the queue. TODO
int Queue::dequeue()
{
    //Case 1: List is empty, nothing to dequeue, return failure.
    if(!rear) return 0;

    //Case 2: List has one node, dequeue data
    if(rear->next == rear)
    {
        delete [] rear->textMessage.sender;
        delete [] rear->textMessage.message;
        delete rear;
        rear = NULL;
        return 1;
    }

    //Case 3: List has more than one item
    if(rear->next)
    {
        q_node * temp = rear->next;
        rear->next = temp->next;
        delete [] temp->textMessage.sender;
        delete [] temp->textMessage.message;
        delete temp;
        return 1;
    }
    
    //Case 4: None of the cases above were met, default to failure
    return 0;
}

//*******************Text Messenger ADT Functions***************


