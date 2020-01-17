#pragma once

using ll = int;

// right(E,0)/down(S,1)/left(W,2)/up(N,3)
const ll dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

// right(E,0)/down(S,1)/left(W,2)/up(N,3)
// down-ri(SE,4)/do-le(SW,5)/up-le(NW,6)/up-ri(NE,7)
const ll dir[8][2] = {
    {0,1}, {1,0}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,-1}, {-1,1}
};
