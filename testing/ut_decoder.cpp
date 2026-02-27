#include <bs2sysex/decoder.hpp>
#include <gtest/gtest.h>

class ut_decoder : public testing::Test
{
};

TEST_F(ut_decoder, decode_test_dump_from_hardware)
{
    const std::vector<std::uint8_t> dump = {
        0xf0, 0x00, 0x20, 0x29, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
        0x42, 0x00, 0x00, 0x4b, 0x53, 0x78, 0x02, 0x00, 0x03, 0x20, 0x0f, 0x6f, 0x77, 0x78, 0x01, 0x00,
        0x43, 0x40, 0x20, 0x00, 0x03, 0x7f, 0x7f, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x79, 0x36,
        0x0a, 0x36, 0x00, 0x0f, 0x77, 0x7a, 0x70, 0x00, 0x73, 0x00, 0x17, 0x03, 0x05, 0x30, 0x00, 0x00,
        0x59, 0x00, 0x11, 0x20, 0x00, 0x00, 0x00, 0x60, 0x00, 0x13, 0x00, 0x00, 0x20, 0x20, 0x08, 0x0a,
        0x1f, 0x19, 0x10, 0x09, 0x14, 0x02, 0x01, 0x00, 0x46, 0x20, 0x1f, 0x6f, 0x78, 0x02, 0x39, 0x26,
        0x40, 0x3f, 0x50, 0x08, 0x04, 0x01, 0x7c, 0x7e, 0x40, 0x34, 0x40, 0x00, 0x00, 0x03, 0x10, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x6e, 0x42, 0x20, 0x53, 0x68, 0x6f, 
        0x72, 0x74, 0x20, 0x42, 0x61, 0x73, 0x73, 0x20, 0x20, 0xf7};

    std::string patch_name = bs2sysex::decodePatchName(dump);
    EXPECT_EQ("DnB Short Bass ", patch_name);

    auto result = bs2sysex::decode(dump);
    EXPECT_EQ(0, result[bs2sysex::param::PatchNumber]);
    EXPECT_EQ(0, result[bs2sysex::param::PortamentoTime]);
    EXPECT_EQ(66, result[bs2sysex::param::OscPitchBendRange]);
    EXPECT_EQ(0, result[bs2sysex::param::OscSync]);
    EXPECT_EQ(2, result[bs2sysex::param::Osc1Waveform]);
    EXPECT_EQ(93, result[bs2sysex::param::Osc1ManualPW]);
    EXPECT_EQ(63, result[bs2sysex::param::Osc1Range]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1Coarse]);
    EXPECT_EQ(128, result[bs2sysex::param::Osc1Fine]);
    EXPECT_EQ(3, result[bs2sysex::param::Osc2Waveform]);
    EXPECT_EQ(64, result[bs2sysex::param::Osc2ManualPW]);
    EXPECT_EQ(63, result[bs2sysex::param::Osc2Range]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2Coarse]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2Fine]);
    EXPECT_EQ(0, result[bs2sysex::param::SubOscWave]);
    EXPECT_EQ(1, result[bs2sysex::param::SubOscOct]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerOsc1Level]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerOsc2Level]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerSubOscLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerNoiseLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerRingModLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerExtLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterFrequency]);
    EXPECT_EQ(62, result[bs2sysex::param::FilterResonance]);
    EXPECT_EQ(91, result[bs2sysex::param::FilterOverdrive]);
    EXPECT_EQ(1, result[bs2sysex::param::FilterSlope]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterType]);
    EXPECT_EQ(2, result[bs2sysex::param::FilterShape]);
    EXPECT_EQ(108, result[bs2sysex::param::VelocityAmpEnv]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvAttack]);
    EXPECT_EQ(127, result[bs2sysex::param::AmpEnvDecay]);
    EXPECT_EQ(127, result[bs2sysex::param::AmpEnvSustain]);
    EXPECT_EQ(92, result[bs2sysex::param::AmpEnvRelease]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvTriggering]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvAttack]);
    EXPECT_EQ(92, result[bs2sysex::param::ModEnvDecay]);
    EXPECT_EQ(24, result[bs2sysex::param::ModEnvSustain]);
    EXPECT_EQ(80, result[bs2sysex::param::ModEnvRelease]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvTriggering]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1Wave]);
    EXPECT_EQ(89, result[bs2sysex::param::LFO1Delay]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1Slew]);
    EXPECT_EQ(69, result[bs2sysex::param::LFO1Speed]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1SyncValue]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1SpeedSync]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1KeySync]);
    EXPECT_EQ(48, result[bs2sysex::param::LFO2Delay]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2Wave]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2Slew]);
    EXPECT_EQ(38, result[bs2sysex::param::LFO2Speed]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2SyncValue]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2SpeedSync]);
    EXPECT_EQ(1, result[bs2sysex::param::LFO2KeySync]);
    EXPECT_EQ(0, result[bs2sysex::param::ArpOn]);
    EXPECT_EQ(1, result[bs2sysex::param::ArpSeqRetrig]);
    EXPECT_EQ(2, result[bs2sysex::param::ArpOctaves]);
    EXPECT_EQ(5, result[bs2sysex::param::ArpNoteMode]);
    EXPECT_EQ(31, result[bs2sysex::param::ArpRhythm]);
    EXPECT_EQ(50, result[bs2sysex::param::ArpSwing]);
    EXPECT_EQ(64, result[bs2sysex::param::ModWheelFilterFreq]);
    EXPECT_EQ(73, result[bs2sysex::param::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(64, result[bs2sysex::param::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(64, result[bs2sysex::param::ModWheelOsc2Pitch]);
    EXPECT_EQ(64, result[bs2sysex::param::AftertouchFilterFreq]);
    EXPECT_EQ(70, result[bs2sysex::param::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(64, result[bs2sysex::param::AftertouchLFO2Speed]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc1LFO1Depth]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2LFO1Depth]);
    EXPECT_EQ(78, result[bs2sysex::param::Osc1LFO2PWMod]);
    EXPECT_EQ(83, result[bs2sysex::param::Osc2LFO2PWMod]);
    EXPECT_EQ(127, result[bs2sysex::param::FilterLFO2Depth]);
    EXPECT_EQ(64, result[bs2sysex::param::Osc1ModEnvDepth]);
    EXPECT_EQ(64, result[bs2sysex::param::Osc2ModEnvDepth]);
    EXPECT_EQ(63, result[bs2sysex::param::Osc1ModEnvPWMod]);
    EXPECT_EQ(63, result[bs2sysex::param::Osc2ModEnvPWMod]);
    EXPECT_EQ(105, result[bs2sysex::param::FilterModEnvDepth]);
    EXPECT_EQ(0, result[bs2sysex::param::FxOscFilterMod]);
    EXPECT_EQ(0, result[bs2sysex::param::FxDistortion]);
    EXPECT_EQ(0, result[bs2sysex::param::VCALimiter]);
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

    auto result = bs2sysex::decode(dump);
    EXPECT_EQ(0, result[bs2sysex::param::PatchNumber]);
    EXPECT_EQ(0, result[bs2sysex::param::PortamentoTime]);
    EXPECT_EQ(0, result[bs2sysex::param::OscPitchBendRange]);
    EXPECT_EQ(0, result[bs2sysex::param::OscSync]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1Waveform]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1ManualPW]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1Range]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1Coarse]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1Fine]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2Waveform]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2ManualPW]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2Range]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2Coarse]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2Fine]);
    EXPECT_EQ(0, result[bs2sysex::param::SubOscWave]);
    EXPECT_EQ(0, result[bs2sysex::param::SubOscOct]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerOsc1Level]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerOsc2Level]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerSubOscLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerNoiseLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerRingModLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::MixerExtLevel]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterFrequency]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterResonance]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterOverdrive]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterSlope]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterType]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterShape]);
    EXPECT_EQ(0, result[bs2sysex::param::VelocityAmpEnv]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvAttack]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvDecay]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvSustain]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvRelease]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvTriggering]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvAttack]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvDecay]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvSustain]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvRelease]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvTriggering]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1Wave]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1Delay]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1Slew]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1Speed]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1SyncValue]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1SpeedSync]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO1KeySync]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2Delay]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2Wave]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2Slew]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2Speed]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2SyncValue]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2SpeedSync]);
    EXPECT_EQ(0, result[bs2sysex::param::LFO2KeySync]);
    EXPECT_EQ(0, result[bs2sysex::param::ArpOn]);
    EXPECT_EQ(0, result[bs2sysex::param::ArpSeqRetrig]);
    EXPECT_EQ(0, result[bs2sysex::param::ArpOctaves]);
    EXPECT_EQ(0, result[bs2sysex::param::ArpNoteMode]);
    EXPECT_EQ(0, result[bs2sysex::param::ArpRhythm]);
    EXPECT_EQ(0, result[bs2sysex::param::ArpSwing]);
    EXPECT_EQ(0, result[bs2sysex::param::ModWheelFilterFreq]);
    EXPECT_EQ(0, result[bs2sysex::param::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(0, result[bs2sysex::param::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(0, result[bs2sysex::param::ModWheelOsc2Pitch]);
    EXPECT_EQ(0, result[bs2sysex::param::AftertouchFilterFreq]);
    EXPECT_EQ(0, result[bs2sysex::param::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(0, result[bs2sysex::param::AftertouchLFO2Speed]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1LFO1Depth]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2LFO1Depth]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1LFO2PWMod]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2LFO2PWMod]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterLFO2Depth]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1ModEnvDepth]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2ModEnvDepth]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc1ModEnvPWMod]);
    EXPECT_EQ(0, result[bs2sysex::param::Osc2ModEnvPWMod]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterModEnvDepth]);
    EXPECT_EQ(0, result[bs2sysex::param::FxOscFilterMod]);
    EXPECT_EQ(0, result[bs2sysex::param::FxDistortion]);
    EXPECT_EQ(0, result[bs2sysex::param::VCALimiter]);
    EXPECT_EQ(0, result[bs2sysex::param::Paraphonic]);
    EXPECT_EQ(0, result[bs2sysex::param::FilterTracking]);
    EXPECT_EQ(0, result[bs2sysex::param::AmpEnvRetrig]);
    EXPECT_EQ(0, result[bs2sysex::param::ModEnvRetrig]);
    EXPECT_EQ(0, result[bs2sysex::param::TuningTable]);
    EXPECT_EQ(0, result[bs2sysex::param::OscError]);
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



    auto result = bs2sysex::decode(dump);
    EXPECT_EQ(127, result[bs2sysex::param::PatchNumber]);
    EXPECT_EQ(127, result[bs2sysex::param::PortamentoTime]);
    EXPECT_EQ(127, result[bs2sysex::param::OscPitchBendRange]);
    EXPECT_EQ(1, result[bs2sysex::param::OscSync]);
    EXPECT_EQ(3, result[bs2sysex::param::Osc1Waveform]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc1ManualPW]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc1Range]);
    EXPECT_EQ(255, result[bs2sysex::param::Osc1Coarse]);
    EXPECT_EQ(255, result[bs2sysex::param::Osc1Fine]);
    EXPECT_EQ(3, result[bs2sysex::param::Osc2Waveform]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2ManualPW]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2Range]);
    EXPECT_EQ(255, result[bs2sysex::param::Osc2Coarse]);
    EXPECT_EQ(255, result[bs2sysex::param::Osc2Fine]);
    EXPECT_EQ(3, result[bs2sysex::param::SubOscWave]);
    EXPECT_EQ(1, result[bs2sysex::param::SubOscOct]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerOsc1Level]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerOsc2Level]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerSubOscLevel]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerNoiseLevel]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerRingModLevel]);
    EXPECT_EQ(255, result[bs2sysex::param::MixerExtLevel]);
    EXPECT_EQ(255, result[bs2sysex::param::FilterFrequency]);
    EXPECT_EQ(127, result[bs2sysex::param::FilterResonance]);
    EXPECT_EQ(127, result[bs2sysex::param::FilterOverdrive]);
    EXPECT_EQ(1, result[bs2sysex::param::FilterSlope]);
    EXPECT_EQ(1, result[bs2sysex::param::FilterType]);
    EXPECT_EQ(3, result[bs2sysex::param::FilterShape]);
    EXPECT_EQ(127, result[bs2sysex::param::VelocityAmpEnv]);
    EXPECT_EQ(127, result[bs2sysex::param::AmpEnvAttack]);
    EXPECT_EQ(127, result[bs2sysex::param::AmpEnvDecay]);
    EXPECT_EQ(127, result[bs2sysex::param::AmpEnvSustain]);
    EXPECT_EQ(127, result[bs2sysex::param::AmpEnvRelease]);
    EXPECT_EQ(3, result[bs2sysex::param::AmpEnvTriggering]);
    EXPECT_EQ(127, result[bs2sysex::param::ModEnvAttack]);
    EXPECT_EQ(127, result[bs2sysex::param::ModEnvDecay]);
    EXPECT_EQ(127, result[bs2sysex::param::ModEnvSustain]);
    EXPECT_EQ(127, result[bs2sysex::param::ModEnvRelease]);
    EXPECT_EQ(3, result[bs2sysex::param::ModEnvTriggering]);
    EXPECT_EQ(3, result[bs2sysex::param::LFO1Wave]);
    EXPECT_EQ(127, result[bs2sysex::param::LFO1Delay]);
    EXPECT_EQ(127, result[bs2sysex::param::LFO1Slew]);
    EXPECT_EQ(255, result[bs2sysex::param::LFO1Speed]);
    EXPECT_EQ(63, result[bs2sysex::param::LFO1SyncValue]);
    EXPECT_EQ(1, result[bs2sysex::param::LFO1SpeedSync]);
    EXPECT_EQ(1, result[bs2sysex::param::LFO1KeySync]);
    EXPECT_EQ(127, result[bs2sysex::param::LFO2Delay]);
    EXPECT_EQ(3, result[bs2sysex::param::LFO2Wave]);
    EXPECT_EQ(127, result[bs2sysex::param::LFO2Slew]);
    EXPECT_EQ(255, result[bs2sysex::param::LFO2Speed]);
    EXPECT_EQ(63, result[bs2sysex::param::LFO2SyncValue]);
    EXPECT_EQ(1, result[bs2sysex::param::LFO2SpeedSync]);
    EXPECT_EQ(1, result[bs2sysex::param::LFO2KeySync]);
    EXPECT_EQ(1, result[bs2sysex::param::ArpOn]);
    EXPECT_EQ(1, result[bs2sysex::param::ArpSeqRetrig]);
    EXPECT_EQ(7, result[bs2sysex::param::ArpOctaves]);
    EXPECT_EQ(7, result[bs2sysex::param::ArpNoteMode]);
    EXPECT_EQ(31, result[bs2sysex::param::ArpRhythm]);
    EXPECT_EQ(127, result[bs2sysex::param::ArpSwing]);
    EXPECT_EQ(127, result[bs2sysex::param::ModWheelFilterFreq]);
    EXPECT_EQ(127, result[bs2sysex::param::ModWheelLFO1toOscPitch]);
    EXPECT_EQ(127, result[bs2sysex::param::ModWheelLFO2toFilterFreq]);
    EXPECT_EQ(127, result[bs2sysex::param::ModWheelOsc2Pitch]);
    EXPECT_EQ(127, result[bs2sysex::param::AftertouchFilterFreq]);
    EXPECT_EQ(127, result[bs2sysex::param::AftertouchLFO1toOsc12Pitch]);
    EXPECT_EQ(127, result[bs2sysex::param::AftertouchLFO2Speed]);
    EXPECT_EQ(255, result[bs2sysex::param::Osc1LFO1Depth]);
    EXPECT_EQ(255, result[bs2sysex::param::Osc2LFO1Depth]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc1LFO2PWMod]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2LFO2PWMod]);
    EXPECT_EQ(255, result[bs2sysex::param::FilterLFO2Depth]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc1ModEnvDepth]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2ModEnvDepth]);
    EXPECT_EQ(63, result[bs2sysex::param::Osc1ModEnvPWMod]);
    EXPECT_EQ(127, result[bs2sysex::param::Osc2ModEnvPWMod]);
    EXPECT_EQ(127, result[bs2sysex::param::FilterModEnvDepth]);
    EXPECT_EQ(127, result[bs2sysex::param::FxOscFilterMod]);
    EXPECT_EQ(127, result[bs2sysex::param::FxDistortion]);
    EXPECT_EQ(127, result[bs2sysex::param::VCALimiter]);
    EXPECT_EQ(1, result[bs2sysex::param::Paraphonic]);
    EXPECT_EQ(7, result[bs2sysex::param::FilterTracking]);
    EXPECT_EQ(1, result[bs2sysex::param::AmpEnvRetrig]);
    EXPECT_EQ(1, result[bs2sysex::param::ModEnvRetrig]);
    EXPECT_EQ(15, result[bs2sysex::param::TuningTable]);
    EXPECT_EQ(7, result[bs2sysex::param::OscError]);
}
