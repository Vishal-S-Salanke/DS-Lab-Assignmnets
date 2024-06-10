#include<stdio.h>

int match(char *str1, char *substr1);
int checksubString(char *str2, char *substr2);

int main(){
   char str[20],substr[20];
   printf("Enter a string: ");
   gets(str);
   printf("Enter a substring: ");
   gets(substr);
   if(checksubString(str,substr)==1)
   {
      printf("TRUE");
   }
   else
   {
      printf("FALSE!"); 
   }
   return 0;
}

int match(char *str1, char *substr1)
{
   if (*substr1 == '\0')
   {  
	 return 1;
   }
   if (*str1 == '\0')
   {
      if(*substr1 != '\0')
      {
         return 0;
      }
   }
   if (*str1 == *substr1)
   {
      return match(str1 + 1, substr1 + 1);
   }
   return 0;
}

int checksubString(char *str2, char *substr2)
{
   if (*str2 == *substr2)
   {
      if(match(str2, substr2))
      {
         return 1;
      }
   }
   if (*str2 == '\0')
   {
      return 0;
   }
   else
   {
      return checksubString(str2 + 1, substr2);
   }
   return checksubString(str2 + 1, substr2);
}
