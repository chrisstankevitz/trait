#include "IoTraitsUnsigned.h"
#include <iostream>

using std::ostream;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCIoTraitsUnsigned::TCIoTraitsUnsigned(
  TEEncoding Encoding,
  unsigned ScaleToEncode,
  unsigned TranslateToEncode)
  : mEncoding(Encoding),
    mScaleToEncode(ScaleToEncode),
    mTranslateToEncode(TranslateToEncode)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TCIoTraitsUnsigned::Write(unsigned Value, ostream& Stream) const
{
  Value -= mTranslateToEncode;

  Value *= mScaleToEncode;

  switch (mEncoding)
  {
    case eUint32BigEndian:
    {
      Stream.write(reinterpret_cast<const char*>(&Value), 4);

      break;
    }
  }
}
