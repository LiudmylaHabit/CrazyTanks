#ifndef CONST_DEF
#define CONST_DEF

const int Height = 20;
const int Width = 50;
const char empty = ' ';
const char wall = '0';
const char player = 'A';
const char enemy = 'X';
const char bullet = '*';
const int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //up, right, down, left

const int WALL_COUNT = 100;
#endif