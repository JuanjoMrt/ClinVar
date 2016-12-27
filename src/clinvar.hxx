

/** @brief lee un fichero de mutaciones, linea a linea
@param[in] s nombre del fichero
*/

void clinvar::load (string nombreDB){
	int i = 0;
	ifstream fe;
	string cadena;

	cout << "Abrimos " << nombreDB << endl;
	fe.open(nombreDB.c_str(), ifstream::in);
	if(fe.fail()){
		cerr << "Error al abrir el fichero" << nombreDB << endl;
	}
	else{

		do{
			getline(fe,cadena, '\n');
			//Leemos la cabecera del fichero(líneas que empiezan con #)
		}while(cadena.find("#") == 0 && !fe.eof());
		
		while( !fe.eof() ){
			mutacion mut = mutacion(cadena);
			this.insert(mut);
			cout << "Mutación " << mut.getID() << "\n";
			i++;
			getline(fe, cadena, '\n');	
		}
	}
	cout << i << " mutaciones cargadas";
	fe.close();
}

//void clinvar::insert (const mutacion & x){}
//bool clinvar::erase (IDmut ID){}
//iterator clinvar::find_Mut (IDmut ID){}
//enfermedad_iterator clinvar::find_Enf(IDenf ID){}
//vector<enfermedad> clinvar::getEnfermedades(mutacion & mut){}
//list<IDenf> clinvar::getEnfermedades(string keyword){}
//set<IDmut> clinvar::getMutacionesEnf (IDenf ID){}
//set<IDmut> clinvar::getMutacionesGen (IDgen ID){}
//set<mutacion,ProbMutaciones> clinvar::topKMutaciones (int k, string keyword){}
/* Métodos relacionados con los iteradores */
//iterator clinvar::begin(){}
//iterator clinvar::end(){}
//iterator clinvar::lower_bound(string cromosoma, unsigned int posicion){}
//iterator clinvar::upper_bound(string cromosoma, unsigned int posicion){}
//enfermedad_iterator clinvar::ebegin(){}
//enfermedad_iterator clinvar::eend(){}
//gen_iterator clinvar::gbegin(){}
//gen_iterator clinvar::gend(){}