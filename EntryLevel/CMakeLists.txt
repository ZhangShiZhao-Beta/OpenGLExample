# EntryLevel
set(HEADER_FILES
    inc/xxx.h
)

set(SOURCE_FILES
    src/xxx.cpp
)

add_library(EntryLevel)

target_sources(EntryLevel
    PRIVATE
        ${SOURCE_FILES}
    PUBLIC
        ${HEADER_FILES}
)

target_include_directories(EntryLevel
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
