/*
mvxxx 2017
https://github.com/mvxxx
*/

#pragma once

#include "states/SubState.hpp"
#include "mapManager/mapManager.hpp"
#include "eventControl/EventControl.hpp"

class MainGameSubState :public SubState
{
	/* ===Objects=== */
public:
protected:
private:
	MapManager mapManager;

	/* ===Methods=== */
public:

	MainGameSubState();

	virtual void onStart() override;

	virtual void onStop() override;

	virtual void run() override;

	void fillRenderer( Renderer& renderer );

protected:
private:
};


