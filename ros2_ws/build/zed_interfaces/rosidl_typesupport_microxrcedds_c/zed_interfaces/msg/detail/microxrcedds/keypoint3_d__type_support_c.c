// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from zed_interfaces:msg/Keypoint3D.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/keypoint3_d__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "zed_interfaces/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "zed_interfaces/msg/detail/keypoint3_d__struct.h"
#include "zed_interfaces/msg/detail/keypoint3_d__functions.h"

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


// forward declare type support functions


typedef zed_interfaces__msg__Keypoint3D _Keypoint3D__ros_msg_type;

static bool _Keypoint3D__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Keypoint3D__ros_msg_type * ros_message = (_Keypoint3D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: kp
  {
    const size_t size = 3;
    rv = ucdr_serialize_array_float(cdr, ros_message->kp, size);
  }

  return rv;
}

static bool _Keypoint3D__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Keypoint3D__ros_msg_type * ros_message = (_Keypoint3D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: kp
  {
    const size_t size = 3;
    rv = ucdr_deserialize_array_float(cdr, ros_message->kp, size);
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t get_serialized_size_zed_interfaces__msg__Keypoint3D(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Keypoint3D__ros_msg_type * ros_message = (const _Keypoint3D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: kp
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message->kp[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Keypoint3D__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_zed_interfaces__msg__Keypoint3D(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t max_serialized_size_zed_interfaces__msg__Keypoint3D(
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

static size_t _Keypoint3D__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_zed_interfaces__msg__Keypoint3D(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Keypoint3D = {
  "zed_interfaces::msg",
  "Keypoint3D",
  _Keypoint3D__cdr_serialize,
  _Keypoint3D__cdr_deserialize,
  _Keypoint3D__get_serialized_size,
  get_serialized_size_zed_interfaces__msg__Keypoint3D,
  _Keypoint3D__max_serialized_size
};

static rosidl_message_type_support_t _Keypoint3D__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Keypoint3D,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint3D)() {
  return &_Keypoint3D__type_support;
}

#if defined(__cplusplus)
}
#endif
