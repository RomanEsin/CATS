//
//  main.cpp
//  psudnfisadnf
//
//  Created by Roman Esin on 26.09.2020.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    int x[n], y[n];
    int nums[n];

    for (int i = 0; i < n; i++) {
        // init nums array
        nums[i] = 0;

        cin >> x[i];
        cin >> y[i];
    }

    // O(n^2) time
    for (int i = 0; i < n; i++) {
        int x1 = x[i];
        int w = y[i] + x1;

        for (int j = 0; j < n; j++) {
            int x2 = x[j];
            int w2 = y[j] + x2;

            // x1 <= x2 <= w
            //     ||
            // x1 <= w2 <= w
            if ((x1 <= x2 && x2 <= w) || (x1 <= w2 && w2 <= x2)) {
                nums[i] += 1;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    cout << max << endl;

    return 0;
}
