#include "IoTraitsDouble.h"
#include <iostream>

using std::ostream;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
TCIoTraitsDouble::TCIoTraitsDouble(
  TEEncoding Encoding,
  double Scale,
  double Translate)
  : mEncoding(Encoding),
    mScale(Scale),
    mTranslate(Translate)
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TCIoTraitsDouble::Write(double Value_, ostream& Stream) const
{
  const double Value = mScale * (Value - mTranslate);

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
