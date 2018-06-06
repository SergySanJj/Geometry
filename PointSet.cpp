#include "PointSet.h"


PointSet::~PointSet()
{
}

void PointSet::coordinatesInput(std::string path)
{
	std::ifstream fin(path);
	for (int i = 0; i < N; i++)
	{
		int x, y;
		fin >> x >> y;
		points[i].x = x;
		points[i].y = y;
	}
}

void PointSet::drawPoints(HDC hdc)
{
	HPEN pen = CreatePen(PS_SOLID, 4, RGB(255, 255, 255));
	SelectObject(hdc, pen);

	MoveToEx(hdc, points[0].x, points[0].y, (LPPOINT)NULL);
	LineTo(hdc, points[0].x, points[0].y);

	for (int i = 1; i < N; i++)
	{
		MoveToEx(hdc, points[i].x, points[i].y, (LPPOINT)NULL);
		LineTo(hdc, points[i].x, points[i].y);
	}
}

void drawPoly(HDC hdc, std::vector<Point> poly)
{
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, pen);

	MoveToEx(hdc, poly[0].x, poly[0].y, (LPPOINT)NULL);

	for (int i = 1; i < poly.size(); i++)
	{
		LineTo(hdc, poly[i].x, poly[i].y);
		MoveToEx(hdc, poly[i].x, poly[i].y, (LPPOINT)NULL);
	}
	LineTo(hdc, poly[0].x, poly[0].y);
}