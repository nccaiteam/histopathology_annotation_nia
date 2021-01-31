# Install script for directory: C:/ASAP-1.9/src/buildtools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:\ASAP-1.9\install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES
    "C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Redist/MSVC/14.16.27012/x64/Microsoft.VC141.CRT/msvcp140.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Redist/MSVC/14.16.27012/x64/Microsoft.VC141.CRT/msvcp140_1.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Redist/MSVC/14.16.27012/x64/Microsoft.VC141.CRT/msvcp140_2.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Redist/MSVC/14.16.27012/x64/Microsoft.VC141.CRT/vcruntime140.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Redist/MSVC/14.16.27012/x64/Microsoft.VC141.CRT/concrt140.dll"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE DIRECTORY FILES "")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/platforms" TYPE FILE FILES "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../plugins/platforms/qwindows.dll")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/platforms" TYPE FILE FILES "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../plugins/platforms/qwindowsd.dll")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../bin/libEGL.dll")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../bin/libEGLd.dll")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../bin/d3dcompiler_47.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../bin/Qt5OpenGL.dll")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../bin/Qt5OpenGLd.dll")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
   include(BundleUtilities)
   if("${CMAKE_INSTALL_CONFIG_NAME}" STREQUAL "Debug")
   fixup_bundle("${CMAKE_INSTALL_PREFIX}/bin/ASAP_d.exe"   "${CMAKE_INSTALL_PREFIX}/bin/libEGLd.dll;${CMAKE_INSTALL_PREFIX}/bin/Qt5OpenGLd.dll;${CMAKE_INSTALL_PREFIX}/bin/plugins/filters/NucleiDetectionFilterPlugin_d.dll;${CMAKE_INSTALL_PREFIX}/bin/formats/openslidefileformat_d.dll"   "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../bin;C:/ASAP-1.9/libs/opencv-4.5.1-vc14_vc15/opencv/build/x64/vc15/bin;C:\ASAP-1.9\libs\openslide-win64-20171122\openslide-win64-20171122\include\openslide/../../bin;/../bin;/../bin;C:/ASAP-1.9/libs/boost_1_67_0/lib64-msvc-14.1")
   else()
   fixup_bundle("${CMAKE_INSTALL_PREFIX}/bin/ASAP.exe"   "${CMAKE_INSTALL_PREFIX}/bin/libEGL.dll;${CMAKE_INSTALL_PREFIX}/bin/Qt5OpenGL.dll;${CMAKE_INSTALL_PREFIX}/bin/plugins/filters/NucleiDetectionFilterPlugin.dll;${CMAKE_INSTALL_PREFIX}/bin/formats/openslidefileformat.dll"   "C:\ASAP-1.9\libs\Qt\5.14.2\msvc2017_64\lib\cmake\Qt5/../../../bin;C:/ASAP-1.9/libs/opencv-4.5.1-vc14_vc15/opencv/build/x64/vc15/bin;C:\ASAP-1.9\libs\openslide-win64-20171122\openslide-win64-20171122\include\openslide/../../bin;/../bin;/../bin;C:/ASAP-1.9/libs/boost_1_67_0/lib64-msvc-14.1")
   endif()
   
endif()

