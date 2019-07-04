/*TD7 EX2-4*/

#include <stdlib.h>
#include <stdio.h>

// Role : revoie la longueur de la chaine s
int Strlen(const char s[]){
  int i=0;
  while(s[i]!='\0')
    i++;
  return i;
}

/* role
 */
int Strchr2(const char s[],const char c){
  int i=0;
  int trouve=0;
  
  while(s[i]!='\0' && !trouve){
    if(s[i]==c) trouve=1;
    else
      i++;
}
  //
  return trouve ? i : -1;
}

int Strchr1(const char s[],const char c){
  for(int i=0;s[i]!='\0';i++){
    if(s[i]==c)
      // c is in s at index i
      return i;
  }
  // c not in s
  return -1;
}

// Role: s1=s2 ,copy s2 to s1
void Strcpy(char s1[],const char s2[]){
  int i=0;
  while((s1[i]=s2[i]) != '\0')
    i++;
}

// Role: s1=s1+s2,appends string s2 to string s1
void Strcat(char s1[],const char s2[]){
  int i=0,j=0;
  while(s1[i]!='\0')
    i++;
  while((s1[i]=s2[i]) !='\0'){
    i++;j++;
  }
}

/* role : compare the two string s1 and s2
 * s1 > s2 return a int > 0
 * s1 == s2 return 0
 * s1 < s2 return a int < 0
 */
int Compare(const char s1[],const char s2[]){
  int i=0;
  while(s1[i]!='\0' && s2[i]!='\0'){
    
    if((s1[i]>='a'&&s2[i]>='a') || (s1[i]<='Z'&&s2[i]<='Z')){
      if(s1[i]>s2[i]) return 1;
      else if(s1[i]<s2[i]) return -1;
    }
    else if(s1[i]<s2[i]) return 1;
    else return -1;
    
    i++;
  }
  if(s1[i]>s2[i]) return 1;
  else if(s1[i]<s2[i]) return -1;
  return 0;
}

int Compare2(const char s1[],const char s2[]){
  int i=0;
  while(s1[i]==s2[i])
    if(s1[i++]=='\0')
      return 0;
  return s1[i]-s2[i];
}

int main(){

  char str1[10];
  char str2[]="bonjour";

  printf("lg = %d\n",Strlen(str2));
  printf("pos = %d\n",Strchr1(str2,'j'));
  printf("pos = %d\n",Strchr2(str2,'z'));

  Strcpy(str1,str2);
  printf("str1 = (%s)\n",str1);
  printf("str2 = (%s)\n",str2);

  char str3[8]="abri";
  char str4[]="cot";
  Strcat(str3,str4);
  printf("str3 = (%s)\n",str3);
  
  char str5[]="abcDe";
  char str6[]="abcdef";
  printf("%d\n",Compare(str5,str6));
  
  return EXIT_SUCCESS;
}
