cmake_minimum_required(VERSION 3.30)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "" FORCE)
endif()

project(Image_Picker CXX)

if(WIN32)
    set(Qt6_DIR	"C:\\Development\\Qt\\6.9.3\\msvc2022_64\\lib\\cmake\\Qt6")
    set(Qt6_DLL_DIR "C:\\Development\\Qt\\6.9.3\\msvc2022_64\\bin")
    set(Qt6_PLUGIN_DIR "C:\\Development\\Qt\\6.9.3\\msvc2022_64\\plugins\\platforms")
elseif(APPLE)
    set(Qt6_DIR	"/Volumes/Miscellaneous/Development/Qt/6.9.3/macos/lib/cmake/Qt6")
endif()

find_package(Qt6 COMPONENTS
    Core
    Gui
    Widgets
    REQUIRED)

qt_standard_project_setup()

if(WIN32)
    set(app_icon_resource_windows
        "${CMAKE_CURRENT_SOURCE_DIR}/resource.rc"
    )

    qt_add_executable(Image_Picker main.cpp
        backend.cpp
        MyWindow.h
        ImageViewer.h
        ImageViewer.cpp
        resource.qrc
        ${app_icon_resource_windows}
    )

    set_target_properties(Image_Picker PROPERTIES WIN32_EXECUTABLE ON)

    target_link_libraries(Image_Picker PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)

    set(Qt6_DLLS
        "${Qt6_DLL_DIR}/Qt6Core.dll"
        "${Qt6_DLL_DIR}/Qt6Gui.dll"
        "${Qt6_DLL_DIR}/Qt6Widgets.dll"
    )

    foreach(DLL ${Qt6_DLLS})
        add_custom_command(TARGET Image_Picker POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DLL} ${CMAKE_CURRENT_BINARY_DIR})
    endforeach()

    add_custom_command(TARGET Image_Picker POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/platforms
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${Qt6_PLUGIN_DIR}/qwindows.dll" ${CMAKE_CURRENT_BINARY_DIR}/platforms)

elseif(APPLE)
    set(MACOSX_BUNDLE_ICON_FILE window.icns)

    set(app_icon "${CMAKE_CURRENT_SOURCE_DIR}/icons/window.icns")
    set_source_files_properties(${app_icon} PROPERTIES
           MACOSX_PACKAGE_LOCATION "Resources")

    qt_add_executable(Image_Picker main.cpp
        backend.cpp
        MyWindow.h
        ImageViewer.h
        ImageViewer.cpp
        resource.qrc
        ${app_icon}
    )

    set_target_properties(Image_Picker PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_BUNDLE_NAME "Image Picker"
    )

    target_link_libraries(Image_Picker PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
    )

    add_custom_command(TARGET Image_Picker POST_BUILD
        COMMAND "macdeployqt"
                "$<TARGET_BUNDLE_DIR:Image_Picker>"
    )
endif()