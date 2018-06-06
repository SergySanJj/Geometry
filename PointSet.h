#pragma once



#include <vector>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <cmath>

using std::vector;

struct Point
{
	
	int x = 0;
	int y = 0;
};

class PointSet
{
public:
	PointSet(int n, std::string path) :N(n) { points.resize(n); coordinatesInput(path); }
	~PointSet();

	void coordinatesInput(std::string path);
	void drawPoints(HDC hdc);

	std::vector<Point> getPoints()
	{
		return points;
	}


	int orr(Point pp, Point q, Point r)
	{
		int val = (q.y - pp.y) * (r.x - q.x) -
			(q.x - pp.x) * (r.y - q.y);

		if (val == 0) return 0;  // colinear
		return (val > 0) ? 1 : 2; // clock or counterclock wise
	}


	std::vector<Point> convexHull(int n)
	{
		vector<Point> POINTS = points;
		// Initialize Result
		vector<Point> hull;

		// Find the leftmost point
		int l = 0;
		for (int i = 1; i < n; i++)
			if (POINTS[i].x < POINTS[l].x)
				l = i;

		// Start from leftmost point, keep moving counterclockwise
		// until reach the start point again.  This loop runs O(h)
		// times where h is number of POINTS in result or output.
		int p = l, q;
		do
		{
			// Add current point to result
			hull.push_back(POINTS[p]);

			// Search for a point 'q' such that orr(p, x,
			// q) is counterclockwise for all POINTS 'x'. The idea
			// is to keep track of last visited most counterclock-
			// wise point in q. If any point 'i' is more counterclock-
			// wise than q, then update q.
			q = (p + 1) % n;
			for (int i = 0; i < n; i++)
			{
				// If i is more counterclockwise than current q, then
				// update q
				if (orr(POINTS[p], POINTS[i], POINTS[q]) == 2)
					q = i;
			}

			// Now q is the most counterclockwise with respect to p
			// Set p as q for next iteration, so that q is added to
			// result 'hull'
			p = q;
		} while (p != l);  // While we don't come to first point

						   // Print Result
		return hull;
	}

private:
	const int DIM = 2;
	int N = 0;
	std::vector<Point> points;
};

void drawPoly(HDC hdc, std::vector<Point> poly);





