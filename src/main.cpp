﻿#include "Algorithms/hash_table.h"

#include <algorithm>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glm/vec2.hpp"

#include "Game/AllowedCell.h"
#include "Game/Desk.h"
#include "Game/Figure.h"

#include "GLPref/GLPref.h"
#include "Resources/ResourceManager.h"
#include "Game/Game.h"
#include "Game/GObject.h"
#include "Game/Desk.h"
#include "Algorithms/StandartDebut.h"

//GLfloat points[] =
//{
//	0.0f, 50.0f, 0.0f,
//	50.0f, -50.0f, 0.0f,
//	-50.0f, -50.0f, 0.0f
//};
//
//GLfloat colors[] =
//{
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f
//};
//
//GLfloat texCoord[] =
//{
//	0.5f, 1.0f,
//	1.0f, 0.0f,
//	0.0f, 0.0f
//};

int main(int argc, char** argv)
{
	glm::ivec2 g_MainWindow_size(1080, 1080);
	glm::ivec2 g_BoardSize(g_MainWindow_size);
	GLPref::init(g_MainWindow_size);
	{
		
		Game game;
		Game::init(g_BoardSize, argv[0]);

		Game::desk = new Desk;
		Game::desk->SetSprite("sprite_Desk", "Desk", "SpriteShader", Game::m_BoardSize.x, Game::m_BoardSize.y, "");

		for (int it = 0; it < 9; ++it)
		{
			Game::figures_black[it] = new Figure;
			Game::figures_white[it] = new Figure;

			Game::figures_black[it]->SetSprite("Figure_black", "Figures", "SpriteShader", 135, 135, "black_pawn");
			Game::figures_black[it]->fraction = 2;
			Game::figures_white[it]->SetSprite("Figure_white", "Figures", "SpriteShader", 135, 135, "white_pawn");
			Game::figures_white[it]->fraction = 1;
		}

		int it_Figures_black = 0;
		int it_Figures_white = 0;

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (Game::BoardGraph[i][j] == 1)
				{
					Game::figures_white[it_Figures_white]->Translate(glm::vec3(i, j, 0));
					Game::figures_white[it_Figures_white]->cellposition = glm::vec2(i, j);
					Game::white_home[it_Figures_white] = glm::ivec2(i, j);
					++it_Figures_white;
				}
				else if (Game::BoardGraph[i][j] == 2)
				{
					Game::figures_black[it_Figures_black]->Translate(glm::vec3(i, j, 0));
					Game::figures_black[it_Figures_black]->cellposition = glm::vec2(i, j);
					Game::black_home[it_Figures_black] = glm::ivec2(i, j);
					++it_Figures_black;
				}
			}
		}
		Game::ai.CollectMoves(StandartDebut);
		while (!glfwWindowShouldClose(Game::MainWindow))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			Game::desk->render();
			for (int it = 0; it < 9; ++it)
			{
				Game::figures_black[it]->render();
				Game::figures_white[it]->render();
			}

			glfwSwapBuffers(Game::MainWindow);

			glfwPollEvents();
		}
	}
	ResourceManager::UnloadAllResources();
	glfwTerminate();

	return 0;
}