class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Closest x-coordinate inside rectangle
        int closestX = max(x1, min(xCenter, x2));

        // Closest y-coordinate inside rectangle
        int closestY = max(y1, min(yCenter, y2));

        // Distance from circle center to closest point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};