#include <Soundex.hpp>
#include<unordered_map>

namespace{

const size_t MaxCodeLength {4};
const std::string NotADigit{"*"};

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

auto lastEncodedDigit(std::string const & encoding)
{
  return encoding.empty() ? NotADigit : std::string(1,encoding.back());
}

auto lower(char letter)
{
  return std::tolower(static_cast<unsigned char>(letter));
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

    auto found = encodings.find(lower(letter));
    return found != encodings.end() ? found->second : NotADigit;
}

bool isEncodingComplete(std::string const & encodedString)
{
  return encodedString.length() == MaxCodeLength;
}

auto upperFront(std::string const & encodedString)
{
  return std::string(1,
  std::toupper(static_cast<unsigned char>(encodedString.front())));
}

void encodeHead(std::string& encoding, std::string const & word)
{
  encoding += encodedDigit(word.front());
}

bool isVowel(char letter)
{
  return std::string("aeiouy").find(lower(letter)) != std::string::npos;
}

void encodeLetter(std::string& encoding,char letter, char lastLetter)
{
  auto currentEncodedDigit = encodedDigit(letter);
  if(currentEncodedDigit != NotADigit && 
  (currentEncodedDigit != lastEncodedDigit(encoding) || isVowel(lastLetter)))
  {
    encoding += currentEncodedDigit;
  }
}

void encodeTail(std::string& encoding, std::string const & word)
{
  for(auto i=1u; i < word.length();i++)
  { 
    if(!isEncodingComplete(encoding))
    {
      encodeLetter(encoding,word[i],word[i-1]);
    }
   
  }

}

auto encodedDigits(std::string const & word)
{
  std::string encoding;
  encodeHead(encoding, word);
  encodeTail(encoding, word);
  return encoding;
}

}

std::string Soundex::encode(const std::string &word) const
{
  return zeroPad(upperFront(head(word))+ tail(encodedDigits(word)));
}
