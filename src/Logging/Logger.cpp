#include "Logger.h"

void mte::Logger::printErrors()
{
	for (auto x : _errorList)
		x.print();
	_errorList.clear();
}

mte::Error::Error()
{
	_errorTime = (float)glfwGetTime();
	_errorTotal++;
	_errorID=_errorTotal;
	
}

void mte::Error::print()
{
	HANDLE  hConsole;//windows only
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (int)_errorSeverity);
	printf("Time: %4.2f File: %s  \n",_errorTime, _errorLocation.c_str());
	printf("ID: %d %s \n\n",_errorID,_errorMessage.c_str());



	SetConsoleTextAttribute(hConsole, 7);
}

std::vector<mte::Error> mte::Logger::_errorList;
unsigned mte::Error::_errorTotal = 0;