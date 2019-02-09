/*
mvxxx 2019
https://github.com/mvxxx
*/

#pragma once
/**
* @brief EventDock class/wrapper
* @see EventControl.hpp
*/
class EventDock
{
	/* ===Objects=== */
public:
protected:
private:
	/* ===Methods=== */
public:
	/**
	* @brief handle types of events
	* @param eventList - wrapper for events
	*/
	virtual void handleEventTypes( const eventWrapper_t& eventList ) = 0;
protected:
private:
};
