//
//  HelloTriangleApplication.hpp
//  VulkanTesting
//
//  Created by Cyrille FROUIN on 16/06/2019.
//  Copyright © 2019 Cyrille FROUIN. All rights reserved.
//

#ifndef HelloTriangleApplication_h
#define HelloTriangleApplication_h

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <optional>

const int WIDTH = 800;
const int HEIGHT = 600;

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation",
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	
	bool isComplete() {
		return graphicsFamily.has_value();
	}
};

class HelloTriangleApplication {
private:
	GLFWwindow *window;
	
	VkInstance instance;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;
	VkQueue graphicsQueue;
	VkDebugUtilsMessengerEXT debugMessenger;
	
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}
	
private:
	void initWindow();

	void initVulkan();	
	
	void mainLoop();
	
	void cleanup();
	
	void createInstance();
	
	void pickPhysicalDevice();
	
	void createLogicalDevice();
	
	bool isDeviceSuitable(VkPhysicalDevice device);
	
	void setupDebugMessenger();
	
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
	
	bool checkValidationLayerSupport();
	
	std::vector<const char*> getRequiredExtensions();
	
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
	
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
};

#endif /* HelloTriangleApplication_h */
