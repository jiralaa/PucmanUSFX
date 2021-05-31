#pragma once
#include "Pacman.h"
class MsPacman :
    public Pacman
{
private:
public:
    MsPacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
    void handleEvent(SDL_Event* event) override;
};

