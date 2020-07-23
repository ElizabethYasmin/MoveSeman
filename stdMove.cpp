/* el move estándar funciona en realidad como un conversor de tipo
se utiliza para decirle al compilador que utilice un objeto como 
si fuera un rvalue,lo que significa que se puede mover*/

#include <cstdio>
#include <vector>//para usar std::vector
#include <string>
#include <utility>

void message(const std::string & s) {//funcion para mostrar un mensaje en la pantalla
    puts(s.c_str());
    fflush(stdout);
}

void disp_vector(const std::vector<std::string> & v) {//Funcion que muestra los vectores
    size_t size = v.size();
    printf("vector size: %ld\n", size);
    if(size) {
        for( std::string s : v ) {
            printf("[%s]", s.c_str());/*c_str devuelve un const char* que apunta 
			a una cadena terminada en nulo (es decir, una cadena de estilo C). 
			Es útil cuando quiere pasar el "contenido" de un std::string a una 
			función que espera trabajar con una cadena de estilo C.*/
        }
        puts("");//salto de linea
    }
    fflush(stdout);
}


//EL STD::MOVE SE PUEDE USAR PARA REALIZAR UNA FUNCION DE INTERCAMBIO(sin utilizar copia)
template <typename T>
void swap(T & a,T & b){
	message("llamando swap()");
	T tmp(std::move(a));
	a=std::move(b);
	b=std::move(tmp);
}

int main( int argc, char ** argv ) {
	/*std::vector ->Un vector es una matriz dinámica con 
	almacenamiento manejado automáticamente. 
	Se puede acceder a los elementos de un vector con la misma
	 eficacia que los de una matriz, con la ventaja de que los
	  vectores pueden cambiar dinámicamente de tamaño.*/
    std::vector<std::string> v1 = { "uno", "dos", "tres", "cuatro", "cinco" };
    /*std::string (a diferencia de una cadena C) puede contener el carácter \0.*/
    
    std::vector<std::string> v2 = { "seis", "siete", "ocho", "nueve", "diez" };
    
    message("v1");
    disp_vector(v1);
    message("v2");
    disp_vector(v2);
    
    
    message("-----------------------------------");
    
    //FUNCION ESTANDAR SWAP
    //std::swap(v1,v2);
    //FUNCION SWAP
    //::swap(v1,v2);
    //COPIANDO ELEMENTOS
    //v2=v1;
    //MOVIENDO V1 A V2
    //v2=std::move(v1);//funcion plantilla de move/conversor
	// de tipo que dice que esto se puede mover

	message("v1");
    disp_vector(v1);
    message("v2");
    disp_vector(v2);



    return 0;
}
