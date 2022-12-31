#include <codec/decoder.hpp>
#include <gtest/gtest.h>

class ut_decoder : public testing::Test
{
};

TEST_F(ut_decoder, decode_test_dump_from_hardware)
{
    const std::vector<std::uint8_t> dump =
        {0xf0, 0x00, 0x20, 0x29, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
         0x42, 0x00, 0x00, 0x4b, 0x53, 0x78, 0x02, 0x00, 0x03, 0x20, 0x0f, 0x6f, 0x77, 0x78, 0x01, 0x00,
         0x43, 0x40, 0x20, 0x00, 0x03, 0x7f, 0x7f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x79, 0x36,
         0x0a, 0x36, 0x00, 0x0f, 0x77, 0x7a, 0x70, 0x00, 0x73, 0x00, 0x17, 0x03, 0x05, 0x30, 0x00, 0x00,
         0x59, 0x00, 0x11, 0x20, 0x00, 0x00, 0x00, 0x60, 0x00, 0x13, 0x00, 0x00, 0x20, 0x20, 0x08, 0x0a,
         0x1f, 0x19, 0x10, 0x09, 0x14, 0x02, 0x01, 0x00, 0x46, 0x20, 0x1f, 0x6f, 0x78, 0x02, 0x39, 0x26,
         0x40, 0x3f, 0x50, 0x08, 0x04, 0x01, 0x7c, 0x7e, 0x40, 0x34, 0x40, 0x00, 0x00, 0x03, 0x10, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};

    auto result = sysex_decoder::decode(dump);
    EXPECT_EQ(0, result[sysex_decoder::param::PatchNumber]);
    EXPECT_EQ(0, result[sysex_decoder::param::PortamentoTime]);
    EXPECT_EQ(66, result[sysex_decoder::param::OscPitchBendRange]);
    EXPECT_EQ(0, result[sysex_decoder::param::OscSync]);
    EXPECT_EQ(2, result[sysex_decoder::param::Osc1Waveform]);
    EXPECT_EQ(93, result[sysex_decoder::param::Osc1ManualPW]);
    EXPECT_EQ(63, result[sysex_decoder::param::Osc1Range]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1Coarse]);
    EXPECT_EQ(128, result[sysex_decoder::param::Osc1Fine]);
    EXPECT_EQ(3, result[sysex_decoder::param::Osc2Waveform]);
    EXPECT_EQ(64, result[sysex_decoder::param::Osc2ManualPW]);
    EXPECT_EQ(63, result[sysex_decoder::param::Osc2Range]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2Coarse]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2Fine]);
    EXPECT_EQ(0, result[sysex_decoder::param::SubOscWave]);
    EXPECT_EQ(1, result[sysex_decoder::param::SubOscOct]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerOsc1Level]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerOsc2Level]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerSubOscLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerNoiseLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerRingModLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerExtLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterFrequency]);
    EXPECT_EQ(62, result[sysex_decoder::param::FilterResonance]);
    EXPECT_EQ(91, result[sysex_decoder::param::FilterOverdrive]);
    EXPECT_EQ(1, result[sysex_decoder::param::FilterSlope]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterType]);
    EXPECT_EQ(2, result[sysex_decoder::param::FilterShape]);
    EXPECT_EQ(108, result[sysex_decoder::param::VelocityAmpEnv]);
    EXPECT_EQ(0, result[sysex_decoder::param::AmpEnvAttack]);
    EXPECT_EQ(127, result[sysex_decoder::param::AmpEnvDecay]);
    EXPECT_EQ(127, result[sysex_decoder::param::AmpEnvSustain]);
    EXPECT_EQ(92, result[sysex_decoder::param::AmpEnvRelease]);
    EXPECT_EQ(0, result[sysex_decoder::param::AmpEnvTriggering]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModEnvAttack]);
    EXPECT_EQ(92, result[sysex_decoder::param::ModEnvDecay]);
    EXPECT_EQ(24, result[sysex_decoder::param::ModEnvSustain]);
    EXPECT_EQ(80, result[sysex_decoder::param::ModEnvRelease]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModEnvTriggering]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1Wave]);
    EXPECT_EQ(89, result[sysex_decoder::param::LFO1Delay]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1Slew]);
    EXPECT_EQ(69, result[sysex_decoder::param::LFO1Speed]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1SyncValue]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1SpeedSync]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1KeySync]);
    EXPECT_EQ(48, result[sysex_decoder::param::LFO2Delay]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2Wave]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2Slew]);
    EXPECT_EQ(38, result[sysex_decoder::param::LFO2Speed]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2SyncValue]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2SpeedSync]);
    EXPECT_EQ(1, result[sysex_decoder::param::LFO2KeySync]);
    EXPECT_EQ(0, result[sysex_decoder::param::ArpOn]);
    EXPECT_EQ(1, result[sysex_decoder::param::ArpSeqRetrig]);
    EXPECT_EQ(2, result[sysex_decoder::param::ArpOctaves]);
    EXPECT_EQ(5, result[sysex_decoder::param::ArpNoteMode]);
    EXPECT_EQ(31, result[sysex_decoder::param::ArpRhythm]);
    EXPECT_EQ(50, result[sysex_decoder::param::ArpSwing]);
    EXPECT_EQ(64, result[sysex_decoder::param::ModWheelFilterFreq]);
    EXPECT_EQ(73, result[sysex_decoder::param::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(64, result[sysex_decoder::param::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(64, result[sysex_decoder::param::ModWheelOsc2Pitch]);
    EXPECT_EQ(64, result[sysex_decoder::param::AftertouchFilterFreq]);
    EXPECT_EQ(70, result[sysex_decoder::param::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(64, result[sysex_decoder::param::AftertouchLFO2Speed]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc1LFO1Depth]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2LFO1Depth]);
    EXPECT_EQ(78, result[sysex_decoder::param::Osc1LFO2PWMod]);
    EXPECT_EQ(83, result[sysex_decoder::param::Osc2LFO2PWMod]);
    EXPECT_EQ(127, result[sysex_decoder::param::FilterLFO2Depth]);
    EXPECT_EQ(64, result[sysex_decoder::param::Osc1ModEnvDepth]);
    EXPECT_EQ(64, result[sysex_decoder::param::Osc2ModEnvDepth]);
    EXPECT_EQ(63, result[sysex_decoder::param::Osc1ModEnvPWMod]);
    EXPECT_EQ(63, result[sysex_decoder::param::Osc2ModEnvPWMod]);
    EXPECT_EQ(105, result[sysex_decoder::param::FilterModEnvDepth]);
    EXPECT_EQ(0, result[sysex_decoder::param::FxOscFilterMod]);
    EXPECT_EQ(0, result[sysex_decoder::param::FxDistortion]);
    EXPECT_EQ(0, result[sysex_decoder::param::VCALimiter]);
}

TEST_F(ut_decoder, decode_test_min_values)
{
    const std::vector<std::uint8_t> dump =
        {0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7};

    auto result = sysex_decoder::decode(dump);
    EXPECT_EQ(0, result[sysex_decoder::param::PatchNumber]);
    EXPECT_EQ(0, result[sysex_decoder::param::PortamentoTime]);
    EXPECT_EQ(0, result[sysex_decoder::param::OscPitchBendRange]);
    EXPECT_EQ(0, result[sysex_decoder::param::OscSync]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1Waveform]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1ManualPW]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1Range]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1Coarse]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1Fine]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2Waveform]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2ManualPW]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2Range]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2Coarse]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2Fine]);
    EXPECT_EQ(0, result[sysex_decoder::param::SubOscWave]);
    EXPECT_EQ(0, result[sysex_decoder::param::SubOscOct]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerOsc1Level]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerOsc2Level]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerSubOscLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerNoiseLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerRingModLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::MixerExtLevel]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterFrequency]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterResonance]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterOverdrive]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterSlope]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterType]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterShape]);
    EXPECT_EQ(0, result[sysex_decoder::param::VelocityAmpEnv]);
    EXPECT_EQ(0, result[sysex_decoder::param::AmpEnvAttack]);
    EXPECT_EQ(0, result[sysex_decoder::param::AmpEnvDecay]);
    EXPECT_EQ(0, result[sysex_decoder::param::AmpEnvSustain]);
    EXPECT_EQ(0, result[sysex_decoder::param::AmpEnvRelease]);
    EXPECT_EQ(0, result[sysex_decoder::param::AmpEnvTriggering]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModEnvAttack]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModEnvDecay]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModEnvSustain]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModEnvRelease]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModEnvTriggering]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1Wave]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1Delay]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1Slew]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1Speed]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1SyncValue]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1SpeedSync]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO1KeySync]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2Delay]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2Wave]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2Slew]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2Speed]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2SyncValue]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2SpeedSync]);
    EXPECT_EQ(0, result[sysex_decoder::param::LFO2KeySync]);
    EXPECT_EQ(0, result[sysex_decoder::param::ArpOn]);
    EXPECT_EQ(0, result[sysex_decoder::param::ArpSeqRetrig]);
    EXPECT_EQ(0, result[sysex_decoder::param::ArpOctaves]);
    EXPECT_EQ(0, result[sysex_decoder::param::ArpNoteMode]);
    EXPECT_EQ(0, result[sysex_decoder::param::ArpRhythm]);
    EXPECT_EQ(0, result[sysex_decoder::param::ArpSwing]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModWheelFilterFreq]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(0, result[sysex_decoder::param::ModWheelOsc2Pitch]);
    EXPECT_EQ(0, result[sysex_decoder::param::AftertouchFilterFreq]);
    EXPECT_EQ(0, result[sysex_decoder::param::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(0, result[sysex_decoder::param::AftertouchLFO2Speed]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1LFO1Depth]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2LFO1Depth]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1LFO2PWMod]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2LFO2PWMod]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterLFO2Depth]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1ModEnvDepth]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2ModEnvDepth]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc1ModEnvPWMod]);
    EXPECT_EQ(0, result[sysex_decoder::param::Osc2ModEnvPWMod]);
    EXPECT_EQ(0, result[sysex_decoder::param::FilterModEnvDepth]);
    EXPECT_EQ(0, result[sysex_decoder::param::FxOscFilterMod]);
    EXPECT_EQ(0, result[sysex_decoder::param::FxDistortion]);
    EXPECT_EQ(0, result[sysex_decoder::param::VCALimiter]);
}

