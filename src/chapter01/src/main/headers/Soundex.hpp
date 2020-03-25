#pragma once

#include <string>

class Soundex
{

  public:
    std::string encode(const std::string &word) const;
};
