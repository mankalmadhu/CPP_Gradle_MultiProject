#include <Soundex.hpp>

namespace{
std::string zeroPad(const std::string &word)
{
    return word + "000";
}
}

std::string Soundex::encode(const std::string &word) const
{
    return zeroPad(word);
}
