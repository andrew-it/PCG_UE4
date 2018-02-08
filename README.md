# Procedural brick wall and a plane for UE4

## The wall
Class ```AProceduralWallTest```
Features:
* Could be "destroyed" using 1D Perlin Noise or/and random circles cutting
* Offset by a half of brick length (in brickwork style)
* Used Perlin Noise library from https://github.com/Reputeless/PerlinNoise.git

## The plane
Just plain, constructed by four triangles: per two on side