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
            char message1[100], letter1; //initialises the message as an array, and a variable which will be used for individual letters
            int key1, count1=0; //initialises the key and a counter which will be used when changing individual letters
    
            printf("Enter a message:");
            scanf("%s", message1);
            printf ("Enter an integer to use as the key:");
            scanf("%d", &key1);
            for (count1=0; message1[count1] != '\0'; ++count1) //This is where each letter in the word gets individually rotated by the key
            {
                letter1=message1[count1]; //the char "letter" becomes element "count" of the array "message"
                
                if (letter1>='a' && letter1<='z') //lowercase letters
                {
                    letter1=letter1+key1;
                    if (letter1>'z')
                    {
                        letter1=letter1-'z'+'a'-1; //this takes into account the fact that z is at the end of the alphabet
                    }
                    message1[count1]=letter1;
                }
                else if (letter1>='A' && letter1<='Z')//uppercase letters
                {
                    letter1=letter1+key1;
                    if (letter1>'Z')
                    {
                        letter1=letter1-'Z'+'A'-1;
                    }
                    message1[count1]=letter1;
                }
            }
            
            
            printf("Your message is: %s\n", message1);
        
            break;
            
        case '2': printf("You selected option 2\n");
            char message2[100], letter2; //initialises the message as an array, and a variable which will be used for individual letters
            int key2, count2=0; //initialises the key and a counter which will be used when changing individual letters
    
            printf("Enter a message:");
            scanf("%s", message2);
            printf ("Enter an integer to use as the key:");
            scanf("%d", &key2);
            for (count2=0; message2[count2] != '\0'; ++count2) //This is where each letter in the word gets individually rotated by the key
            {
                letter2=message2[count2]; //the char "letter" becomes element i of the array "message"
                
                if (letter2>='a' && letter2<='z') //lowercase letters
                {
                    letter2=letter2-key2;
                    if (letter2<'a')
                    {
                        letter2=letter2+'z'-'a'+1; //this takes into account the fact that z is at the end of the alphabet
                    }
                    message2[count2]=letter2;
                }
                else if (letter2>='A' && letter2<='Z')//uppercase letters
                {
                    letter2=letter2-key2;
                    if (letter2<'A')
                    {
                        letter2=letter2+'Z'-'A'+1;
                    }
                    message2[count2]=letter2;
                }
            }
            
            
            printf("Your message is: %s\n", message2);
        
            
        
        
        
        
            
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

