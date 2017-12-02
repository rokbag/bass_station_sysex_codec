#pragma once
#include <vector>
#include <map>

using uint8 = unsigned char;
using data_t = std::vector<uint8>;

enum class EParam {
    PatchNumber,
    PortamentoTime,
    OscPitchBendRange,
    OscSync,
    Osc1Waveform,
    Osc1ManualPW,
    Osc1Range,
    Osc1Coarse,
    Osc1Fine,
    Osc2Waveform,
    Osc2ManualPW,
    Osc2Range,
    Osc2Coarse,
    Osc2Fine,
    SubOscWave,
    SubOscOct,
    MixerOsc1Level,
    MixerOsc2Level,
    MixerSubOscLevel,
    MixerNoiseLevel,
    MixerRingModLevel,
    MixerExternalSignalLevel,
    FilterFrequency,
    FilterResonance,
    FilterOverdrive,
    FilterSlope,
    FilterType,
    VelocityAmpEnv
};

using value_map_type = std::map<EParam, uint8>;
