#include <gtest/gtest.h>
#include "codec/decoder.h"

namespace sysex_decoder {

class ut_decoder : public decoder, public testing::Test
{
};


TEST_F(ut_decoder, decode_test_example_patch)
{
    const data_t dump = {0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x4b, 0x53, 0x78, 0x02, 0x00,
                         0x03, 0x20, 0x0f, 0x6f, 0x77, 0x78, 0x01, 0x00, 0x43, 0x40, 0x20, 0x00,
                         0x03, 0x7f, 0x7f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x55, 0x36,
                         0x08, 0x36, 0x00, 0x0f, 0x77, 0x7a, 0x70, 0x00, 0x73, 0x00, 0x17, 0x03,
                         0x05, 0x30, 0x00, 0x00, 0x59, 0x00, 0x11, 0x20, 0x00, 0x00, 0x00, 0x60,
                         0x00, 0x13, 0x00, 0x00, 0x20, 0x20, 0x08, 0x0a, 0x1f, 0x19, 0x10, 0x09,
                         0x14, 0x02, 0x01, 0x00, 0x46, 0x20, 0x1f, 0x6f, 0x78, 0x02, 0x39, 0x26,
                         0x40, 0x3f, 0x50, 0x08, 0x04, 0x01, 0x7c, 0x7e, 0x40, 0x34, 0x40, 0x00,
                         0x00, 0x03, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};

    auto result = decode(dump);
    EXPECT_EQ(  0, result[EParam::PatchNumber]);
    EXPECT_EQ(  0, result[EParam::PortamentoTime]);
    EXPECT_EQ( 66, result[EParam::OscPitchBendRange]);
    EXPECT_EQ(  0, result[EParam::OscSync]);
    EXPECT_EQ(  2, result[EParam::Osc1Waveform]);
    EXPECT_EQ( 93, result[EParam::Osc1ManualPW]);
    EXPECT_EQ( 63, result[EParam::Osc1Range]);
    EXPECT_EQ(  0, result[EParam::Osc1Coarse]);
    EXPECT_EQ(128, result[EParam::Osc1Fine]);
    EXPECT_EQ(  3, result[EParam::Osc2Waveform]);
    EXPECT_EQ( 64, result[EParam::Osc2ManualPW]);
    EXPECT_EQ( 63, result[EParam::Osc2Range]);
    EXPECT_EQ(127, result[EParam::Osc2Coarse]);
    EXPECT_EQ(127, result[EParam::Osc2Fine]);
    EXPECT_EQ(  0, result[EParam::SubOscWave]);
    EXPECT_EQ(  1, result[EParam::SubOscOct]);
    EXPECT_EQ(255, result[EParam::MixerOsc1Level]);
    EXPECT_EQ(255, result[EParam::MixerOsc2Level]);
    EXPECT_EQ(  0, result[EParam::MixerSubOscLevel]);
    EXPECT_EQ(  0, result[EParam::MixerNoiseLevel]);
    EXPECT_EQ(  0, result[EParam::MixerRingModLevel]);
    EXPECT_EQ(  0, result[EParam::MixerExtLevel]);
    EXPECT_EQ(  6, result[EParam::FilterFrequency]);
    EXPECT_EQ( 85, result[EParam::FilterResonance]);
    EXPECT_EQ( 91, result[EParam::FilterOverdrive]);
    EXPECT_EQ(  1, result[EParam::FilterSlope]);
    EXPECT_EQ(  0, result[EParam::FilterType]);
    EXPECT_EQ(108, result[EParam::VelocityAmpEnv]);
    EXPECT_EQ(  0, result[EParam::AmpEnvAttack]);
    EXPECT_EQ(127, result[EParam::AmpEnvDecay]);
    EXPECT_EQ(127, result[EParam::AmpEnvSustain]);
    EXPECT_EQ( 92, result[EParam::AmpEnvRelease]);
    EXPECT_EQ(  0, result[EParam::AmpEnvTriggering]);
    EXPECT_EQ(  0, result[EParam::ModEnvAttack]);
    EXPECT_EQ( 92, result[EParam::ModEnvDecay]);
    EXPECT_EQ( 24, result[EParam::ModEnvSustain]);
    EXPECT_EQ( 80, result[EParam::ModEnvRelease]);
    EXPECT_EQ(  0, result[EParam::ModEnvTriggering]);
    EXPECT_EQ(  0, result[EParam::LFO1Wave]);
    EXPECT_EQ( 89, result[EParam::LFO1Delay]);
    EXPECT_EQ(  0, result[EParam::LFO1Slew]);
    EXPECT_EQ( 69, result[EParam::LFO1Speed]);
    EXPECT_EQ(  0, result[EParam::LFO1SyncValue]);
    EXPECT_EQ(  0, result[EParam::LFO1SpeedSync]);
    EXPECT_EQ(  0, result[EParam::LFO1KeySync]);
    EXPECT_EQ( 48, result[EParam::LFO2Delay]);
    EXPECT_EQ(  0, result[EParam::LFO2Wave]);
    EXPECT_EQ(  0, result[EParam::LFO2Slew]);
    EXPECT_EQ( 38, result[EParam::LFO2Speed]);
    EXPECT_EQ(  0, result[EParam::LFO2SyncValue]);
    EXPECT_EQ(  0, result[EParam::LFO2SpeedSync]);
    EXPECT_EQ(  1, result[EParam::LFO2KeySync]);
    EXPECT_EQ(  0, result[EParam::ArpOn]);
    EXPECT_EQ(  1, result[EParam::ArpSeqRetrig]);
    EXPECT_EQ(  2, result[EParam::ArpOctaves]);
    EXPECT_EQ(  5, result[EParam::ArpNoteMode]);
    EXPECT_EQ( 31, result[EParam::ArpRhythm]);
    EXPECT_EQ( 50, result[EParam::ArpSwing]);
    EXPECT_EQ( 64, result[EParam::ModWheelFilterFreq]);
    EXPECT_EQ( 73, result[EParam::ModWheelLFO1toOscPitch]);
    EXPECT_EQ( 64, result[EParam::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ( 64, result[EParam::ModWheelOsc2Pitch]);
    EXPECT_EQ( 64, result[EParam::AftertouchFilterFreq]);
    EXPECT_EQ( 70, result[EParam::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ( 64, result[EParam::AftertouchLFO2Speed]);
    EXPECT_EQ(127, result[EParam::Osc1LFO1Depth]);
    EXPECT_EQ(127, result[EParam::Osc2LFO1Depth]);
    EXPECT_EQ( 78, result[EParam::Osc1LFO2PWMod]);
    EXPECT_EQ( 83, result[EParam::Osc2LFO2PWMod]);
    EXPECT_EQ(127, result[EParam::FilterLFO2Depth]);
    EXPECT_EQ( 64, result[EParam::Osc1ModEnvDepth]);
    EXPECT_EQ( 64, result[EParam::Osc2ModEnvDepth]);
    EXPECT_EQ( 63, result[EParam::Osc1ModEnvPWMod]);
    EXPECT_EQ( 63, result[EParam::Osc2ModEnvPWMod]);
    EXPECT_EQ(105, result[EParam::FilterModEnvDepth]);
    EXPECT_EQ(  0, result[EParam::FxOscFilterMod]);
    EXPECT_EQ(  0, result[EParam::FxDistortion]);
    EXPECT_EQ(  0, result[EParam::VCALimiter]);
}

TEST_F(ut_decoder, decode_test_min_values)
{
    const data_t dump = {0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};

    auto result = decode(dump);
    EXPECT_EQ(0, result[EParam::PatchNumber]);
    EXPECT_EQ(0, result[EParam::PortamentoTime]);
    EXPECT_EQ(0, result[EParam::OscPitchBendRange]);
    EXPECT_EQ(0, result[EParam::OscSync]);
    EXPECT_EQ(0, result[EParam::Osc1Waveform]);
    EXPECT_EQ(0, result[EParam::Osc1ManualPW]);
    EXPECT_EQ(0, result[EParam::Osc1Range]);
    EXPECT_EQ(0, result[EParam::Osc1Coarse]);
    EXPECT_EQ(0, result[EParam::Osc1Fine]);
    EXPECT_EQ(0, result[EParam::Osc2Waveform]);
    EXPECT_EQ(0, result[EParam::Osc2ManualPW]);
    EXPECT_EQ(0, result[EParam::Osc2Range]);
    EXPECT_EQ(0, result[EParam::Osc2Coarse]);
    EXPECT_EQ(0, result[EParam::Osc2Fine]);
    EXPECT_EQ(0, result[EParam::SubOscWave]);
    EXPECT_EQ(0, result[EParam::SubOscOct]);
    EXPECT_EQ(0, result[EParam::MixerOsc1Level]);
    EXPECT_EQ(0, result[EParam::MixerOsc2Level]);
    EXPECT_EQ(0, result[EParam::MixerSubOscLevel]);
    EXPECT_EQ(0, result[EParam::MixerNoiseLevel]);
    EXPECT_EQ(0, result[EParam::MixerRingModLevel]);
    EXPECT_EQ(0, result[EParam::MixerExtLevel]);
    EXPECT_EQ(0, result[EParam::FilterFrequency]);
    EXPECT_EQ(0, result[EParam::FilterResonance]);
    EXPECT_EQ(0, result[EParam::FilterOverdrive]);
    EXPECT_EQ(0, result[EParam::FilterSlope]);
    EXPECT_EQ(0, result[EParam::FilterType]);
    EXPECT_EQ(0, result[EParam::VelocityAmpEnv]);
    EXPECT_EQ(0, result[EParam::AmpEnvAttack]);
    EXPECT_EQ(0, result[EParam::AmpEnvDecay]);
    EXPECT_EQ(0, result[EParam::AmpEnvSustain]);
    EXPECT_EQ(0, result[EParam::AmpEnvRelease]);
    EXPECT_EQ(0, result[EParam::AmpEnvTriggering]);
    EXPECT_EQ(0, result[EParam::ModEnvAttack]);
    EXPECT_EQ(0, result[EParam::ModEnvDecay]);
    EXPECT_EQ(0, result[EParam::ModEnvSustain]);
    EXPECT_EQ(0, result[EParam::ModEnvRelease]);
    EXPECT_EQ(0, result[EParam::ModEnvTriggering]);
    EXPECT_EQ(0, result[EParam::LFO1Wave]);
    EXPECT_EQ(0, result[EParam::LFO1Delay]);
    EXPECT_EQ(0, result[EParam::LFO1Slew]);
    EXPECT_EQ(0, result[EParam::LFO1Speed]);
    EXPECT_EQ(0, result[EParam::LFO1SyncValue]);
    EXPECT_EQ(0, result[EParam::LFO1SpeedSync]);
    EXPECT_EQ(0, result[EParam::LFO1KeySync]);
    EXPECT_EQ(0, result[EParam::LFO2Delay]);
    EXPECT_EQ(0, result[EParam::LFO2Wave]);
    EXPECT_EQ(0, result[EParam::LFO2Slew]);
    EXPECT_EQ(0, result[EParam::LFO2Speed]);
    EXPECT_EQ(0, result[EParam::LFO2SyncValue]);
    EXPECT_EQ(0, result[EParam::LFO2SpeedSync]);
    EXPECT_EQ(0, result[EParam::LFO2KeySync]);
    EXPECT_EQ(0, result[EParam::ArpOn]);
    EXPECT_EQ(0, result[EParam::ArpSeqRetrig]);
    EXPECT_EQ(0, result[EParam::ArpOctaves]);
    EXPECT_EQ(0, result[EParam::ArpNoteMode]);
    EXPECT_EQ(0, result[EParam::ArpRhythm]);
    EXPECT_EQ(0, result[EParam::ArpSwing]);
    EXPECT_EQ(0, result[EParam::ModWheelFilterFreq]);
    EXPECT_EQ(0, result[EParam::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(0, result[EParam::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(0, result[EParam::ModWheelOsc2Pitch]);
    EXPECT_EQ(0, result[EParam::AftertouchFilterFreq]);
    EXPECT_EQ(0, result[EParam::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(0, result[EParam::AftertouchLFO2Speed]);
    EXPECT_EQ(0, result[EParam::Osc1LFO1Depth]);
    EXPECT_EQ(0, result[EParam::Osc2LFO1Depth]);
    EXPECT_EQ(0, result[EParam::Osc1LFO2PWMod]);
    EXPECT_EQ(0, result[EParam::Osc2LFO2PWMod]);
    EXPECT_EQ(0, result[EParam::FilterLFO2Depth]);
    EXPECT_EQ(0, result[EParam::Osc1ModEnvDepth]);
    EXPECT_EQ(0, result[EParam::Osc2ModEnvDepth]);
    EXPECT_EQ(0, result[EParam::Osc1ModEnvPWMod]);
    EXPECT_EQ(0, result[EParam::Osc2ModEnvPWMod]);
    EXPECT_EQ(0, result[EParam::FilterModEnvDepth]);
    EXPECT_EQ(0, result[EParam::FxOscFilterMod]);
    EXPECT_EQ(0, result[EParam::FxDistortion]);
    EXPECT_EQ(0, result[EParam::VCALimiter]);
}

TEST_F(ut_decoder, decode_test_max_values)
{
    const data_t dump = {0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7};

    auto result = decode(dump);
    EXPECT_EQ(127, result[EParam::PatchNumber]);
    EXPECT_EQ(127, result[EParam::PortamentoTime]);
    EXPECT_EQ(127, result[EParam::OscPitchBendRange]);
    EXPECT_EQ(  1, result[EParam::OscSync]);
    EXPECT_EQ(  3, result[EParam::Osc1Waveform]);
    EXPECT_EQ(127, result[EParam::Osc1ManualPW]);
    EXPECT_EQ(127, result[EParam::Osc1Range]);
    EXPECT_EQ(255, result[EParam::Osc1Coarse]);
    EXPECT_EQ(255, result[EParam::Osc1Fine]);
    EXPECT_EQ(  3, result[EParam::Osc2Waveform]);
    EXPECT_EQ(127, result[EParam::Osc2ManualPW]);
    EXPECT_EQ(127, result[EParam::Osc2Range]);
    EXPECT_EQ(255, result[EParam::Osc2Coarse]);
    EXPECT_EQ(255, result[EParam::Osc2Fine]);
    EXPECT_EQ(  3, result[EParam::SubOscWave]);
    EXPECT_EQ(  1, result[EParam::SubOscOct]);
    EXPECT_EQ(255, result[EParam::MixerOsc1Level]);
    EXPECT_EQ(255, result[EParam::MixerOsc2Level]);
    EXPECT_EQ(255, result[EParam::MixerSubOscLevel]);
    EXPECT_EQ(255, result[EParam::MixerNoiseLevel]);
    EXPECT_EQ(255, result[EParam::MixerRingModLevel]);
    EXPECT_EQ(255, result[EParam::MixerExtLevel]);
    EXPECT_EQ(255, result[EParam::FilterFrequency]);
    EXPECT_EQ(127, result[EParam::FilterResonance]);
    EXPECT_EQ(127, result[EParam::FilterOverdrive]);
    EXPECT_EQ(  1, result[EParam::FilterSlope]);
    EXPECT_EQ(  1, result[EParam::FilterType]);
    EXPECT_EQ(127, result[EParam::VelocityAmpEnv]);
    EXPECT_EQ(127, result[EParam::AmpEnvAttack]);
    EXPECT_EQ(127, result[EParam::AmpEnvDecay]);
    EXPECT_EQ(127, result[EParam::AmpEnvSustain]);
    EXPECT_EQ(127, result[EParam::AmpEnvRelease]);
    EXPECT_EQ(  3, result[EParam::AmpEnvTriggering]);
    EXPECT_EQ(127, result[EParam::ModEnvAttack]);
    EXPECT_EQ(127, result[EParam::ModEnvDecay]);
    EXPECT_EQ(127, result[EParam::ModEnvSustain]);
    EXPECT_EQ(127, result[EParam::ModEnvRelease]);
    EXPECT_EQ(  3, result[EParam::ModEnvTriggering]);
    EXPECT_EQ(  3, result[EParam::LFO1Wave]);
    EXPECT_EQ(127, result[EParam::LFO1Delay]);
    EXPECT_EQ(127, result[EParam::LFO1Slew]);
    EXPECT_EQ(255, result[EParam::LFO1Speed]);
    EXPECT_EQ( 63, result[EParam::LFO1SyncValue]);
    EXPECT_EQ(  1, result[EParam::LFO1SpeedSync]);
    EXPECT_EQ(  1, result[EParam::LFO1KeySync]);
    EXPECT_EQ(127, result[EParam::LFO2Delay]);
    EXPECT_EQ(  3, result[EParam::LFO2Wave]);
    EXPECT_EQ(127, result[EParam::LFO2Slew]);
    EXPECT_EQ(255, result[EParam::LFO2Speed]);
    EXPECT_EQ( 63, result[EParam::LFO2SyncValue]);
    EXPECT_EQ(  1, result[EParam::LFO2SpeedSync]);
    EXPECT_EQ(  1, result[EParam::LFO2KeySync]);
    EXPECT_EQ(  1, result[EParam::ArpOn]);
    EXPECT_EQ(  1, result[EParam::ArpSeqRetrig]);
    EXPECT_EQ(  7, result[EParam::ArpOctaves]);
    EXPECT_EQ(  7, result[EParam::ArpNoteMode]);
    EXPECT_EQ( 31, result[EParam::ArpRhythm]);
    EXPECT_EQ(127, result[EParam::ArpSwing]);
    EXPECT_EQ(127, result[EParam::ModWheelFilterFreq]);
    EXPECT_EQ(127, result[EParam::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(127, result[EParam::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(127, result[EParam::ModWheelOsc2Pitch]);
    EXPECT_EQ(127, result[EParam::AftertouchFilterFreq]);
    EXPECT_EQ(127, result[EParam::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(127, result[EParam::AftertouchLFO2Speed]);
    EXPECT_EQ(255, result[EParam::Osc1LFO1Depth]);
    EXPECT_EQ(255, result[EParam::Osc2LFO1Depth]);
    EXPECT_EQ(127, result[EParam::Osc1LFO2PWMod]);
    EXPECT_EQ(127, result[EParam::Osc2LFO2PWMod]);
    EXPECT_EQ(255, result[EParam::FilterLFO2Depth]);
    EXPECT_EQ(127, result[EParam::Osc1ModEnvDepth]);
    EXPECT_EQ(127, result[EParam::Osc2ModEnvDepth]);
    EXPECT_EQ( 63, result[EParam::Osc1ModEnvPWMod]);
    EXPECT_EQ(127, result[EParam::Osc2ModEnvPWMod]);
    EXPECT_EQ(127, result[EParam::FilterModEnvDepth]);
    EXPECT_EQ(127, result[EParam::FxOscFilterMod]);
    EXPECT_EQ(127, result[EParam::FxDistortion]);
    EXPECT_EQ(127, result[EParam::VCALimiter]);
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


TEST_F(ut_decoder, mixer_osc1_level)
{
    auto result = mixer_osc1_level(0, 0);
    EXPECT_EQ(0, result);
    result = mixer_osc1_level(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, mixer_osc2_level)
{
    auto result = mixer_osc2_level(0, 0);
    EXPECT_EQ(0, result);
    result = mixer_osc2_level(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, mixer_sub_osc_level)
{
    auto result = mixer_sub_osc_level(0, 0);
    EXPECT_EQ(0, result);
    result = mixer_sub_osc_level(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, mixer_noise_level)
{
    auto result = mixer_noise_level(0, 0);
    EXPECT_EQ(0, result);
    result = mixer_noise_level(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, mixer_rm_level)
{
    auto result = mixer_rm_level(0, 0);
    EXPECT_EQ(0, result);
    result = mixer_rm_level(255, 255);
    EXPECT_EQ(255, result);
}

TEST_F(ut_decoder, mixer_ext_level)
{
    auto result = mixer_ext_level(0, 0);
    EXPECT_EQ(0, result);
    result = mixer_ext_level(255, 255);
    EXPECT_EQ(255, result);
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

TEST_F(ut_decoder, filter_slope)
{
    auto result = filter_slope(0);
    EXPECT_EQ(0, result);
    result = filter_slope(255);
    EXPECT_EQ(1, result);
}

TEST_F(ut_decoder, filter_type)
{
    auto result = filter_type(0);
    EXPECT_EQ(0, result);
    result = filter_type(255);
    EXPECT_EQ(1, result);
}


TEST_F(ut_decoder, velocity_amp_env)
{
    auto result = velocity_amp_env(0, 0);
    EXPECT_EQ(0, result);
    result = velocity_amp_env(255, 255);
    EXPECT_EQ(127, result);
}

}
