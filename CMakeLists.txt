cmake_minimum_required(VERSION 3.10)

set(MATHILDA Mathilda)

project(${MATHILDA} C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__USE_MINGW_ANSI_STDIO=1")

#defines
add_compile_definitions(HAVE_ILDA_INLINE)
add_compile_definitions(
    $<$<CONFIG:Debug>:ILDA_DEBUG>
    $<$<CONFIG:Debug>:ILDA_ENABLE_ASSERTS>
    $<$<CONFIG:Release>:ILDA_RELEASE>
    $<$<CONFIG:Release>:ILDA_ENABLE_ASSERTS>
    $<$<CONFIG:Dist>:ILDA_DIST>
)

#files (sources and headers)
file(GLOB_RECURSE SRC_FILES "./${MATHILDA}/src/**.c" "${MATHILDA}src/**.cpp")
file(GLOB_RECURSE HEADER_FILES "./${MATHILDA}/src/**.h" "${MATHILDA}/src/**.hpp")

set(FILTERED_SRC_FILES)

foreach(file ${SRC_FILES})
    if(NOT file MATCHES ".*source\\.c$")
        list(APPEND FILTERED_SRC_FILES ${file})
    endif()

endforeach()

#exec
option(ILDA_EXEC_BUILD "build an exec" OFF)
if(ILDA_EXEC_BUILD)
    add_executable(${MATHILDA} ${FILTERED_SRC_FILES} ${HEADER_FILES})
else()
    add_library(${MATHILDA} STATIC ${FILTERED_SRC_FILES} ${HEADER_FILES})
endif(ILDA_EXEC_BUILD)
unset(ILDA_EXEC_BUILD CACHE)
#include dirs
target_include_directories(${MATHILDA} PRIVATE "./${MATHILDA}/include")
target_include_directories(${MATHILDA} PRIVATE "./${MATHILDA}/src")

#set binaries folder
if(NOT TARGET_ARCH)
    if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
        set(TARGET_ARCH "x86_64")
    elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86")
        set(TARGET_ARCH "x86")
    elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
        set(TARGET_ARCH "ARM64")
    endif()
endif()


set(ILDA_OUTPUT_DIR $<CONFIG>-${TARGET_ARCH}-$<PLATFORM_ID>)
install(TARGETS ${MATHILDA}
    RUNTIME         DESTINATION "bin/${ILDA_OUTPUT_DIR}"
    ARCHIVE         DESTINATION "lib/${ILDA_OUTPUT_DIR}"
    LIBRARY         DESTINATION "lib/${ILDA_OUTPUT_DIR}"
    FILES $<TARGET_PDB_FILE:${MATHILDA}> DESTINATION "bin-int/$<CONFIG>-${CMAKE_SYSTEM_PROCESSOR}-$<PLATFORM_ID>" OPTIONAL
)

#file(GLOB_RECURSE OBJECT_FILES "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/*.o"
#                       "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/*.obj")

#install(FILES ${OBJECT_FILES}
#    DESTINATION "bin-int/${ILDA_OUTPUT_DIR}"
#)

