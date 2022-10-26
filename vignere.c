#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Format: ./vigenere (code)\n");
        return 1;
    }

    string key= argv[1];

    for (int i=0, n = strlen(key); i<n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Give me the code word!\n");
            return 1;
        }
    }
    string plaintext=get_string("PlainText: ");
    printf("ciphertext: ");

    if( plaintext!=NULL)
    {
        for (int i=0, j=0, n=strlen(plaintext); i<n; i++)
        {
            if(isalpha(plaintext[i]))
            {
                if (islower(plaintext[i]))
                {
                    printf("%c", (plaintext[i]-'a'+toupper(key[j])-'A')%26+'a');
                }

                else if(isupper(plaintext[i]))
                {
                    printf("%c", (plaintext[i]-'A'+toupper(key[j])-'A')%26+'A');
                }
                j=(j+1)%strlen(key);
            }

            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    printf("\n");
    return 0;

}