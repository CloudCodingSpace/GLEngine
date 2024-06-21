#include "ge_shader.hpp"

GEShader::GEShader(const std::string &vertPath, const std::string &fragPath)
{
    std::string vertSrc = ReadShaderFile(vertPath);
    std::string fragSrc = ReadShaderFile(fragPath);

    const char* vSrc = vertSrc.c_str();
    const char* fSrc = fragSrc.c_str();

    unsigned int vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vSrc, NULL);
    glCompileShader(vertShader);

    unsigned int fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fSrc, NULL);
    glCompileShader(fragShader);

    ID = glCreateProgram();
    glAttachShader(ID, vertShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);
}

void GEShader::Bind()
{
    glUseProgram(ID);
}

void GEShader::PutTexture(const std::string &name, int slot)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), slot);
}

void GEShader::PutMat4(const std::string &name, glm::mat4 &mat)
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void GEShader::Unbind()
{
    glUseProgram(0);
}

void GEShader::Cleanup()
{
    glDeleteProgram(ID);
}

std::string GEShader::ReadShaderFile(const std::string &path)
{
    std::ifstream file(path);
    if(file) {
        std::string content = "", line = "";

        while(getline(file, line)) {
            content += line + "\n";
            line = "";
        }

        file.close();
        return content;
    } else {
        throw std::runtime_error("Failed to read the shader file!");
    }
}