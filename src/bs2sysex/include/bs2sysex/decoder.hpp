#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include "param.hpp"

namespace bs2sysex
{
using value = std::uint8_t;
using sysex_payload = std::vector<std::uint8_t>;

std::map<param, value> decode(const sysex_payload& payload);
std::map<param, value> decode(const sysex_payload& payload, int offset);
std::string decodePatchName(const sysex_payload& payload);
}
