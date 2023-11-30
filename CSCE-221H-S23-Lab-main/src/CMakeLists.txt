#
# This function adds an executable.
#
function(add_exe example_name)
  set(example_source "${example_name}.cpp")
  set(example_exe "${example_name}")
  add_executable(${example_exe} ${example_source})
  target_include_directories(${example_exe} PUBLIC "${CMAKE_SOURCE_DIR}/include")
  target_include_directories(${example_exe} PUBLIC "${CMAKE_SOURCE_DIR}/external")
endfunction()

add_exe(lab03)
add_exe(lab08)
add_exe(lab09)
add_exe(lab10)