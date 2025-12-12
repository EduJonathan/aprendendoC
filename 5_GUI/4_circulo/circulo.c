#include <math.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

#define WINDOW_SIZE 800
#define PI          3.14159265358979323846f

float rotation = 0.0f;

void draw_circle(float cx, float cy, float radius, int segments, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // centro
    for (int i = 0; i <= segments; i++)
    {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(cx + radius * cosf(angle), cy + radius * sinf(angle));
    }
    glEnd();
}

void draw_circle_outline(float cx, float cy, float radius, int segments, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; i++)
    {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(cx + radius * cosf(angle), cy + radius * sinf(angle));
    }
    glEnd();
}

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        printf("Erro ao iniciar GLFW!\n");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(WINDOW_SIZE, WINDOW_SIZE,
                                          "Círculo Perfeito - OpenGL Moderno (GLFW)", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // VSync = 60 FPS suave

    // Configuração da projeção (centro na tela)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2, 1.2, -1.2, 1.2, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    // Anti-aliasing (borda lisa)
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    printf("Círculo rodando! Pressione ESC para sair.\n");

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // fundo azul escuro
        glClear(GL_COLOR_BUFFER_BIT);

        glLoadIdentity();
        glRotatef(rotation, 0.0f, 0.0f, 1.0f); // rotação suave

        // Círculo preenchido (azul neon)
        draw_circle(0.0f, 0.0f, 0.8f, 120, 0.2f, 0.7f, 1.0f);

        // Borda branca brilhante (grossa)
        glLineWidth(6.0f);
        draw_circle_outline(0.0f, 0.0f, 0.8f, 120, 1.0f, 1.0f, 1.0f);

        // Ponto central
        draw_circle(0.0f, 0.0f, 0.05f, 30, 1.0f, 1.0f, 1.0f);

        rotation += 0.5f;
        if (rotation >= 360.0f)
            rotation = 0.0f;

        glfwSwapBuffers(window);
        glfwPollEvents();

        // Fecha com ESC
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    glfwTerminate();
    return 0;
}
