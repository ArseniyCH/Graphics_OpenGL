#pragma once

#ifndef OPEN_GL_CONTROL
#define OPEN_GL_CONTROL

#include "openGLControl.h"

#include <map>

// GLFW stuff for creating window and Windows message handling.
class COpenGLApp
{
public:
	GLFWwindow * window; // Handle to application window
	COpenGLControl oglControl; // OpenGL Control

	void ResetTimer();
	void UpdateTimer();
	float sof(float fVal);

	bool InitializeApp(string a_sAppName);
	bool CreateAppWindow(const char * title);
	
	void AppBody();
	void Shutdown();

	static void window_focus_callback(GLFWwindow * window, int focus);

	static void window_size_callback(GLFWwindow*, int width, int height);

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

private:
	bool InitGLEW();

	static bool bGlewInitialized;
	string sAppName;

	bool bAppActive; // To check if application is active (not minimized)
	clock_t tLastFrame;
	float fFrameInterval;
};

namespace Keys
{
	int Key(int iKey);
}

extern COpenGLApp appMain;

void InitScene(void *), RenderScene(void *), ReleaseScene(void *);

#endif