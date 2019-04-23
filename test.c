#include <stdio.h>

char rotationenc (char message[], int key);
int main()
{
    char message1[250]; //initialises the message as an array, and a variable which will identify individual letters
    int key1; //initialises the key and a counter which will be used when changing individual letters
    
    printf("Enter a message:\n");
    scanf("\n%[^\n]s", message1);//the user sends a message to stdin, which is stored in the array message1. "\n%[^\n]s" is used so that the message is read until a new line character, as opposed to a space character
    
    printf ("Enter an integer to use as the key:\n");
    scanf("%d", &key1);//user inputs number which will tell the code how many places each letter needs to be rotated
    
    
    printf("Your message encrypted is: \n%c\n", rotationenc (message1, key1));

}
char rotationenc (char message[], int key)
{
    char letter1;
    int count1=0;
    for (count1=0; message[count1] != '\0'; ++count1) //This loop travels along each individual element of the array message1, until it reaches a null character
    {
        letter1=message[count1]; //the char "letter1" becomes element "count1" of the array "message1"
        
        if (letter1>='a' && letter1<='z') //if the letter is lowercase
        {
            letter1=((letter1-'a')+key)%26+'a'; //the letter (which is stored as a numerical ASCII value) is rotated by the value of key
           
            message[count1]=letter1; //the encrypted letter is assigned to the original element of the array
        }
        else if (letter1>='A' && letter1<='Z')//if the letter is uppercase (same as above)
        {
           letter1=((letter1-'A')+key)%26+'A';
         
            message[count1]=letter1;
        }
        else
        {
            message[count1]=letter1; //if the character is anything other than a letter(e.g. space, full stop), it remains unchanged
        }
        return *message;
    }
    
}
