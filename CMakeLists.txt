cmake_minimum_required(VERSION 3.8)

project(jvulkan-natives-Linux-x86_64)

file(GLOB vulkan_natives_sources ./*.cpp ./*/*.cpp)
SET( vulkan_natives_srcs ${vulkan_natives_sources}) 

add_library(jvulkan-natives-Linux-x86_64 SHARED ${vulkan_natives_srcs})

target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE ./headers)

# Headers for JNI stuff
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /usr/lib/jvm/java-1.8.0/include/linux)
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /usr/lib/jvm/java-1.8.0/include)

# Headers for Vulkan SDK, currently 1.1.101.0
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /home/dkaip/Downloads/VulkanSDK/1.1.101.0/x86_64/include)

# Headers for Wayland stuff
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE /home/dkaip/wayland/wayland-1.16.92/src)

