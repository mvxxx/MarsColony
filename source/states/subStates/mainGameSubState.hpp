/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "states/SubState.hpp"
#include "mapManager/mapManager.hpp"
#include "eventControl/EventControl.hpp"
#include "renderer/renderer.hpp"
#include "mapManager/SelectionManager.hpp"

class MainGameSubState :public SubState
{
	/* ===Objects=== */
public:
protected:
private:
	MapManager mapManager;
	SelectionManager selectionManager;

	/* ===Methods=== */
public:

	MainGameSubState( std::shared_ptr<Scene> scene );

	virtual void onStart() override;

	virtual void onStop() override;

	virtual void run() override;

	void fillRenderer( Renderer& renderer );

protected:
private:
};


