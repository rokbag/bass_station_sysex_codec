#pragma once

#include <string>
#include <vector>
#include <map>

namespace sysex_decoder {

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
    MixerExtLevel,
    FilterFrequency,
    FilterResonance,
    FilterOverdrive,
    FilterSlope,
    FilterType,
    FilterShape,
    VelocityAmpEnv,
    AmpEnvAttack,
    AmpEnvDecay,
    AmpEnvSustain,
    AmpEnvRelease,
    AmpEnvTriggering,
    VelocityModEnv,
    ModEnvAttack,
    ModEnvDecay,
    ModEnvSustain,
    ModEnvRelease,
    ModEnvTriggering,
    LFO1Wave,
    LFO1Delay,
    LFO1Slew,
    LFO1Speed,
    LFO1SyncValue,
    LFO1SpeedSync,
    LFO1KeySync,
    LFO2Delay,
    LFO2Wave,
    LFO2Slew,
    LFO2Speed,
    LFO2SyncValue,
    LFO2SpeedSync,
    LFO2KeySync,
    ArpOn,
    ArpSeqRetrig,
    ArpOctaves,
    ArpNoteMode,
    ArpRhythm,
    ArpSwing,
    ModWheelFilterFreq,
    ModWheelLFO1toOscPitch,
    ModWheelLFO2toFilterFreq,
    ModWheelOsc2Pitch,
    AftertouchFilterFreq,
    AftertouchLFO1toOsc12Pitch,
    AftertouchLFO2Speed,
    Osc1LFO1Depth,
    Osc2LFO1Depth,
    Osc1LFO2PWMod,
    Osc2LFO2PWMod,
    FilterLFO2Depth,
    Osc1ModEnvDepth,
    Osc2ModEnvDepth,
    Osc1ModEnvPWMod,
    Osc2ModEnvPWMod,
    FilterModEnvDepth,
    FxOscFilterMod,
    FxDistortion,
    VCALimiter,
    PatchName
};

using uint8 = unsigned char;
using data_t = std::vector<uint8>;
using value_map = std::map<EParam, uint8>;


class decoder
{
public:
    value_map decode(const data_t &payload);
    value_map decode(const data_t &payload, int offset);

    void print(const value_map& data, EParam filter);

protected:
    uint8 patch_number(const uint8 msb);
    uint8 portamento_time(const uint8 msb, const uint8 lsb);

    uint8 osc_pitch_bend_range(const uint8 msb);
    uint8 osc_sync(const uint8 msb);

    uint8 osc1_waveform(const uint8 msb);
    uint8 osc1_manual_pw(const uint8 msb, const uint8 lsb);
    uint8 osc1_range(const uint8 msb, const uint8 lsb);
    uint8 osc1_coarse(const uint8 msb, const uint8 lsb);
    uint8 osc1_fine(const uint8 msb, const uint8 lsb);

    uint8 osc2_waveform(const uint8 msb);
    uint8 osc2_manual_pw(const uint8 msb, const uint8 lsb);
    uint8 osc2_range(const uint8 msb, const uint8 lsb);
    uint8 osc2_coarse(const uint8 msb, const uint8 lsb);
    uint8 osc2_fine(const uint8 msb, const uint8 lsb);

    uint8 sub_osc_waveform(const uint8 msb);
    uint8 sub_osc_octave(const uint8 msb);

    uint8 mixer_osc1_level(const uint8 msb, const uint8 lsb);
    uint8 mixer_osc2_level(const uint8 msb, const uint8 lsb);
    uint8 mixer_sub_osc_level(const uint8 msb, const uint8 lsb);
    uint8 mixer_noise_level(const uint8 msb, const uint8 lsb);
    uint8 mixer_rm_level(const uint8 msb, const uint8 lsb);
    uint8 mixer_ext_level(const uint8 msb, const uint8 lsb);

    uint8 filter_frequency(const uint8 msb, const uint8 lsb);
    uint8 filter_resonance(const uint8 msb, const uint8 lsb);
    uint8 filter_overdrive(const uint8 msb, const uint8 lsb);
    uint8 filter_slope(const uint8 msb);
    uint8 filter_type(const uint8 msb);
    uint8 filter_shape(const uint8 msb);

