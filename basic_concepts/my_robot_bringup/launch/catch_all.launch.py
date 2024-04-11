from launch import LaunchDescription
from launch_ros.actions import Node 


def generate_launch_description():
    ld = LaunchDescription()

    turtlesim_node = Node(
        package="turtlesim",
        executable="turtlesim_node",
        name="turtlesim"
    )

    turtle_spawner_node = Node(
        package="my_py_pkg",
        executable="turtle_spawner",
        name="turtle_spawner",
        parameters=[
            {"secs": 4}
        ]
    )

    main_turtle_node = Node(
        package="my_py_pkg",
        executable="main_turtle",
        name="main_turtle"
    )

    ld.add_action(turtlesim_node)
    ld.add_action(turtle_spawner_node)
    ld.add_action(main_turtle_node)
    return ld
