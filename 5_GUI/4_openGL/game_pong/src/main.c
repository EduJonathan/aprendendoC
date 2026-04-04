#include <GL/glut.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// Game state
static float paddleHalfHeight = 0.15f;
static float paddleHalfWidth  = 0.02f;
static float paddleSpeed      = 1.2f;

static float leftPaddleY  = 0.0f;
static float rightPaddleY = 0.0f;

static float ballX       = 0.0f;
static float ballY       = 0.0f;
static float ballVX      = 0.8f;
static float ballVY      = 0.5f;
static float ballSpeed   = 0.9f;
static float ballRadius  = 0.02f;

static int scoreLeft  = 0;
static int scoreRight = 0;

static bool keyUp   = false;
static bool keyDown = false;
static bool keyW    = false;
static bool keyS    = false;

static void reset_ball(bool toLeft)
{
    ballX     = 0.0f;
    ballY     = 0.0f;
    ballSpeed = 0.9f;
    ballVX    = toLeft ? -ballSpeed : ballSpeed;
    ballVY    = (rand() % 100 / 100.0f - 0.5f) * ballSpeed;
}

static void reset_game(void)
{
    leftPaddleY  = 0.0f;
    rightPaddleY = 0.0f;
    scoreLeft    = 0;
    scoreRight   = 0;
    reset_ball(true);
}

static void draw_rect(float x, float y, float w, float h)
{
    glBegin(GL_QUADS);
    glVertex2f(x - w, y - h);
    glVertex2f(x + w, y - h);
    glVertex2f(x + w, y + h);
    glVertex2f(x - w, y + h);
    glEnd();
}

static void draw_circle(float x, float y, float r)
{
    const int segs = 32;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segs; ++i)
    {
        float a = (float)i / (float)segs * 3.1415926f * 2.0f;
        glVertex2f(x + cosf(a) * r, y + sinf(a) * r);
    }
    glEnd();
}

static void draw_text(const char *text, float x, float y)
{
    glRasterPos2f(x, y);
    for (const char *c = text; *c; ++c)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    glColor3f(0.06f, 0.06f, 0.06f);
    draw_rect(0.0f, 0.0f, 1.0f, 1.0f);

    // Center line
    glColor3f(0.4f, 0.4f, 0.4f);
    for (float y = -1.0f; y < 1.0f; y += 0.1f)
    {
        draw_rect(0.0f, y, 0.005f, 0.03f);
    }

    // Paddles
    glColor3f(0.9f, 0.9f, 0.9f);
    draw_rect(-0.9f, leftPaddleY, paddleHalfWidth, paddleHalfHeight);
    draw_rect(0.9f, rightPaddleY, paddleHalfWidth, paddleHalfHeight);

    // Ball
    glColor3f(1.0f, 0.6f, 0.1f);
    draw_circle(ballX, ballY, ballRadius);

    // Score
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", scoreLeft);
    glColor3f(1, 1, 1);
    draw_text(buffer, -0.25f, 0.85f);
    snprintf(buffer, sizeof(buffer), "%d", scoreRight);
    draw_text(buffer, 0.15f, 0.85f);

    glutSwapBuffers();
}

static void update(float dt)
{
    // Player input
    if (keyW)
        leftPaddleY += paddleSpeed * dt;

    if (keyS)
        leftPaddleY -= paddleSpeed * dt;

    if (keyUp)
        rightPaddleY += paddleSpeed * dt;

    if (keyDown)
        rightPaddleY -= paddleSpeed * dt;


    // Clamp paddles
    if (leftPaddleY > 1.0f - paddleHalfHeight)
        leftPaddleY = 1.0f - paddleHalfHeight;

    if (leftPaddleY < -1.0f + paddleHalfHeight)
        leftPaddleY = -1.0f + paddleHalfHeight;

    if (rightPaddleY > 1.0f - paddleHalfHeight)
        rightPaddleY = 1.0f - paddleHalfHeight;

    if (rightPaddleY < -1.0f + paddleHalfHeight)
        rightPaddleY = -1.0f + paddleHalfHeight;


    // Ball movement
    ballX += ballVX * dt;
    ballY += ballVY * dt;

    // Wall collision
    if (ballY + ballRadius > 1.0f)
    {
        ballY = 1.0f - ballRadius;
        ballVY = -ballVY;
    }

    if (ballY - ballRadius < -1.0f)
    {
        ballY = -1.0f + ballRadius;
        ballVY = -ballVY;
    }

    // Paddle collision
    if (ballX - ballRadius < -0.9f + paddleHalfWidth)
    {
        if (ballY > leftPaddleY - paddleHalfHeight && ballY < leftPaddleY + paddleHalfHeight)
        {
            ballX = -0.9f + paddleHalfWidth + ballRadius;
            ballVX = fabsf(ballVX) + 0.05f;
            ballVX = -ballVX;
        }
    }

    if (ballX + ballRadius > 0.9f - paddleHalfWidth)
    {
        if (ballY > rightPaddleY - paddleHalfHeight && ballY < rightPaddleY + paddleHalfHeight)
        {
            ballX = 0.9f - paddleHalfWidth - ballRadius;
            ballVX = -fabsf(ballVX) - 0.05f;
        }
    }

    // Score
    if (ballX < -1.0f)
    {
        scoreRight += 1;
        reset_ball(false);
    }
    if (ballX > 1.0f)
    {
        scoreLeft += 1;
        reset_ball(true);
    }
}

static void timer(int value)
{
    update(1.0f / 60.0f);
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

static void keyboard_down(unsigned char key, int x, int y)
{
    (void)x;
    (void)y;
    switch (key)
    {
    case 'w':
        keyW = true;
        break;

    case 's':
        keyS = true;
        break;

    case 'r':
        reset_game();
        break;
    }
}

static void keyboard_up(unsigned char key, int x, int y)
{
    (void)x;
    (void)y;
    switch (key)
    {
    case 'w':
        keyW = false;
        break;

    case 's':
        keyS = false;
        break;
    }
}

static void special_down(int key, int x, int y)
{
    (void)x;
    (void)y;
    switch (key)
    {
    case GLUT_KEY_UP:
        keyUp = true;
        break;

    case GLUT_KEY_DOWN:
        keyDown = true;
        break;
    }
}

static void special_up(int key, int x, int y)
{
    (void)x;
    (void)y;
    switch (key)
    {
    case GLUT_KEY_UP:
        keyUp = false;
        break;
        
    case GLUT_KEY_DOWN:
        keyDown = false;
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Pong (OpenGL) - W/S and Up/Down");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    reset_game();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard_down);
    glutKeyboardUpFunc(keyboard_up);
    glutSpecialFunc(special_down);
    glutSpecialUpFunc(special_up);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
