// Tushar Ganta
// CSS342 Dimpsey
// October 29th, 2022

#include "greedy_robot.h"
using namespace std;

int main(int argc, char *argv[])
{
  int max_distance = atoi(argv[1]);
  int robotx = atoi(argv[2]);
  int roboty = atoi(argv[3]);
  int treasurex = atoi(argv[4]);
  int treasurey = atoi(argv[5]);

  GreedyRobot robot(max_distance, robotx, roboty, treasurex, treasurey);
  robot.AllPaths(robotx, roboty, treasurex, treasurey, max_distance, "", ' ');

  for (string &s : robot.path)
  {
    cout << s << endl;
  }

  cout << "Number of paths: " << robot.path.size() << endl;

  return 0;
}