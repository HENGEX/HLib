#requires the same version of cmake that is using ROOT
#Author Omar.Zapata@cern.ch 2017 CMS-UdeA

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(HLib)


file( WRITE  "${CMAKE_BINARY_DIR}/thishlib.sh" "")
  
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "if [ -n \"$ROOT_LIBRARY_PATH\" ] ; then\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport ROOT_LIBRARY_PATH=$ROOT_LIBRARY_PATH:${CMAKE_BINARY_DIR}/\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "else\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport ROOT_LIBRARY_PATH=${CMAKE_BINARY_DIR}/\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "fi\n")
 
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "if [ -n \"$LD_LIBRARY_PATH\" ] ; then\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${CMAKE_BINARY_DIR}/\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "else\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport LD_LIBRARY_PATH=${CMAKE_BINARY_DIR}/\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "fi\n")
   
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "if [ -n \"$ROOT_INCLUDE_PATH\" ] ; then\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:${CMAKE_SOURCE_DIR}/include\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "else\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport ROOT_INCLUDE_PATH=${CMAKE_SOURCE_DIR}/include\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "fi\n")

file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "if [ -n \"$PYTHONPATH\" ] ; then\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport PYTHONPATH=$PYTHONPATH:${CMAKE_SOURCE_DIR}/python\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "else\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh" "\texport PYTHONPATH=${CMAKE_SOURCE_DIR}/include\n")
file( APPEND "${CMAKE_BINARY_DIR}/thishlib.sh"  "fi\n")

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

find_package(ROOT REQUIRED COMPONENTS RIO Gui Core RIO Net Hist Graf Graf3d Gpad Tree TreePlayer Rint Postscript Matrix Physics MathCore Thread )

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
ROOT_GENERATE_DICTIONARY(G__HarryPlotter ${CMAKE_CURRENT_SOURCE_DIR}/include/Plotter.h LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/include/LinkDef.h)

#---Create a shared library with geneated dictionary
add_library(HarryPlotter SHARED src/Plotter.cxx G__HarryPlotter.cxx)
target_link_libraries(HarryPlotter ${ROOT_LIBRARIES})

