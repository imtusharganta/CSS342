// Tushar Ganta
// CSS342 Dimpsey
// October 29th, 2022

#include <iostream>
using namespace std;

/*
This method is a recursive method for the catalan number
We first check if the number is less than or equal to run, because the catalan number of 1 is one.
We then perform the catalan function recursively and then add it to the result, and then return the result.
*/

int catalan(int n);
int catalan(int n)
{
  if (n <= 1)
  {
    return 1;
  }
  else
  {
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      result += catalan(i) * catalan(n - i - 1);
    }
    return result;
  }
}

/*
In this main method, we take in the character arguments, and then print out the catalan number using the catalan method call.
*/
int main(int argc, char *argv[])
{
  int temp = atoi(argv[1]);
  if (temp < 0)
  {
    cout << "Enter a Postive Number" << endl;
  }
  else
  {
    cout << catalan(temp) << endl;
  }
  return 0;
}