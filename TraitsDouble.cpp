#include "TraitsDouble.h"
#include <iomanip>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
std::string TCTraitsDouble::GetString(double Value) const
{
  std::string Return = mLabel;

  Return.append(" = ");

  Return.append(GetDoubleAsString(Value));

  if (!mUiUnits.empty())
  {
    Return.append(" (");
    Return.append(mUiUnits);
    Return.append(")");
  }

  return Return;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
std::string TCTraitsDouble::GetDoubleAsString(double Value) const
{
  if (Value != Value)
  {
    return "NaN";
  }

  std::ostringstream Stream;

  if (mUiDigitsAfterDecimal)
  {
    Stream
      << std::fixed
      << std::setprecision(*mUiDigitsAfterDecimal);
  }

  Stream << Value * mInternalToUiScale;

  return Stream.str();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCTraitsDouble::TCTraitsDouble(
  const std::string& Label,
  const std::string& UiUnits,
  const boost::optional<unsigned>& UiDigitsAfterDecimal,
  double InternalToUiScale)
  : mLabel(Label),
    mUiUnits(UiUnits),
    mUiDigitsAfterDecimal(UiDigitsAfterDecimal),
    mInternalToUiScale(InternalToUiScale)
{
}
