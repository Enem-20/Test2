#pragma once

#include<queue>
#include<memory>
#include<vector>

class GameObject;

namespace Engine
{
	class EngineMain
	{
	public:
		static void Init(char** argv);
	private:
		static void FirstFrame();
		static void render();
		static void ScriptUpdates();
	};
}