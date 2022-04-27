#include "Casilla.h"
#include <math.h>

//CONSTRUCTORES Y DESTRUCTORES
Casilla::Casilla(int x, int y){
  f = x; //fila
  c = y; //columna
}

Casilla::Casilla(const Casilla& cas){
	f = cas.f;
	c = cas.c;
}

Casilla::~Casilla(){
}

//OPERADORES
Casilla Casilla::operator +(Casilla cas){
  Casilla res;
  res.f = f + cas.f;
  res.c = c + cas.c;
  return res;
}

Casilla Casilla::operator +(float num){
  Casilla res;
  res.f = f + num;      //avanza o retrocede fila, clave en mov de ajedrez
  res.c = c;
  return res;
}

Casilla Casilla::operator -(Casilla cas){
  Casilla res;
	res.f= f - cas.f; 
	res.c= c - cas.c; 
	return res; 
}

Casilla Casilla::operator *(float num){
  Casilla res;
  res.f = f * num;
  res.c = c * num;
  return res;
}

float Casilla::operator *(Casilla cas){
  return f*cas.f + c*cas.c;
}

float Casilla::argumento(){
  return atan2((float)c,(float)f);
}

float Casilla::modulo(){
  return sqrt((float)(f*f+c*c));
}

bool operator==(Casilla cas1, Casilla cas2){
	if (cas1.f == cas2.f && cas1.c == cas2.c) {
		return true;
	}
	else {
		return false;
	}
}

bool operator != (Casilla cas1, Casilla cas2) {
	return (!(cas1 == cas2));
}
