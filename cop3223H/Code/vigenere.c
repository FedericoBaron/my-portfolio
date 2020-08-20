// Arup Guha
// 10/17/2018
// Implements a Vigenere cipher on all characters in the stream of standard input.

#include <stdio.h>
#include <ctype.h>

void encryptVigenere(int key[], int length);

int main(void) {
    //int key[] = {1,4,4,12,14,21,8,4};
    int invkey[] = {25,22,22,14,12,5,18,22};
    encryptVigenere(invkey, 8);
    return 0;
}

void encryptVigenere(int key[], int length) {

    int c, i = 0;

    // Loop through all the characters.
    while ((c = getchar()) != EOF) {

        // Take care of lower case.
        if (islower(c)) {
            putchar( ((c-'a')+key[i%length]+26)%26+'a');
            i++;
        }
        // Upper case.
        else if (isupper(c)) {
            putchar( ((c-'A')+key[i%length]+26)%26+'A');
            i++;
        }
        // Don't change non-alphabetic characters at all.
        else
            putchar(c);
    }
}