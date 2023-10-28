#include "Title.h"

void Title::Initialize()
{
}

SceneType Title::Update()
{
	// 엔터 키를 눌렀을 때, 씬을 변경
	if (GetAsyncKeyState(VK_RETURN))
	{
		return SceneType::INGAME;
	}

	return SceneType::NONE;
}

void Title::Render()
{           Panel::Print("                                                       ", 35, 4);
            Panel::Print("                         /\\                            ", 35, 5);
            Panel::Print("                        |  |                           ", 35, 6);
            Panel::Print("                        |  |                           ", 35, 7);
            Panel::Print("                       .'  '.                          ", 35, 8);
            Panel::Print("                       |    |                          ", 35, 9);
            Panel::Print("                       |    |                          ", 35, 10);
            Panel::Print("                       | /\\ |                          ", 35, 11);
            Panel::Print("                     .' |__|'.                         ", 35, 12);
            Panel::Print("                     |  |  |  |                        ", 35, 13);
            Panel::Print("                    .'  |  |  '.                       ", 35, 14);
            Panel::Print("               /\\  |  \\__/   |    /\\                  ", 35, 15);
            Panel::Print("              |  |  |   |  |   |  |  |                 ", 35, 16);
            Panel::Print("          /|  |  |,-\\   |  |   /-,|  |  |\\             ", 35, 17);
            Panel::Print("          ||  |,-'   |  |  |  |   '-,|  ||             ", 35, 18);
            Panel::Print("          ||-'       |  |  |  |       '-||             ", 35, 19);
            Panel::Print("|\\     _,-'         |  |  |  |           '-,_     /| ", 35, 20);
            Panel::Print("||  ,-'   _          |  |  |  |               '-,  || ", 35, 21);
            Panel::Print("||-'    =(*)=        |  |  |  |                  '-|| ", 35, 22);
            Panel::Print("||                   |  \\  /  |                    || ", 35, 23);
            Panel::Print("|\\________....--------\\   ||   /--------....________/| ", 35, 24);
            Panel::Print("                     /|  ||  |\\                        ", 35, 25);
            Panel::Print("                    / |  ||  | \\                       ", 35, 26);
            Panel::Print("                   /  |  \\/ |  \\                      ", 35, 27);
            Panel::Print("                  /   |      |   \\                     ", 35, 28);
            Panel::Print("                //   .|      |.   \\                   ", 35, 29);
            Panel::Print("              .' |_./ |      | \\._| '.                 ", 35, 30);
            Panel::Print("             /     _.-|||  |||-. _    \\                ", 35, 31);
            Panel::Print("             \\__.-'   \\||/\\||/  '-.__/                ", 35, 32);

   Panel::Print("                   ----Press Enter Key----                   ", 30, 35);

}

void Title::Release()
{
}

Title::Title()
{
}

Title::~Title()
{
}
