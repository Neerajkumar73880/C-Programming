/*Parenthesis Maching Code 
  Expresion = 3*2-(8+1)  */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	int size;
	int top;
	char *arr;
};
int isEmpty(struct stack* ptr){
	if(ptr->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(struct stack* ptr){
	if(ptr->top==ptr->size-1){
		return 1;                                                      
	}
	else{
		return 0;
	}
}

void push(struct stack* ptr,char val){
	if(isFull(ptr)){
		printf("Stack Overflow! cannot push %c to the stack\n",val);
	}
	else{
		ptr->top++;
		ptr->arr[ptr->top]=val;
	}
}
char stackTop(struct stack *ptr){
	return ptr->arr[ptr->top];
}
int match(char a,char b){
	if(a=='{' && b=='}'){
		return 1;
	}
	if(a=='(' && b==')'){
		return 1;
	}
	if(a=='[' && b==']'){
		return 1;
	}
	return 0;
}
int pop(struct stack* ptr){
	if(isEmpty(ptr)){
		printf("Stack Underflow! cannot pop from the stack\n");
		return -1;
	}
	else{
		char val =ptr->arr[ptr->top];
		ptr->top--;
		return val;
	}
}
int parenthesisMatch(struct stack * ptr,char str[]){
	char popped_ch;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			push(ptr,str[i]);
		}
		else if(str[i]==')' || str[i]=='}' || str[i]==']')
		{
			if(isEmpty(ptr)){
				return 0;
			}
			popped_ch=pop(ptr);
			if(!match(popped_ch,str[i])){
				return 0;
			}
		}
	}
	if(isEmpty(ptr))
	return 1;
	else
	return 0;
}
int main(){
	struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
	sp->size=100;
	sp->top=-1;
	sp->arr=(char *)malloc(sp->size*sizeof(char));
	
	char str[]="3*2{([])-()8}(+1)";
	if (parenthesisMatch(sp,str))
	{
		printf("Parenthesis  are  Balanced");
	}
	else
	    printf("Parenthesis are not Balanced");
	
	
	return 0;
}
