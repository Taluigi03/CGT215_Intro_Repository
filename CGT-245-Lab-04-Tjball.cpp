#include <iostream>
using namespace std;


// Print out the menu of choices for the user to select from
void printMenu()
{
    cout << "Please Select which operation to perform:" << endl;
    cout << "\t1. Factorial" << endl;
    cout << "\t2. Arithmetic Series" << endl;
    cout << "\t3. Geometric Series" << endl;
    cout << "\t4. Exit" << endl;
    cout << "Your Selection: ";
}


// Calculate and display a factorial
void factorial()
{
    int number;

    cout << "Factorial:" << endl;
    cout << "Enter a number: ";
    cin >> number;

    // Factorial requires a positive whole number
    while (number <= 0)
    {
        cout << "Nice try, please enter a POSITIVE number....: ";
        cin >> number;
    }

    long long result = 1;

    for (int i = 1; i <= number; i++)
    {
        result *= i;

        cout << i;

        if (i < number)
        {
            cout << " * ";
        }
    }

    cout << " = " << result << endl;
}


// Calculate and display an arithmetic series
void arithmetic()
{
    int start;
    int difference;
    int elements;

    cout << "Arithmetic Series:" << endl;

    cout << "Enter a number to start at: ";
    cin >> start;

    cout << "Enter a number to add each time: ";
    cin >> difference;

    cout << "Enter the number of elements in the series: ";
    cin >> elements;

    // Number of elements must be positive
    while (elements <= 0)
    {
        cout << "Nice try, please enter a POSITIVE number....: ";
        cin >> elements;
    }

    int current = start;
    int total = 0;

    for (int i = 0; i < elements; i++)
    {
        cout << current;

        total += current;

        if (i < elements - 1)
        {
            cout << " + ";
        }

        current += difference;
    }

    cout << " = " << total << endl;
}


// Calculate and display a geometric series
void geometric()
{
    int start;
    int ratio;
    int elements;

    cout << "Geometric Series:" << endl;

    cout << "Enter a number to start at: ";
    cin >> start;

    cout << "Enter a number to multiply by each time: ";
    cin >> ratio;

    cout << "Enter the number of elements in the series: ";
    cin >> elements;

    // Number of elements must be positive
    while (elements <= 0)
    {
        cout << "Nice try, please enter a POSITIVE number....: ";
        cin >> elements;
    }

    int current = start;
    int total = 0;

    for (int i = 0; i < elements; i++)
    {
        cout << current;

        // Add the current term to the series total
        total += current;

        if (i < elements - 1)
        {
            cout << " + ";
        }

        // Generate the next term
        current *= ratio;
    }

    cout << " = " << total << endl;
}


int main()
{
    int choice;
    char again;

    do
    {
        printMenu();
        cin >> choice;

        // Exit if user selects 4 or enters an invalid menu option
        if (choice > 3 || choice < 1)
        {
            return 0;
        }
        else if (choice == 1)
        {
            factorial();
        }
        else if (choice == 2)
        {
            arithmetic();
        }
        else if (choice == 3)
        {
            geometric();
        }

        cout << "Go Again? [Y/N] ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}