/** @brief fichero de implementacion de la clase enfermedad
*/

enfermedad::enfermedad()
	:enfermedad("Hereditary_cancer-predisposing_syndrome", "C0027672:699346009", "MedGen:SNOMED_CT")
{ }

enfermedad::enfermedad(const string &name, const string &ID, const string &database){
	setName(name);
	setID(ID);
	setDatabase(database);
}

void enfermedad::setName(const string &name){
	this->name = name;
}

void enfermedad::setID(const string &ID){
	this->ID = ID;
}

void enfermedad::setDatabase(const string &database){
	this->database = database;
}

string enfermedad::getName() const{
	return name;
}

string enfermedad::getID() const{
	return ID;
}

string enfermedad::getDatabase() const{
	return database;
}

enfermedad &enfermedad::operator=(const enfermedad &e){
	if (&e != this){
		setName(e.getName());
		setID(e.getID());
		setDatabase(e.getDatabase());
	}

	return *this;
}

string enfermedad::toString() const{
	return ID + ":  " + name + "  in  " + database;
}

bool enfermedad::operator==(const enfermedad &e) const{
	bool iguales = false;

	if (this->name == e.getName())
		if (this->ID == e.getID())
			if (this->database == e.getDatabase())
				iguales = true;

	return iguales;
} 

bool enfermedad::operator!=(const enfermedad &e) const{
	return !(*this == e);
}

bool enfermedad::operator<(const enfermedad &e) const{		// Orden alfabético por campo name. 
	int tama_elem1 = name.size(),
		 tama_elem2 = e.getName().size();

	bool menor = false,
		  no_salgas = true,
		  tam1_menor_tam2 = tama_elem1 < tama_elem2;

	int tamanio_min = (tam1_menor_tam2) ? tama_elem1 : tama_elem2;

	for (int i = 0; i < tamanio_min && !menor && no_salgas; i++){
		if (name.at(i) < e.getName().at(i))
			menor = true;

		else if (name.at(i) > e.getName().at(i))
			no_salgas = false;

		else if (name.at(i) == e.getName().at(i) && i == (tamanio_min - 1)){
			if (tam1_menor_tam2)
				menor = true;
		}
	}

	return menor;
}

bool enfermedad::operator>(const enfermedad &e) const{
	return !(*this < e) && (e < *this);
}

bool enfermedad::nameContains(const string &str) const{
	bool contenido = false;
	string name_lower = "",
			 str_lower = "";

	if (name.size() >= str.size()){
		for (unsigned i = 0; i < name.size(); i++)	
			name_lower += tolower(name[i]);

		for (unsigned i = 0; i < str.size(); i++)	
			str_lower += tolower(str[i]);

		if (name_lower.find(str_lower) != string::npos)
			contenido = true;
	}

	return contenido;
}   
 
ostream &operator<<(ostream &os, const enfermedad &e){
	os << "Enfermedad -> " << e.toString() << endl; 

	return os;
}
