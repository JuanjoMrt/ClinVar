#ifndef __ENFERMEDAD_H
#define __ENFERMEDAD_H

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void clinvar::load (string nombreDB);
void clinvar::insert (const mutacion & x);
bool clinvar::erase (IDmut ID);
iterator clinvar::find_Mut (IDmut ID);
enfermedad_iterator clinvar::find_Enf(IDenf ID);
vector<enfermedad> clinvar::getEnfermedades(mutacion & mut);
list<IDenf> clinvar::getEnfermedades(string keyword);
set<IDmut> clinvar::getMutacionesEnf (IDenf ID);
set<IDmut> clinvar::getMutacionesGen (IDgen ID);
set<mutacion,ProbMutaciones> clinvar::topKMutaciones (int k, string keyword);
/* Métodos relacionados con los iteradores */
iterator clinvar::begin();
iterator clinvar::end();
iterator clinvar::lower_bound(string cromosoma, unsigned int posicion);
iterator clinvar::upper_bound(string cromosoma, unsigned int posicion);
enfermedad_iterator clinvar::ebegin();
enfermedad_iterator clinvar::eend();
gen_iterator clinvar::gbegin();
gen_iterator clinvar::gend();