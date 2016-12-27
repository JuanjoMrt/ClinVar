#ifndef __CLINVAR_H
#define __CLINVAR_H

#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


class clinvar{
	private:
		set<mutacion> mutDB; //base de datos que contiene toda la información asociada a una mutacion
		unordered_map<IDmut,set<mutacion>::iterator> IDm_map; // Asocia IDmutacion con mutación
		map<IDgen, list< set<mutacion>::iterator> > gen_map; // Asocia genes con mutaciones
		map<IDenf,Enfermedad> EnfDB; // Base de datos de enfermedades
		multimap<IDenf,set<mutacion>::iterator> IDenf_map; // Asocia enfermedad con mutaciones
	public:
		public:
			void load (string nombreDB);
			void insert (const mutacion & x);
			bool erase (IDmut ID);
			iterator find_Mut (IDmut ID);
			enfermedad_iterator find_Enf(IDenf ID);
			vector<enfermedad> getEnfermedades(mutacion & mut);
			list<IDenf> getEnfermedades(string keyword);
			set<IDmut> getMutacionesEnf (IDenf ID);
			set<IDmut> getMutacionesGen (IDgen ID);
			set<mutacion,ProbMutaciones> topKMutaciones (int k, string keyword);
			/* Métodos relacionados con los iteradores */
			iterator begin();
			iterator end();
			iterator lower_bound(string cromosoma, unsigned int posicion);
			iterator upper_bound(string cromosoma, unsigned int posicion);
			enfermedad_iterator ebegin();
			enfermedad_iterator eend();
			gen_iterator gbegin();
			gen_iterator gend();
}

#include "../src/clinvar.hxx"

#endif