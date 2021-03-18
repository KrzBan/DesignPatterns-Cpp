#pragma once

#include <iostream>

namespace Facade {

	struct VulkanWindow {
		int exampleData;
		//PhysicalDevice
		//LogicDevice
		//ExtensionChecking
		//Setting up the logger
		//Queue family
		//Complicated set-up
	};

	//Here comes the facade
	class Window {
		int m_WindowWidth;
		int m_WindowHeight;

		VulkanWindow* m_pVulkanWindow;

	public:
		Window(int width, int height)
			:m_WindowWidth(width), m_WindowHeight(height), m_pVulkanWindow{ nullptr } {
			//set-up pVulkanWindow
		}
	};
}