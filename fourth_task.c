/* Task description:Removing parts from strings
Visit HP too!

Write the inverse of the previous function: the part delimited 
by the start and end indices should be removed from the original 
text, and the rest is kept! 
The function should not modify the source string received as a 
parameter, a brand new string should be created dynamically, and 
returned by the function.

Write a C program to demonstrate the usage of the function. 
Don't forget to release the memory at the end.


*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removestring(char* original, int start, int end)
{
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
  int len = originalLen-(end-start);
  char* new=(char*)malloc(sizeof(char)*(len+1));
  for (int i = 0; i < len; i++)
  {
    new[i]=(i<start-1)?(original[i]):(original[end+i-start]);
  }
  new[len]='\0';
  return new;
}

int main(){
  char string[101] = "This is a text not containing anything rude or harsh"; // this is an array on the stack, mutable!
  char *remstr = removestring(string, 2, 10);
  printf("%s", remstr);
  // Deallocate!!
  free(remstr);
  return 0;
}
