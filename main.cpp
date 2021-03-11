//
// Copyright (C)   ExecuitIF.
//
//
//
/***********************************************************************************************
 ***            C O N F I D E N T I A L  ---  E X E C U I T I F   S T U D I O S              ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name :   CloseGL                                                    *
 *                                                                                             *
 *                    File Name :   main.cpp                                                   *
 *                                                                                             *
 *                   Programmer :   ExecuitIF                                                  *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *          int main                                                                           *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */



#include "#.hpp"

int eulacheck()
{
	ifstream fin;
	fin.open(".\\eula.txt");
	if(!fin.is_open())
	{
		system("cd .\\&cd.>eula.txt");
		delay(1);
		fstream fout;
		fout.open(".\\eula.txt",ios::app | ios::app);
		fout<<"#Copyright ExecuitIF studios,all rights reserved!\n#You must agree eula(turn eula=false to eula=true) or you must delete all CloseGL files!\n#Do not remove any space or lines from this file!\n#Just turn eula=false to eula=true if you agree the eula.\n#eula address:\"https://github.com/CloseGLAPI/SCode/blob/master/eula.md\"""\n\neula=false";
		cout<<"[CloseGL.EULACHECK.ERROR]Created eula file,please agree eula!Find eula.txt for more information!\n";
		cout<<"[CloseGL.EULACHECK.INFO]Coudln't read eula.txt,stopping......\n";
		return -1;
	}
	char tmp[101]="\0",a[101]="\0";
	int eula=0;
	for(int i=1;i<=6;i++)
	{
		fin.getline(tmp,100);
	}
	fin.getline(a,100);
	if(!strcmp(a,"eula=true"))
	{
		return 0;
	}
	else
	{
		cout<<"[CloseGL.EULACHECK.ERROR]You must agree eula and turn eula.txt eula=false to eula=true!\n";
		cout<<"[CloseGL.EULACHECK.WARNING]Go eula.txt for more information!\n";
		cout<<"[CloseGL.EULACHECK.INFO]Coudln't read eula.txt,stopping......\n";
		return -2;
	}
	
}

static char x[2]="\0";
static char y[2]="\0";

int CloseGLruning()
{
	char final[101],a[1],b[1];
	strcat(final,"color");
	strcat(final," ");
	strcat(final,x);
	strcat(final,y);
	puts(final);
	system(final);
	return 0;
}



int main(int argc, char** argv)
{
	srand(time(NULL));//maybe will use
	if(argc>2)
	{
		strcpy(x,1+*(1+argv));
		strcpy(y,1+*(2+argv));
	}
	else
	{
		cout<<"\a\n\tUseage:CloseGL.exe [info1] [info2]\n";
		cout<<"\n\tEG:CloseGL.exe -4 -9\n";
		cout<<"\tGo https://github.com/CloseGLAPI/SCode/blob/master/help.md for more information.\n\n";
		pause;
	}
	//check eula
	if(eulacheck())
	{
		return -1;
	}
	//start doing.
	else
	{
		CloseGLruning();
	}
	return 0;
}

