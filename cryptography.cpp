/*
Authors: Samantha Casler & Philip Cesani
Spring 2019

Program will ask user what they would like to do to a message,
validate that it is a valid message and get the key number.
The program will the validate the key and call the appropriate function
to work on the user's message. The program will either encrypt the
given message by the key, decrypt the given message by the key,
or terminate the program.

*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string validateInfo (string); // function to validate userChoice and return the valid choice
bool validateInfo (bool, int); // function to validate key and return the valid key
void decrypt (int, string); // function to decrypt the users message
void encryptString(int, string);// function to encrypt the users message

int main ()
{
     string userChoice;      // Variable to hold if the user wanted to encrypt, decrypt, or exit
     string userMessage; // Variable to hold the users message to be encrypted or decrypted
     int key; // Variable to hold how much the key for encoding or decoding the message will be shifted
     bool keyValidation; // Variable to hold if the key was validated
     string compareEncrypt = "ENCRYPT"; // Variable to hold the comparable encrypt string
     string compareDecrypt = "DECRYPT";// Variable to hold the comparable decrypt string
     string compareExit = "EXIT";// Variable to hold the comparable exit string

    cout << "Welcome to cryptography\n";
    do{

        do{
            keyValidation = false; // Setting the variable keyValidation to false, to be changed by the validation function

            cout << "What would you like to do to a message? ";
            cout << "(encrypt, decrypt, exit)";
            cin >> userChoice;

            const int CHOICE_SIZE = userChoice.length(); // Constant integer to hold the lenght of userChoice
            for (int i = 0; i< CHOICE_SIZE ; i ++){ // loop to make all of userChoice uppercase

            userChoice[i] = toupper(userChoice[i]);
            }

            userChoice = validateInfo(userChoice); // calling the validate function to validate userChoice is valid

            if (userChoice == compareExit) // if userChoice is exit then print footer
            {
               cout << "\nSamantha Casler and Philip Cesani Security Systems\n";
               cout << "2-25-2019\n";
               return 0;
            }


            cout << "Enter your message:\n"; // statement to get the message to be encrypted or decrypted
            cin >> userMessage;

            cout << "Enter the key number (1-35)\n";// statement to get the key for the encrypted or decrypted message
            cin >> key;

            keyValidation = validateInfo(keyValidation,key);// calling the validate function to validate that the key is valid

            }while (keyValidation == true);// loop to execute if the key was not valid

            if (userChoice == compareEncrypt){// if userChoice is encrypt then call the encrypt function
                encryptString(key, userMessage);
            }
            else if (userChoice == compareDecrypt){// if userChoice is decrypt then call the decrypt function
                decrypt(key, userMessage);
            }



            }while( userChoice != compareExit);// loop to execute if the userChoice was not exit

}

// function to validate userChoice and return the valid choice
string validateInfo(string userChoice)
{
     string compareEncrypt = "ENCRYPT"; // Variable to hold the comparable encrypt string
     string compareDecrypt = "DECRYPT";// Variable to hold the comparable decrypt string
     string compareExit = "EXIT";// Variable to hold the comparable exit string

     while (userChoice != compareEncrypt && userChoice != compareDecrypt && userChoice != compareExit){
        //loop to execute if userChoice was not valid until a valid choice is entered

        cout << "Invalid message\n\n";

        cout << "What would you like to do to a message? ";
        cout << "(encrypt, decrypt, exit)";

        cin >> userChoice;

          const int CHOICE_SIZE = userChoice.length(); // a constant integer to hold the length of the user choice
          for (int i = 0; i< CHOICE_SIZE ; i ++){// a loop to make all of userChoice upper case
              userChoice[i] = toupper(userChoice[i]);
          }
}

return userChoice;
}

//function to validate the key entered by the user and return true if key was invalid
bool validateInfo (bool isCalled, int key){

    if  (key < 0 || key > 35)
    {
        cout << "Invalid Key Number\n";
        isCalled = true; // set isCalled to true so that do while loop will execute
    }
    else
        isCalled = false;
    return isCalled;
}

//function to decrypt user message
void decrypt(int decryptionKey, string userMessage ){

 vector<char> decryptionTable; //defining a 1D vector to hold the table of regular characters

 char letters [] = {'A','B','C','D','E','F',
        'G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z','0',
        '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',
        'G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z','0',
        '1','2','3','4','5','6','7','8','9'}; // character array to populate 2D vector

        const int MAX_SIZE = 200; // constant integer to hold the largest size of the user message
        char message [MAX_SIZE] ; // varaiable to hold user message array
        const int MESSAGE_SIZE = userMessage.length(); // constant integer to hold the length of the users message

        for (int i = 0; i < MESSAGE_SIZE; i++) // loop to populate the message array
        {
            message [i] = userMessage [i];

        }

        const int ARRAY_SIZE = sizeof(letters); // constant integer to hold the size of the letters array



        decryptionTable.assign(letters, letters + ARRAY_SIZE); // assigning letters array to the 1D vector

         vector<vector <char> > _2dvectorDecyptionTable (2, decryptionTable);// populating the 2D vector


         for (int i = 0; i< MESSAGE_SIZE ; i ++){// loop to make all of userMessage upper case

            userMessage[i] = toupper(userMessage[i]);
          }


    const int MAX_ALPHA = 36; // constant integer for the members of the vector array
    const int SIZE = _2dvectorDecyptionTable.size();// constant integer for the size of the 2D vector
    for (int i = 1; i < SIZE; i++) {// loop to execute once for the second row of the vector array
        for (int j = 0; j < MAX_ALPHA; j++){ // loop to execute once for every member of the vector array
            _2dvectorDecyptionTable[i][j] = _2dvectorDecyptionTable[0][j + decryptionKey];
        }
        cout << endl;
    }

        cout << endl;

    cout << "Your translated text is:\n";

    for (int i = 1; i < SIZE; i++) {// loop to execute once for the second row of the vector array
        for (int j = 0; j < MESSAGE_SIZE; j++){// loop to execute once for every member of the userMessage
            for (int k = 0; k < MAX_ALPHA; k++){// loop to execute once for every member of the vector array
                if(userMessage[j] == _2dvectorDecyptionTable[i][k]){// if the userMessage member is equal to the table
                    userMessage[j] = _2dvectorDecyptionTable[0][k];// store the shifted member in the userMessage
                }
            }
        }
}
    cout << userMessage << endl;
}

//function to encrypt the user message
void encryptString (int decryptionKey, string userMessage){


    vector<char> decryptionTable;//defining a 1D vector to hold the table of regular characters

    char letters [] = {'A','B','C','D','E','F',
        'G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z','0',
        '1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',
        'G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z','0',
        '1','2','3','4','5','6','7','8','9'};// character array to populate 2D vector

        const int ARRAY_SIZE = sizeof(letters);// constant integer to hold the size of the letters array

        decryptionTable.assign(letters, letters + ARRAY_SIZE);// assigning letters array to the 1D vector

        const int MAX_SIZE = 200; // constant integer to hold the largest size of the user message
        char message [MAX_SIZE] ; // varaiable to hold user message array
        const int MESSAGE_SIZE = userMessage.length(); // constant integer to hold the length of the users message

        for (int i = 0; i < MESSAGE_SIZE; i++)// loop to populate the message array
        {
            message [i] = userMessage [i];

        }

        for (int i = 0; i< MESSAGE_SIZE ; i ++){// loop to make all of userMessage upper case

        userMessage[i] = toupper(userMessage[i]);

    }
   const int MAX_ALPHA = 36; // constant integer for the members of the vector array
    vector<vector <char> > _2dvectorDecyptionTable (2, decryptionTable);// populating the 2D vector
    const int SIZE = _2dvectorDecyptionTable.size();// constant integer for the size of the 2D vector
       for (int i = 1; i < SIZE; i++) {// loop to execute once for the second row of the vector array
        for (int j = 0; j < MAX_ALPHA; j++){ // loop to execute once for every member of the vector array
            _2dvectorDecyptionTable[i][j] = _2dvectorDecyptionTable[0][j + decryptionKey];

        }
        cout << endl;
    }


    cout << "Your translated text is:\n";
        for (int j = 0; j < MESSAGE_SIZE; j++){// loop to execute once for every member of the userMessage
            for (int k = 0; k < MAX_ALPHA; k++){// loop to execute once for every member of the vector array

            if (userMessage [j] == _2dvectorDecyptionTable [0][k])// if the userMessage member is equal to the table
                cout << _2dvectorDecyptionTable [1][k];// output the encoded messagee
            }

        }
        cout << endl<< endl <<endl;
}

