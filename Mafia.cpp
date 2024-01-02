
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Circle {
    int x, y, r;
};

bool intersects(const Circle &c, int line, bool horizontal) {
    if (horizontal) {
        return c.y - c.r <= line && line <= c.y + c.r;
    } else {
        return c.x - c.r <= line && line <= c.x + c.r;
    }
}

int maxIntersections(const vector<Circle> &circles, int size, bool horizontal) {
    vector<int> count(size + 1, 0);
    for (const auto &circle : circles) {
        for (int i = 0; i <= size; ++i) {
            if (intersects(circle, i, horizontal)) {
                count[i]++;
            }
        }
    }
    return *max_element(count.begin(), count.end());
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<Circle> circles(K);
    for (int i = 0; i < K; ++i) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    int maxHorizontal = maxIntersections(circles, M, true);
    int maxVertical = maxIntersections(circles, N, false);

    cout << max(maxHorizontal, maxVertical) << endl;
    return 0;
}
