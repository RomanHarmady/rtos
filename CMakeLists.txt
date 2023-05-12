cmake_minimum_required(VERSION 3.8)
project(rtos)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(realtime_tools REQUIRED)
include_directories(${realtime_tools_INCLUDE_DIRS})

set(dependencies "geometry_msgs" "rclcpp")
#add_executable(rtos_pub src/rtos_pub.cpp)
#ament_target_dependencies(rtos_pub ${dependencies})

add_executable(rtos_sub src/rtos_sub.cpp)
ament_target_dependencies(rtos_sub ${dependencies})

add_executable(logger src/logger.cpp)
ament_target_dependencies(logger  ${dependencies})

add_executable(rtos_node src/rtos_node.cpp)
ament_target_dependencies(rtos_node ${dependencies})

#add_executable(realtime_pub src/realtime_pub.cpp)
#ament_target_dependencies(realtime_pub ${dependencies})

install(TARGETS
  #rtos_pub
  rtos_sub
  rtos_node
  logger
 # realtime_pub
  DESTINATION lib/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
