#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;
TileGraph* GameObject::tileGraph = nullptr;

GameObject::GameObject(Texture* _textura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	eliminar = false;
	enMovimiento = false;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	textura = _textura;
	numeroFrame = 0;
	contadorFrames = 0;
	framesMovimiento = 1;
	colisionador = new SDL_Rect({ _posicionX, _posicionY, _ancho, _alto });
}

void GameObject::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect({ 25 * numeroFrame, 0, getAncho(), getAlto() });

	// Renderizar en la pantalla
	textura->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}

bool GameObject::revisarColision(const SDL_Rect* _otroColisionador)
{
	if (_otroColisionador->x > colisionador->x + colisionador->w) {
		return false;
	}

	if (_otroColisionador->y > colisionador->y + colisionador->h) {
		return false;
	}

	if (_otroColisionador->x + _otroColisionador->w < colisionador->x) {
		return false;
	}

	if (_otroColisionador->y + _otroColisionador->h < colisionador->y) {
		return false;
	}

	return true;
}

bool GameObject::revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2)
{
	if (_colisionador1->x > _colisionador2->x + _colisionador2->w) {
		return false;
	}

	if (_colisionador1->y > _colisionador2->y + _colisionador2->h) {
		return false;
	}

	if (_colisionador1->x + _colisionador1->w < _colisionador2->x) {
		return false;
	}

	if (_colisionador1->y + _colisionador1->h < _colisionador2->y) {
		return false;
	}

	return true;
}

void GameObject::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}