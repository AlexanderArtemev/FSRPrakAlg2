#include "solver.h"
#include <iostream>
#include <vector>

void Solver::answer(int W, Th arr[], int N) {
    std::vector<std::vector<int>> h(N + 1, std::vector<int>(W + 1, 0));
    int global_W = 0;
    std::vector<int> t_th(N, 0);
    int reW = W;
    int i = 0;
    int w;
    while (i < N) {
        w = 0;
        while (w < W) {
            if (arr[i].wei <= w+1) {
                int t = h[i][w+1 - arr[i].wei] + arr[i].val;
                int n_t = h[i][w+1];
                h[i+1][w+1] = std::max(t, n_t);
            } else {
                h[i+1][w+1] = h[i][w+1];
            }
            w++;
        }
        i++;
    }
    std::cout << h[N][W];
    i = N;
    while (i > 0 && h[N][W] > 0) {
        if (h[N][W] != h[i - 1][reW]) {
            t_th[i - 1] = 1;
            h[N][W] -= arr[i - 1].val;
            global_W += arr[i - 1].wei;
            reW -= arr[i - 1].wei;
        }
        i--;
    }
    if (W-global_W<0){
        std::cout<<"error"<<std::endl;
    }
    W = W-global_W;
    std::cout << " " << W << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << t_th[i] << " ";
    }
}