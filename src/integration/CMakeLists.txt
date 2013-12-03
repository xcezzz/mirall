MACRO_OPTIONAL_FIND_PACKAGE(NautilusExtension)

if (NAUTILUS_EXT_FOUND)
    add_subdirectory(nautilus)
endif (NAUTILUS_EXT_FOUND)

#add_subdirectory(explorer)
#add_subdirectory(finder)
