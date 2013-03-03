CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Traits)

IF(CMAKE_COMPILER_IS_GNUCC)
  ADD_DEFINITIONS(-Wall -std=c++0x)
ENDIF(CMAKE_COMPILER_IS_GNUCC)

INCLUDE_DIRECTORIES(".")

ADD_LIBRARY(IoTraits
  IoTraits/IoTraitsDouble.cpp
  IoTraits/IoTraitsStreamer.cpp
  IoTraits/IoTraitsUnsigned.cpp
  )

ADD_LIBRARY(Traits
  Traits/Traitses.cpp
  )

TARGET_LINK_LIBRARIES(Traits
  Utility
  )

ADD_LIBRARY(UiTraits
  UiTraits/UiTraitsDouble.cpp
  UiTraits/UiTraitsPrinter.cpp
  UiTraits/UiTraitsUnsigned.cpp
  )

ADD_LIBRARY(Utility
  Utility/WrappingVariantMaker.cpp
  )

ADD_LIBRARY(Position
  Position/Position.cpp
  Position/PositionIoTraits.cpp
  Position/PositionUiTraits.cpp
  )

TARGET_LINK_LIBRARIES(Position
  IoTraits
  Traits
  UiTraits
  )

ADD_EXECUTABLE(TraitsDemo
  Utilities/TraitsDemo.cpp
  )

TARGET_LINK_LIBRARIES(TraitsDemo
  IoTraits
  Position
  UiTraits
  )
