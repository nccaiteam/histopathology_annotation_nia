#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "core" for configuration "Debug"
set_property(TARGET core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(core PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/core_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/core_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS core )
list(APPEND _IMPORT_CHECK_FILES_FOR_core "${_IMPORT_PREFIX}/lib/core_d.lib" "${_IMPORT_PREFIX}/bin/core_d.dll" )

# Import target "multiresolutionimageinterface" for configuration "Debug"
set_property(TARGET multiresolutionimageinterface APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(multiresolutionimageinterface PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/multiresolutionimageinterface_d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "jpeg2kcodec"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/multiresolutionimageinterface_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS multiresolutionimageinterface )
list(APPEND _IMPORT_CHECK_FILES_FOR_multiresolutionimageinterface "${_IMPORT_PREFIX}/lib/multiresolutionimageinterface_d.lib" "${_IMPORT_PREFIX}/bin/multiresolutionimageinterface_d.dll" )

# Import target "jpeg2kcodec" for configuration "Debug"
set_property(TARGET jpeg2kcodec APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(jpeg2kcodec PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/jpeg2kcodec_d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "openjp2"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/jpeg2kcodec_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS jpeg2kcodec )
list(APPEND _IMPORT_CHECK_FILES_FOR_jpeg2kcodec "${_IMPORT_PREFIX}/lib/jpeg2kcodec_d.lib" "${_IMPORT_PREFIX}/bin/jpeg2kcodec_d.dll" )

# Import target "openslidefileformat" for configuration "Debug"
set_property(TARGET openslidefileformat APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(openslidefileformat PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/openslidefileformat_d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "core"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "multiresolutionimageinterface"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/formats/openslidefileformat_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS openslidefileformat )
list(APPEND _IMPORT_CHECK_FILES_FOR_openslidefileformat "${_IMPORT_PREFIX}/lib/openslidefileformat_d.lib" "${_IMPORT_PREFIX}/bin/formats/openslidefileformat_d.dll" )

# Import target "annotation" for configuration "Debug"
set_property(TARGET annotation APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(annotation PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/annotation_d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "multiresolutionimageinterface"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/annotation_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS annotation )
list(APPEND _IMPORT_CHECK_FILES_FOR_annotation "${_IMPORT_PREFIX}/lib/annotation_d.lib" "${_IMPORT_PREFIX}/bin/annotation_d.dll" )

# Import target "basicfilters" for configuration "Debug"
set_property(TARGET basicfilters APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(basicfilters PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/basicfilters_d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "core"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/basicfilters_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS basicfilters )
list(APPEND _IMPORT_CHECK_FILES_FOR_basicfilters "${_IMPORT_PREFIX}/lib/basicfilters_d.lib" "${_IMPORT_PREFIX}/bin/basicfilters_d.dll" )

# Import target "FRST" for configuration "Debug"
set_property(TARGET FRST APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(FRST PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/FRST_d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio;opencv_world"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/FRST_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS FRST )
list(APPEND _IMPORT_CHECK_FILES_FOR_FRST "${_IMPORT_PREFIX}/lib/FRST_d.lib" "${_IMPORT_PREFIX}/bin/FRST_d.dll" )

# Import target "wholeslidefilters" for configuration "Debug"
set_property(TARGET wholeslidefilters APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(wholeslidefilters PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/wholeslidefilters_d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio;opencv_world;annotation;FRST;basicfilters;multiresolutionimageinterface"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/wholeslidefilters_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS wholeslidefilters )
list(APPEND _IMPORT_CHECK_FILES_FOR_wholeslidefilters "${_IMPORT_PREFIX}/lib/wholeslidefilters_d.lib" "${_IMPORT_PREFIX}/bin/wholeslidefilters_d.dll" )

# Import target "ASAP" for configuration "Debug"
set_property(TARGET ASAP APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ASAP PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/ASAP_d.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS ASAP )
list(APPEND _IMPORT_CHECK_FILES_FOR_ASAP "${_IMPORT_PREFIX}/bin/ASAP_d.exe" )

# Import target "ASAPLib" for configuration "Debug"
set_property(TARGET ASAPLib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(ASAPLib PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/ASAPLib_d.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "multiresolutionimageinterface;Qt5::Widgets;Qt5::Core;Qt5::OpenGL"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "basicfilters"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/ASAPLib_d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS ASAPLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_ASAPLib "${_IMPORT_PREFIX}/lib/ASAPLib_d.lib" "${_IMPORT_PREFIX}/bin/ASAPLib_d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
