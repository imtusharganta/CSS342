#include "time_span.h"
#include <iostream>
using namespace std;

int main()
{
  TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
  TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;

  // Given Driver Tests
  dur7 = dur1 + dur3;

  cout << dur1 << endl;
  cout << dur2 << endl;
  cout << dur3 << endl;
  cout << dur4 << endl;
  cout << dur5 << endl;
  cout << dur6 << endl;
  cout << dur7 << endl;

  dur7 += dur3;
  cout << dur3 << endl;
  cout << dur7 << endl;

  if (dur3 != dur6)
  {
    cout << "Durations are different." << endl;
  }
  else
  {
    cout << "Durations are the same" << endl;
  }

  // My own Tests
  cout << "----- MY TESTS -----" << endl;
  cout << "TEST 1, translation tests" << endl;
  TimeSpan obj1(10, 400, 60);
  cout << "should translate to 16, 41, 0. is: " << obj1 << endl;
  TimeSpan obj2(-18.5, -20, 24879);
  cout << "should translate to -11, -55, -21. is: " << obj2 << endl;
  TimeSpan obj3(0.4, -0.09, 236.98);
  cout << "should translate to 0, 27, 52, is: " << obj3 << endl;
  cout << " \n " << endl;
  cout << "TEST 2, comparison tests" << endl;
  TimeSpan obj4(8, 7.5, -30);        // 8:7:0
  TimeSpan obj41(8, 7, 0);           // 8:7:0
  TimeSpan obj5(13.5, -200, -1000);  // 9:53:20
  TimeSpan obj6(0, 0.07, 40);        // 0:0:44
  TimeSpan obj7(10, 20, 30);         // 10:20:30
  TimeSpan obj8(8, 90.1, 100.2);     // 9:31:46
  TimeSpan obj9(-10, 100, -100);     //-8:-21:-40
  TimeSpan obj10(98.11, 78.1, 58.1); // 99:25:40

  cout << "compare '==' obj4 and obj41, expected 1 because true. output: " << obj4.operator==(obj41) << endl;
  cout << "compare '==' obj4 and obj5, expected 0 because false. output: " << obj4.operator==(obj5) << endl;
  cout << "compare '!=' obj4 and obj6, expected 1 because true. output: " << obj4.operator!=(obj6) << endl;
  cout << "compare '<'  obj6 and obj7, expected 1 because true. output: " << obj6.operator<(obj7) << endl;
  cout << "compare '>'  obj8 and obj9, expected 1 because true. output: " << obj8.operator>(obj9) << endl;
  cout << "compare '<=' obj4 and obj41, expected 1 because true. output: " << obj4.operator<=(obj41) << endl;
  cout << "compare '>=' obj6 and obj10, expected 0 because false. output: " << obj6.operator>=(obj10) << endl;
  cout << " \n " << endl;

  cout << "TEST 3 More Overloads" << endl;
  TimeSpan obj11(0);
  TimeSpan obj12(12, 15);
  TimeSpan obj13(-2, 300, -20);
  TimeSpan obj14(1, 2, 3);

  cout << "Should be 0, 12, 15, output: " << obj11.operator+(obj12) << endl;
  cout << obj11 << endl;
  cout << obj7.operator-(obj12) << endl;
  cout << obj11.operator+=(obj13) << endl;
  cout << obj11.operator-=(obj14) << endl;
  cout << obj11.operator+(obj5) << endl;
  cout << obj11 << endl;
}