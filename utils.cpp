#include "utils.h"

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
