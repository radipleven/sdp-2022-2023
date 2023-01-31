#include "solution.h"
#include <stack>

bool isCorrect(const char* expression)
{
  //Create a pointer to the beginning of the string and a stack to store the brackets that have been encountered
  const char* phrase = expression;
  char  current =  *phrase;;
  std:: stack <char> parenthesis;
  

  while (*phrase != '\0')
  {
    current=*phrase;
    //Iterate through the string. If the current character is not a bracket, skip it. 
    if (current != '(' && current != ')' && current != '[' && current != ']' && current != '{' && current != '}' ) 
    {
      phrase ++;
      continue;
    }
    
 
    // If it is an opening bracket, push it onto the stack
    if (current == '(') parenthesis.push('(');

    //If it is a closing bracket, check if the stack is empty or the top element is not the corresponding opening bracket
    if (current==')' && ( parenthesis.empty() || parenthesis.top() != '('  ))
    {
        return false;
    }
    //Otherwise, pop the top element from the stack
    //Same applies for the other types of brackets
    else if (current == ')' && ( parenthesis.empty() || parenthesis.top() == '('  )) parenthesis.pop();
    
    if (current=='[')  parenthesis.push('[');
     
    if (current==']' && ( parenthesis.empty() || parenthesis.top() != '['  ))
    {
        return false;
    }else if (current == ']' && ( parenthesis.empty() || parenthesis.top() == '['  )) parenthesis.pop();
    


    if (current=='{') parenthesis.push('{');
      
    if (current=='}' && ( parenthesis.empty() || parenthesis.top() != '{'  ))
    {
        return false;
    }else if (current == '}' && ( parenthesis.empty() || parenthesis.top() == '{'  )) parenthesis.pop();
    
    phrase++;
  }
  //After all characters have been processed, return true if the stack is empty (i.e. all opening brackets have been matched with closing brackets)
  //and false otherwise
  return parenthesis.empty();
} 