#pragma once
#include <string>
#include <vector>
#include <glfw/glfw3.h>
#include <iostream>
#include <windows.h> 

namespace mte {
	
	enum class ErrorSeverityLevel
	{
		normal = 7,//white 7 or 15
		bad = 14,//yellow 14
		severe=6,//orange
		gameCrashing=4,//red 4 or 12
		good=2,//green 2 or 10
		great=3,//blue 3 or 11
		other=5,//purple 4 or 13
		boring=8, //gray 8
	};

	struct Error {
	public:
		Error();
		std::string _errorLocation = "";
		std::string _errorMessage = "";
		float _errorTime;
		ErrorSeverityLevel _errorSeverity = ErrorSeverityLevel::normal;
		void print();
		static unsigned _errorTotal;
		unsigned _errorID = 0;
	private:
	};


	class Logger {
	public:
		void sendError(Error error) { _errorList.push_back(error); };

		void printErrors();

	private:

		static std::vector<Error> _errorList;


	};

}