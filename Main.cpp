// 1) How to design a static stack using array.
// Note: This static stack is an upside down stack
// since the first element of the stack is placed at the first position (smallest address)
// 2) How to design a dynamic stack using linked list.


#include "IntStack.h"
#include "DIntStack.h"
#include <string>
using namespace std ;

bool isNumber(char);
bool isOperand(char);
int prescedence(char);


int main()
{
	int i; 
	DIntStack stack;
	char equation;
	string eq;
	cout << "Please input an equation in Infix notation to be converted to Postfix notation: " << endl;
	cin>> eq;
	cout << "The input is " << eq<< endl;

	cout << "It's Postfix notation is " << endl;
	for( i = 0; i< eq.length(); i++)
	{
		char temp = eq[i];
		char diftemp ;
		if(eq[i] == ']') break;
		if(isNumber(temp))
		{
			cout << temp;
		}
		else
		{
			if(temp == '(')
			{
				stack.Push(temp);
			}
			else if(temp == ')')
			{
				try
					{
						do
						{
							diftemp = stack.Pop();
							if(diftemp != '(')
								{
									cout<< diftemp;
								}
						}while (diftemp != '(');
					}
				catch (IntStack::IsEmptyException)
					{
						cout << "The Stack is Empty " << endl ;
					}
			}
			else if( stack.Size() == 0 ) stack.Push(temp);

			else if (prescedence(stack.Top()) >= prescedence(temp))
			{
				try
					{
						while (prescedence(stack.Top()) >= prescedence(temp))
						{
							
							cout<< stack.Pop();
							if( stack.Size() == 0) break;
						}
					}
				catch (IntStack::IsEmptyException)
					{
						cout << "The Stack is Empty " << endl ;
					}
				stack.Push(temp);
			}
			else if (prescedence(stack.Top()) < prescedence(temp))
			{
				stack.Push(temp);
			}
			else if(temp == ']')
			{
				try
					{	
						while(stack.Size() != 0)
						{
							cout<< stack.Pop();
						}
					}
				catch (IntStack::IsEmptyException)
					{
						cout << "The Stack is Empty " << endl ;
					}
			}
		}

	}
	try
	{	
		while(stack.Size() != 0)
		{
			cout<< stack.Pop();
		}
	}
	catch (IntStack::IsEmptyException)
	{
		cout << "The Stack is Empty " << endl ;
	}



	system("pause") ;
	return 0 ;
}

bool isNumber(char c)
{
	if (isalpha(c)) return true;
	return false;

}
bool isOperand(char c)
{
	if(isalpha(c)) return false;
	return true;
}
int prescedence(char in)
{
	if( in == '*' || in == '/') return 4;
	if( in == '+' || in == '-') return 3;
	if( in == '(' ) return 2;
	if( in == '[' ) return 1;
}
