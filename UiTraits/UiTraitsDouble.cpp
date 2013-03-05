#include "UiTraitsDouble.h"
#include <iomanip>
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
std::string TCUiTraitsDouble::GetString(double Value) const
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
std::string TCUiTraitsDouble::GetDoubleAsString(double Value) const
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

  if (mInternalToUiScale)
  {
    Value *= *mInternalToUiScale;
  }

  Stream << Value;

  return Stream.str();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCUiTraitsDouble::TCUiTraitsDouble(
  const std::string& Label,
  const std::string& UiUnits,
  const boost::optional<unsigned>& UiDigitsAfterDecimal,
  const boost::optional<double>&  InternalToUiScale)
  : mLabel(Label),
    mUiUnits(UiUnits),
    mUiDigitsAfterDecimal(UiDigitsAfterDecimal),
    mInternalToUiScale(InternalToUiScale)
{
}
