#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void push(char i);
void print();
void pop();

int main(){
	
	char given[100];
	int i = 0;
	
	printf("Enter Parenthesis and/or braces: ");
	gets(given);
	
	while(given[i] != '\0'){
		push(given[i++]);
			if(top > 1 && (contents[top-1] == ')' && contents[top-2] == '(') || (contents[top-1] == '}' && contents[top-2] == '{') || (contents[top-1] == ']' && contents[top-2] == '[') ){
				pop();
				pop();			
		}
	}
	
	if(top!=0)
		printf("Not Balance");
	else
		printf("Balance");
	return 0;
}


void make_empty(){
	top = 0;
}

bool is_empty(){
	return top == 0;
}

bool is_full(){
	return top == STACK_SIZE;
}

void push(char i){
	if(is_full())
		printf("overflow");
	else
		contents[top++] = i;
}

void pop(){
	if(is_empty())
		printf("underflow");
	else
		contents[--top];
}

void print(){
	int i;
	for(i=0;i<top;i++)
		printf("%c ",contents[i]);
		printf("\n");
}
