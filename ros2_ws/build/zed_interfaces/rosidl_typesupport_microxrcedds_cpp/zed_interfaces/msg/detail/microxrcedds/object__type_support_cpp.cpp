// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from zed_interfaces:msg/Object.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/msg/detail/object__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "zed_interfaces/msg/detail/object__struct.hpp"

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
bool cdr_serialize(
  const zed_interfaces::msg::BoundingBox2Di &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  zed_interfaces::msg::BoundingBox2Di &);

size_t get_serialized_size(
  const zed_interfaces::msg::BoundingBox2Di &,
  size_t current_alignment);

size_t
max_serialized_size_BoundingBox2Di(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace zed_interfaces

namespace zed_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const zed_interfaces::msg::BoundingBox3D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  zed_interfaces::msg::BoundingBox3D &);

size_t get_serialized_size(
  const zed_interfaces::msg::BoundingBox3D &,
  size_t current_alignment);

size_t
max_serialized_size_BoundingBox3D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace zed_interfaces

namespace zed_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const zed_interfaces::msg::BoundingBox2Df &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  zed_interfaces::msg::BoundingBox2Df &);

size_t get_serialized_size(
  const zed_interfaces::msg::BoundingBox2Df &,
  size_t current_alignment);

size_t
max_serialized_size_BoundingBox2Df(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace zed_interfaces

namespace zed_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const zed_interfaces::msg::BoundingBox3D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  zed_interfaces::msg::BoundingBox3D &);

size_t get_serialized_size(
  const zed_interfaces::msg::BoundingBox3D &,
  size_t current_alignment);

size_t
max_serialized_size_BoundingBox3D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace zed_interfaces

namespace zed_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const zed_interfaces::msg::Skeleton2D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  zed_interfaces::msg::Skeleton2D &);

size_t get_serialized_size(
  const zed_interfaces::msg::Skeleton2D &,
  size_t current_alignment);

size_t
max_serialized_size_Skeleton2D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace zed_interfaces

namespace zed_interfaces
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const zed_interfaces::msg::Skeleton3D &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  zed_interfaces::msg::Skeleton3D &);

size_t get_serialized_size(
  const zed_interfaces::msg::Skeleton3D &,
  size_t current_alignment);

size_t
max_serialized_size_Skeleton3D(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace zed_interfaces


namespace zed_interfaces
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_serialize(
  const zed_interfaces::msg::Object & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: label
  rv = ucdr_serialize_string(cdr, ros_message.label.c_str());
  // Member: label_id
  rv = ucdr_serialize_int16_t(cdr, ros_message.label_id);
  // Member: sublabel
  rv = ucdr_serialize_string(cdr, ros_message.sublabel.c_str());
  // Member: confidence
  rv = ucdr_serialize_float(cdr, ros_message.confidence);
  // Member: position
  {
    size_t size = ros_message.position.size();
    rv = ucdr_serialize_array_float(cdr, ros_message.position.data(), size);
  }
  // Member: position_covariance
  {
    size_t size = ros_message.position_covariance.size();
    rv = ucdr_serialize_array_float(cdr, ros_message.position_covariance.data(), size);
  }
  // Member: velocity
  {
    size_t size = ros_message.velocity.size();
    rv = ucdr_serialize_array_float(cdr, ros_message.velocity.data(), size);
  }
  // Member: tracking_available
  rv = ucdr_serialize_bool(cdr, ros_message.tracking_available);
  // Member: tracking_state
  rv = ucdr_serialize_int8_t(cdr, ros_message.tracking_state);
  // Member: action_state
  rv = ucdr_serialize_int8_t(cdr, ros_message.action_state);
  // Member: bounding_box_2d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.bounding_box_2d,
    cdr);
  // Member: bounding_box_3d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.bounding_box_3d,
    cdr);
  // Member: dimensions_3d
  {
    size_t size = ros_message.dimensions_3d.size();
    rv = ucdr_serialize_array_float(cdr, ros_message.dimensions_3d.data(), size);
  }
  // Member: skeleton_available
  rv = ucdr_serialize_bool(cdr, ros_message.skeleton_available);
  // Member: body_format
  rv = ucdr_serialize_int8_t(cdr, ros_message.body_format);
  // Member: head_bounding_box_2d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.head_bounding_box_2d,
    cdr);
  // Member: head_bounding_box_3d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.head_bounding_box_3d,
    cdr);
  // Member: head_position
  {
    size_t size = ros_message.head_position.size();
    rv = ucdr_serialize_array_float(cdr, ros_message.head_position.data(), size);
  }
  // Member: skeleton_2d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.skeleton_2d,
    cdr);
  // Member: skeleton_3d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.skeleton_3d,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_deserialize(
  ucdrBuffer * cdr,
  zed_interfaces::msg::Object & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: label
  ros_message.label.resize(ros_message.label.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.label[0], ros_message.label.capacity());
  if (rv) {
    ros_message.label.resize(std::strlen(&ros_message.label[0]));
  }
  // Member: label_id
  rv = ucdr_deserialize_int16_t(cdr, &ros_message.label_id);
  // Member: sublabel
  ros_message.sublabel.resize(ros_message.sublabel.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.sublabel[0], ros_message.sublabel.capacity());
  if (rv) {
    ros_message.sublabel.resize(std::strlen(&ros_message.sublabel[0]));
  }
  // Member: confidence
  rv = ucdr_deserialize_float(cdr, &ros_message.confidence);
  // Member: position
  {
    const size_t size = ros_message.position.size();
    rv = ucdr_deserialize_array_float(cdr, ros_message.position.data(), size);
  }
  // Member: position_covariance
  {
    const size_t size = ros_message.position_covariance.size();
    rv = ucdr_deserialize_array_float(cdr, ros_message.position_covariance.data(), size);
  }
  // Member: velocity
  {
    const size_t size = ros_message.velocity.size();
    rv = ucdr_deserialize_array_float(cdr, ros_message.velocity.data(), size);
  }
  // Member: tracking_available
  rv = ucdr_deserialize_bool(cdr, &ros_message.tracking_available);
  // Member: tracking_state
  rv = ucdr_deserialize_int8_t(cdr, &ros_message.tracking_state);
  // Member: action_state
  rv = ucdr_deserialize_int8_t(cdr, &ros_message.action_state);
  // Member: bounding_box_2d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.bounding_box_2d);
  // Member: bounding_box_3d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.bounding_box_3d);
  // Member: dimensions_3d
  {
    const size_t size = ros_message.dimensions_3d.size();
    rv = ucdr_deserialize_array_float(cdr, ros_message.dimensions_3d.data(), size);
  }
  // Member: skeleton_available
  rv = ucdr_deserialize_bool(cdr, &ros_message.skeleton_available);
  // Member: body_format
  rv = ucdr_deserialize_int8_t(cdr, &ros_message.body_format);
  // Member: head_bounding_box_2d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.head_bounding_box_2d);
  // Member: head_bounding_box_3d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.head_bounding_box_3d);
  // Member: head_position
  {
    const size_t size = ros_message.head_position.size();
    rv = ucdr_deserialize_array_float(cdr, ros_message.head_position.data(), size);
  }
  // Member: skeleton_2d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.skeleton_2d);
  // Member: skeleton_3d
  rv = zed_interfaces::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.skeleton_3d);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
