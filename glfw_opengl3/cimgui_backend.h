#pragma once
//#include "../imgui/imgui.h"

#if defined _WIN32
#include <Windows.h>
#endif

#if defined _WIN32 || defined __CYGWIN__
#ifdef CIMGUI_NO_EXPORT
#define API
#else
#define API __declspec(dllexport)
#endif
#else
#ifdef __GNUC__
#define API  __attribute__((__visibility__("default")))
#else
#define API
#endif
#endif


#if defined __cplusplus
#define EXTERN extern "C"
#else
#include <stdarg.h>
#include <stdbool.h>
#define EXTERN extern
#endif

#define CIMGUI_API EXTERN API

struct ImDrawData;

CIMGUI_API bool igOpenGL3Init(const char* glsl_version = NULL);
CIMGUI_API void igOpenGL3Shutdown();
CIMGUI_API void igOpenGL3NewFrame();
CIMGUI_API void igOpenGL3RenderDrawData(ImDrawData* draw_data);

CIMGUI_API bool igOpenGL3CreateFontsTexture();
CIMGUI_API void igOpenGL3DestroyFontsTexture();
CIMGUI_API bool igOpenGL3CreateDeviceObjects();
CIMGUI_API void igOpenGL3DestroyDeviceObjects();

struct GLFWwindow;
struct GLFWmonitor;

CIMGUI_API bool igGlfwInitForOpenGL(GLFWwindow* window, bool install_callbacks);
CIMGUI_API bool igGlfwInitForVulkan(GLFWwindow* window, bool install_callbacks);
CIMGUI_API bool igGlfwInitForOther(GLFWwindow* window, bool install_callbacks);
CIMGUI_API void igGlfwShutdown();
CIMGUI_API void igGlfwNewFrame();

CIMGUI_API void igGlfwInstallCallbacks(GLFWwindow* window);
CIMGUI_API void igGlfwRestoreCallbacks(GLFWwindow* window);

CIMGUI_API void igGlfwWindowFocusCallback(GLFWwindow* window, int focused);        // Since 1.84
CIMGUI_API void igGlfwCursorEnterCallback(GLFWwindow* window, int entered);        // Since 1.84
CIMGUI_API void igGlfwCursorPosCallback(GLFWwindow* window, double x, double y);   // Since 1.87
CIMGUI_API void igGlfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
CIMGUI_API void igGlfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
CIMGUI_API void igGlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
CIMGUI_API void igGlfwCharCallback(GLFWwindow* window, unsigned int c);
CIMGUI_API void igGlfwMonitorCallback(GLFWmonitor* monitor, int event);