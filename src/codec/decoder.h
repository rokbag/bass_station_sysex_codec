#pragma once
#include "util/types.h"

class decoder
{
public:
    value_map_type decode(const data_t &payload, int offset);

protected:
    uint8 decode_filter_frequency(const uint8 &msb, const uint8 &lsb);
    uint8 decode_filter_resonance(const uint8 &msb, const uint8 &lsb);
    uint8 decode_filter_overdrive(const uint8 &msb, const uint8 &lsb);
};
