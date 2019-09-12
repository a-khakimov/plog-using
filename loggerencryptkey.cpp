#include "loggerencryptkey.h"
#include <fstream>

LoggerEncryptKey::LoggerEncryptKey(const std::string& keyPath) : m_good(false)
{
    std::ifstream keyFile(keyPath);
    if(keyFile.good()) {
        keyFile >> m_key;
        m_good = true;
    }
}

const std::string LoggerEncryptKey::getKey()
{
    return m_key;
}

bool LoggerEncryptKey::good()
{
    return m_good;
}
