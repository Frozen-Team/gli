#==============================================================================
# Copyright (c) 2015 Frozen Team.
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation 
# the rights to use, copy, modify, merge, publish, distribute, sublicense, 
# and/or sell copies of the Software, and to permit persons to whom the 
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included 
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
# SOFTWARE.
#==============================================================================
# CMakeLists for GLI
cmake_minimum_required(VERSION 3.3)

project(GLI CXX)

set(GLI_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include/gli" CACHE PATH "The directory the headers are installed in")

file(GLOB_RECURSE GLI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/gli/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/gli/*.inl)
file(GLOB_RECURSE GLI_FILES_CORE ${CMAKE_CURRENT_SOURCE_DIR}/gli/core/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/gli/core/*.inl)

install(FILES ${GLI_FILES}
    DESTINATION "${GLI_INCLUDE_INSTALL_DIR}"
    COMPONENT dev)

install(FILES ${GLI_FILES_CORE}
    DESTINATION "${GLI_INCLUDE_INSTALL_DIR}/core/"
    COMPONENT dev)