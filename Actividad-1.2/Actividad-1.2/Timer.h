//
//  Timer.h
//  Actividad-1.2
//
//  Created by Diego Solis on 8/26/20.
//  Copyright © 2020 Diego Solis. All rights reserved.
//

#ifndef Timer_h
#define Timer_h
#include <chrono>
#include <iostream>

class Timer {
public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    };

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        auto timestep = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "Execution time: " << timestep << " nanoseconds" << std::endl;
    };
private:
    std::chrono::high_resolution_clock::time_point start,end;
};


#endif /* Timer_h */
