# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(simpletextviewer LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

qt_add_executable(simpletextviewer
    assistant.cpp assistant.h
    findfiledialog.cpp findfiledialog.h
    main.cpp
    mainwindow.cpp mainwindow.h
    textedit.cpp textedit.h
    openurldialog.h openurldialog.cpp
)

set_target_properties(simpletextviewer PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_compile_definitions(simpletextviewer PUBLIC
    SRCDIR="${CMAKE_CURRENT_SOURCE_DIR}/"
)

target_link_libraries(simpletextviewer PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets
    Qt::Network
)
