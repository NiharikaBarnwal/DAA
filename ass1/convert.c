//Convert infix to postfix
//Niharika Barnwal
//30
#include<stdio.h>
#include<stdbool.h>
#define max 100
int top=-1;
int stack[max];
bool IsFull();
bool IsEmpty();
void push(char);
char pop();
int precedence(char x);
void convert_postfix(char infix[], char postfix[]);
int main()
{
	int x;
	char infix[20], postfix[20];
	printf("Enter the infix Expression:");
	scanf("%[^\n]",infix);
	convert_postfix(infix,postfix);
	printf("The converted postfix expression is %s\n",postfix);
}
bool IsFull()
{
	if(top==max-1)
		return 1;
	else
		return 0;
}
bool IsEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(char item)
{
	if(!IsFull())
	{
		top++;
		stack[top]=item;
	}
	else
		printf("Stack overflow\n");
}
char pop()
{
	if (!IsEmpty())
	{
		char x;
		x=stack[top];
		top--;
		return x;
	}
	else
		printf("Stack Underflow\n");
}
int precedence(char x)
{
	if(x=='(')
		return 0;
	if(x=='+' || x=='-')
		return 1;
	if(x=='*' || x=='/' || x=='%')
		return 2;
	return 3; //'^'
}
void convert_postfix(char infix[20], char postfix[20])
{
	int i,j=0,x;
	char symb;
	for(i=0;infix[i]!='\0';i++)
	{
		symb=infix[i];
	    if((symb>=65 && symb<=90) || (symb>=48 && symb<=57) || (symb>=97 && symb<=122))
        {
			postfix[j]=infix[i];
			j++;
		}
		else if(symb=='(')
			push(symb);
		else if(symb==')')
		{
			while((x=pop())!='(')
			{
				postfix[j++]=x;
			};
		}
		else	
		{
			while((precedence(symb)<=precedence(stack[top])) && !IsEmpty())
			{
				x=pop();
				postfix[j]=x;
				j++;
			}
			push(symb);
		}
	}
	while(!IsEmpty())
	{
		x=pop();
		postfix[j]=x;
		j++;
	}
	postfix[j]='\0';
}
