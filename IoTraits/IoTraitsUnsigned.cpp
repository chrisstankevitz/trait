#include "IoTraitsUnsigned.h"
#include <iostream>

using std::ostream;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCIoTraitsUnsigned::TCIoTraitsUnsigned(
  TEEncoding Encoding,
  unsigned Scale,
  unsigned Translate)
  : mEncoding(Encoding),
    mScale(Scale),
    mTranslate(Translate)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TCIoTraitsUnsigned::Write(unsigned Value_, ostream& Stream) const
{
  const unsigned Value = mScale * (Value - mTranslate);

  switch (mEncoding)
  {
    case eUint32BigEndian:
    {
      Stream.write(reinterpret_cast<const char*>(&Value), 4);

      break;
    }
  }
}
