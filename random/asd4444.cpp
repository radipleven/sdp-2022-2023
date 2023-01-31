#include <iostream>

unsigned int myAbs(int num)
{
	return (num > 0 ? num : (-num));
}

unsigned int myTest(int a)
{
	return a*2;
}
double myFabs(double num)
{
	double epsilon = 0.00000001;
	return ((num-epsilon)>0 ? num:(-num));
}

char to_lower(char ch)
{
	return ch + ('a' - 'A');
}

char to_upper(char ch)
{
	return ch - ('a'-'A');
}

int convertCharToInt(char ch)
{
	int num = ch - '0';
	return num;
}

char convertIntToChar(int n)
{
	char ch = n + '0';
	return ch;
}

int getLength(int n)
{
	int counter = 0;
	while (n!=0)
	{
		counter++;
		n /= 10;
	}
	return counter;
}

int reverse(int num)
{
	int newnum = 0;
	while (num!=0)
	{
		newnum = (num % 10) + 10*newnum;
		num /= 10;
	}
	return newnum;
}

int getKDigit(int n, int k)
{
	int length = getLength(n) - k;
	for (int i = 0; i < length; i++)
	{
		n /= 10;
	}
	return n % 10;
}

int squareRoot(int n)
{
	for (int i = 1; i <= n/2; i++)
	{
		if (i * i > n)
			return i - 1;
	}
	return -1;
}

bool exSquareRoot(int n)
{
	for (int i = 1; i*i <= n; i++)
	{
		if (i * i == n)
			return true;
	}
	return false;
}

int main()
{
	//task 1
	/*int n;
	std::cin >> n;
	std::cout<<myAbs(n);*/
	/*double n;
	std::cin >> n;
	std::cout << myFabs(n);*/

	//task 2
	/*char ch;
	std::cin >> ch;
	std::cout<<to_upper(ch);*/

	//task 3
	/*char ch;
	std::cin >> ch;
	std::cout << convertCharToInt(ch);*/
	/*int num;
	std::cin >> num;
	std::cout << convertIntToChar(num);*/

	//task 4
	/*int n;
	std::cin >> n;
	std::cout << getLength(n);*/

	//task 5

	/*int n = 6289;
	int k = 4;
	std::cout << getKDigit(n, k);*/

	//task 6
	/*int n = 0;
	std::cin >> n;
	std :: cout << squareRoot(n);*/

	//task 7



    return 0;
}
