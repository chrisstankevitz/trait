#include "UiTraitsUnsigned.h"
#include <sstream>

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCUiTraitsUnsigned::TCUiTraitsUnsigned(
  const std::string& Label,
  const std::string& UiUnits)
  : mLabel(Label),
    mUiUnits(UiUnits)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
std::string TCUiTraitsUnsigned::GetString(unsigned Value) const
{
  std::ostringstream Stream;

  Stream << mLabel << " = ";

  Stream << Value;

  if (!mUiUnits.empty())
  {
    Stream << " (" << mUiUnits << ")";
  }

  return Stream.str();
}
