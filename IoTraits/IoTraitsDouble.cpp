#include "IoTraitsDouble.h"
#include <iostream>

using std::istream;
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
    Value += *mTranslateToEncode;
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

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TCIoTraitsDouble::Read(double& Value, istream& Stream) const
{
  switch (mEncoding)
  {
    case eFloat64BigEndian:
    {
      Stream.read(reinterpret_cast<char*>(&Value), 8);

      break;
    }

    case eUint32BigEndian:
    {
      unsigned ValueAsUnsigned;

      Stream.read(reinterpret_cast<char*>(&ValueAsUnsigned), 4);

      Value = static_cast<double>(ValueAsUnsigned);

      break;
    }
  }

  if (mScaleToEncode)
  {
    Value /= *mScaleToEncode;
  }

  if (mTranslateToEncode)
  {
    Value -= *mTranslateToEncode;
  }

}
