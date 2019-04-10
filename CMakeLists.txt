cmake_minimum_required(VERSION 3.8)

project(jvulkan-natives-Linux-x86_64)

file(GLOB vulkan_natives_sources ./*.cpp ./*/*.cpp)
SET( vulkan_natives_srcs ${vulkan_natives_sources}) 

# Add link library paths, BTW, this line needs to be before the add_library line below
link_directories(/usr/lib64 /home/dkaip/Downloads/VulkanSDK/1.1.101.0/x86_64/lib)

add_library(jvulkan-natives-Linux-x86_64 SHARED ${vulkan_natives_srcs})

target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE ./headers)

# Headers for JNI stuff
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /usr/lib/jvm/java-1.8.0/include/linux)
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /usr/lib/jvm/java-1.8.0/include)

# Headers for Vulkan SDK, currently 1.1.101.0
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /home/dkaip/Downloads/VulkanSDK/1.1.101.0/x86_64/include)

# Headers for Wayland stuff
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /home/dkaip/wayland/wayland-1.16.92/src)

# Add wayland modules
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE wayland-client)

# Add vulkan modules
# target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE vulkan VkLayer_api_dump VkLayer_assistant_layer VkLayer_core_validation VkLayer_device_simulation VkLayer_monitor VkLayer_object_tracker VkLayer_parameter_validation VkLayer_screenshot VkLayer_threading VkLayer_unique_objects VkLayer_utils VkLayer_vktrace_layer)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE vulkan)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_api_dump)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_assistant_layer)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_core_validation)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_device_simulation)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_monitor)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_object_tracker)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_parameter_validation)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_screenshot)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_threading)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_unique_objects)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_utils)
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE VkLayer_vktrace_layer)
