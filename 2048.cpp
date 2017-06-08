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
bool matrix::no_zeroes(){
    int i,j;
    for(i=0;i<ORDER;++i)
        for(j=0;j<ORDER;++j)
            if(data[i][j]==0)
                return false;
    return true;
}
void matrix::display(){
    int i,j;
    for(i=0;i<ORDER;++i){
        cout<<"\n";
        for(j=0;j<ORDER;++j){
            cout.width(4);
            cout<<data[i][j]<<" ";
        }
    }
}
matrix::matrix(){
    int i,j;
    this->zeroes=0;
    srand((int) time(0));
    for(i=0;i<ORDER;++i)
        for(j=0;j<ORDER;++j){
            data[i][j]=0;
            empty[zeroes].i=i;
            empty[zeroes].j=j;
            zeroes++;
        }
}

void matrix::fill_random(){
   int i,j;
   zeroes=0;
   for(i=0;i<ORDER;++i){
      for(j=0;j<ORDER;++j)
      if(data[i][j]==0){
          empty[zeroes].i=i;
          empty[zeroes].j=j;
          zeroes++;
      }
   }
   int index = rand() % zeroes;
   data[empty[index].i][empty[index].j]=2;
}
bool matrix::up(){
    int col;
    bool generate=false;
    for(col=0;col<ORDER;++col){
        int ptr=1,stop=-1;
        while(ptr > 0 && ptr < ORDER){
          if(data[ptr][col]==0)
              ptr++;
          else if(data[ptr-1][col]==0){
                data[ptr-1][col]=data[ptr][col];
                data[ptr][col]=0;
                generate=true;
                if(ptr > 1)
                    ptr--;
                else
                    ptr++;
            }
            else if(data[ptr-1][col]==data[ptr][col] && stop < (ptr-1)){
                data[ptr-1][col]*=2;
                data[ptr][col]=0;
                stop = ptr-1;
                generate=true;
                if(ptr > 1)
                   ptr--;
                else
                   ptr++;
            }
            else
                ptr++;
        }
    }
    return generate;
};
bool matrix::down(){
    int col;
    bool generate=false;
    for(col=0;col<ORDER;++col){
        int ptr=ORDER-2,stop=ORDER;
        while((ptr < ORDER-1) && ptr >= 0){
          if(data[ptr][col]==0)
              ptr--;
          else if(data[ptr+1][col]==0){
                data[ptr+1][col]=data[ptr][col];
                data[ptr][col]=0;
                generate=true;
                if(ptr < 2)
                    ptr++;
                else
                    ptr--;
            }
            else if(data[ptr+1][col]==data[ptr][col] && stop > (ptr+1)){
                data[ptr+1][col]*=2;
                data[ptr][col]=0;
                stop = ptr+1;
                generate=true;
                if(ptr < 2)
                   ptr++;
                else
                   ptr--;
            }
            else
                ptr--;
        }
    }
    return generate;
}
bool matrix::left(){
    int row;
    bool generate=false;
    for(row=0;row<ORDER;++row){
        int ptr=1,stop=-1;
        while(ptr > 0 && ptr < ORDER){
          if(data[row][ptr]==0)
              ptr++;
          else if(data[row][ptr-1]==0){
                data[row][ptr-1]=data[row][ptr];
                data[row][ptr]=0;
                generate=true;
                if(ptr > 1)
                    ptr--;
                else
                    ptr++;
            }
            else if(data[row][ptr-1]==data[row][ptr] && stop < (ptr-1)){
                data[row][ptr-1]*=2;
                data[row][ptr]=0;
                stop = ptr-1;
                generate=true;
                if(ptr > 1)
                   ptr--;
                else
                   ptr++;
            }
            else
                ptr++;
        }
    }
    return generate;
}
bool matrix::right(){
    int row;
    bool generate=false;
    for(row=0;row<ORDER;++row){
        int ptr=ORDER-2,stop=ORDER;
        while((ptr < ORDER-1) && ptr >= 0){
          if(data[row][ptr]==0)
              ptr--;
          else if(data[row][ptr+1]==0){
                data[row][ptr+1]=data[row][ptr];
                data[row][ptr]=0;
                generate=true;
                if(ptr < 2)
                    ptr++;
                else
                    ptr--;
            }
            else if(data[row][ptr+1]==data[row][ptr] && stop > (ptr+1)){
                data[row][ptr+1]*=2;
                data[row][ptr]=0;
                stop = ptr+1;
                generate=true;
                if(ptr < 2)
                   ptr++;
                else
                   ptr--;
            }
            else
                ptr--;
        }
    }
    return generate;
};

