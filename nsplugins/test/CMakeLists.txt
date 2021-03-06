set( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR} )
include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/../ )

########### next target ###############

set(testnsplugin_SRCS testnsplugin.cpp ${nsplugins_SRCS} )

qt4_add_dbus_adaptor( testnsplugin_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/../org.kde.nsplugins.CallBack.xml ${CMAKE_CURRENT_SOURCE_DIR}/../plugin_part.h PluginPart
)

set(nsplugins_class_xml  ${CMAKE_CURRENT_SOURCE_DIR}/../viewer/org.kde.nsplugins.class.xml)
QT4_ADD_DBUS_INTERFACE( testnsplugin_SRCS ${nsplugins_class_xml} nsplugins_class_interface )

set(nsplugins_instance_xml  ${CMAKE_CURRENT_SOURCE_DIR}/../viewer/org.kde.nsplugins.instance.xml)
set_source_files_properties(${nsplugins_instance_xml} PROPERTIES INCLUDE "comm/dbustypes.h")
QT4_ADD_DBUS_INTERFACE( testnsplugin_SRCS ${nsplugins_instance_xml} nsplugins_instance_interface )

set(nsplugins_viewer_xml  ${CMAKE_CURRENT_SOURCE_DIR}/../viewer/org.kde.nsplugins.viewer.xml)
QT4_ADD_DBUS_INTERFACE( testnsplugin_SRCS ${nsplugins_viewer_xml} nsplugins_viewer_interface )

kde4_add_executable(testnsplugin TEST ${testnsplugin_SRCS})

target_link_libraries(testnsplugin ${KDE4_KPARTS_LIBS} ${QT_QTDBUS_LIBRARY})
