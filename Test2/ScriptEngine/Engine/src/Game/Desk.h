#pragma once

#include "GObject.h"

class Desk : public GObject
{
public:
	Desk();

	void render() override;
};