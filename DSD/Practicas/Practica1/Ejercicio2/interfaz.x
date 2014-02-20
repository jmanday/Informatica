		struct diccionario { 
			string clave<>;
			string valor<>;
			struct diccionario * sig;
		};

		struct listaDiccionarios {
			int id;
			struct diccionario * dic;
			struct listaDiccionarios * sig;
		};

		union resultadoAsociacion switch (int estado) {
			case 1:
				string val<>;
			default:
				void;
		};

		union listaResultados switch (int estado) {
			case 1:
				struct diccionario * diccio;
			default:
				void;
		};

		struct argumentos{
			int i;
			string c<>;
			string v<>;
		};
		typedef struct argumentos args1;


program EJERCICIO2 {

	version EJERVER {		

		int PONERASOCIACION (args1) = 1;
		resultadoAsociacion OBTENERASOCIACION (args1) = 2;
		int BORRARASOCIACION (args1) = 3;
		listaResultados ENUMERAR (int) = 4;

	} = 1;

} = 0x20000200;

