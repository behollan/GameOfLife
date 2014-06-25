//
//  main.cpp
//  game thing
//
//  Created by Joseph Gibson on 25.06.14.
//  Copyright (c) 2014 Joseph Gibson. All rights reserved.
//

//here we fucking go
#include <iostream>
#include <iomanip>
#define H 30 //Define height
#define W 30 //Define width
using namespace std;

void clear(bool mat[][W]) //Sets matrix to all dead
{
    for (int m = 0; m < H; m++)
    {
        for (int n = 0; n < W; n++)
            mat[m][n] = 0;
    }
}

void print(bool mat[][W]) //Prints matrix to screen
{
    cout << setw(3) << " ";
    for (int p = 0; 5*p < W; p++) cout << setw(5) << 5*p+1;
    cout << endl;
    for (int m = 0; m < H; m++)
    {
        cout << setw(3) << m+1;
        for (int n = 0; n < W; n++)
        {
            if (mat[m][n]) cout << "#";
            else cout << "-";
        }
        cout << endl;
    }
}

int main()
{
    bool now[H][W];
    int x, y;//cont; //Used for user input
    
    cout <<endl<<endl<< left << "Welcome to Conway's Game of Life." << endl << endl;
    cout << "The Rules of Life:" << endl;
    cout << "1. <2 neighbors: dies" << endl;
    cout << "2. >3 neighbors: dies" << endl;
    cout << "3. =2,3 neighbors reamins same" << endl;
    cout << "4. dead+3neighbors ITS ALIVE!" << endl << endl;
    cout << "Press any key to begin. Enter the column and row of a cell to make \nlive, separated by a space. ";
    cout << "When you are ready, enter \"-1\" to begin the \nsimulation. Then enter any number to continue or \"-1\" to quit." << endl;
    cin.get();
    
    clear(now);
    print(now);
    
    do //Get initial state
    {
        cin >> x;
        if (x == -1) break; //User is done inputting
        cin >> y;
        if(now[y-1][x-1]==1)
            now[y-1][x-1] = 0;
        else
            now[y-1][x-1] = 1; //Sets cell to alive
        
        print(now); //Updates screen
    }while(x != -1);
    
    
    return 0;
}
