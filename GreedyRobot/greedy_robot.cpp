// Tushar Ganta
// CSS342 Dimpsey
// October 29th, 2022

#include "greedy_robot.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// The no args constructor will set everything to zero.
GreedyRobot::GreedyRobot()
{
  this->max_distance_ = 0;
  this->robot_x_ = 0;
  this->robot_y_ = 0;
  this->treasure_x_ = 0;
  this->treasure_y_ = 0;
}

// In this constructor, we will set the current greedy robot object's values to the values we pass in, and we then call
// the method which will run the recursive call to find the paths.
GreedyRobot::GreedyRobot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
  this->max_distance_ = max_distance;
  this->robot_x_ = robot_x;
  this->robot_y_ = robot_y;
  this->treasure_x_ = treasure_x;
  this->treasure_y_ = treasure_y;
  // AllPaths(robot_x, robot_y, treasure_x, treasure_y, max_distance, "", ' ');
}

// destructor
GreedyRobot::~GreedyRobot() {}

// This is the method which will check if we reached the goal and return true if we did.
bool GreedyRobot::GoalReached(int robot_x, int robot_y, int treasure_x, int treasure_y) const
{
  return (robot_x == treasure_x && robot_y == treasure_y);
}

/**
 * This is the recursive function where we take in the robot coordinates, treasure coordinates, how many steps we took
 * which direction we went in, and what the previous direction was.
 * We first check if the steps we already took in a certain direction is greater than the max distance we set.
 * if it is, then we exit that conditional. We then check if we reached the goal. if we did, we then add the last direction we
 * used and add it to our path, which is a vector of strings.
 * If the treasure is above our current location, we move north by incrementing the robot y coordinate
 * if the treasure is to the left of our current location, we move west by decrementing the robot x coordinate
 * if the treasure is below our currnet location, we move south by decrementing the robot y coordinate
 * if the treasure is to the right of our current location, we move east by incrementing the robot x coordinate
 */
void GreedyRobot::AllPaths(int robot_x, int robot_y, int treasure_x, int treasure_y, int steps_taken, string direction, char previous)
{
  if (steps_taken > max_distance_)
  {
    // this means it will exit.
    return;
  }

  if (GoalReached(robot_x, robot_y, treasure_x, treasure_y))
  {
    path.push_back(direction);
    return;
  }

  // To move North
  if (treasure_y > robot_y)
  {
    if (previous != 'N')
    {
      AllPaths(robot_x, robot_y + 1, treasure_x, treasure_y, 1, direction + 'N', 'N');
    }
    else
    {
      AllPaths(robot_x, robot_y + 1, treasure_x, treasure_y, steps_taken + 1, direction + 'N', 'N');
    }
  }

  // To move East
  if (treasure_x > robot_x)
  {
    if (previous != 'E')
    {
      AllPaths(robot_x + 1, robot_y, treasure_x, treasure_y, 1, direction + 'E', 'E');
    }
    else
    {
      AllPaths(robot_x + 1, robot_y, treasure_x, treasure_y, steps_taken + 1, direction + 'E', 'E');
    }
  }

  // To move South
  if (treasure_y < robot_y)
  {
    if (previous != 'S')
    {
      AllPaths(robot_x, robot_y - 1, treasure_x, treasure_y, 1, direction + 'S', 'S');
    }
    else
    {
      AllPaths(robot_x, robot_y - 1, treasure_x, treasure_y, steps_taken + 1, direction + 'S', 'S');
    }
  }

  // To move West
  if (treasure_x < robot_x)
  {
    if (previous != 'W')
    {
      AllPaths(robot_x - 1, robot_y, treasure_x, treasure_y, 1, direction + 'W', 'W');
    }
    else
    {
      AllPaths(robot_x - 1, robot_y, treasure_x, treasure_y, steps_taken + 1, direction + 'W', 'W');
    }
  }
}
