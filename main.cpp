#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>
#include "loggerencryptkey.h"
#include "logencrypt.h"

int main()
{
    LoggerEncryptKey loggerEncryptKey("path/to/key");
    if (loggerEncryptKey.good()) {
        plog::key = loggerEncryptKey.getKey();
    }

    static plog::RollingFileAppender<plog::TxtFormatter, plog::LogEncrypt> encAppender("path/to/plogger.elog");
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::verbose, "path/to/plogger.log").addAppender(&consoleAppender).addAppender(&encAppender);

    PLOG_INFO << "Hello my little pony";
    PLOG_ERROR << "Hello my little pony";
    PLOG_DEBUG << "Hello my little pony";
    PLOG_VERBOSE << "Hello my little pony";
    PLOG_WARNING << "Hello my little pony";

    return 0;
}






