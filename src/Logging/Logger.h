#pragma once
#include <string>
#include <vector>

namespace mte {
	
	enum class ErrorSeverityLevel
	{
		normal = 0,//white
		bad,//yellow
		severe,//orange
		gameCrashing,//red
		good,//green
		great,//blue
		other,//purple
	};

	struct Error {
	public:
		std::string _errorLocation = "";
		std::string _errorMessage = "";
		std::string _error;//time of error
		ErrorSeverityLevel _errorSeverity = ErrorSeverityLevel::normal;
		void print();
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