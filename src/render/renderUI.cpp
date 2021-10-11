#include "HumanGL.hpp"

// std::vector<std::tuple<std::string, unsigned int, float, Vector3f>> tuple;

static void placeText(Font &font, std::vector <s_textInformation> texts)
{
	std::vector<s_textInformation>::const_iterator iter;

	float yOffset = (SCREEN_HEIGHT * ratio.y) - 5;
	for (iter = texts.begin(); iter != texts.end(); iter++) {
		s_textInformation info = *iter;

		yOffset -= 48 * info.scale + 2 * ratio.y;
		switch (info.textMode)
		{
		case REGULAR_TEXT:
			yOffset -= 5 * ratio.y;
			font.renderText(info.data, info.alignMode, yOffset, info.scale, info.color);
			break;
		case UNDERLINE_TEXT:
			font.renderUnderlinedText(info.data, info.alignMode, yOffset, info.scale, info.color);
			break;
		default:
			break;
		}
	}
}

void renderUI(Font &font, s_indexBody indexBody, ABody const *body)
{
	glViewport(SCREEN_WIDTH_BODIES * ratio.x, 0, SCREEN_WIDTH_UI * ratio.x, SCREEN_HEIGHT * ratio.y);
	glScissor(SCREEN_WIDTH_BODIES * ratio.x, 0, SCREEN_WIDTH_UI * ratio.x, SCREEN_HEIGHT * ratio.y);
	glClearColor(0.1294f, 0.1294f, 0.1294f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	std::vector<s_textInformation> texts = {
		{ "CONTROLS:", ALIGN_CENTER, UNDERLINE_TEXT, 0.6f * ratio.y, Vector3f(1, 1, 1) },
		{ "Translate: WSADQE", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Rotate: IKJLUO", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Scale: TGFHRY", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Next limb: RIGHT ARROW", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Previous limb: LEFT ARROW", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Reset limb: C", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Reset body: X", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Toggle animation loop: EQUAL", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Toggle shown bodies: Z", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Toggle selected body: N", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Animations: 1 -> 3", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Pause animation: 0", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Print to term: SPACE", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ "Print to file: P", ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },

		{ "Informations", ALIGN_CENTER, UNDERLINE_TEXT, 0.6f * ratio.y, Vector3f(1, 1, 1) },
		{ std::string("Current selected body: ").append(indexBody.modelIndex == 1 ? "DOGGO" : "HUMAN"), ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ std::string("Is animated: ").append(body->isAnimated == true ? "TRUE" : "FALSE"), ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ std::string("Current animation: ").append(std::to_string(body->animationIndex)), ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
		{ std::string("Is animation looping: ").append(body->isAnimationLooping == true ? "TRUE" : "FALSE"), ALIGN_LEFT, REGULAR_TEXT, 0.45f * ratio.y, Vector3f(1, 1, 1) },
	};
	placeText(font, texts);
}
