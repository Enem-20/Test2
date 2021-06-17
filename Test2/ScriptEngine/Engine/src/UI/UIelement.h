#pragma once

#include "../Renderer/Sprite.h"
#include "../Physics/Collider.h"
#include "../Components/Component.h"

#include <sol/sol.hpp>

#include <list>
#include<memory>

class GameObject;

namespace UI
{
	class UIelement : public Components::Component
	{
	public:
		glm::mat4 model;

		UIelement();

		void AddListener(sol::function& func);

		void executeOnClicks();
		void setParamCollider();
		//virtual void OnExecute() = 0;

		virtual void Update() = 0;
		virtual void render() = 0;

		std::shared_ptr<Physics::Collider> collider;
	protected:		
		std::list<sol::function> elements;
		static size_t ID;
	};
}