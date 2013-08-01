#include "stdafx.h"
#include "Guess_Start.h"


Guess::Guess()
{
	m_Max = MAX;
	Target = -1;
	m_Min = 0;
}

void Guess::Set_Max()
{
	int Max;
	cout<<"请输入被猜数值的上限: ";
	cin>>Max;
	m_Max = Max;
}

int Guess::Judge(int Guess_Num)
{
	if(Guess_Num==Target)
	{
		return 1;
	}
	else if(Guess_Num>Target) 
	{
		m_Max = Guess_Num;
		//MessageBox(_T("数字在"),m_Min,_T("与"),m_Max,_T("之间"),_T("提示"),MB_ICONASTERISK|MB_OK);
		//cout<<"数字在"<<m_Min<<"与"<<m_Max<<"之间"<<endl;
		return 0;    
	}
	else if(Guess_Num<Target)
	{
		m_Min = Guess_Num;
		//MessageBox("数字在",m_Min,"与",m_Max,"之间","提示",MB_ICONASTERISK|MB_OK);
		// cout<<"数字在"<<m_Min<<"与"<<m_Max<<"之间"<<endl;
		return 0;
	}
	return 0;
}

void Guess::Play()
{
	srand(time(NULL));
	Target = rand()%m_Max + 1;

	//cout<<Target<<endl;

	while(1)
	{

		// cout<<"请输入要猜的数: ";

		if(Judge(Person)==1)  
		{
			//MessageBox(_T("您猜中了数字，电脑获胜!"),_T("提示"),MB_ICONWARNING|MB_OK);
			//cout<<"您猜中了数字，电脑获胜!"<<endl;
			break;
		}
		//srand(time(NULL));
		Computer = m_Min+rand()%(m_Max-m_Min-1)+1;

		// cout<<"电脑猜的是: "<<Computer<<endl;

		if(Judge(Computer)==1)  
		{
			//MessageBox("您猜中了数字，电脑获胜!","提示",MB_ICONWARNING|MB_OK);
			//cout<<"电脑中了数字，您获胜了!"<<endl;
			break;
		}
	}
}