TEST_F(ut_decoder, decode_test_max_values)
{
    const std::vector<std::uint8_t> dump =
        {0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7};

    auto result = sysex_decoder::decode(dump);
    EXPECT_EQ(127, result[sysex_decoder::param::PatchNumber]);
    EXPECT_EQ(127, result[sysex_decoder::param::PortamentoTime]);
    EXPECT_EQ(127, result[sysex_decoder::param::OscPitchBendRange]);
    EXPECT_EQ(1, result[sysex_decoder::param::OscSync]);
    EXPECT_EQ(3, result[sysex_decoder::param::Osc1Waveform]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc1ManualPW]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc1Range]);
    EXPECT_EQ(255, result[sysex_decoder::param::Osc1Coarse]);
    EXPECT_EQ(255, result[sysex_decoder::param::Osc1Fine]);
    EXPECT_EQ(3, result[sysex_decoder::param::Osc2Waveform]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2ManualPW]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2Range]);
    EXPECT_EQ(255, result[sysex_decoder::param::Osc2Coarse]);
    EXPECT_EQ(255, result[sysex_decoder::param::Osc2Fine]);
    EXPECT_EQ(3, result[sysex_decoder::param::SubOscWave]);
    EXPECT_EQ(1, result[sysex_decoder::param::SubOscOct]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerOsc1Level]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerOsc2Level]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerSubOscLevel]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerNoiseLevel]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerRingModLevel]);
    EXPECT_EQ(255, result[sysex_decoder::param::MixerExtLevel]);
    EXPECT_EQ(255, result[sysex_decoder::param::FilterFrequency]);
    EXPECT_EQ(127, result[sysex_decoder::param::FilterResonance]);
    EXPECT_EQ(127, result[sysex_decoder::param::FilterOverdrive]);
    EXPECT_EQ(1, result[sysex_decoder::param::FilterSlope]);
    EXPECT_EQ(1, result[sysex_decoder::param::FilterType]);
    EXPECT_EQ(3, result[sysex_decoder::param::FilterShape]);
    EXPECT_EQ(127, result[sysex_decoder::param::VelocityAmpEnv]);
    EXPECT_EQ(127, result[sysex_decoder::param::AmpEnvAttack]);
    EXPECT_EQ(127, result[sysex_decoder::param::AmpEnvDecay]);
    EXPECT_EQ(127, result[sysex_decoder::param::AmpEnvSustain]);
    EXPECT_EQ(127, result[sysex_decoder::param::AmpEnvRelease]);
    EXPECT_EQ(3, result[sysex_decoder::param::AmpEnvTriggering]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModEnvAttack]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModEnvDecay]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModEnvSustain]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModEnvRelease]);
    EXPECT_EQ(3, result[sysex_decoder::param::ModEnvTriggering]);
    EXPECT_EQ(3, result[sysex_decoder::param::LFO1Wave]);
    EXPECT_EQ(127, result[sysex_decoder::param::LFO1Delay]);
    EXPECT_EQ(127, result[sysex_decoder::param::LFO1Slew]);
    EXPECT_EQ(255, result[sysex_decoder::param::LFO1Speed]);
    EXPECT_EQ(63, result[sysex_decoder::param::LFO1SyncValue]);
    EXPECT_EQ(1, result[sysex_decoder::param::LFO1SpeedSync]);
    EXPECT_EQ(1, result[sysex_decoder::param::LFO1KeySync]);
    EXPECT_EQ(127, result[sysex_decoder::param::LFO2Delay]);
    EXPECT_EQ(3, result[sysex_decoder::param::LFO2Wave]);
    EXPECT_EQ(127, result[sysex_decoder::param::LFO2Slew]);
    EXPECT_EQ(255, result[sysex_decoder::param::LFO2Speed]);
    EXPECT_EQ(63, result[sysex_decoder::param::LFO2SyncValue]);
    EXPECT_EQ(1, result[sysex_decoder::param::LFO2SpeedSync]);
    EXPECT_EQ(1, result[sysex_decoder::param::LFO2KeySync]);
    EXPECT_EQ(1, result[sysex_decoder::param::ArpOn]);
    EXPECT_EQ(1, result[sysex_decoder::param::ArpSeqRetrig]);
    EXPECT_EQ(7, result[sysex_decoder::param::ArpOctaves]);
    EXPECT_EQ(7, result[sysex_decoder::param::ArpNoteMode]);
    EXPECT_EQ(31, result[sysex_decoder::param::ArpRhythm]);
    EXPECT_EQ(127, result[sysex_decoder::param::ArpSwing]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModWheelFilterFreq]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(127, result[sysex_decoder::param::ModWheelOsc2Pitch]);
    EXPECT_EQ(127, result[sysex_decoder::param::AftertouchFilterFreq]);
    EXPECT_EQ(127, result[sysex_decoder::param::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(127, result[sysex_decoder::param::AftertouchLFO2Speed]);
    EXPECT_EQ(255, result[sysex_decoder::param::Osc1LFO1Depth]);
    EXPECT_EQ(255, result[sysex_decoder::param::Osc2LFO1Depth]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc1LFO2PWMod]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2LFO2PWMod]);
    EXPECT_EQ(255, result[sysex_decoder::param::FilterLFO2Depth]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc1ModEnvDepth]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2ModEnvDepth]);
    EXPECT_EQ(63, result[sysex_decoder::param::Osc1ModEnvPWMod]);
    EXPECT_EQ(127, result[sysex_decoder::param::Osc2ModEnvPWMod]);
    EXPECT_EQ(127, result[sysex_decoder::param::FilterModEnvDepth]);
    EXPECT_EQ(127, result[sysex_decoder::param::FxOscFilterMod]);
    EXPECT_EQ(127, result[sysex_decoder::param::FxDistortion]);
    EXPECT_EQ(127, result[sysex_decoder::param::VCALimiter]);
}
/*
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
*/
