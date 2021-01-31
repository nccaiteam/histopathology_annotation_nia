#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "core" for configuration "Release"
set_property(TARGET core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(core PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/core.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/core.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS core )
list(APPEND _IMPORT_CHECK_FILES_FOR_core "${_IMPORT_PREFIX}/lib/core.lib" "${_IMPORT_PREFIX}/bin/core.dll" )

# Import target "multiresolutionimageinterface" for configuration "Release"
set_property(TARGET multiresolutionimageinterface APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(multiresolutionimageinterface PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/multiresolutionimageinterface.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "jpeg2kcodec"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/multiresolutionimageinterface.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS multiresolutionimageinterface )
list(APPEND _IMPORT_CHECK_FILES_FOR_multiresolutionimageinterface "${_IMPORT_PREFIX}/lib/multiresolutionimageinterface.lib" "${_IMPORT_PREFIX}/bin/multiresolutionimageinterface.dll" )

# Import target "jpeg2kcodec" for configuration "Release"
set_property(TARGET jpeg2kcodec APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(jpeg2kcodec PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/jpeg2kcodec.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "openjp2"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/jpeg2kcodec.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS jpeg2kcodec )
list(APPEND _IMPORT_CHECK_FILES_FOR_jpeg2kcodec "${_IMPORT_PREFIX}/lib/jpeg2kcodec.lib" "${_IMPORT_PREFIX}/bin/jpeg2kcodec.dll" )

# Import target "openslidefileformat" for configuration "Release"
set_property(TARGET openslidefileformat APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(openslidefileformat PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/openslidefileformat.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "core"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "multiresolutionimageinterface"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/formats/openslidefileformat.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS openslidefileformat )
list(APPEND _IMPORT_CHECK_FILES_FOR_openslidefileformat "${_IMPORT_PREFIX}/lib/openslidefileformat.lib" "${_IMPORT_PREFIX}/bin/formats/openslidefileformat.dll" )

# Import target "annotation" for configuration "Release"
set_property(TARGET annotation APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(annotation PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/annotation.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "multiresolutionimageinterface"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/annotation.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS annotation )
list(APPEND _IMPORT_CHECK_FILES_FOR_annotation "${_IMPORT_PREFIX}/lib/annotation.lib" "${_IMPORT_PREFIX}/bin/annotation.dll" )

# Import target "basicfilters" for configuration "Release"
set_property(TARGET basicfilters APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(basicfilters PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/basicfilters.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "core"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/basicfilters.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS basicfilters )
list(APPEND _IMPORT_CHECK_FILES_FOR_basicfilters "${_IMPORT_PREFIX}/lib/basicfilters.lib" "${_IMPORT_PREFIX}/bin/basicfilters.dll" )

# Import target "FRST" for configuration "Release"
set_property(TARGET FRST APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(FRST PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/FRST.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio;opencv_world"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/FRST.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS FRST )
list(APPEND _IMPORT_CHECK_FILES_FOR_FRST "${_IMPORT_PREFIX}/lib/FRST.lib" "${_IMPORT_PREFIX}/bin/FRST.dll" )

# Import target "wholeslidefilters" for configuration "Release"
set_property(TARGET wholeslidefilters APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(wholeslidefilters PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/wholeslidefilters.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio;opencv_world;annotation;FRST;basicfilters;multiresolutionimageinterface"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE ""
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/wholeslidefilters.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS wholeslidefilters )
list(APPEND _IMPORT_CHECK_FILES_FOR_wholeslidefilters "${_IMPORT_PREFIX}/lib/wholeslidefilters.lib" "${_IMPORT_PREFIX}/bin/wholeslidefilters.dll" )

# Import target "ASAP" for configuration "Release"
set_property(TARGET ASAP APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ASAP PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ASAP.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS ASAP )
list(APPEND _IMPORT_CHECK_FILES_FOR_ASAP "${_IMPORT_PREFIX}/bin/ASAP.exe" )

# Import target "ASAPLib" for configuration "Release"
set_property(TARGET ASAPLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(ASAPLib PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/ASAPLib.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "multiresolutionimageinterface;Qt5::Widgets;Qt5::Core;Qt5::OpenGL"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "basicfilters"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/ASAPLib.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ASAPLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_ASAPLib "${_IMPORT_PREFIX}/lib/ASAPLib.lib" "${_IMPORT_PREFIX}/bin/ASAPLib.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
