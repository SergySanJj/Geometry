#include <windows.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include "PointSet.h"

void gener(int n,std::string s)
{
	std::vector<Point> pts(n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		int t_x = rand() % 200;
		int t_y = rand() % 200;
		bool ttt = 0;
		while (!ttt)
		{
			for (int j = 0; j < n; j++)
			{
				if (pts[j].x == t_x && pts[j].y == t_y)
				{
					ttt = 0;
					int t_x = rand() % 200;
					int t_y = rand() % 200;
				}
			}
			ttt = 1;
		}
	}
}

int main()
{
	system("mode con cols=100 lines=70");
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	std::string s = "points.txt";
	PointSet P(10, s);

	P.drawPoints(hdc);

	std::vector<Point> tmp = P.convexHull(10);
	drawPoly(hdc, tmp);
	ReleaseDC(hwnd, hdc);

	std::cin.ignore();
	//system("pause");
	return 0;
}