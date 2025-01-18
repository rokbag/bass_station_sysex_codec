#include <decoder.hpp>
#include <iostream>

namespace {

using bit_position = std::uint8_t;

bs2sysex::value patch_number   (const bit_position lsb)                                { return   lsb & 0b01111111; }
bs2sysex::value portamento_time(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }

bs2sysex::value osc_pitch_bend_range(const bit_position lsb)                           { return   lsb & 0b01111111; }
bs2sysex::value osc_sync(const bit_position lsb)                                       { return  (lsb & 0b01000000) >> 6; }

bs2sysex::value osc1_waveform(const bit_position msb)                                  { return  (msb & 0b01100000) >> 5; }
bs2sysex::value osc1_manual_pw(const bit_position msb, const bit_position lsb)         { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value osc1_range(const bit_position msb, const bit_position lsb)             { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
bs2sysex::value osc1_coarse(const bit_position msb, const bit_position lsb)            { return ((msb & 0b00000111) << 5) + ((lsb & 0b01111100) >> 2); }
bs2sysex::value osc1_fine(const bit_position msb, const bit_position lsb)              { return ((msb & 0b00000011) << 6) + ((lsb & 0b01111110) >> 1); }

bs2sysex::value osc2_waveform(const bit_position lsb)                                  { return   lsb & 0b00000011; }
bs2sysex::value osc2_manual_pw(const bit_position msb, const bit_position lsb)         { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
bs2sysex::value osc2_range(const bit_position msb, const bit_position lsb)             { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value osc2_coarse(const bit_position msb, const bit_position lsb)            { return ((msb & 0b00011111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value osc2_fine(const bit_position msb, const bit_position lsb)              { return ((msb & 0b00001111) << 4) + ((lsb & 0b01111000) >> 3); }

bs2sysex::value sub_osc_waveform(const bit_position lsb)                               { return  (lsb & 0b00110000) >> 4; }
bs2sysex::value sub_osc_octave(const bit_position lsb)                                 { return  (lsb & 0b00001000) >> 3; }

bs2sysex::value mixer_osc1_level(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00000111) << 5) + ((lsb & 0b01111100) >> 2); }
bs2sysex::value mixer_osc2_level(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00000011) << 6) + ((lsb & 0b01111110) >> 1); }
bs2sysex::value mixer_sub_osc_level(const bit_position msb, const bit_position lsb)    { return ((msb & 0b00000001) << 7) +  (lsb & 0b01111111); }
bs2sysex::value mixer_noise_level(const bit_position msb, const bit_position lsb)      { return ((msb & 0b01111111) << 1) + ((lsb & 0b01000000) >> 6); }
bs2sysex::value mixer_rm_level(const bit_position msb, const bit_position lsb)         { return ((msb & 0b00111111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value mixer_ext_level(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00011111) << 3) + ((lsb & 0b01110000) >> 4); }

bs2sysex::value filter_frequency(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00001111) << 4) + ((lsb & 0b01111000) >> 3); }
bs2sysex::value filter_resonance(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }
bs2sysex::value filter_overdrive(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
bs2sysex::value filter_slope(const bit_position lsb)                                   { return  (lsb & 0b00001000) >> 3; }
bs2sysex::value filter_type(const bit_position lsb)                                    { return  (lsb & 0b00000100) >> 2; }
bs2sysex::value filter_shape(const bit_position lsb)                                   { return   lsb & 0b00000011; }

bs2sysex::value velocity_amp_env(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
bs2sysex::value amp_env_attack(const bit_position msb, const bit_position lsb)         { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value amp_env_decay(const bit_position msb, const bit_position lsb)          { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value amp_env_sustain(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
bs2sysex::value amp_env_release(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }
bs2sysex::value amp_env_triggering(const bit_position lsb)                             { return  (lsb & 0b00000110) >> 1; }

bs2sysex::value velocity_mod_env(const bit_position lsb)                               { return   lsb & 0b01111111; }
bs2sysex::value mod_env_attack(const bit_position msb, const bit_position lsb)         { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
bs2sysex::value mod_env_decay(const bit_position msb, const bit_position lsb)          { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value mod_env_sustain(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value mod_env_release(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
bs2sysex::value mod_env_triggering(const bit_position lsb)                             { return  (lsb & 0b00001100) >> 2; }

bs2sysex::value lfo1_wave(const bit_position lsb)                                      { return  (lsb & 0b00000110) >> 1; }
bs2sysex::value lfo1_delay(const bit_position lsb)                                     { return   lsb & 0b01111111; }
bs2sysex::value lfo1_slew(const bit_position msb, const bit_position lsb)              { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }
bs2sysex::value lfo1_speed(const bit_position msb, const bit_position lsb)             { return ((msb & 0b00111111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value lfo1_sync_value(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00000111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value lfo1_speed_sync(const bit_position lsb)                                { return  (lsb & 0b00001000) >> 3; }
bs2sysex::value lfo1_key_sync(const bit_position lsb)                                  { return  (lsb & 0b00010000) >> 4; }

bs2sysex::value lfo2_wave(const bit_position lsb)                                      { return  (lsb & 0b00001100) >> 2; }
bs2sysex::value lfo2_delay(const bit_position msb, const bit_position lsb)             { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
bs2sysex::value lfo2_slew(const bit_position lsb)                                      { return   lsb & 0b01111111; }
bs2sysex::value lfo2_speed(const bit_position msb, const bit_position lsb)             { return ((msb & 0b01111111) << 1) + ((lsb & 0b01000000) >> 6); }
bs2sysex::value lfo2_sync_value(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00001111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value lfo2_speed_sync(const bit_position lsb)                                { return  (lsb & 0b00010000) >> 4; }
bs2sysex::value lfo2_key_sync(const bit_position lsb)                                  { return  (lsb & 0b00100000) >> 5; }

bs2sysex::value arp_on(const bit_position lsb)                                         { return  (lsb & 0b00001000) >> 3; }
bs2sysex::value arp_seq_retrig(const bit_position lsb)                                 { return  (lsb & 0b00100000) >> 5; }
bs2sysex::value arp_octaves(const bit_position lsb)                                    { return  (lsb & 0b00011100) >> 2; }
bs2sysex::value arp_note_mode(const bit_position lsb)                                  { return  (lsb & 0b00001110) >> 1; }
bs2sysex::value arp_rhythm(const bit_position lsb)                                     { return   lsb & 0b00011111; }
bs2sysex::value arp_swing(const bit_position msb, const bit_position lsb)              { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }

bs2sysex::value mod_wheel_filter_freq(const bit_position msb, const bit_position lsb)         { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value mod_wheel_lfo1_to_osc_pitch(const bit_position msb, const bit_position lsb)   { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value mod_wheel_lfo2_to_filter_freq(const bit_position msb, const bit_position lsb) { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }
bs2sysex::value mod_wheel_osc2_pitch(const bit_position msb, const bit_position lsb)          { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }

bs2sysex::value aftertouch_filter_freq(const bit_position msb, const bit_position lsb) { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
bs2sysex::value aftertouch_lfo1_to_osc12_pitch(const bit_position lsb)                 { return   lsb & 0b01111111; }
bs2sysex::value aftertouch_lfo2_speed(const bit_position msb, const bit_position lsb)  { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }

bs2sysex::value osc1_lfo1_depth(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00111111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value osc2_lfo1_depth(const bit_position msb, const bit_position lsb)        { return ((msb & 0b00011111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value osc1_lfo2_pw_mod(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2); }
bs2sysex::value osc2_lfo2_pw_mod(const bit_position msb, const bit_position lsb)       { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
bs2sysex::value filter_lfo2_depth(const bit_position msb, const bit_position lsb)      { return ((msb & 0b01111111) << 1) + ((lsb & 0b01000000) >> 6); }

bs2sysex::value osc1_mod_env_depth(const bit_position msb, const bit_position lsb)     { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value osc2_mod_env_depth(const bit_position msb, const bit_position lsb)     { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value osc1_mod_env_pw_mod(const bit_position msb, const bit_position lsb)    { return ((msb & 0b00000001) << 5) + ((lsb & 0b01111100) >> 2); }
bs2sysex::value osc2_mod_env_pw_mod(const bit_position msb, const bit_position lsb)    { return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1); }
bs2sysex::value filter_mod_env_depth(const bit_position msb, const bit_position lsb)   { return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6); }

bs2sysex::value fx_osc_filter_mod(const bit_position msb, const bit_position lsb)      { return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5); }
bs2sysex::value fx_distortion(const bit_position msb, const bit_position lsb)          { return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value vca_limiter(const bit_position msb, const bit_position lsb)            { return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3); }

bs2sysex::value paraphonic(const bit_position lsb)                                     { return  (lsb & 0b00000010) >> 1; }
bs2sysex::value filter_tracking(const bit_position lsb)                                { return  (lsb & 0b00000111); }
bs2sysex::value amp_env_retrig(const bit_position lsb)                                 { return  (lsb & 0b01000000) >> 6; }
bs2sysex::value mod_env_retrig(const bit_position lsb)                                 { return  (lsb & 0b00100000) >> 5; }
bs2sysex::value tuning_table(const bit_position msb, const bit_position lsb)           { return ((msb & 0b00000001) << 3) + ((lsb & 0b01110000) >> 4); }
bs2sysex::value osc_error(const bit_position lsb)                                      { return  (lsb & 0b00111000) >> 3; }

std::string patch_name(const bs2sysex::sysex_payload& data)
{
    std::string str;
    for (const auto i : data)
    {
        bs2sysex::value value = i & 0b01111111;
        str.append(std::to_string(value));
    }
    return str;
}

}

namespace bs2sysex {

std::map<param, value> decode(const sysex_payload& payload)
{
    return decode(payload, 0);
}

std::map<param, value> decode(const sysex_payload& payload, int offset)
{
    std::map<param, value> values;

    values[param::PatchNumber]                = patch_number                  (payload[offset+9]);
    values[param::PortamentoTime]             = portamento_time               (payload[offset+13], payload[offset+14]);

    values[param::OscPitchBendRange]          = osc_pitch_bend_range          (payload[offset+16]);
    values[param::OscSync]                    = osc_sync                      (payload[offset+18]);

    values[param::Osc1Waveform]               = osc1_waveform                 (payload[offset+19]);
    values[param::Osc1ManualPW]               = osc1_manual_pw                (payload[offset+19], payload[offset+20]);
    values[param::Osc1Range]                  = osc1_range                    (payload[offset+20], payload[offset+21]);
    values[param::Osc1Coarse]                 = osc1_coarse                   (payload[offset+21], payload[offset+22]);
    values[param::Osc1Fine]                   = osc1_fine                     (payload[offset+22], payload[offset+23]);

    values[param::Osc2Waveform]               = osc2_waveform                 (payload[offset+24]);
    values[param::Osc2ManualPW]               = osc2_manual_pw                (payload[offset+25], payload[offset+26]);
    values[param::Osc2Range]                  = osc2_range                    (payload[offset+26], payload[offset+27]);
    values[param::Osc2Coarse]                 = osc2_coarse                   (payload[offset+27], payload[offset+28]);
    values[param::Osc2Fine]                   = osc2_fine                     (payload[offset+28], payload[offset+29]);

    values[param::SubOscWave]                 = sub_osc_waveform              (payload[offset+36]);
    values[param::SubOscOct]                  = sub_osc_octave                (payload[offset+37]);

    values[param::MixerOsc1Level]             = mixer_osc1_level              (payload[offset+37], payload[offset+38]);
    values[param::MixerOsc2Level]             = mixer_osc2_level              (payload[offset+38], payload[offset+39]);
    values[param::MixerSubOscLevel]           = mixer_sub_osc_level           (payload[offset+39], payload[offset+40]);
    values[param::MixerNoiseLevel]            = mixer_noise_level             (payload[offset+41], payload[offset+42]);
    values[param::MixerRingModLevel]          = mixer_rm_level                (payload[offset+42], payload[offset+43]);
    values[param::MixerExtLevel]              = mixer_ext_level               (payload[offset+43], payload[offset+44]);

    values[param::FilterFrequency]            = filter_frequency              (payload[offset+44], payload[offset+45]);
    values[param::FilterResonance]            = filter_resonance              (payload[offset+45], payload[offset+46]);
    values[param::FilterOverdrive]            = filter_overdrive              (payload[offset+46], payload[offset+47]);
    values[param::FilterSlope]                = filter_slope                  (payload[offset+48]);
    values[param::FilterType]                 = filter_type                   (payload[offset+48]);
    values[param::FilterShape]                = filter_shape                  (payload[offset+48]);

    values[param::VelocityAmpEnv]             = velocity_amp_env              (payload[offset+49], payload[offset+50]);
    values[param::AmpEnvAttack]               = amp_env_attack                (payload[offset+50], payload[offset+51]);
    values[param::AmpEnvDecay]                = amp_env_decay                 (payload[offset+51], payload[offset+52]);
    values[param::AmpEnvSustain]              = amp_env_sustain               (payload[offset+52], payload[offset+53]);
    values[param::AmpEnvRelease]              = amp_env_release               (payload[offset+53], payload[offset+54]);
    values[param::AmpEnvTriggering]           = amp_env_triggering            (payload[offset+55]);

    values[param::VelocityModEnv]             = velocity_mod_env              (payload[offset+56]);
    values[param::ModEnvAttack]               = mod_env_attack                (payload[offset+57], payload[offset+58]);
    values[param::ModEnvDecay]                = mod_env_decay                 (payload[offset+58], payload[offset+59]);
    values[param::ModEnvSustain]              = mod_env_sustain               (payload[offset+59], payload[offset+60]);
    values[param::ModEnvRelease]              = mod_env_release               (payload[offset+60], payload[offset+62]);
    values[param::ModEnvTriggering]           = mod_env_triggering            (payload[offset+62]);

    values[param::LFO1Wave]                   = lfo1_wave                     (payload[offset+63]);
    values[param::LFO1Delay]                  = lfo1_delay                    (payload[offset+64]);
    values[param::LFO1Slew]                   = lfo1_slew                     (payload[offset+65], payload[offset+66]);
    values[param::LFO1Speed]                  = lfo1_speed                    (payload[offset+66], payload[offset+67]);
    values[param::LFO1SyncValue]              = lfo1_sync_value               (payload[offset+67], payload[offset+68]);
    values[param::LFO1SpeedSync]              = lfo1_speed_sync               (payload[offset+69]);
    values[param::LFO1KeySync]                = lfo1_key_sync                 (payload[offset+69]);

    values[param::LFO2Wave]                   = lfo2_wave                     (payload[offset+70]);
    values[param::LFO2Delay]                  = lfo2_delay                    (payload[offset+70], payload[offset+71]);
    values[param::LFO2Slew]                   = lfo2_slew                     (payload[offset+72]);
    values[param::LFO2Speed]                  = lfo2_speed                    (payload[offset+73], payload[offset+74]);
    values[param::LFO2SyncValue]              = lfo2_sync_value               (payload[offset+74], payload[offset+75]);
    values[param::LFO2SpeedSync]              = lfo2_speed_sync               (payload[offset+76]);
    values[param::LFO2KeySync]                = lfo2_key_sync                 (payload[offset+76]);

    values[param::ArpOn]                      = arp_on                        (payload[offset+77]);
    values[param::ArpSeqRetrig]               = arp_seq_retrig                (payload[offset+77]);
    values[param::ArpOctaves]                 = arp_octaves                   (payload[offset+78]);
    values[param::ArpNoteMode]                = arp_note_mode                 (payload[offset+79]);
    values[param::ArpRhythm]                  = arp_rhythm                    (payload[offset+80]);
    values[param::ArpSwing]                   = arp_swing                     (payload[offset+81], payload[offset+82]);

    values[param::ModWheelFilterFreq]         = mod_wheel_filter_freq         (payload[offset+82], payload[offset+83]);
    values[param::ModWheelLFO1toOscPitch]     = mod_wheel_lfo1_to_osc_pitch   (payload[offset+83], payload[offset+84]);
    values[param::ModWheelLFO2toFilterFreq]   = mod_wheel_lfo2_to_filter_freq (payload[offset+84], payload[offset+85]);
    values[param::ModWheelOsc2Pitch]          = mod_wheel_osc2_pitch          (payload[offset+85], payload[offset+86]);

    values[param::AftertouchFilterFreq]       = aftertouch_filter_freq        (payload[offset+86], payload[offset+87]);
    values[param::AftertouchLFO1toOsc12Pitch] = aftertouch_lfo1_to_osc12_pitch(payload[offset+88]);
    values[param::AftertouchLFO2Speed]        = aftertouch_lfo2_speed         (payload[offset+89], payload[offset+90]);

    values[param::Osc1LFO1Depth]              = osc1_lfo1_depth               (payload[offset+90], payload[offset+91]);
    values[param::Osc2LFO1Depth]              = osc2_lfo1_depth               (payload[offset+91], payload[offset+92]);
    values[param::Osc1LFO2PWMod]              = osc1_lfo2_pw_mod              (payload[offset+93], payload[offset+94]);
    values[param::Osc2LFO2PWMod]              = osc2_lfo2_pw_mod              (payload[offset+94], payload[offset+95]);
    values[param::FilterLFO2Depth]            = filter_lfo2_depth             (payload[offset+97], payload[offset+98]);

    values[param::Osc1ModEnvDepth]            = osc1_mod_env_depth            (payload[offset+98], payload[offset+99]);
    values[param::Osc2ModEnvDepth]            = osc2_mod_env_depth            (payload[offset+99], payload[offset+100]);
    values[param::Osc1ModEnvPWMod]            = osc1_mod_env_pw_mod           (payload[offset+101], payload[offset+102]);
    values[param::Osc2ModEnvPWMod]            = osc2_mod_env_pw_mod           (payload[offset+102], payload[offset+103]);
    values[param::FilterModEnvDepth]          = filter_mod_env_depth          (payload[offset+105], payload[offset+106]);

    values[param::FxOscFilterMod]             = fx_osc_filter_mod             (payload[offset+106], payload[offset+107]);
    values[param::FxDistortion]               = fx_distortion                 (payload[offset+107], payload[offset+108]);
    values[param::VCALimiter]                 = vca_limiter                   (payload[offset+108], payload[offset+109]);

    values[param::Paraphonic]                 = paraphonic                    (payload[offset+111]);
    values[param::FilterTracking]             = filter_tracking               (payload[offset+112]);
    values[param::AmpEnvRetrig]               = amp_env_retrig                (payload[offset+114]);
    values[param::ModEnvRetrig]               = mod_env_retrig                (payload[offset+115]);
    values[param::TuningTable]                = tuning_table                  (payload[offset+115], payload[offset+116]);
    values[param::OscError]                   = osc_error                     (payload[offset+117]);

    std::string patchname                     = patch_name                    (sysex_payload(payload.begin()+137, payload.begin()+152));

    return values;
}

}
