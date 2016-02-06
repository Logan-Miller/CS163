#include "text_messenger.h"

int main()
{
    //TODO 
    //FOR TESTING PURPOSES ONLY

    //Stack myStack;
    text myText;
    myText.sender = new char[10];
    myText.message = new char[10];
    strcpy(myText.sender, "mike");
    strcpy(myText.message, "hello");
    myText.doNotDist = true;
    //if(myStack.push(myText) == 0) cout << "failure 1" << endl;
    //if(myStack.pop() == 0) cout << "failure 2" << endl;
    //if(myStack.push(myText) == 0) cout << "failure 3" << endl;

    Messenger myPhone;
    if(myPhone.recieveText(myText) == 0) cout << "failure" << endl;
    if(myPhone.viewNewText() == 0) cout << "Failure" << endl;
    //Queue myQueue;
    //if(myQueue.enqueue(myText) == 0) cout << "failure 1" << endl;
    //if(myQueue.dequeue() == 0) cout << "failure 2" << endl;
    //if(myQueue.enqueue(myText) == 0) cout << "failure 3" << endl;


    



    //TODO TESTING

    return 0;
}
