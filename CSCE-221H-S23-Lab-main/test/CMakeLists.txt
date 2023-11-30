#
# This function adds a test.
#
function(add_lab_test test_name)
  set(test_source "${test_name}.cpp")
  set(test_exe "${test_name}")
  add_executable(${test_exe} ${test_source})
  target_include_directories(${test_exe} PUBLIC "${CMAKE_SOURCE_DIR}/include")
  target_include_directories(${test_exe} PUBLIC "${CMAKE_SOURCE_DIR}/external")
  add_test(${test_exe} ${test_exe})
endfunction()

# add_lab_test(test_vector)
# add_lab_test(test_stack)
# add_lab_test(test_queue)
# add_lab_test(test_naive_set)

# add_lab_test(test_hash_table_set)
# add_lab_test(test_linear_probe_set)
# add_lab_test(test_heap_sort)
# add_lab_test(test_vector)

# add_lab_test(simple)