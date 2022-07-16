// glfw_opengl3_test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include <iostream>
#include <GLFW/glfw3.h>
//#include "../imgui/imgui.h"
#include "../cimgui/cimgui.h"
#include "../glfw_opengl3/cimgui_backend.h"
#pragma comment(lib, "../x64/Debug/cimgui.lib")

static GLFWwindow* win;
struct ImGuiContext* ctx;
struct ImGuiIO* io;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

static void error_callback(int e, const char* d)
{
    printf("Error %d: %s\n", e, d);
}

void gui_init() {
    // IMGUI_CHECKVERSION();
    ctx = igCreateContext(NULL);
    io = igGetIO();

    const char* glsl_version = "#version 330 core";
    igGlfwInitForOpenGL(win, true);
    igOpenGL3Init(glsl_version);

    // Setup style
    igStyleColorsDark(NULL);
}

void gui_terminate() {
    igOpenGL3Shutdown();
    igGlfwShutdown();
    //ImGui_ImplOpenGL3_Shutdown();
    //ImGui_ImplGlfw_Shutdown();
    igDestroyContext(ctx);
}

void gui_render() {
    igRender();
    igOpenGL3RenderDrawData(igGetDrawData());
    //ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
}

void gui_update() {
    igOpenGL3NewFrame();
    igGlfwNewFrame();
    //ImGui_ImplOpenGL3_NewFrame();
    //ImGui_ImplGlfw_NewFrame();
    igNewFrame();

    igBegin("Test", NULL, 0);
    igText("Test");
    igButton("Test", ImVec2{ 0, 0 });
    igEnd();

    // // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. 
    // // Here we just want to make the demo initial state a bit more friendly!
    // igSetNextWindowPos((struct ImVec2){0,0}, ImGuiCond_FirstUseEver,(struct ImVec2){0,0} ); 
    igShowDemoWindow(NULL);
}

int main()
{
    /* GLFW */
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stdout, "[GFLW] failed to init!\n");
        exit(1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CIMGUI", NULL, NULL);
    glfwMakeContextCurrent(win);
    //bool err = gl3wInit();
    //if (err) {
    //    fprintf(stderr, "Failed to initialize OpenGL loader!\n");
    //    return 1;
    //}

    gui_init();

    // glfwSetWindowSizeCallback(win, onResize);
    int width, height;
    glfwGetWindowSize(win, &width, &height);

    /* OpenGL */
    //glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);


    while (!glfwWindowShouldClose(win)) {
        /* Input */
        glfwPollEvents();

        gui_update();

        ///* Draw */
        //glfwGetWindowSize(win, &width, &height);
        //glViewport(0, 0, width, height);
        //glClear(GL_COLOR_BUFFER_BIT);
        //glClearColor(0.0, 0.0, 0.0, 0.0);

        gui_render();

        glfwSwapBuffers(win);
    }

    gui_terminate();
    glfwTerminate();

    //std::cout << "Hello World!\n";
    //glfwInit();
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //auto window = glfwCreateWindow(800, 600, "cimgui glfw opengl3 test", NULL, NULL);
    //glfwMakeContextCurrent(window);
    //igCreateContext(NULL);
    //igGlfwInitForOpenGL(window, true);
    //igOpenGL3Init("#version 330 core");
    //while (!glfwWindowShouldClose(window))
    //{
    //    glfwPollEvents();

    //    igOpenGL3NewFrame();
    //    igGlfwNewFrame();

    //    igNewFrame();

    //    igBegin("Test", NULL, 0);
    //    igText("Test");
    //    igButton("Test", ImVec2{ 0, 0 });
    //    igEnd();

    //    igShowDemoWindow(NULL);

    //    /*igEndFrame();*/
    //    igRender();
    //    glfwSwapBuffers(window);
    //    
    //}
    //glfwDestroyWindow(window);
    //glfwTerminate();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
