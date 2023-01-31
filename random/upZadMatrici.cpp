#include <iostream>
using namespace std;
#define MAX_SIZE 100



void fillMatrix(int arr[][MAX_SIZE],size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      std::cin >> arr[i][j];
    }
  }
}

void printMatrix(int arr[][MAX_SIZE],size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (int j = size-1; j >= 0; j--) 
    {
        std::cout << arr[j][i];
    }
    std:: cout << std:: endl;
  }
}

int main()
{

    int matr[][MAX_SIZE] = {    {1,2,3},
                                {4,5,6},
                                {7,8,9}
                            };
    
    
    printMatrix(matr,3);
    return 0;
}
