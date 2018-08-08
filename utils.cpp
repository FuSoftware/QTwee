#include "utils.h"

const std::string Utils::WHITESPACE = " \t\f\v\n\r";

Utils::Utils()
{

}

std::ifstream::pos_type Utils::filesize(const std::string &filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

bool Utils::file_exists(const std::string& name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

std::vector<std::string> Utils::split(const std::string &s, char delim)
{
    std::istringstream ss(s);
    std::string token;
    std::vector<std::string> v;

    while(std::getline(ss, token, delim)) {
        v.push_back(token);
    }

    return v;
}

std::string Utils::trim(const std::string &s)
{
    std::string trimmed = s;
    int start = trimmed.find_first_not_of(Utils::WHITESPACE);
    int end = trimmed.find_last_not_of(Utils::WHITESPACE);
    trimmed.erase(0,start);
    trimmed.erase((end - start) + 1);
    return trimmed;
}
