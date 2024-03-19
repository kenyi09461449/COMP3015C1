#pragma once
#include <GLFW/glfw3.h>
#include <utility>
class Input {
public:

	void Init(GLFWwindow* window) { m_window = window; };

	static Input& Instance()
	{
		static Input instance;
		return instance;
	}

	bool IsKeyPressed(int keycode) {
		auto state = glfwGetKey(m_window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool IsMouseButtonPressed(int button)
	{
		auto state = glfwGetMouseButton(m_window, button);
		return state == GLFW_PRESS;
	}
	std::pair<float, float> GetMousePosition()
	{
		double xpos, ypos;
		glfwGetCursorPos(m_window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}
	float GetMouseX()
	{
		auto x = GetMousePosition();
		return x.first;
	}
	float GetMouseY()
	{
		auto x = GetMousePosition();
		return x.second;
	}
private:
	Input() {}
	~Input() {}
	Input(const Input&) {};
	Input& operator=(const Input&) {};

private:
	GLFWwindow* m_window;
};