get_serialized_size(
  const zed_interfaces::msg::Object & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: label
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.label.size() + 1;
  // Member: label_id
  {
    const size_t item_size = sizeof(ros_message.label_id);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: sublabel
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.sublabel.size() + 1;
  // Member: confidence
  {
    const size_t item_size = sizeof(ros_message.confidence);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: position
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message.position[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: position_covariance
  {
    const size_t array_size = 6;
    const size_t item_size = sizeof(ros_message.position_covariance[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: velocity
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message.velocity[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: tracking_available
  {
    const size_t item_size = sizeof(ros_message.tracking_available);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: tracking_state
  {
    const size_t item_size = sizeof(ros_message.tracking_state);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: action_state
  {
    const size_t item_size = sizeof(ros_message.action_state);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: bounding_box_2d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.bounding_box_2d,
    current_alignment);
  // Member: bounding_box_3d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.bounding_box_3d,
    current_alignment);
  // Member: dimensions_3d
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message.dimensions_3d[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: skeleton_available
  {
    const size_t item_size = sizeof(ros_message.skeleton_available);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: body_format
  {
    const size_t item_size = sizeof(ros_message.body_format);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: head_bounding_box_2d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.head_bounding_box_2d,
    current_alignment);
  // Member: head_bounding_box_3d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.head_bounding_box_3d,
    current_alignment);
  // Member: head_position
  {
    const size_t array_size = 3;
    const size_t item_size = sizeof(ros_message.head_position[0]);
    current_alignment += ucdr_alignment(current_alignment, item_size) + (array_size * item_size);
  }
  // Member: skeleton_2d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.skeleton_2d,
    current_alignment);
  // Member: skeleton_3d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.skeleton_3d,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
max_serialized_size_Object(
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
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_BoundingBox2Di(
    full_bounded,
    current_alignment);
  // Member: bounding_box_3d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_BoundingBox3D(
    full_bounded,
    current_alignment);
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
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_BoundingBox2Df(
    full_bounded,
    current_alignment);
  // Member: head_bounding_box_3d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_BoundingBox3D(
    full_bounded,
    current_alignment);
  // Member: head_position
  {
    const size_t array_size = 3;
    current_alignment += ucdr_alignment(current_alignment, sizeof(float)) + (array_size * sizeof(float));
  }
  // Member: skeleton_2d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_Skeleton2D(
    full_bounded,
    current_alignment);
  // Member: skeleton_3d
  current_alignment += zed_interfaces::msg::typesupport_microxrcedds_cpp::max_serialized_size_Skeleton3D(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _Object__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Object *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Object__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<zed_interfaces::msg::Object *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Object__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Object *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Object__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const zed_interfaces::msg::Object *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _Object__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_Object(&full_bounded, 0);
}

static message_type_support_callbacks_t _Object__callbacks = {
  "zed_interfaces::msg",
  "Object",
  _Object__cdr_serialize,
  _Object__cdr_deserialize,
  _Object__get_serialized_size,
  _Object__get_serialized_size_with_initial_alignment,
  _Object__max_serialized_size
};

static rosidl_message_type_support_t _Object__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_Object__callbacks,
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
get_message_type_support_handle<zed_interfaces::msg::Object>()
{
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_Object__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, msg, Object)() {
  return &zed_interfaces::msg::typesupport_microxrcedds_cpp::_Object__handle;
}

#ifdef __cplusplus
}
#endif
