/*
main for othello game
Taylor Bruening
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include"Othello.h"

using namespace std;

int main(){
Othello myg;

cout<<BOLD<<"\nOTHELLO\n"<<RESET;
cout<<"Enter lower case "<<RED<<"xx"<<RESET<<" to skip a turn\n\n";
myg.play();
myg.victory();

return 0;
}
