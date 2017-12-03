#include "decoder.h"


value_map decoder::decode(const data_t& payload)
{
    return decode(payload, 0);
}


value_map decoder::decode(const data_t& payload, int offset)
{
    value_map values;

    values[EParam::PatchNumber]       = patch_number        (payload[offset+9]);
    values[EParam::PortamentoTime]    = portamento_time     (payload[offset+13], payload[offset+14]);

    values[EParam::OscPitchBendRange] = osc_pitch_bend_range(payload[offset+16]);
    values[EParam::OscSync]           = osc_sync            (payload[offset+18]);

    values[EParam::Osc1Waveform]      = osc1_waveform       (payload[offset+19]);
    values[EParam::Osc1ManualPW]      = osc1_manual_pw      (payload[offset+19], payload[offset+20]);
    values[EParam::Osc1Range]         = osc1_range          (payload[offset+20], payload[offset+21]);
    values[EParam::Osc1Coarse]        = osc1_coarse         (payload[offset+21], payload[offset+22]);
    values[EParam::Osc1Fine]          = osc1_fine           (payload[offset+22], payload[offset+23]);

    values[EParam::Osc2Waveform]      = osc2_waveform       (payload[offset+24]);
    values[EParam::Osc2ManualPW]      = osc2_manual_pw      (payload[offset+25], payload[offset+26]);
    values[EParam::Osc2Range]         = osc2_range          (payload[offset+26], payload[offset+27]);
    values[EParam::Osc2Coarse]        = osc2_coarse         (payload[offset+27], payload[offset+28]);
    values[EParam::Osc2Fine]          = osc2_fine           (payload[offset+28], payload[offset+29]);

    values[EParam::SubOscWave]        = sub_osc_waveform    (payload[offset+36]);
    values[EParam::SubOscOct]         = sub_osc_octave      (payload[offset+37]);

    values[EParam::MixerOsc1Level]    = mixer_osc1_level    (payload[offset+37], payload[offset+38]);
    values[EParam::MixerOsc2Level]    = mixer_osc2_level    (payload[offset+38], payload[offset+39]);
    values[EParam::MixerSubOscLevel]  = mixer_sub_osc_level (payload[offset+39], payload[offset+40]);
    values[EParam::MixerNoiseLevel]   = mixer_noise_level   (payload[offset+41], payload[offset+42]);
    values[EParam::MixerRingModLevel] = mixer_rm_level      (payload[offset+42], payload[offset+43]);
    values[EParam::MixerExtLevel]     = mixer_ext_level     (payload[offset+43], payload[offset+44]);

    values[EParam::FilterFrequency]   = filter_frequency    (payload[offset+44], payload[offset+45]);
    values[EParam::FilterResonance]   = filter_resonance    (payload[offset+45], payload[offset+46]);
    values[EParam::FilterOverdrive]   = filter_overdrive    (payload[offset+46], payload[offset+47]);

    return values;
}

uint8 decoder::patch_number(const uint8& msb)
{
    return msb & 0b01111111;
}

uint8 decoder::portamento_time(const uint8& msb, const uint8& lsb)
{
    return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2);
}


uint8 decoder::osc_pitch_bend_range(const uint8& msb)
{
    return msb & 0b01111111;
}

uint8 decoder::osc_sync(const uint8& msb)
{
    return msb & 0b01000000 >> 6;
}


uint8 decoder::osc1_waveform(const uint8& msb)
{
    return msb & 0b01100000 >> 5;
}

uint8 decoder::osc1_manual_pw(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00001111) << 3) + ((lsb & 0b01110000) >> 4);
}

uint8 decoder::osc1_range(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00000111) << 4) + ((lsb & 0b01111000) >> 3);
}

uint8 decoder::osc1_coarse(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00000111) << 5) + ((lsb & 0b01111100) >> 2);
}

uint8 decoder::osc1_fine(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00000011) << 6) + ((lsb & 0b01111110) >> 1);
}


uint8 decoder::osc2_waveform(const uint8& msb)
{
    return msb & 0b00000011;
}

uint8 decoder::osc2_manual_pw(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00111111) << 1) + ((lsb & 0b01000000) >> 6);
}

uint8 decoder::osc2_range(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00011111) << 2) + ((lsb & 0b01100000) >> 5);
}

uint8 decoder::osc2_coarse(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00011111) << 3) + ((lsb & 0b01110000) >> 4);
}

uint8 decoder::osc2_fine(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0b00001111) << 4) + ((lsb & 0b01111000) >> 3);
}


uint8 decoder::sub_osc_waveform(const uint8& msb)
{
    return msb & 0b00110000 >> 4;
}

uint8 decoder::sub_osc_octave(const uint8& msb)
{
    return msb & 0b00001000 >> 3;
}


uint8 decoder::mixer_osc1_level(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0) << 0) + ((lsb & 0) >> 0);
}

uint8 decoder::mixer_osc2_level(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0) << 0) + ((lsb & 0) >> 0);
}

uint8 decoder::mixer_sub_osc_level(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0) << 0) + ((lsb & 0) >> 0);
}

uint8 decoder::mixer_noise_level(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0) << 0) + ((lsb & 0) >> 0);
}

uint8 decoder::mixer_rm_level(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0) << 0) + ((lsb & 0) >> 0);
}

uint8 decoder::mixer_ext_level(const uint8 &msb, const uint8 &lsb)
{
    return ((msb & 0) << 0) + ((lsb & 0) >> 0);
}


uint8 decoder::filter_frequency(const uint8& msb, const uint8& lsb)
{
    return ((msb & 0b00001111) << 4) + ((lsb & 0b01111000) >> 3);
}

uint8 decoder::filter_resonance(const uint8& msb, const uint8& lsb)
{
    return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2);
}

uint8 decoder::filter_overdrive(const uint8& msb, const uint8& lsb)
{
    return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1);
}

