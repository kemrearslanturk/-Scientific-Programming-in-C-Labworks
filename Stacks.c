#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
struct Stack{
    char entry[MAX];
    int count;
};
struct Stack stack;
void init(struct Stack *s){
    s->count = 0;
}
char pop(struct Stack *s){
    if(s->count > 0){
        s->count--;
        return s->entry[s->count];
    }
}
char peek(struct Stack *s){
    return s->entry[s->count];
}
void push(struct Stack *s, char c){
    if(s->count < MAX){
        s->entry[s->count] = c;
        s->count++;
    }
}
int checkPalindrome(char str[MAX]){
    int i = 0, j = 0; char temp[MAX];
    while(str[i] != '\0'){
        if(str[i] != ' '){
            push(&stack, str[i]);
        }
        i++;
    }
    while(i > 0){
        temp[j] = pop(&stack);
        j++; 
		i--;
    }
    return !strcmp(str, temp);
}
int cumle(char str[MAX],int count){
	char array1[MAX];
	int i,temp,n;
	while(str[i]!='\0'){
	if(str[i] != ' '){
		array1[temp]=str[i];
			i++;
			temp++;
}
else if(str[i]==' '){
	checkPalindrome(array1);
	  if(checkPalindrome(array1)==1){
    	
    		count++;
	}
	else if(checkPalindrome(array1)==0){
	}
	temp=0;
	for(n=0; n<i; n++){
		array1[n]='\0';
	}
}
}
	return count;
}
char upper(char str[MAX]){
	int i;
	 for (i = 0; str[i]!='\0'; i++) {
      if(str[i] >= 'A' && str[i] <= 'Z') {
         str[i] = str[i] + 32;
      }
   }
}

int main(){
    char str[MAX],str2[MAX];
    printf("Write a word:\n");
    scanf(" %[^\n]s",&str);
    if(checkPalindrome(str)==1){
    	printf("Yes that word is palindrome");
	}
	else if(checkPalindrome(str)==0){
		printf("No that word is not palindrome");
	}
/*	scanf(" %[^\n]s",&str2);
	printf("%d",cumle(str2,0));*/

    return 0;
}
