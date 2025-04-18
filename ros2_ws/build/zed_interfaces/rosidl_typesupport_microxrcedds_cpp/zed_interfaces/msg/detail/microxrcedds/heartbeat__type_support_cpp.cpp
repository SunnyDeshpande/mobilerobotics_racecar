// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/heartbeat__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "zed_interfaces/msg/detail/heartbeat__struct.hpp"

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
  const zed_interfaces::msg::Heartbeat & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: beat_count
  rv = ucdr_serialize_uint64_t(cdr, ros_message.beat_count);
  // Member: node_ns
  rv = ucdr_serialize_string(cdr, ros_message.node_ns.c_str());
  // Member: node_name
  rv = ucdr_serialize_string(cdr, ros_message.node_name.c_str());
  // Member: full_name
  rv = ucdr_serialize_string(cdr, ros_message.full_name.c_str());
  // Member: camera_sn
  rv = ucdr_serialize_uint32_t(cdr, ros_message.camera_sn);
  // Member: svo_mode
  rv = ucdr_serialize_bool(cdr, ros_message.svo_mode);
  // Member: simul_mode
  rv = ucdr_serialize_bool(cdr, ros_message.simul_mode);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_deserialize(
  ucdrBuffer * cdr,
  zed_interfaces::msg::Heartbeat & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: beat_count
  rv = ucdr_deserialize_uint64_t(cdr, &ros_message.beat_count);
  // Member: node_ns
  ros_message.node_ns.resize(ros_message.node_ns.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.node_ns[0], ros_message.node_ns.capacity());
  if (rv) {
    ros_message.node_ns.resize(std::strlen(&ros_message.node_ns[0]));
  }
  // Member: node_name
  ros_message.node_name.resize(ros_message.node_name.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.node_name[0], ros_message.node_name.capacity());
  if (rv) {
    ros_message.node_name.resize(std::strlen(&ros_message.node_name[0]));
  }
  // Member: full_name
  ros_message.full_name.resize(ros_message.full_name.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.full_name[0], ros_message.full_name.capacity());
  if (rv) {
    ros_message.full_name.resize(std::strlen(&ros_message.full_name[0]));
  }
  // Member: camera_sn
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message.camera_sn);
  // Member: svo_mode
  rv = ucdr_deserialize_bool(cdr, &ros_message.svo_mode);
  // Member: simul_mode
  rv = ucdr_deserialize_bool(cdr, &ros_message.simul_mode);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
get_serialized_size(
  const zed_interfaces::msg::Heartbeat & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: beat_count
  {
    const size_t item_size = sizeof(ros_message.beat_count);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: node_ns
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.node_ns.size() + 1;
  // Member: node_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.node_name.size() + 1;
  // Member: full_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.full_name.size() + 1;
  // Member: camera_sn
  {
    const size_t item_size = sizeof(ros_message.camera_sn);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: svo_mode
  {
    const size_t item_size = sizeof(ros_message.svo_mode);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: simul_mode
  {
    const size_t item_size = sizeof(ros_message.simul_mode);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
max_serialized_size_Heartbeat(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: beat_count
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint64_t)) + sizeof(uint64_t);
  // Member: node_ns
  *full_bounded = false;
  // Member: node_name
  *full_bounded = false;
  // Member: full_name
  *full_bounded = false;
  // Member: camera_sn
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: svo_mode
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: simul_mode
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static bool _Heartbeat__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Heartbeat *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Heartbeat__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<zed_interfaces::msg::Heartbeat *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Heartbeat__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Heartbeat *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Heartbeat__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Heartbeat *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _Heartbeat__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_Heartbeat(&full_bounded, 0);
}

static message_type_support_callbacks_t _Heartbeat__callbacks = {
  "zed_interfaces::msg",
  "Heartbeat",
  _Heartbeat__cdr_serialize,
  _Heartbeat__cdr_deserialize,
  _Heartbeat__get_serialized_size,
  _Heartbeat__get_serialized_size_with_initial_alignment,
  _Heartbeat__max_serialized_size
};

static rosidl_message_type_support_t _Heartbeat__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_Heartbeat__callbacks,
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
get_message_type_support_handle<zed_interfaces::msg::Heartbeat>()
{
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_Heartbeat__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, msg, Heartbeat)() {
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_Heartbeat__handle;
}

#ifdef __cplusplus
}
#endif
