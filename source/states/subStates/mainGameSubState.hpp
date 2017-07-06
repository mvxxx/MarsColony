/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "mapManager/mapManager.hpp"
#include "renderer/renderer.hpp"
#include "mapManager/SelectionManager.hpp"
#include "wrappers/EventWrapper.hpp"


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

	virtual void run( eventWrapper_t& eventTypes ) override;

	void fillRenderer( Renderer& renderer );

protected:
private:
};


