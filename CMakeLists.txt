cmake_minimum_required(VERSION 3.1)

project(MarsCombat)

## If you want to link SFML statically
#set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "external/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(MarsCombat
        source/cache/Cache.hpp
        source/ecs/component/Component.hpp
        source/ecs/component/ProperBody.hpp
        source/ecs/component/unitPosition.hpp
        source/ecs/component/Velocity.cpp
        source/ecs/component/Velocity.hpp
        source/ecs/component/Visible.hpp
        source/ecs/entity/Entity.cpp
        source/ecs/entity/Entity.hpp
        source/entities/cell/cell.cpp
        source/entities/cell/cell.hpp
        source/entities/id.hpp
        source/eventControl/EventControl.cpp
        source/eventControl/EventControl.hpp
        source/eventDock/EventDock.hpp
        source/frame/Frame.cpp
        source/frame/Frame.hpp
        source/game/Game.cpp
        source/game/Game.hpp
        source/inputManager/InputManager.hpp
        source/loader/Loader.cpp
        source/loader/Loader.hpp
        source/logger/Logger.cpp
        source/logger/Logger.hpp
        source/LoopManager/LoopManager.cpp
        source/LoopManager/LoopManager.hpp
        source/mapManager/manager.hpp
        source/mapManager/mapManager.cpp
        source/mapManager/mapManager.hpp
        source/mapManager/SelectionManager.cpp
        source/mapManager/SelectionManager.hpp
        source/mapManager/TilesManager.cpp
        source/mapManager/TilesManager.hpp
        source/mouse/Mouse.cpp
        source/mouse/Mouse.hpp
        source/renderer/renderer.cpp
        source/renderer/renderer.hpp
        source/scene/Scene.cpp
        source/scene/Scene.hpp
        source/states/subStates/mainGameSubState.cpp
        source/states/subStates/mainGameSubState.hpp
        source/states/GameState.cpp
        source/states/GameState.hpp
        source/states/State.hpp
        source/states/SubState.hpp
        source/wrappers/componentWrapper.hpp
        source/wrappers/DrawMap.hpp
        source/wrappers/EventWrapper.hpp
        source/wrappers/FunctionPointerWrapper_t.hpp
        source/wrappers/point.hpp
        source/wrappers/WorldWrapper.hpp
        source/Config.hpp
        source/main.cpp
        source/Utilities.hpp)
target_link_libraries(MarsCombat sfml-graphics sfml-audio)