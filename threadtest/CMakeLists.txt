

ADD_EXECUTABLE(thread thread.cpp testthread.cpp)
target_link_libraries(thread pthread)