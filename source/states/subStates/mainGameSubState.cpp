/*
mvxxx 2017
https://github.com/mvxxx
*/

#include "mainGameSubState.hpp"
#include  <iostream>

MainGameSubState::MainGameSubState()
{
	this->onStart();
}

void MainGameSubState::onStart()
{
	mapManager.createWorld( "data/defaultMaps/map0.txt" );
}

void MainGameSubState::onStop()
{
}

void MainGameSubState::run()
{
	mapManager.manageAll();
}

void MainGameSubState::fillRenderer(Renderer& renderer)
{
	renderer.addCollection( mapManager.tilesManager.getTiles(), 0 );
}
