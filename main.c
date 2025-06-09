#include <stdio.h>
#include <string.h>

void perform_shift(int count, char *text, int mode)
{
    printf("TEXT: %s", text); //&s is for characters / strings 
    printf("MODE=%d\n", mode);
    printf("SHIFT=%d", count);

    // if(mode == 0)
    // {
        
    // }
    // else
    // {

    // }

    // for (int i = 0; i < count; i++) {
    //     printf("%d\n", i);
    // }
}

int main() {

    // we need to ask the user for the mode (encrypt / decrypt)
    // then set that mode and ask them for the text
    // we then ask for the shift number (default 3) 
    // then we shift each letter in the given text by the entered shift
    // lastly we return the text

    int mode; // 0 = encrypt, 1 = decrypt
    int shift_count;
    char text[100];

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
    fgets(text, 100, stdin);

    perform_shift(shift_count, text, mode);

    // printf("TEXT: %s", buffer);
    // printf("MODE=%d\n", mode);
    // printf("SHIFT=%d", shift_count);
    return 0;
}