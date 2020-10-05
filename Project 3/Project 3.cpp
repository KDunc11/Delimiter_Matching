/* By: Kyle Duncan
 //Collaborated with Joseph Bulanon and Jeffrey Fairbanks
 //Project: Chapter 4, Delimiter Matching
*/

#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#include <fstream>
#include<string>
#include<math.h>

using namespace std;

bool delimiterMatching(string& fName); //Delimiter Matching function, based off the delimiter matching algorithm

int main()
{
	cout << "This program uses the delimiter matching algorithm to check code read in from a text file" << endl;

	string fileName;
	cout << "\n\n\n\nEnter the name of the file being opened(file name then add .txt or entry directory ex "
		<< "C:\\Users\\Kyle\\Desktop\\NNU\\Data Structures\\Project 3): ";
	cin >> fileName;

	delimiterMatching(fileName); //Passes user inputted file name into the function to check for syntax

	cin.ignore();
	cin.ignore();
	return 0;
}

bool delimiterMatching(string& fName)
{
	Stack<char> stack; //Creates an empty stack
	int lineNumber = 1; //Used to track the line number of the code, used for reporting errors in the code
	fstream file;

	file.open(fName);

	if (file.is_open()) //Proceed if the file can be opened
	{
		char temp, *poppedVal, check;
		
		cout << "\nFile opened, checking code......" << endl;

		while (!file.eof())
		{
			char ch = file.get();

			if (ch == '{' || ch == '(' || ch == '[') //If a opening {, (, or [ is found push it onto the stack
				stack.push(ch);

			else if (ch == '}' || ch == ')' || ch == ']') //If a closing }, ), ] is found attempt to pop off the stack
			{
				poppedVal = stack.topEl(); //Holds the value of what will be popped off the top of the stack
				stack.pop();

				if ((ch == '}' && *poppedVal != '{') || (ch == ')' && *poppedVal != '(') || (ch == ']' && *poppedVal != '[')) //Checks if the opening bracket popped off the stack matches the closing bracket found
				{
					cout << "\nDid not pass delimiter matching:\n\t" << *poppedVal << " did not match up with " << ch 
						<< " on line " << lineNumber <<  endl;
					return false;
				}
			}

			else if (ch == '\n') //If \n is found then increment the line count
			{
				lineNumber++;
			}

			else if (ch == '/') //To find the first / of a comment
			{
				check = file.get();

				if (check == '/') //If a single line comment is found
				{
					while (file.get() != '\n');
					lineNumber++;
					continue;
				}

				else if (check == '*') //Checks for a multiline /* */ comment
				{
					while (!file.eof())
					{
						temp = file.get();

						if (temp == '*')
						{
							while (temp == '*')
								temp = file.get();

							if (temp == '/') //If the end of the multiline comment is found then read the next character and break from the inner while loop
								break;
						}
						if (temp == '\n')
							lineNumber++;
					}
				}
				else
					file.unget(); //If a slash is being used for division then the check variable is returned to the file stream
			}

			else if (ch == '\"') //Checks for string literals
			{
				while (!file.eof())
				{
					check = file.get();

					if (check == '\\')
					{
						check = file.get();
						if (check == '\n')
							lineNumber++;
					}
					else if (check == '\n')
					{
						cout << "The slash (/) on line " << lineNumber << " has no closing quote" << endl;
						return false;
					}
					else if (check == '\"')
						break;
				}
			}

			else if (ch == '\'') //Checks for char literals
			{
				check = file.get();

				if (check == '\\')
				{
					check = file.get();
					if (check == '\n')
					{
						cout << "The char literal on line " << lineNumber << " does not have closing single quote." << endl;
						return false;
					}
				}

				check = file.get();
				// Checking to see if the char literal is the correct amount of digits
				if (check != '\'')
				{
					cout << "The char literal on line " << lineNumber << " has illegal length or does not have closing single quote." << endl;
					return false;
				}
			}

		} //End of while loop

		if (stack.isEmpty()) //If the end of the file is reached and the stack is empty then the code passes the check
		{
			cout << "\nCode passed delimiter matching" << endl;
			return true;
		}
		else //Otherwise a delimiter was not matched before the end of the file
		{
			cout << "\nDid not pass delimiter matching, still elements on the stack" << endl;
			return false;
		}
	}

	else //If the file couldn't be opened or found
	{
	cout << "\nCould not open file" << endl;
	return false;
	}

	file.close(); //Closes the file
}