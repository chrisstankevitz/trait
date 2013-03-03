#pragma once

#include <string>

//-----------------------------------------------------------------------------
// This class describes characteristics an unsigned parameter has
//-----------------------------------------------------------------------------
class TCUiTraitsUnsigned
{
  public:

    typedef unsigned TDType;

    TCUiTraitsUnsigned(
      const std::string& Label,
      const std::string& UiUnits = std::string());

    std::string mLabel;

    std::string mUiUnits;

    std::string GetString(unsigned Value) const;
};
