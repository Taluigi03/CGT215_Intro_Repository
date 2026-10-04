#include <iostream>
#include <vector>
#include <string>

using namespace std;

char translateCharacter(char letter, vector<char> codeTable)
{
    // Capital letter
    if (letter >= 65 && letter <= 90)
    {
        return codeTable[letter - 65];
    }

    // Lowercase letter
    else if (letter >= 97 && letter <= 122)
    {
        char upperCaseLetter = letter - 32;

        int upperCaseCode = upperCaseLetter - 65;

        return codeTable[upperCaseCode] + 32;
    }

    // Anything that is not a letter
    else
    {
        return letter;
    }
}

int main()
{
    vector<char> codeTable =
    {
        'V', 'F', 'X', 'B', 'L', 'I', 'T', 'Z', 'J',
        'R', 'P', 'H', 'D', 'K', 'N', 'O', 'W', 'S',
        'G', 'U', 'Y', 'Q', 'M', 'A', 'C', 'E'
    };

    string text;

    cout << "Enter text: ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++)
    {
        cout << translateCharacter(text[i], codeTable);
    }

    cout << endl;

    return 0;
}