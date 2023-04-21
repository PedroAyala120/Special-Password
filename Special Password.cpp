//This program will have the user enter a password with specific criteria
//Pedro Ayala

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

bool CriteriaCheck(bool, bool, bool, bool);     //definition of a function that
                                                //will display if the user entered password is correct

int main()
{
    const int SIZE = 20;        //max size of the string


    char password[SIZE];        //password string

    bool correct = false;       //criteria check boolean

    //booleans to mark if criteria is met
    bool lcase = false;
    bool ucase = false;
    bool digitf = false;
    bool slength = false;

    /////////////////////////////////
    ////  user inputs password  ////
    ///////////////////////////////
    cout << "Enter a password that must be at least six characters long, ";
    cout << "have at least one upper and lower case, and at least one digit" << endl;
    cout << "Enter password: ";
    cin.getline(password, SIZE);

    //For Loop to check password
    for (int i = 0; i < strlen(password); i++) 
    {
        if (isalnum(password[i])) //checks if password has printable characters
        {
            if (islower(password[i])) //checks if password characters contain a lower case letter
            {
                lcase = true;
            }
            else if (isupper(password[i])) //checks if password characters contain an upper case letter
            {
                ucase = true;
            }
            else if (isdigit(password[i])) //checks if password characters contain a digit
            {
                digitf = true;
            }
        }
        else 
        {   //criteria fail display
            cout << "You entered the wrong characters" << endl;
            break;
        }
    }

    if (strlen(password) >= 6)  //checks if password characters is at least 6
    {
        slength = true;
    }

    correct = CriteriaCheck(lcase, ucase, digitf, slength); 

    if (correct == true) 
    {
        cout << "Congratulations your password is approved!" << endl;
    }

    return 0;
}

///////////////////////////////////////////////
////  Function to Display Criteria Check  ////
/////////////////////////////////////////////
bool CriteriaCheck(bool lcase, bool ucase, bool digitf, bool slength)
{
    //if statement to check criteria
    if (slength == true && lcase == true && ucase == true && digitf == true) 
    {
        return true;
    }
    else 
    {   //Print missing attributes
        if (slength == false) 
        {
            cout << "Your password is not six characters long" << endl;
        }
        if (lcase == false) 
        {
            cout << "Your password is missing a lowercase letter" << endl;
        }
        if (ucase == false) 
        {
            cout << "Your password is missing an uppercase letter" << endl;
        }
        if (digitf == false) 
        {
            cout << "Your password is missing a digit" << endl;
        }
        return false;
    }
}
