#
# Set the binary executable name
#
set(project_BIN ${PROJECT_NAME})

#
# Find all executables
#
file(GLOB project_SRCS *.cpp *.h)

#
# Add executables to project
#
add_executable(${project_BIN} ${project_SRCS})

target_link_libraries(${project_BIN}
    PRIVATE io2d::io2d
    PUBLIC pugixml
)
