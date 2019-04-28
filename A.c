#include <stdio.h>
#include <string.h>

int main ()
{
    
    /*
     * This menu allows the user to select what they would like to do. The user types an interger (1-6) into stdin, which controls
     * a switch case where each case is a different cipher task. The function of each task is described to the user in stdout.
     */
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

    switch(c) // this directs the code based on the user's input (char c)
    {
        /*
         * Case 1 (encryption) will take an array(message1) and an integer(key1) from stdin, and will send encrypted text to stdout.
         * The encryption works by moving along each element of the array (each letter of the message), rotating to the ASCII character
         * indicated by the numerical key. 
         */
        case '1': printf("You selected option 1\n"); 
            char message1[250], letter1; //initialises the message as an array, and a variable which will identify individual letters
            int key1, count1=0; //initialises the key and a counter which will be used when changing individual letters
            
            printf("Enter a message:\n");
            scanf("\n%[^\n]s", message1);//the user sends a message to stdin, which is stored in the array message1. "\n%[^\n]s" is used so that the message is read until a new line character, as opposed to a space character
            
            printf ("Enter an integer to use as the key:\n");
            scanf("%d", &key1);//user inputs number which will tell the code how many places each letter needs to be rotated
            for (count1=0; message1[count1] != '\0'; ++count1) //This loop travels along each individual element of the array message1, until it reaches a null character
            {
                letter1=message1[count1]; //the char "letter1" becomes element "count1" of the array "message1"
                
                if (letter1>='a' && letter1<='z') //if the letter is lowercase
                {
                    letter1=((letter1-'a')+key1)%26+'a'; //the letter (which is stored as a numerical ASCII value) is rotated by the value of key
                   
                    message1[count1]=letter1; //the encrypted letter is assigned to the original element of the array
                }
                else if (letter1>='A' && letter1<='Z')//if the letter is uppercase (same as above)
                {
                   letter1=((letter1-'A')+key1)%26+'A';
                 
                    message1[count1]=letter1;
                }
                else
                {
                    message1[count1]=letter1; //if the character is anything other than a letter(e.g. space, full stop), it remains unchanged
                }
            }
            
            
            printf("Your message encrypted is: \n%s\n", message1);
        
            break;
            
            /*Case 2 is simply the reverse of case 1.  The only difference is that instead of incrementing the value of letter by key2, the
            code decrements the value of letter by key2. Also, when considering the fact that the letters at the end of the alphabet can
            'drop off' end of the stored ASCII codes, the method which we use to correct this is different. */
           
        case '2': printf("You selected option 2\n"); 
            char message2[250], letter2; //initialises the message as an array, and a variable which will be used for individual letters
            int key2, count2=0; //initialises the key and a counter which will be used when changing individual letters
    
            printf("Enter cipher text:\n");
            scanf("\n%[^\n]s", message2);
            printf ("Enter an integer to use as the key:\n");
            scanf("%d", &key2);
            for (count2=0; message2[count2] != '\0'; ++count2) //This loop moves along each element of the array
            {
                letter2=message2[count2]; //the char "letter2" becomes element "count2" of the array "message2"
                
                if (letter2>='a' && letter2<='z') //if the letter is lowercase
                {
                    letter2=letter2-key2; //the letter is rotated backwards by the value of the key (decryption)
                    if (letter2<'a')
                        {
                            letter2=letter2+'z'-'a'+1; //this takes into account the fact that z is at the end of the alphabet
                        }
                    message2[count2]=letter2;//the original element of the array becomes the decrypted letter
                }
                else if (letter2>='A' && letter2<='Z')//if the letter is uppercase
                {
                    letter2=letter2-key2;
                    if (letter2<'A')
                        {
                            letter2=letter2+'Z'-'A'+1; //this takes into account the fact that z is at the end of the alphabet
                        }
                    message2[count2]=letter2;//the original element of the array becomes the decrypted letter
                }
                
                else
                {
                    message2[count2]=letter2;//if the character is anything other than a letter(e.g. space, full stop), it remains unchanged
                }
            }
            
            
            printf("Your message decrypted is: \n%s\n", message2);
        
            break;
            
        /* Case 3 recieves a message from the user (must be typed in uppercase) and string of 26 characters 
         * (also uppercase, this is the substitution alphabet). Each letter of the user's message is 
         * individually replaced with the respective letter in the substitution alphabet, then the 
         * encrypted message is printed.
         */
        case '3': printf("You selected option 3\n");
            char alphabet3[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};//the normal alphabet stored as an array
            char message3[250];//this array stores the user's message
            char key3[26];//this array of 26 elements stores the substitution alphabet 
            int count3a=0, count3b=0;
            
            printf("Enter a message in all UPPER CASE:\n");
            scanf("\n%[^\n]s", message3);//user writes message to stdin, which is stored as message 3
        
            printf("Enter a substitution alphabet of 26 characters in all UPPER CASE, with no spaces:\n");
            scanf("\n%[^\n]s", key3);//user writes 26 unique characters which is stored as an array and used as the substitution alphabet
            
            for(count3a=0; count3a<strlen(message3); count3a++)//this loop moves along each letter of the input message
            //the function strlen calculates how many characters are in message3
            //the for loop ends when count3a is at the final character of message3
            {
                for(count3b=0; count3b<26; count3b++) //this moves along each letter of the array alphabet3
                    {
                        if (alphabet3[count3b]==message3[count3a])//when the message letter being read is equal to the corresponding letter in the alphabet
                        {
                            message3[count3a]=key3[count3b];//the message letter becomes the substitution letter indicated by key3
                            break;
                        }
                        else
                        {
                            message3[count3a]=message3[count3a];//if the character in the message isn't a letter (eg ?) it remains as it was input by the user
                        }
                    }
            }
            printf("Your message encrypted is: \n%s\n", message3);
     
            break;
         /*Case 4 works in a similar fashion to case 3 but in reverse. The user inputs 
          *encryped text and a substitution alphabet, and recieves a decrytped message as the output.
          */
        case '4': printf("You selected option 4\n");
            char alphabet4[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
            char message4[250];
            char key4[26];
            int count4a=0, count4b=0;
            int i=0, j=0;
    
            printf("Enter cipher text in all UPPER CASE:\n");
            scanf("\n%[^\n]s", message4);
            
            printf("Enter a substitution alphabet of 26 characters in all UPPER CASE:\n");
            scanf("\n%[^\n]s", key4);
            
    
            for(count4a=0; count4a<strlen(message4); count4a++)//loop moves along each character of cipher text (array message4)
            {
                for(count4b=0; count4b<26; count4b++)//loop moves along each letter of array alphabet4
                    {
                        if (message4[count4a]==key4[count4b])//when a specific character in the cipher text is a specific letter in the substitution alphabet
                        {
                            message4[count4a]=alphabet4[count4b];//that character becomes the corresponding character in the standard alphabet
                            break;
                        }
                        else
                        {
                            message4[count4a]=message4[count4a];//if the character is anything other than a letter it remains the same
                        }
                    }
            }
            
            printf("Your message decrypted is: \n%s\n", message4);
        
            break;
          
          /*
           * Case 5 is the decryption of a message encrypted using a rotation cipher, without knowledge of the key used.
           * It works the same as the decryption when the key is known, however instead of printing one message to stdout,
           * it prints 26 messages, each one a possible decryption. As there are only 26 possible messages, the user simply scrolls
           * through and identifies which message in stdout is readable. Once this is done, the reader knows the original message
           * and the rotationkey used to encrypt it.
           */
        case '5': printf("You selected option 5\n");
            char message5[250], letter5; //initialises the encrypted message as an array, and initialises a variable which will be used for individual letters
    
            printf("Enter a message:\n");
            scanf("\n%[^\n]s", message5);
            for (int key5=0; key5<27; key5++) //this will force the code to rotate the message by every possibile key from 0 to 26
            {
                char decrypted[100];//this array will store the decrypted message
                for (int count5=0; message5[count5] != '\0'; count5++) //This loop moves along each letter of the array message5
                {
                    letter5=message5[count5]; //the char "letter5" becomes element "count5" of the array "message5"
                
                    if (letter5>='a' && letter5<='z') //if the letter is lowercase
                    {
                        letter5=letter5-key5; //the letter is rotated backward by the value of key5
                        
                        /*
                         * if the letter is rotated "off the end" of the alphabet to something before "a" 
                         * when it should have been allocated to the other end of the alphabet near "z", the code needs to
                         * account for this
                         */
                        
                        if (letter5<'a')//if the ASCII value of the character is less than that of "a"
                        {
                            letter5=letter5+'z'-'a'+1; //it is shifted back inside the alphabet in the correct place
                        }
                        decrypted[count5]=letter5;//the element of the decrypted message becomes the newly decrypted corresponding letter
                    }
                    else if (letter5>='A' && letter5<='Z')//this is the same as above except for uppercase letters
                    {
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
            
            
                printf("\nYour message decrypted with key %d is:\n%s\n",key5, decrypted); // this will print every possible decryption, each on a new line
        }

            break;
        /*
         * Case 6 is the decryption without a key of a message which was encrypted using a substitution cipher. As there are 26! possible
         * messages, this case does not print every possibility like case 5. Instead, statistical analysis is performed. 
         * First, the number of times each letter appears in the message is counted. When the user compares this with the statistics
         * for the frequency of each letter in the english language, we can determine which normal letter corresponds
         * to each subsituted letter. The longer the message is, the more accurate this analysis is.
         */
        case '6': printf("You selected option 6\n");
            char message6[1000];//this array stores the encrypted message
            char freq[26]={'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'U', 'C', 'M', 'F', 'Y', 'W', 'G', 'P', 'B', 'V', 'K', 'X', 'Q', 'J', 'Z'};
            char key6[26];
            int count6=0;//this count is used in the loop which counts how many times each letter appears
            int count6a=0; 
            int count6b=0;//count6a and 6b are used during decryption
            int cA=0,cB=0,cC=0,cD=0,cE=0,cF=0,cG=0,cH=0,cI=0,cJ=0,cK=0,cL=0,cM=0,cN=0,cO=0,cP=0,cQ=0,cR=0,cS=0,cT=0,cU=0,cV=0,cW=0,cX=0,cY=0,cZ=0;//these integers will count the number of times each letter appears in the message
            
            printf("Enter cipher text in all UPPER CASE:\n");
            scanf("\n%[^\n]s", message6);//the message is scanned and stored in array message6
            
            for(count6=0; count6<strlen(message6); count6++)//this loop moves along each element of the array message 6
            {
                switch (message6[count6])//this switch case counts how many times each letter occurs. 
                {
                    /*
                     * if element 'count6' of array 'message6' is "A", the counter 'cA' increases by 1. 
                     * This repeats for every individual letter in the message.
                     */
                    case 'A': cA++; break;
                    case 'B': cB++; break;
                    case 'C': cC++; break;
                    case 'D': cD++; break;
                    case 'E': cE++; break;
                    case 'F': cF++; break;
                    case 'G': cG++; break;
                    case 'H': cH++; break;
                    case 'I': cI++; break;
                    case 'J': cJ++; break;
                    case 'K': cK++; break;
                    case 'L': cL++; break;
                    case 'M': cM++; break;
                    case 'N': cN++; break;
                    case 'O': cO++; break;
                    case 'P': cP++; break;
                    case 'Q': cQ++; break;
                    case 'R': cR++; break;
                    case 'S': cS++; break;
                    case 'T': cT++; break;
                    case 'U': cU++; break;
                    case 'V': cV++; break;
                    case 'W': cW++; break;
                    case 'X': cX++; break;
                    case 'Y': cY++; break;
                    case 'Z': cZ++; break;
                }
            }
            printf("A: %d\nB: %d\nC: %d\nD: %d\nE: %d\nF: %d\nG: %d\nH: %d\nI: %d\nJ: %d\nK: %d\nL: %d\n",cA,cB,cC,cD,cE,cF,cG,cH,cI,cJ,cK,cL);
            printf("M: %d\nN: %d\nO: %d\nP: %d\nQ: %d\nR: %d\nS: %d\nT: %d\nU: %d\nV: %d\nW: %d\nX: %d\n",cM,cN,cO,cP,cQ,cR,cS,cT,cU,cV,cW,cX);    
            printf("Y: %d\nZ: %d\n",cY, cZ);//the number of times each letter appears is printed to stdout
        
            /*
             * The number of times each letter appears allows us to decrypt the cipher text using statistical analysis, By comparing the 
             * frequency of each letter in the cipher text to the average frequency of each letter in the english language. For example, the
             * letter E is the most frequently used letter in the english language, therefore the most frequent letter in the cipher text
             * is decrypted as E.
             */
            
            printf("Enter the letters in the list above, in ascending order of frequency (ALL CAPS, no spaces):\n");
            scanf("\n%[^\n]s", key6);
            
    
            for(count6a=0; count6a<strlen(message6); count6a++)//loop moves along each character of cipher text (array message6)
            {
                for(count6b=0; count6b<26; count6b++)//loop moves along each letter of array key6
                    {
                        if (message6[count6a]==key6[count6b])//when a specific character in the cipher text is a specific letter in key6 
                        {
                            message6[count6a]=freq[count6b];//that character becomes the corresponding character in the standard alphabet
                            break;
                        }
                        else
                        {
                            message6[count6a]=message6[count6a];//if the character is anything other than a letter it remains the same
                        }
                    }
            }
            
            printf("Your message decrypted is: \n%s\n", message6);
            break;
            
        default: printf("Unknown option %c\nPlease enter 1, 2, 3, 4, 5 or 6\n", c); //This default case accounts for if the user inputs something other than 1-6 in the menu
    
    }
}