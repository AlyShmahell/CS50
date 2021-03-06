/**
 * Copyright (C) 2015-2016 Aly Shmahell
 */

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <sysexits.h>
#include "bigint_255.hpp"
#include "turing50.hpp"
using namespace std;
#ifndef EVOLVE50_INCLUDED
#define EVOLVE50_INCLUDED
stack <string> stak;
queue <string> que;
string father;
string genepool[4]= {"+",".",",","-"};
int current_pool_size;
void upload();
void tick();
void cycle();
void check(string strng);
short select(string strain);
long long int dinput[3];
long long int doutput[3];
string mate(string alpha,string beta);

void initialize()
{
    for (int i=0; i<4; i++)
    {
        stak.push(genepool[i]);
    }
}

void upload()
{
    current_pool_size=0;
    while(!stak.empty())
    {
        que.push(stak.top());
        current_pool_size++;
        stak.pop();
    }
}

void tick()
{
    while(!que.empty())
    {
        father=que.front();
        que.pop();
        for(int i=0; i<4; i++)
        {
            check(mate(father,genepool[i]));
        }
    }
}
string mate(string alpha,string beta)
{
    stringstream sstream;
    string strng;
    sstream<<alpha<<beta;
    sstream>>strng;
    return strng;
}

void cycle()
{
    upload();
    while(current_pool_size--)
    {
        tick();
    }
}

void check(string strng)
{
    short flag=2;
    long long int scan=foutput;
    for(int i =0; i<3; i++)
    {
        finput=dinput[i];
        functional_mode(strng);
        if(foutput!=doutput[i]&&scan!=foutput)
        {
            flag=0;
            break;
        }
        else if(foutput!=doutput[i]&&scan==foutput)
        {
            flag=1;
            break;
        }
    }
    if(flag==2)
    {
        cout<<"Success  :  "<<strng<<endl;
        exit(0);
    }
    else if(flag==1)
    {
        cout<<"hold   :   "<<strng<<endl;
        stak.push(strng);
    }
    else if(flag==0)
    {
        cout<<"failure  :  "<<strng<<endl;
    }
}
#endif
