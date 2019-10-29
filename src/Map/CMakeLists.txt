# Map sources

set(Map_Physic_Srcs
    ${Srcdir}/Map/Physic/Hitbox.cpp
    ${Srcdir}/Map/Physic/Hitbox.h
    ${Srcdir}/Map/Physic/ManageHitbox.cpp
    ${Srcdir}/Map/Physic/ManageHitbox.h
)


set(Map_Srcs 
    ${Map_Physic_Srcs}
    ${Srcdir}/Map/Camera.cpp
    ${Srcdir}/Map/Camera.h
    ${Srcdir}/Map/Layer.cpp
    ${Srcdir}/Map/Layer.h
    ${Srcdir}/Map/ManageRenderTexture.cpp
    ${Srcdir}/Map/ManageRenderTexture.h
    ${Srcdir}/Map/ManageRessources.cpp
    ${Srcdir}/Map/ManageRessources.h
    ${Srcdir}/Map/ManageSurfaces.cpp
    ${Srcdir}/Map/ManageSurfaces.h
    ${Srcdir}/Map/Map.cpp
    ${Srcdir}/Map/Map.h
    ${Srcdir}/Map/Surface.cpp
    ${Srcdir}/Map/Surface.h
    ${Srcdir}/Map/SurfaceSprite.cpp
    ${Srcdir}/Map/SurfaceSprite.h
    ${Srcdir}/Map/SurfaceText.cpp
    ${Srcdir}/Map/SurfaceText.h
    ${Srcdir}/Map/Tile.cpp
    ${Srcdir}/Map/Tile.h
    PARENT_SCOPE
)