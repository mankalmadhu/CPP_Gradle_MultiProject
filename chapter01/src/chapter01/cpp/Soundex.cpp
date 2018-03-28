#include <Soundex.hpp>
#include<unordered_map>

namespace{

const size_t MaxCodeLength {4};

auto zeroPad( std::string const & word )
{
    auto zerosNeeded =  MaxCodeLength - word.length();
    return word + std::string(zerosNeeded , '0');
}

auto head(std::string const & word)
{
  return word.substr(0,1);
}

auto tail(std::string const & word)
{
  return word.substr(1);
}

auto encodedDigit(char letter)
{
    static const std::unordered_map<char, std::string> encodings {
       {'b',"1"},
       {'f',"1"},
       {'p',"1"},
       {'v',"1"},
       {'c', "2"},
       {'g', "2"},
       {'j', "2"},
       {'k', "2"},
       {'q', "2"},
       {'s', "2"},
       {'x', "2"},
       {'z', "2"},
       {'d',"3"},
       {'t',"3"},
       {'l',"4"},
       {'m',"5"},
       {'n',"5"},
       {'r',"6"}
    };

    auto found = encodings.find(letter);
    return found != encodings.end() ? found->second : "";
}

bool isEncodingComplete(std::string const & encodedString)
{
  return encodedString.length() == MaxCodeLength -1
;}

auto encodedDigits(std::string const & word)
{
  std::string encoding;
  for(auto eachChar : word)
  { 
    if(isEncodingComplete(encoding))
    {
      break;
    }
    encoding += encodedDigit(eachChar);
  }
  return encoding;
}

}

std::string Soundex::encode(const std::string &word) const
{
  return zeroPad(head(word)+ encodedDigits(tail(word)));
}
