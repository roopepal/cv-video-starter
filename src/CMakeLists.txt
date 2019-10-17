find_package(OpenCV 4.1.1 REQUIRED)

#message(STATUS "OpenCV library status:")
#message(STATUS "    config: ${OpenCV_DIR}")
#message(STATUS "    version: ${OpenCV_VERSION}")
#message(STATUS "    libraries: ${OpenCV_LIBS}")
#message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(main main.cpp)

target_link_libraries(
    main ${OpenCV_LIBS}
)

target_compile_definitions(
    main PRIVATE DATA_DIR=\"${PROJECT_SOURCE_DIR}/data/\"
)

INSTALL(
    TARGETS main 
    DESTINATION ${PROJECT_SOURCE_DIR}/build
)
