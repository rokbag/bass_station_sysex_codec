#include <gtest/gtest.h>
#include "codec/decoder.h"


class ut_decoder : public testing::Test
{
protected:

    decoder uut;
};

TEST_F(ut_decoder, decode_test)
{

    auto result = uut.decode();
    EXPECT_EQ(0, result);
}
