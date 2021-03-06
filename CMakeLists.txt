cmake_minimum_required(VERSION 3.8)

# This batch of set statements will need their values changed to values
# that are appropriate for your development environment.
set(VulkanSDK "/home/dkaip/Downloads/VulkanSDK/1.2.148.1")
set(NormalSystemLibraries "/usr/lib64")
set(WaylandLibraries "/usr/lib64")
set(VulkanSDKLibraries "${VulkanSDK}/x86_64/lib")

set(JNIHeaders1 "/usr/lib/jvm/java-1.8.0/include/linux")
set(JNIHeaders2 "/usr/lib/jvm/java-1.8.0/include")

set(VulkanSDKHeaders "${VulkanSDK}/x86_64/include")

set(WaylandHeaders "/home/dkaip/wayland/wayland-1.16.92/src")

# Now get on with business and get the library built
project(jvulkan-natives-Linux-x86_64)

find_library(VULKAN_SDK_NATIVE_LIBRARIES
	NAMES 
		vulkan
		 PATHS ${VulkanSDKLibraries} NO_DEFAULT_PATH)

find_library(WAYLAND_LIBRARIES NAMES wayland-client PATHS ${WaylandLibraries})

# The additional / is important to remove the last character from the path.
# Note that it does not matter if the OS uses / or \, because we are only
# saving the path size.
string(LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_PATH_SIZE)
add_definitions("-DSOURCE_PATH_SIZE=${SOURCE_PATH_SIZE}")

file(GLOB vulkan_natives_sources ./*.cpp ./*/*.cpp)
set(vulkan_natives_srcs ${vulkan_natives_sources}) 

add_library(jvulkan-natives-Linux-x86_64 SHARED ${vulkan_natives_srcs})

target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE ./headers)

# Headers for JNI stuff
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE ${JNIHeaders1})
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE ${JNIHeaders2})

# Headers for Vulkan SDK, currently 1.1.126.0
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE ${VulkanSDKHeaders})

# Headers for Wayland stuff
target_include_directories(jvulkan-natives-Linux-x86_64 PRIVATE ${WaylandHeaders})

# Add wayland modules
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE ${WAYLAND_LIBRARIES})

# Add vulkan modules
target_link_libraries(jvulkan-natives-Linux-x86_64 PRIVATE ${VULKAN_SDK_NATIVE_LIBRARIES})
