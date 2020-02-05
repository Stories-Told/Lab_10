#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

// Global constant for array amount
// Allows for easy editing in case amount
// of users needs to be increased
const int amount = 5;

// Forward Declarations
void Store_User_Information();
void Print_User_Data();


// Struct to hold contact info
struct contactType
{
    string firstName;
    string lastName;
    long double phoneNumber;
} first_Name[amount], last_Name[amount], phone_Number[amount]; // Struct array variables

int main()
{
    // Function to store user information
    // creates a input file and opens the
    // .txt file that stores contact info
    Store_User_Information();

    // Function to output user data
    // creates a output file in order to
    // save the input .txt file info into
    // a newly created output file that has a new
    // format
    Print_User_Data();

    return 0;
}


// Function to read the contact data into an array
void Store_User_Information()
{
    // Input File
    ifstream inputFile;

    // Open the input file
    inputFile.open("contacts.txt");

    // Check for error in opening the input file
    if (!inputFile)
    {
        cerr << "ERROR: Unable to open file..." << endl;
        exit(1);
    }

    // Read in the .txt information and store the info
    // into array variables from the struct
    if (inputFile.is_open())
    {
        for (int i = 0; i <= amount; i++)
        {
            inputFile >> first_Name[i].firstName >> last_Name[i].lastName >> phone_Number[i].phoneNumber;
        }
    }

    // Closes the input file
    inputFile.close();
}


// Function to print out the contacts information
void Print_User_Data()
{
    // Create output file in order to save user contact info
    // to that file
    ofstream outputFile;

    // Create a new file
    outputFile.open("Contacts_Info.txt");

    // Print the user data that was entered
    for (int i = 0; i <= amount - 1; i++)
    {
        // outputs to console the contact info
        cout << last_Name[i].lastName
             << ", "
             << first_Name[i].firstName
             << "     "
             << setprecision(10)
             << phone_Number[i].phoneNumber
             << endl;

        // Saves user contact info into new .txt file
        outputFile << last_Name[i].lastName
                   << ", "
                   << first_Name[i].firstName
                   << "     "
                   << setprecision(10)
                   << phone_Number[i].phoneNumber
                   << endl;
    }

    // Closes the output file
    outputFile.close();
}
