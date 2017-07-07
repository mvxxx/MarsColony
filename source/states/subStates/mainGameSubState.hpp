/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "wrappers/FunctionPointerWrapper_t.hpp"
#include "mapManager/mapManager.hpp"
#include "renderer/renderer.hpp"
#include "mapManager/SelectionManager.hpp"
#include "wrappers/EventWrapper.hpp"
#include "inputManager/InputManager.hpp"


class MainGameSubState :public SubState
{
	/* ===Objects=== */
public:
protected:
private:
	MapManager mapManager;
	SelectionManager selectionManager;
	mv::InputManager<Scene> cameraControl; 

	/* ===Methods=== */
public:

	MainGameSubState( std::shared_ptr<Scene> scene );

	virtual void onStart() override;

	virtual void onStop() override;

	virtual void run( eventWrapper_t& eventTypes ) override;

	void fillRenderer( Renderer& renderer );

protected:
private:
};


