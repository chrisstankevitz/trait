#pragma once

#include <boost/optional.hpp>
#include <string>

//-----------------------------------------------------------------------------
// This class describes characteristics a double parameter has
//-----------------------------------------------------------------------------
class TCTraitsDouble
{
  public:

    typedef double TDType;

    TCTraitsDouble(
      const std::string& Label,
      const std::string& UiUnits = std::string(),
      const boost::optional<unsigned>& UiDigitsAfterDecimal =
        boost::optional<unsigned>(),
      double InternalToUiScale = 1);

    std::string mLabel;

    std::string mUiUnits;

    boost::optional<unsigned> mUiDigitsAfterDecimal;

    double mInternalToUiScale;

    std::string GetString(double Value) const;

  private:

    std::string GetDoubleAsString(double Value) const;
};
