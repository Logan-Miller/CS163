#include "text_messenger.h"

int main()
{
    //TODO 
    //FOR TESTING PURPOSES ONLY

    Stack myStack;
    text myText;
    myText.sender = new char[10];
    myText.message = new char[10];
    strcpy(myText.sender, "mike");
    strcpy(myText.message, "hello");
    myText.doNotDist = true;
    if(myStack.push(myText) == 0) cout << "failure 1" << endl;
    if(myStack.pop() == 0) cout << "failure 2" << endl;
    if(myStack.push(myText) == 0) cout << "failure 3" << endl;

    //TODO TESTING

    return 0;
}
