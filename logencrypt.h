#ifndef LOGENCRYPT_H
#define LOGENCRYPT_H

#include <string>
#include <plog/Log.h>


namespace plog
{

static std::string key;

class LogEncrypt
{
public:
    static std::string header(const plog::util::nstring &str)
    {
        return encrypt(str);
    }

    static std::string encrypt(const plog::util::nstring &str)
    {
        const std::string& in = str;
        std::string out;
        out.resize(in.size());

        for (size_t i = 0; i < out.size(); ++i) {
            out[i] = in[i] ^ key[i % (key.size() - 1)];
            if (i == out.size() - 1) {
                ++i;
                out.push_back('\n' ^ key[i % (key.size() - 1)]);
            }
        }
        return out;
    }
};
}

#endif // LOGENCRYPT_H
