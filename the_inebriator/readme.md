	//=========================== The Inebriator =========================//
 	Alexandre "Xande" Lakiss
 	Gleice "Gle Ice" Kelly
 	João "Lucas" Coelho
 	José "Zuzé" Rodolfo

		1. Proposta do projeto
			1.1 1º GQ
			1.2 2º GQ
		2. Equipamentos eletrônicos utilizados no circuito (1º GQ)
		3. Funcionamento do projeto
			3.1 Escolhendo a bebida
			3.2 Escolhendo a temperatura
			3.3 Preparação do drink
			3.4 Como beber

	=======================================================================//
	1. PROPOSTA DO PROJETO
	O projeto tem por finalidade fazer uma máquina que seja capaz de servir até três tipos de drink de maneira automatizada, o usuário precisa apenas escolher qual a bebida e a temperatura desejada dentre as opções do menu.

		1.1 1º GQ - Para o primeiro GQ será entregue o projeto da seguinte maneira:
		    	* Menu com 3 opções de bebidas;
		    	* Possibilidade de ajuste de temperatura no menu;
          		* 1 Peltier funcional;
		        * 1 Bomba do líquido funcional;
		        * 1 Válvula Solenoide funcional;
		        * Das 3 opções de bebidas do menu, uma será funcional (a qual valida a funcionalidade do projeto);

		1.2 2º GQ - Para o segundo GQ, as seguintes adições serão feitas:
		       * Mais 2 opções de bebidas funcionais;
	     	       * +1 Bomba;
		       * +1 Válvula Solenoide;
		       * Esteira para movimentaÁ„o do copo;
           	       * Braço robótico;

	2. EQUIPAMENTES ELETRÔNICOS UTILIZADOS NO CIRCUITO (1º GQ)
		- 1 Arduíno Mega
		- 1 Válvula Solenoide
		- 1 Peltier
		- 1 Módulo Relê de 4 portas
		- 2 placas de circuito
		- 1 Display LCD LiquidCrystal 16x2
		- 1 Sensor de calor LM35
		- 5 botões
		- 1 Potenciômetro 50k
		- 1 Bomba de Aquário
		- 1 Fonte de alimentação (5v e 13v)

	3. FUNCIONAMENTO DO PROJETO
		3.1 Escolhendo a bebida - O usuário dispõe de 3 botões (vai, volta e confirma) para navegar pelo menu. Após escolher a bebida desejada, basta apertar o botão de confirma e esperar.
		3.2 Escolhendo a temperatura - Antes de confirmar a escolha da bebida, o usuário pode escolher a temperatura desejada para o drink, que varia entre 0˚ e temperatura ambiente (30˚ máximo do visor de escolha).
		3.3 Preparação do drink - Após a escolha do usuário, acontecem as seguintes etapas em ordem:
				  	* A bomba de aquário È ativada e bombeia o líquido para o funil durante 5 segundos;
			     		* A peltier gela atÈ atingir a temperatura desejada ou o limite de 10 segundos;
				  	* A válvula solenoide È ativada e deixa que o conte˙do do funil saia durante 5 segundos para o copo.
		3.4 Como beber - Moderadamente =)
