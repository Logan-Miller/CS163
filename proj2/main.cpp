//Logan Miller
//CS163
//Assignment 2

//Assignment 2: This program simulates a texting type app for the user.
//The user is able to recieve text messages. They can then view these new text
//messages. Upon viewing they can choose to save the text. The user is then
//able to view all saved text messages. When a saved text message is viewed
//the user can then decided if they wish to retain it or discard it. The user
//can also send text messages.


#include "text_messenger.h"

void populateTexts(Messenger &phone);

int main()
{
    Messenger myPhone;
    populateTexts(myPhone);
    int response = '\n';
    bool textToView = false;

    //Welcome display for user
    cout << "Welcome to the texter app. This app allows you to recieve text\n"
         << "messages, send text messages, view your new text messages,\n"
         << "save text messages and delete text messages." << endl << endl;

    do
    {
        cout << "Choose from the available options:" << endl;
        cout << "(1) To Send a text message" << endl;
        cout << "(2) To view new text messages" << endl;
        cout << "(3) To view saved text messages" << endl;
        cout << "(4) To quit the texter app" << endl;

        cout << "Enter choice now: ";
        cin >> response;
        cin.ignore(100, '\n');

        //Case 1: the user wishes to send a text. Since there are no other
        //users this function is for show.
        if(response == 1)
        {
            text aText;
            aText.sender = new char[50];
            aText.message = new char[150];
            cout << "Enter who you want to text: ";
            cin.getline(aText.sender, 50, '\n');
            cin.ignore(100, '\n');
            cout << "Enter your message (Up to 150 characters): ";
            cin.getline(aText.message, 150, '\n');
            cin.ignore(100, '\n');
            myPhone.sendMessage(aText);
            cout << endl << endl;
        }

        //Case 2: user wishes to view any new texts. After viewing a text they
        //are given the choice whether or not to save the text
        if(response == 2)
        {
            cout << "Let's see if you have any new texts" << endl;
            if(myPhone.viewNewText() == 0)
            {
                textToView = false;
                cout << "There doesn't appear to be any new texts." << endl;
                cout << endl << endl;
            }

            else textToView = true;
            
            if(textToView == true)
            {
                cout << "Would you like to save this text? (1 for yes, 2 for"
                     << " no)" << endl;

                cin >> response;
                cin.ignore(100, '\n');
                
                if(myPhone.saveNewText(response) == 0)
                {
                    
                    cout << endl;
                    cout << "There appears to be an error deleting your text";
                    cout << endl;
                }
                cout << endl << endl;
            }
        }

        //Case 3: the user wishes to view saved texts. After viewing a saved
        //text they are given the choice of whether or not to retain the text
        if(response == 3)
        {
        
            cout << "Let's look at your saved texts" << endl;
            if(myPhone.viewSavedText() == 0)
            {
                textToView = false;
                cout << "There doesn't appear to be any saved texts." << endl;
                cout << endl << endl;
            }

            else textToView = true;
            
            if(textToView == true)
            {
                cout << "Would you like to retain this text? (1 for yes,"
                     << " 2 for no: ";

                cin >> response;
                cin.ignore(100, '\n');
                if(myPhone.processSavedText(response) == 0)
                {
                    cout << endl;
                    cout << "There appears to be an error deleting your text";
                    cout << endl;
                }
                cout << endl << endl;
            }
        }

    //Case 4: the user wishes to quit the program
    }while(response != 4);

    cout << "Texter will now close, good bye." << endl << endl;
    return 0;
}


//This function is purely for populating the messenger with new texts
//for testing purposes since no real texts are coming into the program from
//an outside source.
void populateTexts(Messenger &myPhone)
{
    text text1;
    text1.sender = new char[50];
    text1.message = new char[150];
    strcpy(text1.sender, "mike");
    strcpy(text1.message, "what's up");
    text1.doNotDist = false;
    if(myPhone.recieveText(text1) == 0) cout << "failure1" << endl;
    
    text text2;
    text2.sender = new char[50];
    text2.message = new char[150];
    strcpy(text2.sender, "larry");
    strcpy(text2.message, "did you hear about mike");
    text2.doNotDist = false;
    if(myPhone.recieveText(text2) == 0) cout << "failure2" << endl;
    
    text text3;
    text3.sender = new char[50];
    text3.message = new char[150];
    strcpy(text3.sender, "larry");
    strcpy(text3.message, "real good news apparently");
    text3.doNotDist = false;
    if(myPhone.recieveText(text3) == 0) cout << "failure3" << endl;
    
    text text4;
    text4.sender = new char[50];
    text4.message = new char[150];
    strcpy(text4.sender, "steve");
    strcpy(text4.message, "have you texted mike yet");
    text4.doNotDist = false;
    if(myPhone.recieveText(text4) == 0) cout << "failure4" << endl;
    
    text text5;
    text5.sender = new char[50];
    text5.message = new char[150];
    strcpy(text5.sender, "sue");
    strcpy(text5.message, "do you hear a dog");
    text5.doNotDist = false;
    if(myPhone.recieveText(text5) == 0) cout << "failure5" << endl;
    
    text text6;
    text6.sender = new char[50];
    text6.message = new char[150];
    strcpy(text6.sender, "mike");
    strcpy(text6.message, "hey, I got a dog");
    text6.doNotDist = false;
    if(myPhone.recieveText(text6) == 0) cout << "failure6" << endl;
    
    return;
}
