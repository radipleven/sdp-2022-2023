#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "stack"
using namespace std;

int task1( int number ) {
  int result = number; //test solution, changes need to be made, implement stack
  int final =1;
  stack <int> numbers;
  for (int i = 0; i < number; i++)
  {
    numbers.push(result--);
  }
  for (int i = 0; i < number; i++)
  {
    int a =numbers.top();
    final *=a;
    numbers.pop();
  }
  
  return final;
}
bool task2 (const string& list) {
    stack <char> phrase;
    bool res = false;
    for (int i = 0; i < list.size(); i++)
    {
        phrase.push(list[i]);
    }
    for (int i = 0; i < phrase.size(); i++)
    {
      char sym1 = phrase.top();
    phrase.pop();
    char sym2 =phrase.top();
    phrase.pop();

    if (sym1==')' && sym2=='(')
    {
      res = true;
    }else if (sym1==']' && sym2=='[')
    {
      res = true;
    }else if (sym1=='}' && sym2=='{')
    {
      res = true;
    }
    }
    
    
    
    return res;
}


bool isCorrect(const char* expression)
{
  const char* phrase = expression;
  char prev;
  bool edits = false;
  stack <char> round;
  stack <char> square;
  stack <char> curly;
  int roundCount = 0;
  int sqCount = 0;
  int cuCount = 0;
  cout << "Before while" << endl;
  cout << "Round size: "<< round.size() << endl;
  cout << "Square size: "<< square.size() << endl;
  cout << "Curly size: "<< curly.size() << endl;
  
  while (*phrase != '\0')
  {
    char a= *phrase;
    std:: cout<< "char: " << a << std:: endl;
    if (a == '(')
    { 
      
      round.push('(');
      edits = true;
      roundCount ++;
      cout << "pushing ( in round" << endl;
    }else if (a==')')
    {
      round.pop();
      roundCount--;
      cout << "popping ( in round" << endl;
      if (roundCount<0 || prev=='[' || prev == '{')
      {
        return false;
      }
      
    }

    if (a=='[')
    { 
      
      square.push('[');
      edits = true;
      sqCount++;
      cout << "pushing [ in square" << endl;
    }else if (a==']')
    {
      square.pop();
      sqCount--;
      if (sqCount<0 || prev=='(' || prev == '{')
      {
        return false;
      }
      
    }

    if (a=='{')
    { 
      
      curly.push('{');
      edits = true;
      cuCount++;
    }else if (a=='}')
    {
      curly.pop();
      cuCount++;
      if (cuCount<0 || prev=='[' || prev == '(' )
      {
        return false;
      }
      
    }
    prev = a;
    phrase ++;
  }
  
    cout << "Round size: "<< round.size() << endl;
    cout << "Square size: "<< square.size() << endl;
    cout << "Curly size: "<< curly.size() << endl;
  if (round.size()==0 && square.size()==0 && curly.size()==0 )
  {
    return true;
  }else return false;
}
int main()
{
  stack<char> round;
  round.push('(');
  round.pop();
  
  //cout << "Size: "<< round.size()<< endl;

    cout << isCorrect("([])")<< endl;
    return 0;
}