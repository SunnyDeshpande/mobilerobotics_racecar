// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from zed_interfaces:msg/Object.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/object__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "zed_interfaces/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "zed_interfaces/msg/detail/object__struct.h"
#include "zed_interfaces/msg/detail/object__functions.h"

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

#include "rosidl_runtime_c/string.h"  // label, sublabel
#include "rosidl_runtime_c/string_functions.h"  // label, sublabel
#include "zed_interfaces/msg/detail/bounding_box2_df__functions.h"  // head_bounding_box_2d
#include "zed_interfaces/msg/detail/bounding_box2_di__functions.h"  // bounding_box_2d
#include "zed_interfaces/msg/detail/bounding_box3_d__functions.h"  // bounding_box_3d, head_bounding_box_3d
#include "zed_interfaces/msg/detail/skeleton2_d__functions.h"  // skeleton_2d
#include "zed_interfaces/msg/detail/skeleton3_d__functions.h"  // skeleton_3d

// forward declare type support functions
size_t get_serialized_size_zed_interfaces__msg__BoundingBox2Df(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_interfaces__msg__BoundingBox2Df(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox2Df)();
size_t get_serialized_size_zed_interfaces__msg__BoundingBox2Di(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_interfaces__msg__BoundingBox2Di(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox2Di)();
size_t get_serialized_size_zed_interfaces__msg__BoundingBox3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_interfaces__msg__BoundingBox3D(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox3D)();
size_t get_serialized_size_zed_interfaces__msg__Skeleton2D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_interfaces__msg__Skeleton2D(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Skeleton2D)();
size_t get_serialized_size_zed_interfaces__msg__Skeleton3D(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_zed_interfaces__msg__Skeleton3D(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Skeleton3D)();


typedef zed_interfaces__msg__Object _Object__ros_msg_type;

static bool _Object__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _Object__ros_msg_type * ros_message = (_Object__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: label
 {
    uint32_t string_len = (ros_message->label.data == NULL) ? 0 : (uint32_t)strlen(ros_message->label.data) + 1;
    ros_message->label.size = (ros_message->label.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->label.data, string_len);
  }
  // Member: label_id
  rv = ucdr_serialize_int16_t(cdr, ros_message->label_id);
  // Member: sublabel
 {
    uint32_t string_len = (ros_message->sublabel.data == NULL) ? 0 : (uint32_t)strlen(ros_message->sublabel.data) + 1;
    ros_message->sublabel.size = (ros_message->sublabel.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->sublabel.data, string_len);
  }
  // Member: confidence
  rv = ucdr_serialize_float(cdr, ros_message->confidence);
  // Member: position
  {
    const size_t size = 3;
    rv = ucdr_serialize_array_float(cdr, ros_message->position, size);
  }
  // Member: position_covariance
  {
    const size_t size = 6;
    rv = ucdr_serialize_array_float(cdr, ros_message->position_covariance, size);
  }
  // Member: velocity
  {
    const size_t size = 3;
    rv = ucdr_serialize_array_float(cdr, ros_message->velocity, size);
  }
  // Member: tracking_available
  rv = ucdr_serialize_bool(cdr, (ros_message->tracking_available) ? 0x01 : 0x00);
  // Member: tracking_state
  rv = ucdr_serialize_int8_t(cdr, ros_message->tracking_state);
  // Member: action_state
  rv = ucdr_serialize_int8_t(cdr, ros_message->action_state);
  // Member: bounding_box_2d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox2Di
      )()->data))->cdr_serialize(&ros_message->bounding_box_2d, cdr);
  // Member: bounding_box_3d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox3D
      )()->data))->cdr_serialize(&ros_message->bounding_box_3d, cdr);
  // Member: dimensions_3d
  {
    const size_t size = 3;
    rv = ucdr_serialize_array_float(cdr, ros_message->dimensions_3d, size);
  }
  // Member: skeleton_available
  rv = ucdr_serialize_bool(cdr, (ros_message->skeleton_available) ? 0x01 : 0x00);
  // Member: body_format
  rv = ucdr_serialize_int8_t(cdr, ros_message->body_format);
  // Member: head_bounding_box_2d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox2Df
      )()->data))->cdr_serialize(&ros_message->head_bounding_box_2d, cdr);
  // Member: head_bounding_box_3d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox3D
      )()->data))->cdr_serialize(&ros_message->head_bounding_box_3d, cdr);
  // Member: head_position
  {
    const size_t size = 3;
    rv = ucdr_serialize_array_float(cdr, ros_message->head_position, size);
  }
  // Member: skeleton_2d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Skeleton2D
      )()->data))->cdr_serialize(&ros_message->skeleton_2d, cdr);
  // Member: skeleton_3d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Skeleton3D
      )()->data))->cdr_serialize(&ros_message->skeleton_3d, cdr);

  return rv;
}

