// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from zed_interfaces:msg/Skeleton2D.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/skeleton2_d__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "zed_interfaces/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "zed_interfaces/msg/detail/skeleton2_d__struct.h"
#include "zed_interfaces/msg/detail/skeleton2_d__functions.h"

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

#include "zed_interfaces/msg/detail/keypoint2_df__functions.h"  // keypoints

// forward declare type support functions
size_t get_serialized_size_zed_interfaces__msg__Keypoint2Df(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_interfaces__msg__Keypoint2Df(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint2Df)();


typedef zed_interfaces__msg__Skeleton2D _Skeleton2D__ros_msg_type;

static bool _Skeleton2D__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Skeleton2D__ros_msg_type * ros_message = (_Skeleton2D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: keypoints
  {
    const size_t array_size = sizeof(ros_message->keypoints)/sizeof(ros_message->keypoints[0]);
    for(size_t i = 0; i < array_size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint2Df
          )()->data))->cdr_serialize(&ros_message->keypoints[i], cdr);
        if(rv == false){
          break;
        }
    }
  }

  return rv;
}

static bool _Skeleton2D__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Skeleton2D__ros_msg_type * ros_message = (_Skeleton2D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: keypoints
  {
    const size_t array_size = sizeof(ros_message->keypoints)/sizeof(ros_message->keypoints[0]);
    for(size_t i = 0; i < array_size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint2Df
        )()->data))->cdr_deserialize(cdr, &ros_message->keypoints[i]);
      if(rv == false){
        break;
      }
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t get_serialized_size_zed_interfaces__msg__Skeleton2D(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Skeleton2D__ros_msg_type * ros_message = (const _Skeleton2D__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: keypoints
  {
    const size_t array_size = sizeof(ros_message->keypoints)/sizeof(ros_message->keypoints[0]);
    for(size_t i = 0; i < array_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Keypoint2Df
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->keypoints[i], current_alignment);
      current_alignment += element_size;
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Skeleton2D__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_zed_interfaces__msg__Skeleton2D(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t max_serialized_size_zed_interfaces__msg__Skeleton2D(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: keypoints
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static size_t _Skeleton2D__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_zed_interfaces__msg__Skeleton2D(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Skeleton2D = {
  "zed_interfaces::msg",
  "Skeleton2D",
  _Skeleton2D__cdr_serialize,
  _Skeleton2D__cdr_deserialize,
  _Skeleton2D__get_serialized_size,
  get_serialized_size_zed_interfaces__msg__Skeleton2D,
  _Skeleton2D__max_serialized_size
};

static rosidl_message_type_support_t _Skeleton2D__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Skeleton2D,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Skeleton2D)() {
  return &_Skeleton2D__type_support;
}

#if defined(__cplusplus)
}
#endif
