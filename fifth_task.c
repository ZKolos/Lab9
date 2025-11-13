/* Task description:Inserting strings into strings

This task is similar to the previous ones: the function receives a string, and creates a new one.

This time, however, the task is not to remove/cut something from a string,
but to insert another string to somewhere into the original string.
For instance, the result of insertstring("hello!", 5, ", world") is a new string
containing hello, world!: the second string has been inserted between letters "o" and "!".
*/

#include <stdio.h> //don't forget to include the required libraries
#include <string.h>
#include <stdlib.h>

char* insert(char*original, int position, char* text){
  int lenog = strlen(original);
  int lentext = strlen(text);
  int len = lenog+lentext;
  char*new=(char*)malloc(sizeof(char)*(len+1));
  for (int i = 0; i < len; i++)
  {
    if (i<=position-1){
      new[i]=original[i];
    }else if(i<=(position+lentext)){
      new[i]=text[i-position-1];
    }else{
      new[i]=original[i-1+lentext];
    }
  }
  new[len]='\0';
  return new;
}

int main()
{
  char string[101] = "This is a text not containing anything rude or harsh";
  char *ins = insert(string, 2, "gurt sybau");
  printf("%s", ins);
  free(ins);
  return 0;
}
