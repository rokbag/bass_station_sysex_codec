#pragma once

#include <vector>
#include <map>
#include "param.hpp"

namespace bs2sysex
{
using value = std::uint8_t;
using sysex_payload = std::vector<std::uint8_t>;

std::map<param, value> decode(const sysex_payload& payload);
std::map<param, value> decode(const sysex_payload& payload, int offset);
}
