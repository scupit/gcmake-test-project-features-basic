#include "FEATURES_BASIC/FEATURES_LIB/FeaturesLib.hpp"

#if IS_FMT_ENABLED
  #include "fmt/core.h"
#else
  #include <iostream>
#endif

#include <map>

std::vector<std::string> enabledFeatures() {
  std::vector<std::string> enabledSubset;

  #if IS_FMT_ENABLED
    enabledSubset.push_back("fmt");
  #endif

  #if IS_FIRST_ONE_ENABLED
    enabledSubset.push_back("first-one");
  #endif

  #if IS_SECOND_ONE_ENABLED
    enabledSubset.push_back("second-one");
  #endif

  return enabledSubset;
}

void printEnabledFeatures() {
  #if IS_FMT_ENABLED
    fmt::print("Printed with fmt.\nEnabled features:\n");
  #else
    std::cout << "Printed with cout.\nEnabled features:\n";
  #endif

  for (const auto& featureName : enabledFeatures()) {
    #if IS_FMT_ENABLED
      fmt::print("\t- {}\n", featureName);
    #else
      std::cout << "\t- " << featureName << '\n';
    #endif
  }
}

static const char* yesNo(const bool b) {
  return b ? "yes" : "no";
}

void printLanguageFeatures() {
  const std::map<int, bool> standardChecks {
    {17, USING_AT_LEAST_CPP_17},
    {20, USING_AT_LEAST_CPP_20}
  };

  for (const auto& [standard, isInUse] : standardChecks) {
    #if IS_FMT_ENABLED
      fmt::print("Is at least C++{} in use?: {}\n", standard, yesNo(isInUse));
    #else
      std::cout << "Is at least C++" << standard << " in use?: " << yesNo(isInUse) << '\n';
    #endif
  }
}
