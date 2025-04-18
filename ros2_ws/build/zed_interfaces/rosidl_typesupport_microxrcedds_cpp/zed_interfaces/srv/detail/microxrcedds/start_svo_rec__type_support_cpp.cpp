// generated from rosidl_typesupport_microxrcedds_cpp/resource/idl__type_support.cpp.em
// with input from zed_interfaces:srv/StartSvoRec.idl
// generated code does not contain a copyright notice
#include "zed_interfaces/srv/detail/start_svo_rec__rosidl_typesupport_microxrcedds_cpp.hpp"
#include "zed_interfaces/srv/detail/start_svo_rec__struct.hpp"

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

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_serialize(
  const zed_interfaces::srv::StartSvoRec_Request & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: bitrate
  rv = ucdr_serialize_uint32_t(cdr, ros_message.bitrate);
  // Member: compression_mode
  rv = ucdr_serialize_uint8_t(cdr, ros_message.compression_mode);
  // Member: target_framerate
  rv = ucdr_serialize_uint32_t(cdr, ros_message.target_framerate);
  // Member: input_transcode
  rv = ucdr_serialize_bool(cdr, ros_message.input_transcode);
  // Member: svo_filename
  rv = ucdr_serialize_string(cdr, ros_message.svo_filename.c_str());

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_deserialize(
  ucdrBuffer * cdr,
  zed_interfaces::srv::StartSvoRec_Request & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: bitrate
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message.bitrate);
  // Member: compression_mode
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message.compression_mode);
  // Member: target_framerate
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message.target_framerate);
  // Member: input_transcode
  rv = ucdr_deserialize_bool(cdr, &ros_message.input_transcode);
  // Member: svo_filename
  ros_message.svo_filename.resize(ros_message.svo_filename.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.svo_filename[0], ros_message.svo_filename.capacity());
  if (rv) {
    ros_message.svo_filename.resize(std::strlen(&ros_message.svo_filename[0]));
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
get_serialized_size(
  const zed_interfaces::srv::StartSvoRec_Request & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: bitrate
  {
    const size_t item_size = sizeof(ros_message.bitrate);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: compression_mode
  {
    const size_t item_size = sizeof(ros_message.compression_mode);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: target_framerate
  {
    const size_t item_size = sizeof(ros_message.target_framerate);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: input_transcode
  {
    const size_t item_size = sizeof(ros_message.input_transcode);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: svo_filename
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.svo_filename.size() + 1;

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
max_serialized_size_StartSvoRec_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: bitrate
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: compression_mode
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: target_framerate
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);
  // Member: input_transcode
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: svo_filename
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static bool _StartSvoRec_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const zed_interfaces::srv::StartSvoRec_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StartSvoRec_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<zed_interfaces::srv::StartSvoRec_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StartSvoRec_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const zed_interfaces::srv::StartSvoRec_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StartSvoRec_Request__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const zed_interfaces::srv::StartSvoRec_Request *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _StartSvoRec_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_StartSvoRec_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t _StartSvoRec_Request__callbacks = {
  "zed_interfaces::srv",
  "StartSvoRec_Request",
  _StartSvoRec_Request__cdr_serialize,
  _StartSvoRec_Request__cdr_deserialize,
  _StartSvoRec_Request__get_serialized_size,
  _StartSvoRec_Request__get_serialized_size_with_initial_alignment,
  _StartSvoRec_Request__max_serialized_size
};

static rosidl_message_type_support_t _StartSvoRec_Request__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_StartSvoRec_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace zed_interfaces

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<zed_interfaces::srv::StartSvoRec_Request>()
{
  return &zed_interfaces::srv::typesupport_microxrcedds_cpp::_StartSvoRec_Request__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, srv, StartSvoRec_Request)() {
  return &zed_interfaces::srv::typesupport_microxrcedds_cpp::_StartSvoRec_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <algorithm>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include <cstring>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/message_type_support_decl.hpp"
// already included above
// #include "ucdr/microcdr.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// forward declaration of message dependencies and their conversion functions

namespace zed_interfaces
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_serialize(
  const zed_interfaces::srv::StartSvoRec_Response & ros_message,
  ucdrBuffer * cdr)
{
  (void) ros_message;
  (void) cdr;
  bool rv = false;

  // Member: success
  rv = ucdr_serialize_bool(cdr, ros_message.success);
  // Member: message
  rv = ucdr_serialize_string(cdr, ros_message.message.c_str());

  return rv;
}

bool
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
cdr_deserialize(
  ucdrBuffer * cdr,
  zed_interfaces::srv::StartSvoRec_Response & ros_message)
{
  (void) cdr;
  (void) ros_message;
  bool rv = false;

  // Member: success
  rv = ucdr_deserialize_bool(cdr, &ros_message.success);
  // Member: message
  ros_message.message.resize(ros_message.message.capacity());
  rv = ucdr_deserialize_string(cdr, &ros_message.message[0], ros_message.message.capacity());
  if (rv) {
    ros_message.message.resize(std::strlen(&ros_message.message[0]));
  }

  return rv;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
get_serialized_size(
  const zed_interfaces::srv::StartSvoRec_Response & ros_message,
  size_t current_alignment)
{
  (void) current_alignment;
  (void) ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: success
  {
    const size_t item_size = sizeof(ros_message.success);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: message
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message.message.size() + 1;

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_PUBLIC_zed_interfaces
max_serialized_size_StartSvoRec_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: success
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: message
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static bool _StartSvoRec_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  auto typed_message =
    static_cast<const zed_interfaces::srv::StartSvoRec_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _StartSvoRec_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<zed_interfaces::srv::StartSvoRec_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _StartSvoRec_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const zed_interfaces::srv::StartSvoRec_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _StartSvoRec_Response__get_serialized_size_with_initial_alignment(
  const void * untyped_ros_message, size_t current_alignment)
{
  auto typed_message =
    static_cast<const zed_interfaces::srv::StartSvoRec_Response *>(
    untyped_ros_message);
  return static_cast<size_t>(get_serialized_size(*typed_message, current_alignment));
}

static size_t _StartSvoRec_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_StartSvoRec_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t _StartSvoRec_Response__callbacks = {
  "zed_interfaces::srv",
  "StartSvoRec_Response",
  _StartSvoRec_Response__cdr_serialize,
  _StartSvoRec_Response__cdr_deserialize,
  _StartSvoRec_Response__get_serialized_size,
  _StartSvoRec_Response__get_serialized_size_with_initial_alignment,
  _StartSvoRec_Response__max_serialized_size
};

static rosidl_message_type_support_t _StartSvoRec_Response__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_StartSvoRec_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace zed_interfaces

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_zed_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<zed_interfaces::srv::StartSvoRec_Response>()
{
  return &zed_interfaces::srv::typesupport_microxrcedds_cpp::_StartSvoRec_Response__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, srv, StartSvoRec_Response)() {
  return &zed_interfaces::srv::typesupport_microxrcedds_cpp::_StartSvoRec_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_cpp/identifier.hpp"
#include "rosidl_typesupport_microxrcedds_cpp/service_type_support_decl.hpp"

namespace zed_interfaces
{

namespace srv
{

namespace typesupport_microxrcedds_cpp
{

static service_type_support_callbacks_t _StartSvoRec__callbacks = {
  "zed_interfaces::srv",
  "StartSvoRec",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, srv, StartSvoRec_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, srv, StartSvoRec_Response),
};

static rosidl_service_type_support_t _StartSvoRec__handle = {
  rosidl_typesupport_microxrcedds_cpp::typesupport_identifier,
  &_StartSvoRec__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_microxrcedds_cpp

}  // namespace srv

}  // namespace zed_interfaces

namespace rosidl_typesupport_microxrcedds_cpp
{

template<>
ROSIDL_TYPESUPPORT_MICROXRCEDDS_CPP_EXPORT_zed_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<zed_interfaces::srv::StartSvoRec>()
{
  return &zed_interfaces::srv::typesupport_microxrcedds_cpp::_StartSvoRec__handle;
}

}  // namespace rosidl_typesupport_microxrcedds_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_cpp, zed_interfaces, srv, StartSvoRec)() {
  return &zed_interfaces::srv::typesupport_microxrcedds_cpp::_StartSvoRec__handle;
}

#ifdef __cplusplus
}
#endif
