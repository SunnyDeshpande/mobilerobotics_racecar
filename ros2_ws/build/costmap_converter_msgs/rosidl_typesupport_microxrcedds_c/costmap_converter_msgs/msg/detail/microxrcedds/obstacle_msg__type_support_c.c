// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from costmap_converter_msgs:msg/ObstacleMsg.idl
// generated code does not contain a copyright notice
#include "costmap_converter_msgs/msg/detail/obstacle_msg__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "costmap_converter_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "costmap_converter_msgs/msg/detail/obstacle_msg__struct.h"
#include "costmap_converter_msgs/msg/detail/obstacle_msg__functions.h"

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

#include "geometry_msgs/msg/detail/polygon__functions.h"  // polygon
#include "geometry_msgs/msg/detail/quaternion__functions.h"  // orientation
#include "geometry_msgs/msg/detail/twist_with_covariance__functions.h"  // velocities
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t get_serialized_size_geometry_msgs__msg__Polygon(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t max_serialized_size_geometry_msgs__msg__Polygon(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Polygon)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t get_serialized_size_geometry_msgs__msg__Quaternion(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t max_serialized_size_geometry_msgs__msg__Quaternion(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Quaternion)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t get_serialized_size_geometry_msgs__msg__TwistWithCovariance(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
size_t max_serialized_size_geometry_msgs__msg__TwistWithCovariance(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_costmap_converter_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TwistWithCovariance)();
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


typedef costmap_converter_msgs__msg__ObstacleMsg _ObstacleMsg__ros_msg_type;

static bool _ObstacleMsg__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ObstacleMsg__ros_msg_type * ros_message = (_ObstacleMsg__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: polygon
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Polygon
      )()->data))->cdr_serialize(&ros_message->polygon, cdr);
  // Member: radius
  rv = ucdr_serialize_double(cdr, ros_message->radius);
  // Member: id
  rv = ucdr_serialize_int64_t(cdr, ros_message->id);
  // Member: orientation
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Quaternion
      )()->data))->cdr_serialize(&ros_message->orientation, cdr);
  // Member: velocities
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TwistWithCovariance
      )()->data))->cdr_serialize(&ros_message->velocities, cdr);

  return rv;
}

static bool _ObstacleMsg__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ObstacleMsg__ros_msg_type * ros_message = (_ObstacleMsg__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: polygon
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Polygon
      )()->data))->cdr_deserialize(cdr, &ros_message->polygon);
  // Field name: radius
  rv = ucdr_deserialize_double(cdr, &ros_message->radius);
  // Field name: id
  rv = ucdr_deserialize_int64_t(cdr, &ros_message->id);
  // Field name: orientation
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Quaternion
      )()->data))->cdr_deserialize(cdr, &ros_message->orientation);
  // Field name: velocities
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TwistWithCovariance
      )()->data))->cdr_deserialize(cdr, &ros_message->velocities);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_costmap_converter_msgs
size_t get_serialized_size_costmap_converter_msgs__msg__ObstacleMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ObstacleMsg__ros_msg_type * ros_message = (const _ObstacleMsg__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: polygon
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Polygon(&ros_message->polygon, current_alignment);
  // Member: radius
  {
    const size_t item_size = sizeof(ros_message->radius);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: id
  {
    const size_t item_size = sizeof(ros_message->id);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: orientation
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Quaternion(&ros_message->orientation, current_alignment);
  // Member: velocities
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__TwistWithCovariance(&ros_message->velocities, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _ObstacleMsg__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_costmap_converter_msgs__msg__ObstacleMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_costmap_converter_msgs
size_t max_serialized_size_costmap_converter_msgs__msg__ObstacleMsg(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: polygon
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Polygon(full_bounded, current_alignment);
  // Member: radius
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: id
  current_alignment += ucdr_alignment(current_alignment, sizeof(int64_t)) + sizeof(int64_t);
  // Member: orientation
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Quaternion(full_bounded, current_alignment);
  // Member: velocities
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__TwistWithCovariance(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _ObstacleMsg__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_costmap_converter_msgs__msg__ObstacleMsg(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ObstacleMsg = {
  "costmap_converter_msgs::msg",
  "ObstacleMsg",
  _ObstacleMsg__cdr_serialize,
  _ObstacleMsg__cdr_deserialize,
  _ObstacleMsg__get_serialized_size,
  get_serialized_size_costmap_converter_msgs__msg__ObstacleMsg,
  _ObstacleMsg__max_serialized_size
};

static rosidl_message_type_support_t _ObstacleMsg__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ObstacleMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, costmap_converter_msgs, msg, ObstacleMsg)() {
  return &_ObstacleMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
