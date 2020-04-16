#include "Logger.h"

void mte::Logger::printErrors()
{
	for (auto x : _errorList)
		x.print();
	_errorList.clear();
}

void mte::Error::print()
{
}

std::vector<mte::Error> mte::Logger::_errorList;