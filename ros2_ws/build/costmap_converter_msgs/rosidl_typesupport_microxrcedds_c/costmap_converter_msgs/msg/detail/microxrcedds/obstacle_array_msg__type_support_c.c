// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from costmap_converter_msgs:msg/ObstacleArrayMsg.idl
// generated code does not contain a copyright notice
#include "costmap_converter_msgs/msg/detail/obstacle_array_msg__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "costmap_converter_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "costmap_converter_msgs/msg/detail/obstacle_array_msg__struct.h"
#include "costmap_converter_msgs/msg/detail/obstacle_array_msg__functions.h"

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

#include "costmap_converter_msgs/msg/detail/obstacle_msg__functions.h"  // obstacles
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
size_t get_serialized_size_costmap_converter_msgs__msg__ObstacleMsg(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_costmap_converter_msgs__msg__ObstacleMsg(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, costmap_converter_msgs, msg, ObstacleMsg)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header)();


typedef costmap_converter_msgs__msg__ObstacleArrayMsg _ObstacleArrayMsg__ros_msg_type;

static bool _ObstacleArrayMsg__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ObstacleArrayMsg__ros_msg_type * ros_message = (_ObstacleArrayMsg__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: obstacles
  {
    const size_t size = ros_message->obstacles.size;
    rv = ucdr_serialize_uint32_t(cdr, size);

    if(rv == true){
      for(size_t i = 0; i < size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, costmap_converter_msgs, msg, ObstacleMsg
          )()->data))->cdr_serialize(&ros_message->obstacles.data[i], cdr);
        if(rv == false){
          break;
        }
      }
    }
  }

  return rv;
}

static bool _ObstacleArrayMsg__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ObstacleArrayMsg__ros_msg_type * ros_message = (_ObstacleArrayMsg__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: obstacles
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->obstacles.capacity){
      return 0;
    }

    ros_message->obstacles.size = size;
    for(size_t i = 0; i < size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, costmap_converter_msgs, msg, ObstacleMsg
        )()->data))->cdr_deserialize(cdr, &ros_message->obstacles.data[i]);
      if(rv == false){
        break;
      }
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_costmap_converter_msgs
size_t get_serialized_size_costmap_converter_msgs__msg__ObstacleArrayMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ObstacleArrayMsg__ros_msg_type * ros_message = (const _ObstacleArrayMsg__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: obstacles
  {
    const size_t sequence_size = ros_message->obstacles.size;

    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, costmap_converter_msgs, msg, ObstacleMsg
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->obstacles.data[i], current_alignment);
      uint8_t alignment_size = (element_size < MICROXRCEDDS_PADDING) ? element_size : MICROXRCEDDS_PADDING;
      current_alignment += ucdr_alignment(current_alignment, alignment_size) + element_size;
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ObstacleArrayMsg__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_costmap_converter_msgs__msg__ObstacleArrayMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_costmap_converter_msgs
size_t max_serialized_size_costmap_converter_msgs__msg__ObstacleArrayMsg(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: obstacles
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static size_t _ObstacleArrayMsg__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_costmap_converter_msgs__msg__ObstacleArrayMsg(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ObstacleArrayMsg = {
  "costmap_converter_msgs::msg",
  "ObstacleArrayMsg",
  _ObstacleArrayMsg__cdr_serialize,
  _ObstacleArrayMsg__cdr_deserialize,
  _ObstacleArrayMsg__get_serialized_size,
  get_serialized_size_costmap_converter_msgs__msg__ObstacleArrayMsg,
  _ObstacleArrayMsg__max_serialized_size
};

static rosidl_message_type_support_t _ObstacleArrayMsg__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ObstacleArrayMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, costmap_converter_msgs, msg, ObstacleArrayMsg)() {
  return &_ObstacleArrayMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
