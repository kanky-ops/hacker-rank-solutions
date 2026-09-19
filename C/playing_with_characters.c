#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
 char ch;
 char S[100];
 char Sen[100];
 scanf("%c",&ch);
  scanf("%s",S);
  scanf("\n");
  
  scanf("%[^\n]%*c",Sen);
   printf("%c\n",ch);
  printf("%s\n",S);
  printf("%s\n",Sen); 
    return 0;
}
