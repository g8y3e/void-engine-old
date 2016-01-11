#ifndef VOID_BASE_LOG_LOG_H_
#define VOID_BASE_LOG_LOG_H_

#include <string>

namespace void_base {
	namespace log {
		void print(const char* file, int line, const char* msg);
		void print(const char* file, int line, const std::string& msg);

		void print(const char* msg);
		void print(const std::string& msg);
	}

#ifdef _DEBUG 
#define LOG(x) log::print(__FILE__, __LINE__, (x))
#define LOG_CLEAR(x) log::((x))
#else
#define LOG(x)
#define LOG_CLEAR(x)
#endif

}

#endif