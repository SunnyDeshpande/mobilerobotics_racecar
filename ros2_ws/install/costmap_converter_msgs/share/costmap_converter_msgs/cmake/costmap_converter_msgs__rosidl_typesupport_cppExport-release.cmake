#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "costmap_converter_msgs::costmap_converter_msgs__rosidl_typesupport_cpp" for configuration "Release"
set_property(TARGET costmap_converter_msgs::costmap_converter_msgs__rosidl_typesupport_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(costmap_converter_msgs::costmap_converter_msgs__rosidl_typesupport_cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libcostmap_converter_msgs__rosidl_typesupport_cpp.so"
  IMPORTED_SONAME_RELEASE "libcostmap_converter_msgs__rosidl_typesupport_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS costmap_converter_msgs::costmap_converter_msgs__rosidl_typesupport_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_costmap_converter_msgs::costmap_converter_msgs__rosidl_typesupport_cpp "${_IMPORT_PREFIX}/lib/libcostmap_converter_msgs__rosidl_typesupport_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
