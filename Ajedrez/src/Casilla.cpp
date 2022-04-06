#include "Casilla.h"
#include <math.h>

//CONSTRUCTORES Y DESTRUCTORES
Casilla::Casilla(int x, int y){
  f = x; //fila
  c = y; //columna
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
