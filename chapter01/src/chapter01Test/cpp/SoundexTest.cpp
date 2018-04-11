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

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    ASSERT_THAT(soundex.encode("Ab"),Eq("A100"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics)
{
    ASSERT_THAT(soundex.encode("A#"),Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithAppropriateDigits)
{
    ASSERT_THAT(soundex.encode("Acdl"),Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharcters)
{
    ASSERT_THAT(soundex.encode("Dcdlb").length(),Eq(4u));
}

TEST_F(SoundexEncoding, IgnoreVowelLikeLetters)
{
    ASSERT_THAT(soundex.encode("Baeiouhycdl"),Eq("B234"));
    ASSERT_THAT(soundex.encode("BAaEeIOioUuhycdl"),Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicatedEncodings)
{
    ASSERT_THAT(soundex.encode("Abfcgdt"),Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter)
{
    ASSERT_THAT(soundex.encode("abcd"),StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants)
{
    ASSERT_THAT(soundex.encode("BCDL"),Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicates1st)
{
    ASSERT_THAT(soundex.encode("Bbcd"),Eq("B230"));
}
