#include "decoder.h"

value_map_type decoder::decode(const data_t& payload, int offset)
{
    value_map_type value_map;
    value_map[EParam::FilterFrequency] = decode_filter_frequency(payload[offset+44], payload[offset+45]);
    value_map[EParam::FilterResonance] = decode_filter_resonance(payload[offset+45], payload[offset+46]);
    value_map[EParam::FilterOverdrive] = decode_filter_overdrive(payload[offset+46], payload[offset+47]);
    return value_map;
}

uint8 decoder::decode_filter_frequency(const uint8& msb, const uint8& lsb)
{
    return ((msb & 0b00001111) << 4) + ((lsb & 0b01111000) >> 3);
}

uint8 decoder::decode_filter_resonance(const uint8& msb, const uint8& lsb)
{
    return ((msb & 0b00000011) << 5) + ((lsb & 0b01111100) >> 2);
}

uint8 decoder::decode_filter_overdrive(const uint8& msb, const uint8& lsb)
{
    return ((msb & 0b00000001) << 6) + ((lsb & 0b01111110) >> 1);
}