static bool _Object__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _Object__ros_msg_type * ros_message = (_Object__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: label
  {
    size_t capacity = ros_message->label.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->label.data, capacity, &string_size);
    if (rv) {
      ros_message->label.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->label.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: label_id
  rv = ucdr_deserialize_int16_t(cdr, &ros_message->label_id);
  // Field name: sublabel
  {
    size_t capacity = ros_message->sublabel.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->sublabel.data, capacity, &string_size);
    if (rv) {
      ros_message->sublabel.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->sublabel.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: confidence
  rv = ucdr_deserialize_float(cdr, &ros_message->confidence);
  // Field name: position
  {
    const size_t size = 3;
    rv = ucdr_deserialize_array_float(cdr, ros_message->position, size);
  }
  // Field name: position_covariance
  {
    const size_t size = 6;
    rv = ucdr_deserialize_array_float(cdr, ros_message->position_covariance, size);
  }
  // Field name: velocity
  {
    const size_t size = 3;
    rv = ucdr_deserialize_array_float(cdr, ros_message->velocity, size);
  }
  // Field name: tracking_available
  rv = ucdr_deserialize_bool(cdr, &ros_message->tracking_available);
  // Field name: tracking_state
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->tracking_state);
  // Field name: action_state
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->action_state);
  // Field name: bounding_box_2d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox2Di
      )()->data))->cdr_deserialize(cdr, &ros_message->bounding_box_2d);
  // Field name: bounding_box_3d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox3D
      )()->data))->cdr_deserialize(cdr, &ros_message->bounding_box_3d);
  // Field name: dimensions_3d
  {
    const size_t size = 3;
    rv = ucdr_deserialize_array_float(cdr, ros_message->dimensions_3d, size);
  }
  // Field name: skeleton_available
  rv = ucdr_deserialize_bool(cdr, &ros_message->skeleton_available);
  // Field name: body_format
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->body_format);
  // Field name: head_bounding_box_2d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox2Df
      )()->data))->cdr_deserialize(cdr, &ros_message->head_bounding_box_2d);
  // Field name: head_bounding_box_3d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, BoundingBox3D
      )()->data))->cdr_deserialize(cdr, &ros_message->head_bounding_box_3d);
  // Field name: head_position
  {
    const size_t size = 3;
    rv = ucdr_deserialize_array_float(cdr, ros_message->head_position, size);
  }
  // Field name: skeleton_2d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Skeleton2D
      )()->data))->cdr_deserialize(cdr, &ros_message->skeleton_2d);
  // Field name: skeleton_3d
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Skeleton3D
      )()->data))->cdr_deserialize(cdr, &ros_message->skeleton_3d);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t get_serialized_size_zed_interfaces__msg__Object(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _Object__ros_msg_type * ros_message = (const _Object__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: label
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->label.size + 1;
  // Member: label_id
  {
    const size_t item_size = sizeof(ros_message->label_id);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: sublabel
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->sublabel.size + 1;
  // Member: confidence
  {
    const size_t item_size = sizeof(ros_message->confidence);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: position
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message->position[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: position_covariance
  {
    const size_t array_size = 6;
    const size_t item_size = sizeof(ros_message->position_covariance[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: velocity
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message->velocity[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: tracking_available
  {
    const size_t item_size = sizeof(ros_message->tracking_available);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: tracking_state
  {
    const size_t item_size = sizeof(ros_message->tracking_state);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: action_state
  {
    const size_t item_size = sizeof(ros_message->action_state);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: bounding_box_2d
  current_alignment +=
    get_serialized_size_zed_interfaces__msg__BoundingBox2Di(&ros_message->bounding_box_2d, current_alignment);
  // Member: bounding_box_3d
  current_alignment +=
    get_serialized_size_zed_interfaces__msg__BoundingBox3D(&ros_message->bounding_box_3d, current_alignment);
  // Member: dimensions_3d
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message->dimensions_3d[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: skeleton_available
  {
    const size_t item_size = sizeof(ros_message->skeleton_available);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: body_format
  {
    const size_t item_size = sizeof(ros_message->body_format);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: head_bounding_box_2d
  current_alignment +=
    get_serialized_size_zed_interfaces__msg__BoundingBox2Df(&ros_message->head_bounding_box_2d, current_alignment);
  // Member: head_bounding_box_3d
  current_alignment +=
    get_serialized_size_zed_interfaces__msg__BoundingBox3D(&ros_message->head_bounding_box_3d, current_alignment);
  // Member: head_position
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message->head_position[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: skeleton_2d
  current_alignment +=
    get_serialized_size_zed_interfaces__msg__Skeleton2D(&ros_message->skeleton_2d, current_alignment);
  // Member: skeleton_3d
  current_alignment +=
    get_serialized_size_zed_interfaces__msg__Skeleton3D(&ros_message->skeleton_3d, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Object__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_zed_interfaces__msg__Object(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_zed_interfaces
size_t max_serialized_size_zed_interfaces__msg__Object(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: label
  *full_bounded = false;
  // Member: label_id
  current_alignment += ucdr_alignment(current_alignment, sizeof(int16_t)) + sizeof(int16_t);
  // Member: sublabel
  *full_bounded = false;
  // Member: confidence
  current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + sizeof(float);
  // Member: position
  {
    const size_t array_size = 3;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }
  // Member: position_covariance
  {
    const size_t array_size = 6;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }
  // Member: velocity
  {
    const size_t array_size = 3;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }
  // Member: tracking_available
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: tracking_state
  current_alignment += ucdr_alignment(current_alignment, sizeof(int8_t)) + sizeof(int8_t);
  // Member: action_state
  current_alignment += ucdr_alignment(current_alignment, sizeof(int8_t)) + sizeof(int8_t);
  // Member: bounding_box_2d
  current_alignment +=
    max_serialized_size_zed_interfaces__msg__BoundingBox2Di(full_bounded, current_alignment);
  // Member: bounding_box_3d
  current_alignment +=
    max_serialized_size_zed_interfaces__msg__BoundingBox3D(full_bounded, current_alignment);
  // Member: dimensions_3d
  {
    const size_t array_size = 3;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }
  // Member: skeleton_available
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: body_format
  current_alignment += ucdr_alignment(current_alignment, sizeof(int8_t)) + sizeof(int8_t);
  // Member: head_bounding_box_2d
  current_alignment +=
    max_serialized_size_zed_interfaces__msg__BoundingBox2Df(full_bounded, current_alignment);
  // Member: head_bounding_box_3d
  current_alignment +=
    max_serialized_size_zed_interfaces__msg__BoundingBox3D(full_bounded, current_alignment);
  // Member: head_position
  {
    const size_t array_size = 3;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }
  // Member: skeleton_2d
  current_alignment +=
    max_serialized_size_zed_interfaces__msg__Skeleton2D(full_bounded, current_alignment);
  // Member: skeleton_3d
  current_alignment +=
    max_serialized_size_zed_interfaces__msg__Skeleton3D(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _Object__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_zed_interfaces__msg__Object(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Object = {
  "zed_interfaces::msg",
  "Object",
  _Object__cdr_serialize,
  _Object__cdr_deserialize,
  _Object__get_serialized_size,
  get_serialized_size_zed_interfaces__msg__Object,
  _Object__max_serialized_size
};

static rosidl_message_type_support_t _Object__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Object,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, zed_interfaces, msg, Object)() {
  return &_Object__type_support;
}

#if defined(__cplusplus)
}
#endif
