#include <iostream>

// for strcpy function
#include <string>

using namespace std;

void ReverseIt(char input_string[50])
{
    char reversed_string[50];

    strcpy(reversed_string, input_string);

    int i = 0;
    // first figure out the length of the string
    // 50 is not the actual length of the string; it's just the maximum string size
    while (input_string[i] != '\0')
    {
        i++;
    }

    /*
        uses the two-pointer approach to reverse the string
        the characters at opposite ends are swapped till we get to the middle
        (k - 1) because char arrays are zero-indexed and the initial value of k is the length of the char array
    */
    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        char temp = reversed_string[j];
        reversed_string[j] = reversed_string[k];
        reversed_string[k] = temp;
    }

    cout << "\nYour reversed string is: " << reversed_string;
}