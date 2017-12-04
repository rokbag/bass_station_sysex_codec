#include "decoder.h"
#include <iostream>

namespace sysex_decoder {

value_map decoder::decode(const data_t& payload)
{
    return decode(payload, 0); }
value_map decoder::decode(const data_t& payload, int offset)
{
    value_map values;

    values[EParam::PatchNumber]                = patch_number                  (payload[offset+9]);
    values[EParam::PortamentoTime]             = portamento_time               (payload[offset+13], payload[offset+14]);

    values[EParam::OscPitchBendRange]          = osc_pitch_bend_range          (payload[offset+16]);
    values[EParam::OscSync]                    = osc_sync                      (payload[offset+18]);

    values[EParam::Osc1Waveform]               = osc1_waveform                 (payload[offset+19]);
    values[EParam::Osc1ManualPW]               = osc1_manual_pw                (payload[offset+19], payload[offset+20]);
    values[EParam::Osc1Range]                  = osc1_range                    (payload[offset+20], payload[offset+21]);
    values[EParam::Osc1Coarse]                 = osc1_coarse                   (payload[offset+21], payload[offset+22]);
    values[EParam::Osc1Fine]                   = osc1_fine                     (payload[offset+22], payload[offset+23]);

    values[EParam::Osc2Waveform]               = osc2_waveform                 (payload[offset+24]);
    values[EParam::Osc2ManualPW]               = osc2_manual_pw                (payload[offset+25], payload[offset+26]);
    values[EParam::Osc2Range]                  = osc2_range                    (payload[offset+26], payload[offset+27]);
    values[EParam::Osc2Coarse]                 = osc2_coarse                   (payload[offset+27], payload[offset+28]);
    values[EParam::Osc2Fine]                   = osc2_fine                     (payload[offset+28], payload[offset+29]);

    values[EParam::SubOscWave]                 = sub_osc_waveform              (payload[offset+36]);
    values[EParam::SubOscOct]                  = sub_osc_octave                (payload[offset+37]);

    values[EParam::MixerOsc1Level]             = mixer_osc1_level              (payload[offset+37], payload[offset+38]);
    values[EParam::MixerOsc2Level]             = mixer_osc2_level              (payload[offset+38], payload[offset+39]);
    values[EParam::MixerSubOscLevel]           = mixer_sub_osc_level           (payload[offset+39], payload[offset+40]);
    values[EParam::MixerNoiseLevel]            = mixer_noise_level             (payload[offset+41], payload[offset+42]);
    values[EParam::MixerRingModLevel]          = mixer_rm_level                (payload[offset+42], payload[offset+43]);
    values[EParam::MixerExtLevel]              = mixer_ext_level               (payload[offset+43], payload[offset+44]);

    values[EParam::FilterFrequency]            = filter_frequency              (payload[offset+44], payload[offset+45]);
    values[EParam::FilterResonance]            = filter_resonance              (payload[offset+45], payload[offset+46]);
    values[EParam::FilterOverdrive]            = filter_overdrive              (payload[offset+46], payload[offset+47]);
    values[EParam::FilterSlope]                = filter_slope                  (payload[offset+48]);
    values[EParam::FilterType]                 = filter_type                   (payload[offset+48]);
    values[EParam::FilterShape]                = filter_shape                  (payload[offset+48]);

    values[EParam::VelocityAmpEnv]             = velocity_amp_env              (payload[offset+49], payload[offset+50]);
    values[EParam::AmpEnvAttack]               = amp_env_attack                (payload[offset+50], payload[offset+51]);
    values[EParam::AmpEnvDecay]                = amp_env_decay                 (payload[offset+51], payload[offset+52]);
    values[EParam::AmpEnvSustain]              = amp_env_sustain               (payload[offset+52], payload[offset+53]);
    values[EParam::AmpEnvRelease]              = amp_env_release               (payload[offset+53], payload[offset+54]);
    values[EParam::AmpEnvTriggering]           = amp_env_triggering            (payload[offset+55]);

    values[EParam::VelocityModEnv]             = velocity_mod_env              (payload[offset+56]);
    values[EParam::ModEnvAttack]               = mod_env_attack                (payload[offset+57], payload[offset+58]);
    values[EParam::ModEnvDecay]                = mod_env_decay                 (payload[offset+58], payload[offset+59]);
    values[EParam::ModEnvSustain]              = mod_env_sustain               (payload[offset+59], payload[offset+60]);
    values[EParam::ModEnvRelease]              = mod_env_release               (payload[offset+60], payload[offset+62]);
    values[EParam::ModEnvTriggering]           = mod_env_triggering            (payload[offset+62]);

    values[EParam::LFO1Wave]                   = lfo1_wave                     (payload[offset+63]);
    values[EParam::LFO1Delay]                  = lfo1_delay                    (payload[offset+64]);
    values[EParam::LFO1Slew]                   = lfo1_slew                     (payload[offset+65], payload[offset+66]);
    values[EParam::LFO1Speed]                  = lfo1_speed                    (payload[offset+66], payload[offset+67]);
    values[EParam::LFO1SyncValue]              = lfo1_sync_value               (payload[offset+67], payload[offset+68]);
    values[EParam::LFO1SpeedSync]              = lfo1_speed_sync               (payload[offset+69]);
    values[EParam::LFO1KeySync]                = lfo1_key_sync                 (payload[offset+69]);

    values[EParam::LFO2Wave]                   = lfo2_wave                     (payload[offset+70]);
    values[EParam::LFO2Delay]                  = lfo2_delay                    (payload[offset+70], payload[offset+71]);
    values[EParam::LFO2Slew]                   = lfo2_slew                     (payload[offset+72]);
    values[EParam::LFO2Speed]                  = lfo2_speed                    (payload[offset+73], payload[offset+74]);
    values[EParam::LFO2SyncValue]              = lfo2_sync_value               (payload[offset+74], payload[offset+75]);
    values[EParam::LFO2SpeedSync]              = lfo2_speed_sync               (payload[offset+76]);
    values[EParam::LFO2KeySync]                = lfo2_key_sync                 (payload[offset+76]);

    values[EParam::ArpOn]                      = arp_on                        (payload[offset+77]);
    values[EParam::ArpSeqRetrig]               = arp_seq_retrig                (payload[offset+77]);
    values[EParam::ArpOctaves]                 = arp_octaves                   (payload[offset+78]);
    values[EParam::ArpNoteMode]                = arp_note_mode                 (payload[offset+79]);
    values[EParam::ArpRhythm]                  = arp_rhythm                    (payload[offset+80]);
    values[EParam::ArpSwing]                   = arp_swing                     (payload[offset+81], payload[offset+82]);

    values[EParam::ModWheelFilterFreq]         = mod_wheel_filter_freq         (payload[offset+82], payload[offset+83]);
    values[EParam::ModWheelLFO1toOscPitch]     = mod_wheel_lfo1_to_osc_pitch   (payload[offset+83], payload[offset+84]);
    values[EParam::ModWheelLFO2toFilterFreq]   = mod_wheel_lfo2_to_filter_freq (payload[offset+84], payload[offset+85]);
    values[EParam::ModWheelOsc2Pitch]          = mod_wheel_osc2_pitch          (payload[offset+85], payload[offset+86]);

    values[EParam::AftertouchFilterFreq]       = aftertouch_filter_freq        (payload[offset+86], payload[offset+87]);
    values[EParam::AftertouchLFO1toOsc12Pitch] = aftertouch_lfo1_to_osc12_pitch(payload[offset+88]);
    values[EParam::AftertouchLFO2Speed]        = aftertouch_lfo2_speed         (payload[offset+89], payload[offset+90]);

    values[EParam::Osc1LFO1Depth]              = osc1_lfo1_depth               (payload[offset+90], payload[offset+91]);
    values[EParam::Osc2LFO1Depth]              = osc2_lfo1_depth               (payload[offset+91], payload[offset+92]);
    values[EParam::Osc1LFO2PWMod]              = osc1_lfo2_pw_mod              (payload[offset+93], payload[offset+94]);
    values[EParam::Osc2LFO2PWMod]              = osc2_lfo2_pw_mod              (payload[offset+94], payload[offset+95]);
    values[EParam::FilterLFO2Depth]            = filter_lfo2_depth             (payload[offset+97], payload[offset+98]);

    values[EParam::Osc1ModEnvDepth]            = osc1_mod_env_depth            (payload[offset+98], payload[offset+99]);
    values[EParam::Osc2ModEnvDepth]            = osc2_mod_env_depth            (payload[offset+99], payload[offset+100]);
    values[EParam::Osc1ModEnvPWMod]            = osc1_mod_env_pw_mod           (payload[offset+101], payload[offset+102]);
    values[EParam::Osc2ModEnvPWMod]            = osc2_mod_env_pw_mod           (payload[offset+102], payload[offset+103]);
    values[EParam::FilterModEnvDepth]          = filter_mod_env_depth          (payload[offset+105], payload[offset+106]);

    values[EParam::FxOscFilterMod]             = fx_osc_filter_mod             (payload[offset+106], payload[offset+107]);
    values[EParam::FxDistortion]               = fx_distortion                 (payload[offset+107], payload[offset+108]);
    values[EParam::VCALimiter]                 = vca_limiter                   (payload[offset+108], payload[offset+109]);

    return values; }

void decoder::print(const value_map &data, EParam filter)
{
    std::cout << static_cast<int>(data.at(filter)) << std::endl;
}

uint8 decoder::patch_number   (const uint8 msb)                         { return   msb & 0b01111111; }
uint8 decoder::portamento_time(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }

uint8 decoder::osc_pitch_bend_range(const uint8 msb)                    { return   msb & 0b01111111; }
uint8 decoder::osc_sync(const uint8 msb)                                { return  (msb & 0b01000000) >> 6; }

uint8 decoder::osc1_waveform(const uint8 msb)                           { return  (msb & 0b01100000) >> 5; }
uint8 decoder::osc1_manual_pw(const uint8 msb, const uint8 lsb)         { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::osc1_range(const uint8 msb, const uint8 lsb)             { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
uint8 decoder::osc1_coarse(const uint8 msb, const uint8 lsb)            { return ((msb & 0b00000111) << 5) + ((lsb & 0b01111100) >> 2); }
uint8 decoder::osc1_fine(const uint8 msb, const uint8 lsb)              { return ((msb & 0b00000011) << 6) + ((lsb & 0b01111110) >> 1); }

uint8 decoder::osc2_waveform(const uint8 msb)                           { return   msb & 0b00000011; }
uint8 decoder::osc2_manual_pw(const uint8 msb, const uint8 lsb)         { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
uint8 decoder::osc2_range(const uint8 msb, const uint8 lsb)             { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::osc2_coarse(const uint8 msb, const uint8 lsb)            { return ((msb & 0b00011111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::osc2_fine(const uint8 msb, const uint8 lsb)              { return ((msb & 0b00001111) << 4) + ((lsb & 0b01111000) >> 3); }

uint8 decoder::sub_osc_waveform(const uint8 msb)                        { return  (msb & 0b00110000) >> 4; }
uint8 decoder::sub_osc_octave(const uint8 msb)                          { return  (msb & 0b00001000) >> 3; }

uint8 decoder::mixer_osc1_level(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00000111) << 5) + ((lsb & 0b01111100) >> 2); }
uint8 decoder::mixer_osc2_level(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00000011) << 6) + ((lsb & 0b01111110) >> 1); }
uint8 decoder::mixer_sub_osc_level(const uint8 msb, const uint8 lsb)    { return ((msb & 0b00000001) << 7) +  (lsb & 0b01111111); }
uint8 decoder::mixer_noise_level(const uint8 msb, const uint8 lsb)      { return ((msb & 0b01111111) << 1) + ((lsb & 0b01000000) >> 6); }
uint8 decoder::mixer_rm_level(const uint8 msb, const uint8 lsb)         { return ((msb & 0b00111111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::mixer_ext_level(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00011111) << 3) + ((lsb & 0b01110000) >> 4); }

uint8 decoder::filter_frequency(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00001111) << 4) + ((lsb & 0b01111000) >> 3); }
uint8 decoder::filter_resonance(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }
uint8 decoder::filter_overdrive(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
uint8 decoder::filter_slope(const uint8 msb)                            { return  (msb & 0b00001000) >> 3; }
uint8 decoder::filter_type(const uint8 msb)                             { return  (msb & 0b00000100) >> 2; }
uint8 decoder::filter_shape(const uint8 msb)                            { return   msb & 0b00000011; }

uint8 decoder::velocity_amp_env(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
uint8 decoder::amp_env_attack(const uint8 msb, const uint8 lsb)         { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::amp_env_decay(const uint8 msb, const uint8 lsb)          { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::amp_env_sustain(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
uint8 decoder::amp_env_release(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }
uint8 decoder::amp_env_triggering(const uint8 msb)                      { return  (msb & 0b00000110) >> 1; }

uint8 decoder::velocity_mod_env(const uint8 msb)                        { return   msb & 0b01111111; }
uint8 decoder::mod_env_attack(const uint8 msb, const uint8 lsb)         { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
uint8 decoder::mod_env_decay(const uint8 msb, const uint8 lsb)          { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::mod_env_sustain(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::mod_env_release(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
uint8 decoder::mod_env_triggering(const uint8 msb)                      { return  (msb & 0b00001100) >> 2; }

uint8 decoder::lfo1_wave(const uint8 msb)                               { return  (msb & 0b00000110) >> 1; }
uint8 decoder::lfo1_delay(const uint8 msb)                              { return   msb & 0b01111111; }
uint8 decoder::lfo1_slew(const uint8 msb, const uint8 lsb)              { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
uint8 decoder::lfo1_speed(const uint8 msb, const uint8 lsb)             { return ((msb & 0b00111111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::lfo1_sync_value(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00000111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::lfo1_speed_sync(const uint8 msb)                         { return  (msb & 0b00001000) >> 3; }
uint8 decoder::lfo1_key_sync(const uint8 msb)                           { return  (msb & 0b00010000) >> 4; }

uint8 decoder::lfo2_wave(const uint8 msb)                               { return  (msb & 0b00001100) >> 2; }
uint8 decoder::lfo2_delay(const uint8 msb, const uint8 lsb)             { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
uint8 decoder::lfo2_slew(const uint8 msb)                               { return   msb & 0b01111111; }
uint8 decoder::lfo2_speed(const uint8 msb, const uint8 lsb)             { return ((msb & 0b01111111) << 1) + ((lsb & 0b01000000) >> 6); }
uint8 decoder::lfo2_sync_value(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00001111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::lfo2_speed_sync(const uint8 msb)                         { return  (msb & 0b00010000) >> 4; }
uint8 decoder::lfo2_key_sync(const uint8 msb)                           { return  (msb & 0b00100000) >> 5; }

uint8 decoder::arp_on(const uint8 msb)                                  { return  (msb & 0b00001000) >> 3; }
uint8 decoder::arp_seq_retrig(const uint8 msb)                          { return  (msb & 0b00100000) >> 5; }
uint8 decoder::arp_octaves(const uint8 msb)                             { return  (msb & 0b00011100) >> 2; }
uint8 decoder::arp_note_mode(const uint8 msb)                           { return  (msb & 0b00001110) >> 1; }
uint8 decoder::arp_rhythm(const uint8 msb)                              { return   msb & 0b00011111; }
uint8 decoder::arp_swing(const uint8 msb, const uint8 lsb)              { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }

uint8 decoder::mod_wheel_filter_freq(const uint8 msb, const uint8 lsb)         { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::mod_wheel_lfo1_to_osc_pitch(const uint8 msb, const uint8 lsb)   { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::mod_wheel_lfo2_to_filter_freq(const uint8 msb, const uint8 lsb) { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
uint8 decoder::mod_wheel_osc2_pitch(const uint8 msb, const uint8 lsb)          { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }

uint8 decoder::aftertouch_filter_freq(const uint8 msb, const uint8 lsb) { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
uint8 decoder::aftertouch_lfo1_to_osc12_pitch(const uint8 msb)          { return   msb & 0b01111111; }
uint8 decoder::aftertouch_lfo2_speed(const uint8 msb, const uint8 lsb)  { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }

uint8 decoder::osc1_lfo1_depth(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00111111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::osc2_lfo1_depth(const uint8 msb, const uint8 lsb)        { return ((msb & 0b00011111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::osc1_lfo2_pw_mod(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }
uint8 decoder::osc2_lfo2_pw_mod(const uint8 msb, const uint8 lsb)       { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
uint8 decoder::filter_lfo2_depth(const uint8 msb, const uint8 lsb)      { return ((msb & 0b01111111) << 1) + ((lsb & 0b01000000) >> 6); }

uint8 decoder::osc1_mod_env_depth(const uint8 msb, const uint8 lsb)     { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::osc2_mod_env_depth(const uint8 msb, const uint8 lsb)     { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::osc1_mod_env_pw_mod(const uint8 msb, const uint8 lsb)    { return ((msb & 0b00000001) << 5) + ((lsb & 0b01111100) >> 2); }
uint8 decoder::osc2_mod_env_pw_mod(const uint8 msb, const uint8 lsb)    { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
uint8 decoder::filter_mod_env_depth(const uint8 msb, const uint8 lsb)   { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }

uint8 decoder::fx_osc_filter_mod(const uint8 msb, const uint8 lsb)      { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
uint8 decoder::fx_distortion(const uint8 msb, const uint8 lsb)          { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
uint8 decoder::vca_limiter(const uint8 msb, const uint8 lsb)            { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }

std::string decoder::patch_name(const data_t& data)                     { return std::string{data.begin(), data.end()}; }

}
