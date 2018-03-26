#include <gmock/gmock.h>
#include <Soundex.hpp>

class SoundexEncoding : public testing::Test
{
  public:
    Soundex soundex;
};

using namespace testing;
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonanatsWithAppropriateDigits)
{
    ASSERT_THAT(soundex.encode("Ab"),Eq("A100"));
}
