#include <stdio.h>
#include <ctype.h>

void perform_shift(int count, char *text, int mode)
{
    // printf("TEXT: %s", text); //&s is for characters
    // printf("MODE=%d\n", mode);
    // printf("SHIFT=%d", count);

                        //null terminator
                        //       v
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char base; // for upper / lower case detection
            int shift = count;

            if (mode == 1) {
                shift = -count;
            }

            if (isupper(c)) {
                base = 'A';
            } else {
                base = 'a';
            }

            int shifted = (c - base + shift) % 26; // not so secret formula from mr caesar

            if (shifted < 0) {
                shifted += 26;
            }
            
            text[i] = shifted + base;
        }
    }

    printf("RESULT: %s\n", text);
}

int main() {
    int mode; // 0 = encrypt, 1 = decrypt
    int shift_count;
    char text[1000]; // sets a fixed limit of 999 characters, will def replace with dynamic allocation later

    do {
        printf("\e[1;1H\e[2J"); // clear the console
        printf("Select a mode (0 = encrypt, 1 = decrypt): ");
        scanf("%d", &mode); //&d is for integers
        while (getchar() != '\n'); // cclear leftover charracters frrom input buffer
    } while (mode < 0 || mode > 1);
    
    //printf("MODE=%d", mode);

    do {
        printf("Enter a shift number (1-25): ");
        scanf("%d", &shift_count);
        while (getchar() != '\n'); 
    } while (shift_count < 1 || shift_count > 25);

    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    perform_shift(shift_count, text, mode);

    // printf("TEXT: %s", buffer);
    // printf("MODE=%d\n", mode);
    // printf("SHIFT=%d", shift_count);
    return 0;
}