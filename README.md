# Procedural brick wall and Minecraft-like terrain for UE4

## Hierarchy
*  ```Actor``` (Build in UE4)
    *  ```AProceduralBlockBase```
        *  ```AProceduralBlockBase2D```
            *  ```AProceduralWall```
                *  ```AProceduralWallWithObject```
        *  ```AProceduralBlockBase3D``` (In future)
            *  ```AProceduralTerrain``` (In future)
    *  ```AProceduralBuilding```
    *  ```AProceduralPlane```

## The procedural wall
Class ```AProceduralWall```

Features:
* Could be "destroyed" using 1D Perlin Noise or/and random circles cutting
  * Perlin Noise library from https://github.com/Reputeless/PerlinNoise.git
* Editable size of brick
* High perfomance (one brick instance represents all wall)
* Optional offset by a half of brick length (in brickwork style)


Class ```AProceduralWallWithObject```

Features:
* Create a hole for build in the wall object like window or door
* Uses block and object sizes for calculating a hole size

## The plane
Class ```AProceduralPlane```

Just plain, constructed by four triangles: per two on a side. (Code from some tutorual in the internet)

## The terrain

