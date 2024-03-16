#include "precompiled.h"

#include "Renderer/ShaderLibrary.h"

#include "Core/Application.h"

namespace SmartGL
{
    std::unordered_map<std::string, Shared<Shader>> ShaderLibrary::m_Shaders;

    void ShaderLibrary::Load(const std::string &name, const std::string &filepath)
    {
        std::string file = FindShaderFile(filepath);

        Shared<Shader> shader = CreateShared<Shader>(name, file);
        m_Shaders[name] = shader;

    }

    void ShaderLibrary::Load(const std::string &name, const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        Shared<Shader> shader = CreateShared<Shader>(name, vertexSrc, fragmentSrc);
        m_Shaders[name] = shader;
    }

    Shared<Shader> ShaderLibrary::Get(const std::string &name)
    {
        SMART_ASSERT(m_Shaders.find(name) != m_Shaders.end(), "Shader not found!");
        return m_Shaders[name];
    }

    std::string ShaderLibrary::FindShaderFile(const std::string &filepath)
    {
        std::string appDirectory = Core::Application::Get().GetSpecification().WorkingDirectory;
        std::string shaderfile = appDirectory + "/" + filepath;

        if(std::filesystem::exists(shaderfile))
            return shaderfile;

        char *env = std::getenv("SMARTGL_DIR");
        SMART_ASSERT(env != nullptr);

        std::string root = env;
        shaderfile = root + "/" + filepath;

        SMART_ASSERT(std::filesystem::exists(shaderfile), "Shader file not found!");

        return shaderfile;
    }
}
