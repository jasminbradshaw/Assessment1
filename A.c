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
    printf("Selection:"); // this prompts the user to select an option from the menu by typing the corresponding number

    char c; 
    scanf("%c", &c); //reads the user's input and stores it in the char c

    switch(c) // this directs the code based on the user's input
    {
        case '1': printf("You selected option 1\n"); // this case will take a array(message) and integer(key) as input and output encypted text
            char message[100], letter; //initialises the message as an array, and a variable which will be used for individual letters
            int key, i=0; //initialises the key and a counter which will be used when changing individual letters
    
            printf("Enter a message:");
            scanf("%s", message);
            printf ("Enter an integer to use as the key:");
            scanf("%d", &key);
            for (i=0; message[i] != '\0'; ++i) //This is where each letter in the word gets individually rotated by the key
            {
                letter=message[i]; //the char "letter" becomes element i of the array "message"
                
                if (letter>='a' && letter<='z') //lowercase letters
                {
                    letter=letter+key;
                    if (letter>'z')
                    {
                        letter=letter-'z'+'a'-1; //this takes into account the fact that z is at the end of the alphabet
                    }
                    message[i]=letter;
                }
                else if (letter>='A' && letter<='Z')//uppercase letters
                {
                    letter=letter+key;
                    if (letter>'Z')
                    {
                        letter=letter-'Z'+'A'-1;
                    }
                    message[i]=letter;
                }
            }
            
            
            printf("Your message is: %s", message);
        
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

