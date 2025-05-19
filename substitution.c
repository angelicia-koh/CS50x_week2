#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_commandline(int argc);
int check_duplicate(int argc, string argv[]);
int check_num_alphabets(int argc, string argv[]);
int check_alphabets(int argc, string argv[]);
int plaintext_encipher(string argv[]);

// argc: an integer that indicates how many arguments were entered
//       on the command line when the program was started.
// argv[]: an array of pointers to arrays of character objects.
int main(int argc, string argv[])
{
    // check key
    int cmd = check_commandline(argc);
    if (cmd == 1)
    {
        printf("Command-line Error.\n");
        return 1;
    }

    else
    {
        int duplicate = check_duplicate(argc, argv);
        int num_alphabet = check_num_alphabets(argc, argv);
        int alphabet = check_alphabets(argc, argv);

        if (duplicate == 1)
        {
            printf("Keys cannot have repeated alphabets\n");
            return 1;
        }

        else if (num_alphabet == 1)
        {
            printf("Keys must contain 26 alphabets\n");
            return 1;
        }

        else if (alphabet == 1)
        {
            printf("Keys must be alphabets\n");
            return 1;
        }

        else
        {
            plaintext_encipher(argv);
        }
    }
}

int check_commandline(int argc)
{
    if (argc == 2)
    {
        return 0;
    }

    else
    {
        printf("ERROR!");
        return 1;
    }
}

int check_duplicate(int argc, string argv[])
{
    int n = strlen(argv[1]);
    for (int i = 0; i < n; i++)
    {
        // saves key as a char individually
        char key_iteration = argv[1][i];

        // compare other individual char sequentially
        for (int j = i + 1; j < 27; j++)
        {
            char key_lower = tolower(key_iteration);
            char key_upper = toupper(key_iteration);
            if (key_iteration == argv[1][j])
            {
                // When a return statement is executed,
                //  the function immediately stops and returns the specified value to the calling
                //  function. In this case, if a duplicate is found, the function will return 1 to
                //  main, and the program will continue executing from there.
                return 1;
            }

            else if (key_lower == argv[1][j])
            {
                return 1;
            }

            else if (key_upper == argv[1][j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int check_num_alphabets(int argc, string argv[])
{
    // check the  numbers of alphabets
    if (strlen(argv[1]) != 26)
    {
        return 1;
    }
    return 0;
}

int check_alphabets(int argc, string argv[])
{
    int p = strlen(argv[1]);
    for (int j = 0; j < p; j++)
    {
        if (isalpha(argv[1][j]) == false)
        {
            return 1;
        }
    }
    return 0;
}

// get plaintext
// encipher
int plaintext_encipher(string argv[])
{
    string getting_text = get_string("Plaintext: ");
    int m = strlen(getting_text);
    int index;

    // creates a character array with a size of m.
    char ciphered_text[m];
    printf("ciphertext: ");

    for (int k = 0; k < m; k++)
    {
        int index_text = getting_text[k]; // int of a given char

        // if lowercase
        if (index_text >= 97 && index_text <= 122)
        {
            // get index of input text
            index = index_text - 'a';
            // find the alphabet on key in that index
            // save the key's alphabet into ciphered_text
            ciphered_text[k] = tolower(argv[1][index]);
        }

        // if uppercase
        else if (index_text >= 65 && index_text <= 90)
        {
            // get index of input text
            index = index_text - 'A';
            // find the alphabet on key in that index
            // save the key's alphabet into ciphered_text
            ciphered_text[k] = toupper(argv[1][index]);
        }

        // if others
        else
        {
            ciphered_text[k] = getting_text[k];
        }

        printf("%c", ciphered_text[k]);
    }
    printf("\n");
    return 0;
}
