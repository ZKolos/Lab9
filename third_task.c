/* Task description:Substrings of strings
Please visit the homepage for more detail and visuals
Write a function that receives a string and copies only
a part of it, specified by a starting and an ending index!
(The received string must be intact.)
The start index is the position of the first character
to keep and the end index is the position of the first character
that it not to keep. (Hence, the interval is closed from
the left and open from the right).
When the start index is less than 0, or the end index is
 greater than the length of the string, write an error
 message to the screen before returning with invalid pointer!
The function should return with the address of a dynamically
 allocated string containing the substring to keep.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* substring(char* original, int start, int end)
{
  /*
   * Creates a new string from "orig" consisting of characters
   * between positions start and end. The caller is responsible
   * to release the memory behind the result of the function.
   */
  if(start < 0){
    printf("Invalid starting value");
    return NULL;
  }
  int originalLen=strlen(original);
  if(end > originalLen){
    printf("Invalid end value");
    return NULL;
  }
  if (start >= end){
    printf("Start has to be smaller than end");
    return NULL;
  }
  int len = end-start;
  char* new=(char*)malloc(sizeof(char)*(len+1));
  for (int i = 0; i < len; i++)
  {
    new[i]=original[start-1+i];
  }
  new[len]='\0';
  return new;
}

int main()
{
  char string[101] = "This is a text not containing anything rude or harsh"; // this is an array on the stack, mutable!
  char *substr = substring(string, 2, 10);
  printf("%s", substr);
  // Deallocate!!
  free(substr);
  return 0;
}
