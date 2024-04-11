// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:srv/Location.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__LOCATION__STRUCT_H_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in srv/Location in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__Location_Request
{
  geometry_msgs__msg__Vector3 location;
} my_robot_interfaces__srv__Location_Request;

// Struct for a sequence of my_robot_interfaces__srv__Location_Request.
typedef struct my_robot_interfaces__srv__Location_Request__Sequence
{
  my_robot_interfaces__srv__Location_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__Location_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Location in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__Location_Response
{
  bool success;
} my_robot_interfaces__srv__Location_Response;

// Struct for a sequence of my_robot_interfaces__srv__Location_Response.
typedef struct my_robot_interfaces__srv__Location_Response__Sequence
{
  my_robot_interfaces__srv__Location_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__Location_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__LOCATION__STRUCT_H_
