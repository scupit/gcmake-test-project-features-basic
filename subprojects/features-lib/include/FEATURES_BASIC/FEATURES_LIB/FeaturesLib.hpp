#ifndef H_FEATURES_LIB_FEATURESLIB
#define H_FEATURES_LIB_FEATURESLIB

#include <string>
#include <vector>

#include "FEATURES_BASIC/FEATURES_LIB/features-lib_export.h"

FEATURES_LIB_EXPORT std::vector<std::string> enabledFeatures();
FEATURES_LIB_EXPORT void printEnabledFeatures();

#endif
