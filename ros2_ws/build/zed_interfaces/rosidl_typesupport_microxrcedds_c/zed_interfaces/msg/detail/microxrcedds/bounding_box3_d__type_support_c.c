// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from zed_interfaces:msg/BoundingBox3D.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/bounding_box3_d__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "zed_interfaces/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "zed_interfaces/msg/detail/bounding_box3_d__struct.h"
#include "zed_interfaces/msg/detail/bounding_box3_d__functions.h"

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

#include "zed_interfaces/msg/detail/keypoint3_d__functions.h"  // corners

// forward declare type support functions
size_t get_serialized_size_zed_interfaces__msg__Keypoint3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_interfaces__msg__Keypoint3D(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint3D)();


typedef zed_interfaces__msg__BoundingBox3D _BoundingBox3D__ros_msg_type;

static bool _BoundingBox3D__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _BoundingBox3D__ros_msg_type * ros_message = (_BoundingBox3D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: corners
  {
    const size_t array_size = sizeof(ros_message->corners)/sizeof(ros_message->corners[0]);
    for(size_t i = 0; i < array_size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint3D
          )()->data))->cdr_serialize(&ros_message->corners[i], cdr);
        if(rv == false){
          break;
        }
    }
  }

  return rv;
}

static bool _BoundingBox3D__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _BoundingBox3D__ros_msg_type * ros_message = (_BoundingBox3D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: corners
  {
    const size_t array_size = sizeof(ros_message->corners)/sizeof(ros_message->corners[0]);
    for(size_t i = 0; i < array_size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint3D
        )()->data))->cdr_deserialize(cdr, &ros_message->corners[i]);
      if(rv == false){
        break;
      }
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t get_serialized_size_zed_interfaces__msg__BoundingBox3D(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _BoundingBox3D__ros_msg_type * ros_message = (const _BoundingBox3D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: corners
  {
    const size_t array_size = sizeof(ros_message->corners)/sizeof(ros_message->corners[0]);
    for(size_t i = 0; i < array_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint3D
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->corners[i], current_alignment);
      current_alignment += element_size;
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BoundingBox3D__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_zed_interfaces__msg__BoundingBox3D(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t max_serialized_size_zed_interfaces__msg__BoundingBox3D(
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

static size_t _BoundingBox3D__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_zed_interfaces__msg__BoundingBox3D(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_BoundingBox3D = {
  "zed_interfaces::msg",
  "BoundingBox3D",
  _BoundingBox3D__cdr_serialize,
  _BoundingBox3D__cdr_deserialize,
  _BoundingBox3D__get_serialized_size,
  get_serialized_size_zed_interfaces__msg__BoundingBox3D,
  _BoundingBox3D__max_serialized_size
};

static rosidl_message_type_support_t _BoundingBox3D__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_BoundingBox3D,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox3D)() {
  return &_BoundingBox3D__type_support;
}

#if defined(__cplusplus)
}
#endif
