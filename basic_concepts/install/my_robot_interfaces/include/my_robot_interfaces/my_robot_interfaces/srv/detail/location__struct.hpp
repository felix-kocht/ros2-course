// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_robot_interfaces:srv/Location.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__LOCATION__STRUCT_HPP_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__LOCATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'location'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__Location_Request __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__Location_Request __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Location_Request_
{
  using Type = Location_Request_<ContainerAllocator>;

  explicit Location_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_init)
  {
    (void)_init;
  }

  explicit Location_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _location_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _location_type location;

  // setters for named parameter idiom
  Type & set__location(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->location = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::Location_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::Location_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Location_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Location_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__Location_Request
    std::shared_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__Location_Request
    std::shared_ptr<my_robot_interfaces::srv::Location_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Location_Request_ & other) const
  {
    if (this->location != other.location) {
      return false;
    }
    return true;
  }
  bool operator!=(const Location_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Location_Request_

// alias to use template instance with default allocator
using Location_Request =
  my_robot_interfaces::srv::Location_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces


#ifndef _WIN32
# define DEPRECATED__my_robot_interfaces__srv__Location_Response __attribute__((deprecated))
#else
# define DEPRECATED__my_robot_interfaces__srv__Location_Response __declspec(deprecated)
#endif

namespace my_robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Location_Response_
{
  using Type = Location_Response_<ContainerAllocator>;

  explicit Location_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Location_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_robot_interfaces::srv::Location_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_robot_interfaces::srv::Location_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Location_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_robot_interfaces::srv::Location_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_robot_interfaces__srv__Location_Response
    std::shared_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_robot_interfaces__srv__Location_Response
    std::shared_ptr<my_robot_interfaces::srv::Location_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Location_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Location_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Location_Response_

// alias to use template instance with default allocator
using Location_Response =
  my_robot_interfaces::srv::Location_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace my_robot_interfaces

namespace my_robot_interfaces
{

namespace srv
{

struct Location
{
  using Request = my_robot_interfaces::srv::Location_Request;
  using Response = my_robot_interfaces::srv::Location_Response;
};

}  // namespace srv

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__LOCATION__STRUCT_HPP_
