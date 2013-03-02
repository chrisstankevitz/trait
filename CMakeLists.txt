CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Traits)

IF(CMAKE_COMPILER_IS_GNUCC)
  ADD_DEFINITIONS(-Wall -std=c++0x)
ENDIF(CMAKE_COMPILER_IS_GNUCC)

ADD_LIBRARY(Traits
  TraitsDouble.cpp
  TraitsPrinter.cpp
  TraitsUnsigned.cpp
  Traitses.cpp
  )

TARGET_LINK_LIBRARIES(Traits
  )

ADD_LIBRARY(Position
  Position.cpp
  PositionUiTraits.cpp
  )

TARGET_LINK_LIBRARIES(Position
  Traits
  )

ADD_EXECUTABLE(TraitsDemo
  TraitsDemo.cpp
  )

TARGET_LINK_LIBRARIES(TraitsDemo
  Position
  Traits
  )
