// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from zed_interfaces:msg/PlaneStamped.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/plane_stamped__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "zed_interfaces/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "zed_interfaces/msg/detail/plane_stamped__struct.h"
#include "zed_interfaces/msg/detail/plane_stamped__functions.h"

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

#include "geometry_msgs/msg/detail/point32__functions.h"  // center, normal
#include "geometry_msgs/msg/detail/polygon__functions.h"  // bounds
#include "geometry_msgs/msg/detail/transform__functions.h"  // pose
#include "shape_msgs/msg/detail/mesh__functions.h"  // mesh
#include "shape_msgs/msg/detail/plane__functions.h"  // coefficients
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t get_serialized_size_geometry_msgs__msg__Point32(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t max_serialized_size_geometry_msgs__msg__Point32(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t get_serialized_size_geometry_msgs__msg__Polygon(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t max_serialized_size_geometry_msgs__msg__Polygon(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Polygon)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t get_serialized_size_geometry_msgs__msg__Transform(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t max_serialized_size_geometry_msgs__msg__Transform(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Transform)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t get_serialized_size_shape_msgs__msg__Mesh(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t max_serialized_size_shape_msgs__msg__Mesh(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, shape_msgs, msg, Mesh)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t get_serialized_size_shape_msgs__msg__Plane(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t max_serialized_size_shape_msgs__msg__Plane(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, shape_msgs, msg, Plane)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_zed_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header)();


typedef zed_interfaces__msg__PlaneStamped _PlaneStamped__ros_msg_type;

static bool _PlaneStamped__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _PlaneStamped__ros_msg_type * ros_message = (_PlaneStamped__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: mesh
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, shape_msgs, msg, Mesh
      )()->data))->cdr_serialize(&ros_message->mesh, cdr);
  // Member: coefficients
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, shape_msgs, msg, Plane
      )()->data))->cdr_serialize(&ros_message->coefficients, cdr);
  // Member: normal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32
      )()->data))->cdr_serialize(&ros_message->normal, cdr);
  // Member: center
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32
      )()->data))->cdr_serialize(&ros_message->center, cdr);
  // Member: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Transform
      )()->data))->cdr_serialize(&ros_message->pose, cdr);
  // Member: extents
  {
    const size_t size = 2;
    rv = ucdr_serialize_array_float(cdr, ros_message->extents, size);
  }
  // Member: bounds
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Polygon
      )()->data))->cdr_serialize(&ros_message->bounds, cdr);

  return rv;
}

static bool _PlaneStamped__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _PlaneStamped__ros_msg_type * ros_message = (_PlaneStamped__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: mesh
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, shape_msgs, msg, Mesh
      )()->data))->cdr_deserialize(cdr, &ros_message->mesh);
  // Field name: coefficients
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, shape_msgs, msg, Plane
      )()->data))->cdr_deserialize(cdr, &ros_message->coefficients);
  // Field name: normal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32
      )()->data))->cdr_deserialize(cdr, &ros_message->normal);
  // Field name: center
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Point32
      )()->data))->cdr_deserialize(cdr, &ros_message->center);
  // Field name: pose
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Transform
      )()->data))->cdr_deserialize(cdr, &ros_message->pose);
  // Field name: extents
  {
    const size_t size = 2;
    rv = ucdr_deserialize_array_float(cdr, ros_message->extents, size);
  }
  // Field name: bounds
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, Polygon
      )()->data))->cdr_deserialize(cdr, &ros_message->bounds);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t get_serialized_size_zed_interfaces__msg__PlaneStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _PlaneStamped__ros_msg_type * ros_message = (const _PlaneStamped__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: mesh
  current_alignment +=
    get_serialized_size_shape_msgs__msg__Mesh(&ros_message->mesh, current_alignment);
  // Member: coefficients
  current_alignment +=
    get_serialized_size_shape_msgs__msg__Plane(&ros_message->coefficients, current_alignment);
  // Member: normal
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Point32(&ros_message->normal, current_alignment);
  // Member: center
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Point32(&ros_message->center, current_alignment);
  // Member: pose
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Transform(&ros_message->pose, current_alignment);
  // Member: extents
  {
    const size_t array_size = 2;
    const size_t item_size = sizeof(ros_message->extents[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: bounds
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__Polygon(&ros_message->bounds, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _PlaneStamped__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_zed_interfaces__msg__PlaneStamped(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t max_serialized_size_zed_interfaces__msg__PlaneStamped(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: mesh
  current_alignment +=
    max_serialized_size_shape_msgs__msg__Mesh(full_bounded, current_alignment);
  // Member: coefficients
  current_alignment +=
    max_serialized_size_shape_msgs__msg__Plane(full_bounded, current_alignment);
  // Member: normal
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Point32(full_bounded, current_alignment);
  // Member: center
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Point32(full_bounded, current_alignment);
  // Member: pose
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Transform(full_bounded, current_alignment);
  // Member: extents
  {
    const size_t array_size = 2;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }
  // Member: bounds
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__Polygon(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _PlaneStamped__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_zed_interfaces__msg__PlaneStamped(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_PlaneStamped = {
  "zed_interfaces::msg",
  "PlaneStamped",
  _PlaneStamped__cdr_serialize,
  _PlaneStamped__cdr_deserialize,
  _PlaneStamped__get_serialized_size,
  get_serialized_size_zed_interfaces__msg__PlaneStamped,
  _PlaneStamped__max_serialized_size
};

static rosidl_message_type_support_t _PlaneStamped__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_PlaneStamped,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, PlaneStamped)() {
  return &_PlaneStamped__type_support;
}

#if defined(__cplusplus)
}
#endif
