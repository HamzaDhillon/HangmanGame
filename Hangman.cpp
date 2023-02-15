#include <iostream>
using namespace std;
void header();
void rules();
void header2();
main()
{
    header();
    rules();
    string word;
    string player1, player2;

    cout << "Player 1! enter your name: " << endl;
    cin >> player1;
    cout << "Player 2! enter your name: " << endl;
    cin >> player2;

    system("cls");
    header();

    cout << player1 << " enter the word " << endl;
    cin >> word;

    system("cls");
    header();

    // initializing new array
    
    char newarr[word.length()];
    int i = 0;
    for (int i = 0; i < word.length(); i++)
    {
        newarr[i] = '-';
    }
    // Main

    int count = 0;
    while (count < 3)
    {
        // printing guessed words

        int h = 0;
        while (newarr[h] != '\0')
        {
            cout << newarr[h];
            h++;
        }
        cout << endl;
        cout << endl;

        char guess;
        cout << player2 << " enter the guess letter" << endl;
        cin >> guess;

        bool flag = false;
        int i = 0;

        // finding the entered word in the array

        while (word[i] != '\0')
        {
            if (word[i] == guess)
            {
                newarr[i] = guess;
                flag = true;
            }
            i++;
        }
        count++;

        system("cls");
        header();

        if (flag == true)
        {
            count--;
        }
        else
        {
            cout << "Wrong Guess!" << endl;
            cout << player2 << " You have " << 3 - count << " tries left" << endl;
            cout << endl;
        }
        flag = false;

        int counter = 0;

        // checking whether the new array have same elements as the being guessed one
        for (int z = 0; z < word.length(); z++)
        {
            if (newarr[z] == word[z])
            {
                counter++;
            }
        }
        if (count == 3)
        {
            cout << "You have been hanged" << endl;
            cout << "The word was " << word << endl;
            header2();
        }

        if (counter == word.length())
        {
            count = 3;

            cout << "          YOU WIN!" << endl;
        }
    }
}
void header()
{
    cout << "____________________________________________________________" << endl;
    cout << endl;
    cout << "___               WELCOME TO HANGMAN GAME                ___" << endl;
    cout << "____________________________________________________________" << endl;
    cout << endl;
}
void rules()
{
    cout << "RULES : YOU HAVE ONLY THREE TRIES TO GUESS THE WORD BY GUESSING RANDOM LETTERS" << endl;
    cout << endl;
    cout << "BE SPECIFIC IN LOWER/UPPER CASE LETTERS " << endl;
    cout << endl;
}
void header2()
{
    cout << " __________             " << endl;
    cout << "|          |           |" << endl;
    cout << "|          |           |" << endl;
    cout << "|          O           |" << endl;
    cout << "|         /|\\          |" << endl;
    cout << "|          |           |" << endl;
    cout << "|         / \\          |" << endl;
    cout << "|______________________|" << endl;
}
