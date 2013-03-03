#include "IoTraitsDouble.h"
#include <iostream>

using std::ostream;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCIoTraitsDouble::TCIoTraitsDouble(
  TEEncoding Encoding,
  TDOptional ScaleToEncode,
  TDOptional TranslateToEncode)
  : mEncoding(Encoding),
    mScaleToEncode(ScaleToEncode),
    mTranslateToEncode(TranslateToEncode)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TCIoTraitsDouble::Write(double Value, ostream& Stream) const
{
  if (mTranslateToEncode)
  {
    Value -= *mTranslateToEncode;
  }

  if (mScaleToEncode)
  {
    Value *= *mScaleToEncode;
  }

  switch (mEncoding)
  {
    case eFloat64BigEndian:
    {
      Stream.write(reinterpret_cast<const char*>(&Value), 8);

      break;
    }

    case eUint32BigEndian:
    {
      unsigned ValueAsUnsigned = static_cast<unsigned>(Value);

      Stream.write(reinterpret_cast<const char*>(&ValueAsUnsigned), 4);

      break;
    }
  }
}
