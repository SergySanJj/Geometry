#include <windows.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <set>
#include "PointSet.h"

bool finder(vector<Point>& pts, Point& pt)
{
	for (int i = 0; i > pts.size(); i++)
	{
		if (pt.cmp(pts[i]) == 1)
		{
			return 1;
		}
		
	}
	return 0;
}

std::vector<Point> gener(int n)
{
	std::vector<Point> pts;

	srand(time(NULL));
	int k = 0;
	while (k != n)
	{
		Point tmpPoint;
		tmpPoint.x = rand() % 500;
		tmpPoint.y = rand() % 500;
		while (finder(pts, tmpPoint) == 1)
		{
			tmpPoint.x = rand() % 500;
			tmpPoint.y = rand() % 500;
		}
		pts.push_back(tmpPoint);
		k++;
	}
	return pts;
}

#define SS 100
int main()
{
	system("mode con cols=100 lines=70");
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	std::string s = "points.txt";
	//PointSet P(SS, s);
	PointSet P(SS);
	P.setPoints(gener(SS));
	P.drawPoints(hdc);

	std::vector<Point> tmp = P.convexHull(SS);
	drawPoly(hdc, tmp);
	ReleaseDC(hwnd, hdc);

	std::cin.ignore();
	//system("pause");
	return 0;
}