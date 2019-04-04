#include <stdio.h>

int main ()
{
    
    //This menu allows the user to select what they would like to do using standard input and scanf()
    printf("Please select an option: \n");
    printf("1) Encrypt message using rotation cipher, given the message and rotation amount\n");
    printf("2) Decrypt message using rotation cipher, given the cipher text and rotation amount\n");
    printf("3) Encrypt message using substitution cipher, given the message and substitution\n");
    printf("4) Decrypt message using substitution cipher, given the cipher text and substitution\n");
    printf("5) Decrypt message using rotation cipher, given the cipher text only\n");
    printf("6) Decrypt message using substitution cipher, given the cipher text only\n");
    printf("Selection:");

    char c;
    scanf("%c", &c);

    switch(c) // this directs the code based on the user's input
    {
        case '1': printf("You selected option 1\n");
            break;
        case '2': printf("You selected option 2\n");
            break;
        case '3': printf("You selected option 3\n");
            break;
        case '4': printf("You selected option 4\n");
            break;
        case '5': printf("You selected option 5\n");
            break;
        case '6': printf("You selected option 6\n");
            break;
        default: printf("Unknown option %c\nPlease enter 1, 2, 3, 4, 5 or 6\n", c);
    
    }
}  

