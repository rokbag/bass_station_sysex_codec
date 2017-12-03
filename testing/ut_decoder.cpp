#include <gtest/gtest.h>
#include "codec/decoder.h"


class ut_decoder : public decoder, public testing::Test
{
};


TEST_F(ut_decoder, decode_test)
{
    const data_t dump = {0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x4b, 0x53, 0x78, 0x02, 0x00, 0x03, 0x20, 0x0f, 0x6f, 0x77, 0x78, 0x01, 0x00, 0x43, 0x40, 0x20, 0x00, 0x03, 0x7f, 0x7f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x55, 0x36, 0x08, 0x36, 0x00, 0x0f, 0x77, 0x7a, 0x70, 0x00, 0x73, 0x00, 0x17, 0x03, 0x05, 0x30, 0x00, 0x00, 0x59, 0x00, 0x11, 0x20, 0x00, 0x00, 0x00, 0x60, 0x00, 0x13, 0x00, 0x00, 0x20, 0x20, 0x08, 0x0a, 0x1f, 0x19, 0x10, 0x09, 0x14, 0x02, 0x01, 0x00, 0x46, 0x20, 0x1f, 0x6f, 0x78, 0x02, 0x39, 0x26, 0x40, 0x3f, 0x50, 0x08, 0x04, 0x01, 0x7c, 0x7e, 0x40, 0x34, 0x40, 0x00, 0x00, 0x03, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};

    auto result = decode(dump, 0);
    EXPECT_EQ(6, result[EParam::FilterFrequency]);
}

TEST_F(ut_decoder, patch_number)
{
    auto result = patch_number(0);
    EXPECT_EQ(0, result);
    result = patch_number(255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, portamento_time)
{
    auto result = portamento_time(0, 0);
    EXPECT_EQ(0, result);
    result = portamento_time(255, 255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, osc_pitch_bend_range)
{
    auto result = osc_pitch_bend_range(0);
    EXPECT_EQ(0, result);
    result = osc_pitch_bend_range(255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, osc_sync)
{
    auto result = osc_sync(0);
    EXPECT_EQ(0, result);
    result = osc_sync(255);
    EXPECT_EQ(1, result);
}


TEST_F(ut_decoder, osc1_waveform)
{
    auto result = osc1_waveform(0);
    EXPECT_EQ(0, result);
    result = osc1_waveform(255);
    EXPECT_EQ(3, result);
}

TEST_F(ut_decoder, osc1_manual_pw)
{
    auto result = osc1_manual_pw(0, 0);
    EXPECT_EQ(0, result);
    result = osc1_manual_pw(255, 255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, osc1_range)
{
    auto result = osc1_range(0, 0);
    EXPECT_EQ(0, result);
    result = osc1_range(255, 255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, osc1_coarse)
{
    auto result = osc1_coarse(0, 0);
    EXPECT_EQ(0, result);
    result = osc1_coarse(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, osc1_fine)
{
    auto result = osc1_fine(0, 0);
    EXPECT_EQ(0, result);
    result = osc1_fine(255, 255);
    EXPECT_EQ(255, result);
}


TEST_F(ut_decoder, osc2_waveform)
{
    auto result = osc2_waveform(0);
    EXPECT_EQ(0, result);
    result = osc2_waveform(255);
    EXPECT_EQ(3, result);
}

TEST_F(ut_decoder, osc2_manual_pw)
{
    auto result = osc2_manual_pw(0, 0);
    EXPECT_EQ(0, result);
    result = osc2_manual_pw(255, 255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, osc2_range)
{
    auto result = osc2_range(0, 0);
    EXPECT_EQ(0, result);
    result = osc2_range(255, 255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, osc2_coarse)
{
    auto result = osc2_coarse(0, 0);
    EXPECT_EQ(0, result);
    result = osc2_coarse(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, osc2_fine)
{
    auto result = osc2_fine(0, 0);
    EXPECT_EQ(0, result);
    result = osc2_fine(255, 255);
    EXPECT_EQ(255, result);
}


TEST_F(ut_decoder, sub_osc_waveform)
{
    auto result = sub_osc_waveform(0);
    EXPECT_EQ(0, result);
    result = sub_osc_waveform(255);
    EXPECT_EQ(3, result);
}

TEST_F(ut_decoder, sub_osc_octave)
{
    auto result = sub_osc_octave(0);
    EXPECT_EQ(0, result);
    result = sub_osc_octave(255);
    EXPECT_EQ(1, result);
}


TEST_F(ut_decoder, filter_frequency)
{
    auto result = filter_frequency(0, 0);
    EXPECT_EQ(0, result);
    result = filter_frequency(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, filter_resonance)
{
    auto result = filter_resonance(0, 0);
    EXPECT_EQ(0, result);
    result = filter_resonance(255, 255);
    EXPECT_EQ(127, result);
}

TEST_F(ut_decoder, filter_overdrive)
{
    auto result = filter_overdrive(0, 0);
    EXPECT_EQ(0, result);
    result = filter_overdrive(255, 255);
    EXPECT_EQ(127, result);
}

