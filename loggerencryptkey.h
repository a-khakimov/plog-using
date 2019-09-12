#ifndef LOGGERENCRYPTKEY_H
#define LOGGERENCRYPTKEY_H

#include <string>

class LoggerEncryptKey {
public:
    LoggerEncryptKey(const std::string& keyPath);
    const std::string getKey();
    bool good();

private:
    std::string m_key;
    bool        m_good;
};

#endif // LOGGERENCRYPTKEY_H
