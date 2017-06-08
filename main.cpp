#include "2048.h"
#include<iostream>
using namespace std;


int main(){
    char key;
    matrix m;
    m.fill_random();
    m.display();
    bool generate;
    while(!QUIT(key)){
        cin >> key;
        generate = false;
        switch( key ){
            case KEY_UP:generate = m.up();break;
            case KEY_DOWN:generate = m.down();break;
            case KEY_LEFT:generate = m.left();break;
            case KEY_RIGHT:generate = m.right();break;
        }
        if(generate)
            m.fill_random();
        else if(m.no_zeroes()){
            cout<<"GAME OVER";
            exit(0);
        }
        m.display();
   }
}

