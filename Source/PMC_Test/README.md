# Procedural brick wall and a plane for UE4

## The wall
Class ```AProceduralWallTest```

Features:
* Could be "destroyed" using 1D Perlin Noise or/and random circles cutting
  * Perlin Noise library from https://github.com/Reputeless/PerlinNoise.git
* Editable size of brick
* High perfomance (one brick instance represents all wall)
* Optional offset by a half of brick length (in brickwork style)


## The plane
Class ```AMyActor```

Just plain, constructed by four triangles: per two on side. (Code from some tutorual in the internet)
