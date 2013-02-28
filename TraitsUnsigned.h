#pragma once

#include <string>

//-----------------------------------------------------------------------------
// This class describes characteristics an unsigned parameter has
//-----------------------------------------------------------------------------
class TCTraitsUnsigned
{
  public:

    typedef unsigned TDType;

    TCTraitsUnsigned(
      const std::string& Label,
      const std::string& UiUnits = std::string());

    std::string mLabel;

    std::string mUiUnits;

    std::string GetString(unsigned Value) const;
};
