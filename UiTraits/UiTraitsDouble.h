#pragma once

#include <boost/optional.hpp>
#include <string>

//-----------------------------------------------------------------------------
// This class describes characteristics a double parameter has
//-----------------------------------------------------------------------------
class TCUiTraitsDouble
{
  public:

    typedef double TDType;

    typedef boost::optional<unsigned> TDOptUint32;

    typedef boost::optional<double> TDOptFloat64;

    TCUiTraitsDouble(
      const std::string& Label,
      const std::string& UiUnits = std::string(),
      const TDOptUint32& UiDigitsAfterDecimal = TDOptUint32(),
      const TDOptFloat64& InternalToUiScale = TDOptFloat64());

    std::string mLabel;

    std::string mUiUnits;

    boost::optional<unsigned> mUiDigitsAfterDecimal;

    boost::optional<double> mInternalToUiScale;

    std::string GetString(double Value) const;

  private:

    std::string GetDoubleAsString(double Value) const;
};
