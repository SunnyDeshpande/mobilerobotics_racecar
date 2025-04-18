// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from zed_interfaces:msg/Keypoint3D.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/keypoint3_d__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "zed_interfaces/msg/detail/keypoint3_d__struct.hpp"

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

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_serialize(
  const zed_interfaces::msg::Keypoint3D & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: kp
  {
    size_t size = ros_message.kp.size();
    rv = ucdr_serialize_array_float(cdr, ros_message.kp.data(), size);
  }

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_deserialize(
  ucdrBuffer * cdr,
  zed_interfaces::msg::Keypoint3D & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: kp
  {
    const size_t size = ros_message.kp.size();
    rv = ucdr_deserialize_array_float(cdr, ros_message.kp.data(), size);
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
get_serialized_size(
  const zed_interfaces::msg::Keypoint3D & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: kp
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message.kp[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
max_serialized_size_Keypoint3D(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: kp
  {
    const size_t array_size = 3;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }

  return current_alignment - initial_alignment;
}

static bool _Keypoint3D__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Keypoint3D *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Keypoint3D__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<zed_interfaces::msg::Keypoint3D *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Keypoint3D__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Keypoint3D *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Keypoint3D__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Keypoint3D *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _Keypoint3D__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_Keypoint3D(&full_bounded, 0);
}

static message_type_support_callbacks_t _Keypoint3D__callbacks = {
  "zed_interfaces::msg",
  "Keypoint3D",
  _Keypoint3D__cdr_serialize,
  _Keypoint3D__cdr_deserialize,
  _Keypoint3D__get_serialized_size,
  _Keypoint3D__get_serialized_size_with_initial_alignment,
  _Keypoint3D__max_serialized_size
};

static rosidl_message_type_support_t _Keypoint3D__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_Keypoint3D__callbacks,
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
get_message_type_support_handle<zed_interfaces::msg::Keypoint3D>()
{
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_Keypoint3D__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, msg, Keypoint3D)() {
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_Keypoint3D__handle;
}

#ifdef __cplusplus
}
#endif
