#pragma once
#include<iostream>
#include<string>
#include <logger.h>
#include <configurator.h>
#include <layout.h>
#include <loggingmacros.h>
#include <helpers/stringhelper.h>

#define MY_LOG_FILE "./logconfig.properities"

#define DEBUG_LOG(logEvent) LOG4CPLUS_DEBUG(pMyLogger->logger,logEvent)
#define INFO_LOG(logEvent) LOG4CPLUS_INFO(pMyLogger->logger,logEvent)
#define ERROR_LOG(logEvent) LOG4CPLUS_ERROR(pMyLogger->logger,logEvent)
using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

class MyLogger
{
public:
	static MyLogger* getInstance(char* pLogName);
	static void release();
	Logger logger;
private:
	MyLogger(char* pLogName);
	~MyLogger();
	static MyLogger* my_logger;
};
extern MyLogger * pMyLogger;
