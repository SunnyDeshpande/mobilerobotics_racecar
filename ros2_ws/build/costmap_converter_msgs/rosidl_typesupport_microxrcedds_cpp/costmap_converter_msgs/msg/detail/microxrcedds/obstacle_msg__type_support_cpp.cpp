// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from costmap_converter_msgs:msg/ObstacleMsg.idl
// generated code does not contain a copyright notice
#include "costmap_converter_msgs/msg/detail/obstacle_msg__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "costmap_converter_msgs/msg/detail/obstacle_msg__struct.hpp"

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
namespace std_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  std_msgs::msg::Header &);

size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);

size_t
max_serialized_size_Header(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace std_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Polygon &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Polygon &);

size_t get_serialized_size(
  const geometry_msgs::msg::Polygon &,
  size_t current_alignment);

size_t
max_serialized_size_Polygon(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Quaternion &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::Quaternion &);

size_t get_serialized_size(
  const geometry_msgs::msg::Quaternion &,
  size_t current_alignment);

size_t
max_serialized_size_Quaternion(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs

namespace geometry_msgs
{
namespace msg
{
namespace typesupport_microxrcedds_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::TwistWithCovariance &,
  ucdrBuffer *);

bool cdr_deserialize(
  ucdrBuffer *,
  geometry_msgs::msg::TwistWithCovariance &);

size_t get_serialized_size(
  const geometry_msgs::msg::TwistWithCovariance &,
  size_t current_alignment);

size_t
max_serialized_size_TwistWithCovariance(
  bool * full_bounded,
  size_t current_alignment);
}  // namespace typesupport_microxrcedds_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace costmap_converter_msgs
{

namespace msg
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_costmap_converter_msgs
cdr_serialize(
  const costmap_converter_msgs::msg::ObstacleMsg & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: polygon
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.polygon,
    cdr);
  // Member: radius
  rv = ucdr_serialize_double(cdr, ros_message.radius);
  // Member: id
  rv = ucdr_serialize_int64_t(cdr, ros_message.id);
  // Member: orientation
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.orientation,
    cdr);
  // Member: velocities
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_serialize(
    ros_message.velocities,
    cdr);

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_costmap_converter_msgs
cdr_deserialize(
  ucdrBuffer * cdr,
  costmap_converter_msgs::msg::ObstacleMsg & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: header
  rv = std_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.header);
  // Member: polygon
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.polygon);
  // Member: radius
  rv = ucdr_deserialize_double(cdr, &ros_message.radius);
  // Member: id
  rv = ucdr_deserialize_int64_t(cdr, &ros_message.id);
  // Member: orientation
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.orientation);
  // Member: velocities
  rv = geometry_msgs::msg::typesupport_microxrcedds_cpp::cdr_deserialize(
    cdr,
    ros_message.velocities);

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_costmap_converter_msgs
get_serialized_size(
  const costmap_converter_msgs::msg::ObstacleMsg & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment += std_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.header,
    current_alignment);
  // Member: polygon
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.polygon,
    current_alignment);
  // Member: radius
  {
    const size_t item_size = sizeof(ros_message.radius);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: id
  {
    const size_t item_size = sizeof(ros_message.id);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: orientation
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.orientation,
    current_alignment);
  // Member: velocities
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::get_serialized_size(
    ros_message.velocities,
    current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_costmap_converter_msgs
max_serialized_size_ObstacleMsg(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment += std_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Header(
    full_bounded,
    current_alignment);
  // Member: polygon
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Polygon(
    full_bounded,
    current_alignment);
  // Member: radius
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: id
  current_alignment += ucdr_alignment(current_alignment, sizeof(int64_t)) + sizeof(int64_t);
  // Member: orientation
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_Quaternion(
    full_bounded,
    current_alignment);
  // Member: velocities
  current_alignment += geometry_msgs::msg::typesupport_microxrcedds_cpp::max_serialized_size_TwistWithCovariance(
    full_bounded,
    current_alignment);

  return current_alignment - initial_alignment;
}

static bool _ObstacleMsg__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const costmap_converter_msgs::msg::ObstacleMsg *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ObstacleMsg__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<costmap_converter_msgs::msg::ObstacleMsg *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ObstacleMsg__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const costmap_converter_msgs::msg::ObstacleMsg *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ObstacleMsg__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const costmap_converter_msgs::msg::ObstacleMsg *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _ObstacleMsg__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_ObstacleMsg(&full_bounded, 0);
}

static message_type_support_callbacks_t _ObstacleMsg__callbacks = {
  "costmap_converter_msgs::msg",
  "ObstacleMsg",
  _ObstacleMsg__cdr_serialize,
  _ObstacleMsg__cdr_deserialize,
  _ObstacleMsg__get_serialized_size,
  _ObstacleMsg__get_serialized_size_with_initial_alignment,
  _ObstacleMsg__max_serialized_size
};

static rosidl_message_type_support_t _ObstacleMsg__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_ObstacleMsg__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace msg

}  // namespace costmap_converter_msgs

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_costmap_converter_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<costmap_converter_msgs::msg::ObstacleMsg>()
{
  return &costmap_converter_msgs::msg::typesupport_microxrcedds_cpp::_ObstacleMsg__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, costmap_converter_msgs, msg, ObstacleMsg)() {
  return &costmap_converter_msgs::msg::typesupport_microxrcedds_cpp::_ObstacleMsg__handle;
}

#ifdef __cplusplus
}
#endif
