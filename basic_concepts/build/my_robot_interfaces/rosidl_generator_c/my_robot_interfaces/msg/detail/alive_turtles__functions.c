// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_robot_interfaces:msg/AliveTurtles.idl
// generated code does not contain a copyright notice
#include "my_robot_interfaces/msg/detail/alive_turtles__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `alive_turles`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
my_robot_interfaces__msg__AliveTurtles__init(my_robot_interfaces__msg__AliveTurtles * msg)
{
  if (!msg) {
    return false;
  }
  // alive_turles
  if (!geometry_msgs__msg__Vector3__Sequence__init(&msg->alive_turles, 0)) {
    my_robot_interfaces__msg__AliveTurtles__fini(msg);
    return false;
  }
  return true;
}

void
my_robot_interfaces__msg__AliveTurtles__fini(my_robot_interfaces__msg__AliveTurtles * msg)
{
  if (!msg) {
    return;
  }
  // alive_turles
  geometry_msgs__msg__Vector3__Sequence__fini(&msg->alive_turles);
}

bool
my_robot_interfaces__msg__AliveTurtles__are_equal(const my_robot_interfaces__msg__AliveTurtles * lhs, const my_robot_interfaces__msg__AliveTurtles * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // alive_turles
  if (!geometry_msgs__msg__Vector3__Sequence__are_equal(
      &(lhs->alive_turles), &(rhs->alive_turles)))
  {
    return false;
  }
  return true;
}

bool
my_robot_interfaces__msg__AliveTurtles__copy(
  const my_robot_interfaces__msg__AliveTurtles * input,
  my_robot_interfaces__msg__AliveTurtles * output)
{
  if (!input || !output) {
    return false;
  }
  // alive_turles
  if (!geometry_msgs__msg__Vector3__Sequence__copy(
      &(input->alive_turles), &(output->alive_turles)))
  {
    return false;
  }
  return true;
}

my_robot_interfaces__msg__AliveTurtles *
my_robot_interfaces__msg__AliveTurtles__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__AliveTurtles * msg = (my_robot_interfaces__msg__AliveTurtles *)allocator.allocate(sizeof(my_robot_interfaces__msg__AliveTurtles), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_robot_interfaces__msg__AliveTurtles));
  bool success = my_robot_interfaces__msg__AliveTurtles__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_robot_interfaces__msg__AliveTurtles__destroy(my_robot_interfaces__msg__AliveTurtles * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_robot_interfaces__msg__AliveTurtles__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_robot_interfaces__msg__AliveTurtles__Sequence__init(my_robot_interfaces__msg__AliveTurtles__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__AliveTurtles * data = NULL;

  if (size) {
    data = (my_robot_interfaces__msg__AliveTurtles *)allocator.zero_allocate(size, sizeof(my_robot_interfaces__msg__AliveTurtles), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_robot_interfaces__msg__AliveTurtles__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_robot_interfaces__msg__AliveTurtles__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_robot_interfaces__msg__AliveTurtles__Sequence__fini(my_robot_interfaces__msg__AliveTurtles__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_robot_interfaces__msg__AliveTurtles__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_robot_interfaces__msg__AliveTurtles__Sequence *
my_robot_interfaces__msg__AliveTurtles__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_robot_interfaces__msg__AliveTurtles__Sequence * array = (my_robot_interfaces__msg__AliveTurtles__Sequence *)allocator.allocate(sizeof(my_robot_interfaces__msg__AliveTurtles__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_robot_interfaces__msg__AliveTurtles__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_robot_interfaces__msg__AliveTurtles__Sequence__destroy(my_robot_interfaces__msg__AliveTurtles__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_robot_interfaces__msg__AliveTurtles__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_robot_interfaces__msg__AliveTurtles__Sequence__are_equal(const my_robot_interfaces__msg__AliveTurtles__Sequence * lhs, const my_robot_interfaces__msg__AliveTurtles__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_robot_interfaces__msg__AliveTurtles__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_robot_interfaces__msg__AliveTurtles__Sequence__copy(
  const my_robot_interfaces__msg__AliveTurtles__Sequence * input,
  my_robot_interfaces__msg__AliveTurtles__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_robot_interfaces__msg__AliveTurtles);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_robot_interfaces__msg__AliveTurtles * data =
      (my_robot_interfaces__msg__AliveTurtles *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_robot_interfaces__msg__AliveTurtles__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_robot_interfaces__msg__AliveTurtles__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_robot_interfaces__msg__AliveTurtles__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
