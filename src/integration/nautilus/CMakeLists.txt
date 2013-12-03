project(nautilus_owncloud C)

cmake_minimum_required(VERSION 2.6)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set (nautilus_owncloud_SOURCES
     plugin.c
     context-menu.c
     overlay.c
    )
set (nautilus_owncloud_HEADERS context-menu.h overlay.h)

include_directories(${NAUTILUS_EXT_INCLUDE_DIRS})
link_directories(${NAUTILUS_EXT_LIBRARY_DIRS})
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_library(nautilus_owncloud SHARED
            ${nautilus_owncloud_SOURCES}
            ${nautilus_owncloud_SOURCES})

target_link_libraries(nautilus_owncloud ${GTK3_LIBRARIES})
target_link_libraries(nautilus_owncloud ${NAUTILUS_EXT_LIBRARIES})

execute_process(COMMAND pkg-config libnautilus-extension --variable extensiondir
                OUTPUT_VARIABLE _extensiondir OUTPUT_STRIP_TRAILING_WHITESPACE)

install(TARGETS nautilus_owncloud DESTINATION ${_extensiondir})
