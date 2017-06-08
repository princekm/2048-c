#include<iostream>
#include <cstdlib>
#include<stdio.h>
using namespace std;

#define ORDER 4
#define QUIT(key) (key == 'q' || key == 'Q')
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'

class position{
    public:
    int i,j;
};

class matrix{
    public:
    int data[ORDER][ORDER];
    position empty[ORDER*ORDER];
    int zeroes;
    public:
    matrix();
    bool left();
    bool right();
    bool up();
    bool down();
    void fill_random();
    bool no_zeroes();
    void display();
};
