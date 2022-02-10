#include "validator.h"

void run() {
    int n = Int(1, 400);   
    Endl();
    int k = 3;
    for(int c1 = 0; c1 < k+1; c1++){
        SpacedInts<int>(n,1,1000000);
    }
}
