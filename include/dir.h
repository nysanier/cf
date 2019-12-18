#pragma once

using ll = int;

// up/right/down/left
ll dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
// up/ri/do/le
// ur/dr/dl/ul
ll dir[8][2] = {
    {0,1}, {1,0}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,-1}, {-1,1}
};
