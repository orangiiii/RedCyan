#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm/glm.hpp>
#include <glm/glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/glm/gtc/type_ptr.hpp>
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

// #define CUBE 1
// #define LINE 1
const unsigned int WIN_W = 800;
const unsigned int WIN_H = 600;
float phi = 0.0f, theta = 0.0f;   // 极坐标角度（用于旋转）
float zoom = 3.0f;                // 摄像机距离（用于缩放）
bool mousePressed = false;
float lastX = 0.0f, lastY = 0.0f;

const char* vertexShaderSource = R"glsl(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 FragPos;
out vec3 Normal;

void main() {
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal;
    gl_Position = projection * view * vec4(FragPos, 1.0);
}
)glsl";

const char* fragmentShaderSource = R"glsl(
#version 330 core
in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

uniform vec3 colorLeft;
uniform vec3 colorRight;
uniform bool renderLeft;

void main() {
    vec3 lightDir = normalize(vec3(0.5, 1.0, 0.3));
    float diffuse = max(dot(Normal, lightDir), 0.0);
    float ambient = 0.2; // 环境光强度
    vec3 baseColor = renderLeft ? colorLeft : colorRight;
    vec3 finalColor = baseColor * (ambient + diffuse);
    FragColor = vec4(finalColor, 1.0);
}
)glsl";
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) mousePressed = true;
        else if (action == GLFW_RELEASE) mousePressed = false;
    }
}

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    if (!mousePressed) return;

    float dx = xpos - lastX;
    float dy = ypos - lastY;

    theta += dx * 0.005f;
    phi   += dy * 0.005f;

    // 限制phi上下旋转角度
    const float limit = glm::radians(89.0f);
    if (phi > limit) phi = limit;
    if (phi < -limit) phi = -limit;

    lastX = xpos;
    lastY = ypos;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    zoom -= yoffset * 0.1f;
    if (zoom < 1.0f) zoom = 1.0f;
    if (zoom > 10.0f) zoom = 10.0f;
}

std::vector<float> loadModelVertices(const std::string& path) {
    std::vector<float> vertexData;

    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_JoinIdenticalVertices);
    if (!scene || !scene->HasMeshes()) {
        std::cerr << "Assimp load failed: " << importer.GetErrorString() << std::endl;
        return vertexData;
    }

    for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
        const aiMesh* mesh = scene->mMeshes[i];
        // 遍历三角面
        for (unsigned int f = 0; f < mesh->mNumFaces; ++f) {
            const aiFace& face = mesh->mFaces[f];
            for (unsigned int j = 0; j < face.mNumIndices; ++j) {
                unsigned int idx = face.mIndices[j];
                // 顶点坐标
                vertexData.push_back(mesh->mVertices[idx].x);
                vertexData.push_back(mesh->mVertices[idx].y);
                vertexData.push_back(mesh->mVertices[idx].z);
                // 法线
                if (mesh->HasNormals()) {
                    vertexData.push_back(mesh->mNormals[idx].x);
                    vertexData.push_back(mesh->mNormals[idx].y);
                    vertexData.push_back(mesh->mNormals[idx].z);
                } else {
                    vertexData.push_back(0.0f);
                    vertexData.push_back(0.0f);
                    vertexData.push_back(1.0f);
                }
            }
        }
    }
    return vertexData;
}
#if CUBE
// Vertex data for a simple cube
float vertices[] = {
    // back face
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    // front face
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    // left face
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

    // right face
     0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f, 1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f, 1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f, 1.0f,  0.0f,  0.0f,

    // bottom face
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    // top face
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f
};
#endif
#ifndef CUBE
// std::vector<float> vertices = loadModelVertices("models/windmill.obj");
std::vector<float> vertices = loadModelVertices("models/vrclass.obj");
#endif

// Shader loading utility functions here (vertexShaderSource and fragmentShaderSource skipped for brevity)

unsigned int createShaderProgram(const char* vShaderCode, const char* fShaderCode) {
    unsigned int vertex, fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return program;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {
    
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WIN_W, WIN_H, "Red-Cyan Anaglyph", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_pos_callback);
    glfwSetScrollCallback(window, scroll_callback);

  
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    #if CUBE
    // 立方体
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    #endif
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);

    glEnable(GL_DEPTH_TEST);
    #if LINE
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // 临时：线框模式，调试用
    #endif  
    #ifndef LINE
    printf("GL_FILL");
    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  // 默认填充模式
    #endif

    while (!glfwWindowShouldClose(window)) {
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);  // 恢复颜色通道写入权限 再清除颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        float eyeOffset = 0.03f * zoom; // 让视差随距离变化
        // glm::mat4 model = glm::mat4(1.0f);
        // 缩小一点
        glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -0.3f, 0.0f));
        model = glm::scale(model, glm::vec3(0.5f));

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WIN_W / WIN_H, 0.1f, 100.0f);
        glm::vec3 target = glm::vec3(0.0f, 0.5f, 0.0f);  // 将观察点往上提一些（Y方向偏移）


        float r = zoom;
        // glm::vec3 eye = glm::vec3(
        //     r * cos(phi) * sin(theta),
        //     r * sin(phi),
        //     r * cos(phi) * cos(theta)
        // );
          glm::vec3 eye = glm::vec3(
            r * cos(phi) * sin(theta),
            r * sin(phi),
            r * cos(phi) * cos(theta)
        );
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);    
        // Left Eye (Red)
        glColorMask(GL_TRUE, GL_FALSE, GL_FALSE, GL_TRUE);
        glm::mat4 viewL = glm::lookAt(eye - glm::vec3(eyeOffset, 0.0f, 0.0f), target, up);
        glUniform1i(glGetUniformLocation(shaderProgram, "renderLeft"), true);
        glUniform3f(glGetUniformLocation(shaderProgram, "colorLeft"), 1.0f, 0.0f, 0.0f);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(viewL));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 6);  

        // 清除深度缓冲区，保留颜色缓冲
        glClear(GL_DEPTH_BUFFER_BIT);

        // Right Eye (Cyan)
        glColorMask(GL_FALSE, GL_TRUE, GL_TRUE, GL_TRUE);
        glm::mat4 viewR = glm::lookAt(eye + glm::vec3(eyeOffset, 0.0f, 0.0f), target, up);
        glUniform1i(glGetUniformLocation(shaderProgram, "renderLeft"), false);
        glUniform3f(glGetUniformLocation(shaderProgram, "colorRight"), 0.0f, 1.0f, 1.0f);
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(viewR));
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 6);  

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}
