#include "cimgui_backend.h"
//#include "../cimgui.h"
#include "../cimgui/imgui/backends/imgui_impl_opengl3.h"
#include "../cimgui/imgui/backends/imgui_impl_glfw.h"//<backends/imgui_impl_glfw.h>
//IMGUI_IMPL_API bool     ImGui_ImplOpenGL3_Init(const char* glsl_version = NULL);
//IMGUI_IMPL_API void     ImGui_ImplOpenGL3_Shutdown();
//IMGUI_IMPL_API void     ImGui_ImplOpenGL3_NewFrame();
//IMGUI_IMPL_API void     ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data);
//
//// (Optional) Called by Init/NewFrame/Shutdown
//IMGUI_IMPL_API bool     ImGui_ImplOpenGL3_CreateFontsTexture();
//IMGUI_IMPL_API void     ImGui_ImplOpenGL3_DestroyFontsTexture();
//IMGUI_IMPL_API bool     ImGui_ImplOpenGL3_CreateDeviceObjects();
//IMGUI_IMPL_API void     ImGui_ImplOpenGL3_DestroyDeviceObjects();

CIMGUI_API bool igOpenGL3Init(const char* glsl_version)
{
	return ImGui_ImplOpenGL3_Init(glsl_version);
}

CIMGUI_API void igOpenGL3Shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
}

CIMGUI_API void igOpenGL3NewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
}

CIMGUI_API void igOpenGL3RenderDrawData(ImDrawData* draw_data)
{
	ImGui_ImplOpenGL3_RenderDrawData(draw_data);
}

CIMGUI_API bool igOpenGL3CreateFontsTexture()
{
	return ImGui_ImplOpenGL3_CreateFontsTexture();
}

CIMGUI_API void igOpenGL3DestroyFontsTexture()
{
	ImGui_ImplOpenGL3_DestroyFontsTexture();
}

CIMGUI_API bool igOpenGL3CreateDeviceObjects()
{
	return ImGui_ImplOpenGL3_CreateDeviceObjects();
}

CIMGUI_API void igOpenGL3DestroyDeviceObjects()
{
	ImGui_ImplOpenGL3_DestroyDeviceObjects();
}


CIMGUI_API bool igGlfwInitForOpenGL(GLFWwindow* window, bool install_callbacks)
{
	return ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);
}
CIMGUI_API bool igGlfwInitForVulkan(GLFWwindow* window, bool install_callbacks)
{
	return ImGui_ImplGlfw_InitForVulkan(window, install_callbacks);
}
CIMGUI_API bool igGlfwInitForOther(GLFWwindow* window, bool install_callbacks)
{
	return ImGui_ImplGlfw_InitForOther(window, install_callbacks);
}
CIMGUI_API void igGlfwShutdown()
{
	ImGui_ImplGlfw_Shutdown();
}
CIMGUI_API void igGlfwNewFrame()
{
	ImGui_ImplGlfw_NewFrame();
}

CIMGUI_API void igGlfwInstallCallbacks(GLFWwindow* window)
{
	ImGui_ImplGlfw_InstallCallbacks(window);
}
CIMGUI_API void igGlfwRestoreCallbacks(GLFWwindow* window)
{
	ImGui_ImplGlfw_RestoreCallbacks(window);
}

CIMGUI_API void igGlfwWindowFocusCallback(GLFWwindow* window, int focused)        // Since 1.8
{
	ImGui_ImplGlfw_WindowFocusCallback(window, focused);
}
CIMGUI_API void igGlfwCursorEnterCallback(GLFWwindow* window, int entered)        // Since 1.8
{
	ImGui_ImplGlfw_CursorEnterCallback(window, entered);
}
CIMGUI_API void igGlfwCursorPosCallback(GLFWwindow* window, double x, double y)   // Since 1.8
{
	ImGui_ImplGlfw_CursorPosCallback(window, x, y);
}
CIMGUI_API void igGlfwMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);
}
CIMGUI_API void igGlfwScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
}
CIMGUI_API void igGlfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	ImGui_ImplGlfw_KeyCallback(window, key, scancode, action, mods);
}
CIMGUI_API void igGlfwCharCallback(GLFWwindow* window, unsigned int c)
{
	ImGui_ImplGlfw_CharCallback(window, c);
}
CIMGUI_API void igGlfwMonitorCallback(GLFWmonitor* monitor, int event)
{
	ImGui_ImplGlfw_MonitorCallback(monitor, event);
}