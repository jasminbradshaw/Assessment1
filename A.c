#include <stdio.h>
#include <string.h>

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
        /*Case 1 (encryption) will take an array(message1) and an integer(key1) as inputs, and will output encrypted text. */
        case '1': printf("You selected option 1\n"); 
            char message1[100], letter1; //initialises the message as an array, and a variable which will be used for individual letters
            int key1, count1=0; //initialises the key and a counter which will be used when changing individual letters
            
            printf("Enter a message:\n");
            scanf("\n%[^\n]s", message1);
            
            printf ("Enter an integer to use as the key:\n");
            scanf("%d", &key1);
            for (count1=0; message1[count1] != '\0'; ++count1) //This is where each letter in the word gets individually rotated by the key
            {
                letter1=message1[count1]; //the char "letter" becomes element "count" of the array "message"
                
                if (letter1>='a' && letter1<='z') //lowercase letters
                {
                    letter1=((letter1-'a')+key1)%26+'a'; //the letter (which is stored as a number) is rotated by the value of key
                   
                    message1[count1]=letter1; //the new letter is assigned to the original element of the array
                }
                else if (letter1>='A' && letter1<='Z')//uppercase letters
                {
                   letter1=((letter1-'A')+key1)%26+'A';
                 
                    message1[count1]=letter1;
                }
                else
                {
                    message1[count1]=letter1;
                }
            }
            
            
            printf("Your message encrypted is: %s\n", message1);
        
            break;
            
            /*Case 2 is simply the reverse of case 1.  The only difference is that instead of incrementing the value of letter by key, the
            code decrements the value of letter by key. Also, when considering the fact that the letters at the end of the alphabet can
            'drop off' end of the stored ASCII codes, the method which we use to correct this is different. */
           
        case '2': printf("You selected option 2\n"); 
            char message2[100], letter2; //initialises the message as an array, and a variable which will be used for individual letters
            int key2, count2=0; //initialises the key and a counter which will be used when changing individual letters
    
            printf("Enter cipher text:\n");
            scanf("\n%[^\n]s", message2);
            printf ("Enter an integer to use as the key:\n");
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
                            letter2=letter2+'Z'-'A'+1; //this takes into account the fact that z is at the end of the alphabet
                        }
                    message2[count2]=letter2;
                }
                
                else
                {
                    message2[count2]=letter2;
                }
            }
            
            
            printf("Your message decrypted is: %s\n", message2);
        
            break;
            
        case '3': printf("You selected option 3\n");
            char alphabet[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
            char message3[250];
            char key3[26];
            int count3a=0, count3b=0;
            
            printf("Enter a message in all UPPER CASE:\n");
            scanf("\n%[^\n]s", message3);
        
            printf("Enter a substitution alphabet of 26 characters in all UPPER CASE:\n");
            scanf("\n%[^\n]s", key3);
            
            for(count3a=0; count3a<strlen(message3); count3a++)
            {
                for(count3b=0; count3b<26; count3b++)
                    {
                        if (alphabet[count3b]==message3[count3a])
                        {
                            message3[count3a]=key3[count3b];
                            break;
                        }
                    }
            }
            printf("Your message encrypted is: \n%s\n", message3);
     
            break;
            
        case '4': printf("You selected option 4\n");
        
        
        
        
        
            
            break;
            
        case '5': printf("You selected option 5\n");
            char message5[100], letter5; //initialises the message as an array, and a variable which will be used for individual letters
    
            printf("Enter a message:\n");
            scanf("\n%[^\n]s", message5);
            for (int key5=0; key5<27; key5++) //this will force the code to rotate the message by every possibile key
            {
                char decrypted[100];
                for (int count5=0; message5[count5] != '\0'; count5++) //This is where each letter in the word gets individually rotated by the key
                {
                    letter5=message5[count5]; //the char "letter" becomes element i of the array "message"
                
                    if (letter5>='a' && letter5<='z') //lowercase letters
                    {
                        letter5=letter5-key5;
                        if (letter5<'a')
                        {
                            letter5=letter5+'z'-'a'+1; //this takes into account the fact that z is at the end of the alphabet
                        }
                        decrypted[count5]=letter5;
                    }
                    else if (letter5>='A' && letter5<='Z')//uppercase letters
                    {
                        //letter2=((letter2-'A')-key2)%26+'A';
                        letter5=letter5-key5;
                        if (letter5<'A')
                        {
                            letter5=letter5+'Z'-'A'+1;
                        }
                        decrypted[count5]=letter5;
                    }
                    else
                    {
                        decrypted[count5]=letter5;
                    }
                }
            
            
                printf("\nYour message decrypted with key %d is:\n%s\n",key5, decrypted); // this will print every possible decryption
        }

        
        
        
            
            break;
            
        case '6': printf("You selected option 6\n");
        
        
        
        
        
            
            break;
            
        default: printf("Unknown option %c\nPlease enter 1, 2, 3, 4, 5 or 6\n", c);
    
    }
}