    uint8 velocity_amp_env(const uint8 msb, const uint8 lsb);
    uint8 amp_env_attack(const uint8 msb, const uint8 lsb);
    uint8 amp_env_decay(const uint8 msb, const uint8 lsb);
    uint8 amp_env_sustain(const uint8 msb, const uint8 lsb);
    uint8 amp_env_release(const uint8 msb, const uint8 lsb);
    uint8 amp_env_triggering(const uint8 msb);

    uint8 velocity_mod_env(const uint8 msb);
    uint8 mod_env_attack(const uint8 msb, const uint8 lsb);
    uint8 mod_env_decay(const uint8 msb, const uint8 lsb);
    uint8 mod_env_sustain(const uint8 msb, const uint8 lsb);
    uint8 mod_env_release(const uint8 msb, const uint8 lsb);
    uint8 mod_env_triggering(const uint8 msb);

    uint8 lfo1_wave(const uint8 msb);
    uint8 lfo1_delay(const uint8 msb);
    uint8 lfo1_slew(const uint8 msb, const uint8 lsb);
    uint8 lfo1_speed(const uint8 msb, const uint8 lsb);
    uint8 lfo1_sync_value(const uint8 msb, const uint8 lsb);
    uint8 lfo1_speed_sync(const uint8 msb);
    uint8 lfo1_key_sync(const uint8 msb);

    uint8 lfo2_wave(const uint8 msb);
    uint8 lfo2_delay(const uint8 msb, const uint8 lsb);
    uint8 lfo2_slew(const uint8 msb);
    uint8 lfo2_speed(const uint8 msb, const uint8 lsb);
    uint8 lfo2_sync_value(const uint8 msb, const uint8 lsb);
    uint8 lfo2_speed_sync(const uint8 msb);
    uint8 lfo2_key_sync(const uint8 msb);

    uint8 arp_on(const uint8 msb);
    uint8 arp_seq_retrig(const uint8 msb);
    uint8 arp_octaves(const uint8 msb);
    uint8 arp_note_mode(const uint8 msb);
    uint8 arp_rhythm(const uint8 msb);
    uint8 arp_swing(const uint8 msb, const uint8 lsb);

    uint8 mod_wheel_filter_freq(const uint8 msb, const uint8 lsb);
    uint8 mod_wheel_lfo1_to_osc_pitch(const uint8 msb, const uint8 lsb);
    uint8 mod_wheel_lfo2_to_filter_freq(const uint8 msb, const uint8 lsb);
    uint8 mod_wheel_osc2_pitch(const uint8 msb, const uint8 lsb);

    uint8 aftertouch_filter_freq(const uint8 msb, const uint8 lsb);
    uint8 aftertouch_lfo1_to_osc12_pitch(const uint8 msb);
    uint8 aftertouch_lfo2_speed(const uint8 msb, const uint8 lsb);

    uint8 osc1_lfo1_depth(const uint8 msb, const uint8 lsb);
    uint8 osc2_lfo1_depth(const uint8 msb, const uint8 lsb);
    uint8 osc1_lfo2_pw_mod(const uint8 msb, const uint8 lsb);
    uint8 osc2_lfo2_pw_mod(const uint8 msb, const uint8 lsb);
    uint8 filter_lfo2_depth(const uint8 msb, const uint8 lsb);

    uint8 osc1_mod_env_depth(const uint8 msb, const uint8 lsb);
    uint8 osc2_mod_env_depth(const uint8 msb, const uint8 lsb);
    uint8 osc1_mod_env_pw_mod(const uint8 msb, const uint8 lsb);
    uint8 osc2_mod_env_pw_mod(const uint8 msb, const uint8 lsb);
    uint8 filter_mod_env_depth(const uint8 msb, const uint8 lsb);

    uint8 fx_osc_filter_mod(const uint8 msb, const uint8 lsb);
    uint8 fx_distortion(const uint8 msb, const uint8 lsb);
    uint8 vca_limiter(const uint8 msb, const uint8 lsb);

    std::string patch_name(const data_t& data);
};

}
