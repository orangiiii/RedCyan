# Install script for directory: U:/code/cow/external/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/cow")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.4.3-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "U:/code/cow/build/external/assimp/lib/libassimp.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "U:/code/cow/external/assimp/code/../include/assimp/anim.h"
    "U:/code/cow/external/assimp/code/../include/assimp/aabb.h"
    "U:/code/cow/external/assimp/code/../include/assimp/ai_assert.h"
    "U:/code/cow/external/assimp/code/../include/assimp/camera.h"
    "U:/code/cow/external/assimp/code/../include/assimp/color4.h"
    "U:/code/cow/external/assimp/code/../include/assimp/color4.inl"
    "U:/code/cow/build/external/assimp/code/../include/assimp/config.h"
    "U:/code/cow/external/assimp/code/../include/assimp/ColladaMetaData.h"
    "U:/code/cow/external/assimp/code/../include/assimp/commonMetaData.h"
    "U:/code/cow/external/assimp/code/../include/assimp/defs.h"
    "U:/code/cow/external/assimp/code/../include/assimp/cfileio.h"
    "U:/code/cow/external/assimp/code/../include/assimp/light.h"
    "U:/code/cow/external/assimp/code/../include/assimp/material.h"
    "U:/code/cow/external/assimp/code/../include/assimp/material.inl"
    "U:/code/cow/external/assimp/code/../include/assimp/matrix3x3.h"
    "U:/code/cow/external/assimp/code/../include/assimp/matrix3x3.inl"
    "U:/code/cow/external/assimp/code/../include/assimp/matrix4x4.h"
    "U:/code/cow/external/assimp/code/../include/assimp/matrix4x4.inl"
    "U:/code/cow/external/assimp/code/../include/assimp/mesh.h"
    "U:/code/cow/external/assimp/code/../include/assimp/ObjMaterial.h"
    "U:/code/cow/external/assimp/code/../include/assimp/pbrmaterial.h"
    "U:/code/cow/external/assimp/code/../include/assimp/GltfMaterial.h"
    "U:/code/cow/external/assimp/code/../include/assimp/postprocess.h"
    "U:/code/cow/external/assimp/code/../include/assimp/quaternion.h"
    "U:/code/cow/external/assimp/code/../include/assimp/quaternion.inl"
    "U:/code/cow/external/assimp/code/../include/assimp/scene.h"
    "U:/code/cow/external/assimp/code/../include/assimp/metadata.h"
    "U:/code/cow/external/assimp/code/../include/assimp/texture.h"
    "U:/code/cow/external/assimp/code/../include/assimp/types.h"
    "U:/code/cow/external/assimp/code/../include/assimp/vector2.h"
    "U:/code/cow/external/assimp/code/../include/assimp/vector2.inl"
    "U:/code/cow/external/assimp/code/../include/assimp/vector3.h"
    "U:/code/cow/external/assimp/code/../include/assimp/vector3.inl"
    "U:/code/cow/external/assimp/code/../include/assimp/version.h"
    "U:/code/cow/external/assimp/code/../include/assimp/cimport.h"
    "U:/code/cow/external/assimp/code/../include/assimp/AssertHandler.h"
    "U:/code/cow/external/assimp/code/../include/assimp/importerdesc.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Importer.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/DefaultLogger.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/ProgressHandler.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/IOStream.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/IOSystem.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/Logger.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/LogStream.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/NullLogger.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/cexport.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Exporter.hpp"
    "U:/code/cow/external/assimp/code/../include/assimp/DefaultIOStream.h"
    "U:/code/cow/external/assimp/code/../include/assimp/DefaultIOSystem.h"
    "U:/code/cow/external/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "U:/code/cow/external/assimp/code/../include/assimp/SceneCombiner.h"
    "U:/code/cow/external/assimp/code/../include/assimp/fast_atof.h"
    "U:/code/cow/external/assimp/code/../include/assimp/qnan.h"
    "U:/code/cow/external/assimp/code/../include/assimp/BaseImporter.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Hash.h"
    "U:/code/cow/external/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "U:/code/cow/external/assimp/code/../include/assimp/ParsingUtils.h"
    "U:/code/cow/external/assimp/code/../include/assimp/StreamReader.h"
    "U:/code/cow/external/assimp/code/../include/assimp/StreamWriter.h"
    "U:/code/cow/external/assimp/code/../include/assimp/StringComparison.h"
    "U:/code/cow/external/assimp/code/../include/assimp/StringUtils.h"
    "U:/code/cow/external/assimp/code/../include/assimp/SGSpatialSort.h"
    "U:/code/cow/external/assimp/code/../include/assimp/GenericProperty.h"
    "U:/code/cow/external/assimp/code/../include/assimp/SpatialSort.h"
    "U:/code/cow/external/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "U:/code/cow/external/assimp/code/../include/assimp/SmallVector.h"
    "U:/code/cow/external/assimp/code/../include/assimp/SmoothingGroups.h"
    "U:/code/cow/external/assimp/code/../include/assimp/SmoothingGroups.inl"
    "U:/code/cow/external/assimp/code/../include/assimp/StandardShapes.h"
    "U:/code/cow/external/assimp/code/../include/assimp/RemoveComments.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Subdivision.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Vertex.h"
    "U:/code/cow/external/assimp/code/../include/assimp/LineSplitter.h"
    "U:/code/cow/external/assimp/code/../include/assimp/TinyFormatter.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Profiler.h"
    "U:/code/cow/external/assimp/code/../include/assimp/LogAux.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Bitmap.h"
    "U:/code/cow/external/assimp/code/../include/assimp/XMLTools.h"
    "U:/code/cow/external/assimp/code/../include/assimp/IOStreamBuffer.h"
    "U:/code/cow/external/assimp/code/../include/assimp/CreateAnimMesh.h"
    "U:/code/cow/external/assimp/code/../include/assimp/XmlParser.h"
    "U:/code/cow/external/assimp/code/../include/assimp/BlobIOSystem.h"
    "U:/code/cow/external/assimp/code/../include/assimp/MathFunctions.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Exceptional.h"
    "U:/code/cow/external/assimp/code/../include/assimp/ByteSwapper.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "U:/code/cow/external/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Compiler/poppack1.h"
    "U:/code/cow/external/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "U:/code/cow/build/external/assimp/code/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
