#pragma once

#include "Core/Application.h"
#include "Core/Log.h"

int main(int argc, char **argv)
{
    SmartGL::Core::Logger::Init();
    SMART_LOG_INFO("Welcome to SmartGL!");

    auto app = SmartGL::Core::CreateApplication();
    app->Run();

    SMART_LOG_TRACE("Shutting down...");
    SmartGL::Core::Logger::Shutdown();

    delete app;
}
