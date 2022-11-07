// Tushar Ganta
// CSS342 Dimpsey
// October 29th, 2022

#ifndef GREEDY_ROBOT_H
#define GREEDY_ROBOT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma once
/*
This is the Header File for the greedy robot. I used a vector and string for adding it to the path that we display in terminal
*/
class GreedyRobot
{

    /*
    I create 2 constructors. One which takes in no arguments, and another which takes in the max distance we can travel at a time on
    one direction, the x and y coordinates of our robot, and the x and y coordinates of our treasure.
    We also have a goal reached method to show that if we reached our goal, we will return true and execute whatever else
    is needed.
    AllPaths is the method that I use to find all the possible paths to the coordinate.
    */
public:
    GreedyRobot();
    GreedyRobot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);
    bool GoalReached(int robot_x, int robot_y, int treasure_x, int treasure_y) const;
    void AllPaths(int robot_x, int robot_y, int treasure_x, int treasure_y, int steps, string direction, char previous);
    vector<string> path;

    ~GreedyRobot();
    /*
    Private instance variables.
    */
private:
    int robot_x_;
    int robot_y_;
    int treasure_x_;
    int treasure_y_;
    int max_distance_;
};

#endif