#pragma once
#include <string>

const int kNumDegrees{ 4 };
enum class DegreeType { SECURITY, NETWORK, SOFTWARE, BASKETWEAVING };
static std::string DegreeNames[kNumDegrees] = { "SECURITY", "NETWORK",
										"SOFTWARE", "BASKETWEAVING" };