
#ifndef _GUESS_START_H_
#define _GUESS_START_H_


#include <iostream>
using namespace std;

#include "time.h"


#define MAX 100

class Guess{
public:
         Guess();
	void Set_Max();
	void Play();
    int  Judge(int Guess_Num);

    int m_Max;
    int Target;
    int m_Min;
	int Person;
	int Computer;
};

#endif