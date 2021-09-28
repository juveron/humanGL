#include "HumanGL.hpp"

void renderUI(Font &font, s_indexBody indexBody)
{
	glViewport(SCREEN_WIDTH_BODIES, 0, SCREEN_WIDTH_UI, SCREEN_HEIGHT);
	glScissor(SCREEN_WIDTH_BODIES, 0, SCREEN_WIDTH_UI, SCREEN_HEIGHT);
	glClearColor(0.1294f, 0.1294f, 0.1294f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	font.renderText("CONTROLS", SCREEN_WIDTH_UI / 2 - (8 * 5), SCREEN_HEIGHT - 35, 0.5f, Vector3f(1, 1, 1));
	font.renderText("Translate: WSADQE", 10.0f, SCREEN_HEIGHT - (35 * 2), 0.5f, Vector3f(1, 1, 1));
	font.renderText("Rotate: IKJLUO", 10.0f, (SCREEN_HEIGHT)-(35 * 3), 0.5f, Vector3f(1, 1, 1));
	font.renderText("Scale: TGFHRY", 10.0f, (SCREEN_HEIGHT)-(35 * 4), 0.5f, Vector3f(1, 1, 1));
	font.renderText("INFORMATIONS", SCREEN_WIDTH_UI / 2 - (12 * 5), SCREEN_HEIGHT - (35 * 5), 0.5f, Vector3f(1, 1, 1));
	font.renderText(std::string("Current selected body: ").append(indexBody.modelIndex == 1 ? "DOGGO" : "HUMAN"), 10.0f, (SCREEN_HEIGHT)-(35 * 6), 0.5f, Vector3f(1, 1, 1));
}
