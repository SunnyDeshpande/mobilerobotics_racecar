// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from zed_interfaces:msg/BoundingBox3D.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/bounding_box3_d__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "zed_interfaces/msg/detail/bounding_box3_d__struct.hpp"

#include <limits>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cstring>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
#include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions
namespace zed_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const zed_interfaces::msg::Keypoint3D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  zed_interfaces::msg::Keypoint3D &);

size_t get_serialized_size(
  const zed_interfaces::msg::Keypoint3D &,
  size_t current_alignment);

size_t
max_serialized_size_Keypoint3D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace zed_interfaces


namespace zed_interfaces
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_serialize(
  const zed_interfaces::msg::BoundingBox3D & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: corners
  {
    // Micro CDR only support arrays of basic types.
  }

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_deserialize(
  ucdrBuffer * cdr,
  zed_interfaces::msg::BoundingBox3D & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: corners
  {
    // Micro CDR only support arrays of basic types.
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
get_serialized_size(
  const zed_interfaces::msg::BoundingBox3D & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: corners
  {
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
max_serialized_size_BoundingBox3D(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: corners
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static bool _BoundingBox3D__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::BoundingBox3D *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BoundingBox3D__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<zed_interfaces::msg::BoundingBox3D *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BoundingBox3D__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::BoundingBox3D *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BoundingBox3D__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::BoundingBox3D *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _BoundingBox3D__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_BoundingBox3D(&full_bounded, 0);
}

static message_type_support_callbacks_t _BoundingBox3D__callbacks = {
  "zed_interfaces::msg",
  "BoundingBox3D",
  _BoundingBox3D__cdr_serialize,
  _BoundingBox3D__cdr_deserialize,
  _BoundingBox3D__get_serialized_size,
  _BoundingBox3D__get_serialized_size_with_initial_alignment,
  _BoundingBox3D__max_serialized_size
};

static rosidl_message_type_support_t _BoundingBox3D__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_BoundingBox3D__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace zed_interfaces

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<zed_interfaces::msg::BoundingBox3D>()
{
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_BoundingBox3D__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, msg, BoundingBox3D)() {
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_BoundingBox3D__handle;
}

#ifdef __cplusplus
}
#endif
