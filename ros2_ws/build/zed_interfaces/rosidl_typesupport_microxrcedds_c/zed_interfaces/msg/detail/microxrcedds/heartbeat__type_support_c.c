// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from zed_interfaces:msg/Heartbeat.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/heartbeat__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "zed_interfaces/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "zed_interfaces/msg/detail/heartbeat__struct.h"
#include "zed_interfaces/msg/detail/heartbeat__functions.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // full_name, node_name, node_ns
#include "rosidl_runtime_c/string_functions.h"  // full_name, node_name, node_ns

// forward declare type support functions


typedef zed_interfaces__msg__Heartbeat _Heartbeat__ros_msg_type;

static bool _Heartbeat__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Heartbeat__ros_msg_type * ros_message = (_Heartbeat__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: beat_count
  rv = ucdr_serialize_uint64_t(cdr, ros_message->beat_count);
  // Member: node_ns
 {
    uint32_t string_len = (ros_message->node_ns.data == NULL) ? 0 : (uint32_t)strlen(ros_message->node_ns.data) + 1;
    ros_message->node_ns.size = (ros_message->node_ns.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->node_ns.data, string_len);
  }
  // Member: node_name
 {
    uint32_t string_len = (ros_message->node_name.data == NULL) ? 0 : (uint32_t)strlen(ros_message->node_name.data) + 1;
    ros_message->node_name.size = (ros_message->node_name.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->node_name.data, string_len);
  }
  // Member: full_name
 {
    uint32_t string_len = (ros_message->full_name.data == NULL) ? 0 : (uint32_t)strlen(ros_message->full_name.data) + 1;
    ros_message->full_name.size = (ros_message->full_name.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->full_name.data, string_len);
  }
  // Member: camera_sn
  rv = ucdr_serialize_uint32_t(cdr, ros_message->camera_sn);
  // Member: svo_mode
  rv = ucdr_serialize_bool(cdr, (ros_message->svo_mode) ? 0x01 : 0x00);
  // Member: simul_mode
  rv = ucdr_serialize_bool(cdr, (ros_message->simul_mode) ? 0x01 : 0x00);

  return rv;
}

static bool _Heartbeat__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Heartbeat__ros_msg_type * ros_message = (_Heartbeat__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: beat_count
  rv = ucdr_deserialize_uint64_t(cdr, &ros_message->beat_count);
  // Field name: node_ns
  {
    size_t capacity = ros_message->node_ns.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->node_ns.data, capacity, &string_size);
    if (rv) {
      ros_message->node_ns.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->node_ns.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: node_name
  {
    size_t capacity = ros_message->node_name.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->node_name.data, capacity, &string_size);
    if (rv) {
      ros_message->node_name.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->node_name.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: full_name
  {
    size_t capacity = ros_message->full_name.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->full_name.data, capacity, &string_size);
    if (rv) {
      ros_message->full_name.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->full_name.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: camera_sn
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message->camera_sn);
  // Field name: svo_mode
  rv = ucdr_deserialize_bool(cdr, &ros_message->svo_mode);
  // Field name: simul_mode
  rv = ucdr_deserialize_bool(cdr, &ros_message->simul_mode);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t get_serialized_size_zed_interfaces__msg__Heartbeat(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Heartbeat__ros_msg_type * ros_message = (const _Heartbeat__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: beat_count
  {
    const size_t item_size = sizeof(ros_message->beat_count);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: node_ns
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->node_ns.size + 1;
  // Member: node_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->node_name.size + 1;
  // Member: full_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->full_name.size + 1;
  // Member: camera_sn
  {
    const size_t item_size = sizeof(ros_message->camera_sn);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: svo_mode
  {
    const size_t item_size = sizeof(ros_message->svo_mode);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: simul_mode
  {
    const size_t item_size = sizeof(ros_message->simul_mode);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Heartbeat__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_zed_interfaces__msg__Heartbeat(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t max_serialized_size_zed_interfaces__msg__Heartbeat(
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

static size_t _Heartbeat__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_zed_interfaces__msg__Heartbeat(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Heartbeat = {
  "zed_interfaces::msg",
  "Heartbeat",
  _Heartbeat__cdr_serialize,
  _Heartbeat__cdr_deserialize,
  _Heartbeat__get_serialized_size,
  get_serialized_size_zed_interfaces__msg__Heartbeat,
  _Heartbeat__max_serialized_size
};

static rosidl_message_type_support_t _Heartbeat__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Heartbeat,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Heartbeat)() {
  return &_Heartbeat__type_support;
}

#if defined(__cplusplus)
}
#endif
