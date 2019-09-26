#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>


#define Modo_Teste_Validador_Prog 0


//using namespace std;

/*
Contém o nome e o CPF de um usuário, bem como a quantidade de ingressos que ele tem.
*/

int Geral_Comparador(std::string A, std::string B){
    int i = 0;

    while(i < A.size() && i < B.size()){
        if(A[i] != B[i]){
            return(0);
        }
        i++;
    }
    return(1);
}

class Validador{
private:
    std::string Palavra;
public:
    /*Validações genéricos*/
    Validador(){};
    int Check_If_Number(char A){/*Retorna 1 se for número.*/
        if(A > 47 && A < 58){
            return(1);
        }else{
            return(0);
        }
    }
    int Check_If_Letter(char A){/*Retorna 1 se for letra.*/
        if((A > 64 && A < 91) || (A > 96 && A < 123) || (A == 128) || (A == 135)){/*Minúscula, maiúscula e cidilhas*/
            return(1);
        }else{
            return(0);
        }
    }
    int Check_If_Dot(char A){/*Retorna 1 se for ponto.*/
        if(A == '.'){
            return(1);
        }else{
            return(0);
        }
    }
    int Check_If_Space(char A){/*Retorna 1 se for espaço.*/
        if(A == ' '){
            return(1);
        }else{
            return(0);
        }
    }

    /*Validações dos campos*/
    int Codigo_Do_Jogo(std::string Palavra){/*3 dígitos, números decimais*/
        int valido;
        //std::string Word;
        int i = 0;

        valido = 1;
        while(Palavra[i] != '\0' && valido == 1){
            valido = Check_If_Number(Palavra[i]);
            i++;
        }
        if(valido == 0){
            std::cout << "\nCaractere diferente de numero!\n";
        }else{
            if(i > 3){
                valido = 0;
                std::cout << "\nTamanho maximo (3) excedido!(" << i << ")\n";
            }
        }
        return(valido);
    }
    int Codigo_Do_Ingresso(std::string Palavra){/*5 dígitos, números decimais*/
        int valido;
        //std::string Word;
        int i = 0;

        valido = 1;
        while(Palavra[i] != '\0' && valido == 1){
            valido = Check_If_Number(Palavra[i]);
            i++;
        }
        if(valido == 0){
            std::cout << "\nCaractere diferente de numero!\n";
        }else{
            if(i > 5){
                valido = 0;
                std::cout << "\nTamanho maximo (5) excedido!\n";
            }
        }
        return(valido);
    }
    int Nome_Do_Jogo(std::string Palavra){/*20 dígitos, letra, dígito ou espaço. Pelo menos 1 letra. Sem 2 espaços seguidos.*/
        int valido;
        int TemLetra;
        int TeveEspaco;
        //std::string Word;
        int i = 0;

        TeveEspaco = 0;
        TemLetra = 0;
        valido = 1;
        while(Palavra[i] != '\0' && valido == 1){
            if(Check_If_Letter(Palavra[i])){
                TemLetra = 1;
                TeveEspaco = 0;
            }else{
                if(Check_If_Number(Palavra[i])){
                    TeveEspaco = 0;
                }else{
                    if(Check_If_Space(Palavra[i])){
                        if(TeveEspaco == 0){
                            TeveEspaco = 1;
                        }else{
                            std::cout << "\nDois espacos Seguidos!\n";
                            valido = 0;
                        }
                    }else{
                        std::cout << "\nCaractere nao permitido no nome.\n";
                        valido = 0;
                    }
                }
            }
            i++;
        }
        if(TemLetra == 0){
            std::cout << "\nNenhuma letra no nome do jogo!\n";
            valido = 0;
        }else{
            if(i > 20){
                std::cout << "\nTamanho maximo (20) excedido!!\n";
                valido = 0;
            }
        }
        return(valido);
    }
    int Data_Do_Jogo(std::string Palavra){/*DD/MM/AA onde DD é de 1 a 31, MM é de 1 a 12 e AA é de 0 a 99, considerando anos bisextos e os meses*/
        int Bisexto;
        int NDias;
        int DD = 0;
        int MM = 0;
        int AA = 0;
        int valido = 1;
        int i = 0;


        if((Palavra[1] != '/' && Palavra[4] != '/' && Palavra[5] != '/') && (Palavra[2] != '/' && Palavra[5] != '/' && Palavra[6] != '/')){
            std::cout << "\nFormato invalido para a Data.\n";
            valido = 0;
        }else{
            if(Palavra[1] == '/'){
                MM = 1;
                if(Palavra[3] == '/'){
                    AA = 3;
                }else{
                    AA = 4;
                }
            }else{
                MM = 2;
                if(Palavra[4] == '/'){
                    AA = 4;
                }else{
                    AA = 5;
                }
            }
            i = 0;
            DD = 0;
            while(i < MM && valido == 1){
                if(Check_If_Number(Palavra[i])){
                    DD = DD*10 + Palavra[i] - 48;
                    i++;
                }else{
                    std::cout << "\nDigito invalido para o dia(" << DD << "," << i << ")n";
                    valido = 0;
                }
            }
            i = MM + 1;
            MM = 0;
            while(i < AA && valido == 1){
                if(Check_If_Number(Palavra[i])){
                    MM = MM*10 + Palavra[i] - 48;
                    i++;
                }else{
                    std::cout << "\nDigito invalido para o mes!(" << MM << "," << i << ")\n";
                    valido = 0;
                }
            }
            i = AA + 1;
            AA = 0;
            while(Palavra[i] != '\0' && valido == 1){
                if(Check_If_Number(Palavra[i])){
                    AA = AA*10 + Palavra[i] - 48;
                    i++;
                }else{
                    std::cout << "\nDigito invalido para o ano!(" << AA << "," << i << ")\n";
                    valido = 0;
                }
            }
            if(AA > 30){
                AA = AA + 1900;
            }else{
                if(AA < 29){
                    AA = AA + 2000;
                }
            }
            if((AA%4 == 0 && AA%100 != 0) || (AA%100 == 0 && AA%400 == 0)){
                Bisexto = 1;
            }else{
                Bisexto = 0;
            }
            NDias = 0;
            switch(MM){
                case(1):
                case(3):
                case(5):
                case(7):
                case(8):
                case(10):
                case(12):
                    NDias = NDias + 1;
                case(4):
                case(6):
                case(9):
                case(11):
                    NDias = NDias + 2 - Bisexto;
                case(2):
                    NDias = NDias + 28 + Bisexto;
            }
            if(MM < 1 || MM > 12){
                std::cout << "\nMes invalido.(" << MM << ")\n";
                valido = 0;
            }else{
                if(DD < 1 || DD > NDias){
                    std::cout << "Dia invalido. (Mes " << MM << " so tem "<< NDias << " dias)\n";
                    valido = 0;
                }
            }
        }
    }
    int Horario_Da_Partida(std::string Palavra){/*HH:MM onde HH é de 7 a 22 e MM é 00,15,30 ou 45*/
        int valido = 1;
        int Valor = 0;

        if(Palavra[1] == ':'){
            if(Check_If_Number(Palavra[0]) && Check_If_Number(Palavra[2]) && Check_If_Number(Palavra[3])){
                Valor = Palavra[0] - 48;
                if(Valor < 7 || Valor > 22){
                    std::cout << "\nHorario fora da margem.("<< Valor <<" fora de 07 a 22)\n";
                    valido = 0;
                }else{
                    Valor = (Palavra[2] - 48)*10 + Palavra[3] - 48;
                    if(Valor != 00 && Valor != 15 && Valor != 30 && Valor != 45){
                        std::cout << "\nMinutos invalidos.\n" << Valor << " Nao e 00, 15, 30 nem 45. \n";
                        valido = 0;
                    }
                }
            }else{
                std::cout << "\nHorario invalido.\n";
                valido = 0;
            }
        }else{
            if(Check_If_Number(Palavra[0]) && Check_If_Number(Palavra[1]) && Check_If_Number(Palavra[3]) && Check_If_Number(Palavra[4])){
                Valor = (Palavra[0] - 48)*10 + Palavra[1] - 48;
                if(Valor < 7 || Valor > 22){
                    std::cout << "\nHorario fora da margem.("<< Valor <<" fora de 07 a 22)\n";
                    valido = 0;
                }else{
                    Valor = (Palavra[3] - 48)*10 + Palavra[4] - 48;
                    if(Valor != 00 && Valor != 15 && Valor != 30 && Valor != 45){
                        std::cout << "\nMinutos invalidos.\n" << Valor << " Nao e 00, 15, 30 nem 45. \n";
                        valido = 0;
                    }
                }
            }else{
                std::cout << "\nHorario Invalido.\n";
                valido = 0;
            }
        }
        return(valido);
    }
    int Preco_Do_Ingresso(std::string Palavra){/*de 0 a 1000, vai até centavos*/
        int i = 0;
        int valor = 0;
        int valido = 1;


        while(Palavra[i] != '\0'){
            if(Palavra[i] == '.' || Palavra[i] == ','){
                Palavra[i] = '.';
            }else{
                if(Check_If_Number(Palavra[i]) == 0){
                    std::cout << "\n O preco do ingresso deve ser um numero nao negativo decimal.\n";
                    valido = 0;
                }
            }
            i++;
        }
        i = 0;
        if(valido == 1){
            while(Palavra[i] != '.' && Palavra[i] != '\0'){
                valor = valor*10 + Palavra[i] - 48;
                i++;
            }
        }
        std::cout << "\nTeste: Valor de " << Palavra << " = " << valor << " \n";
        if(valor == 1000 && Palavra[i] == '.'){
            if((Palavra[i+1] != '0' || Palavra[i+2] != '0')){
                std::cout << "Preco tem que ser menor que 1000.";
                valido = 0;
            }
            if(Palavra[i+3] != '\0'){
                std::cout << "Nao existe milesimo de real.";
                valido = 0;
            }
        }else{
            if(valor > 1000){
                std::cout << "Preco tem que ser menor que 1000.";
                valido = 0;
            }
        }
        return(valido);
    }
    int Numero_Da_Sala_Da_Partida(std::string Palavra){/*1 a 10, mas não faz nada*/
        int valido;
        int valor;

        valido = 1;

        if(Palavra[1] != '\0'){
            if(Check_If_Number(Palavra[0]) && Check_If_Number(Palavra[1])){
                valor = (Palavra[0] - 48)*10 + Palavra[1] - 48;
            }
        }else{
            valor = Palavra[0] - 48;
        }
        if(Palavra[0] != '-'){
            if(valor < 1 || valor > 10){
                std::cout << "\nNumero da sala invalido. (1 a 10) \n";
                valido = 0;
            }
        }else{
            std::cout << "\nNumero da sala invalido. (1 a 10) \n";
            valido = 0;
        }
        return(valido);
    }
    int Cidade_Da_Partida(std::string Palavra){/*15 dígitos, letras, espaços ou pontos. Pelo menos 1 letra. Sem espaços seguidos. Letra antes de ponto.*/
        int i = 0;
        int valido = 1;
        int TemLetra = 0;
        int TeveLetra = 0;
        int TeveEspaco = 0;

        while(Palavra[i] != '\0'){
            if(Check_If_Dot(Palavra[i])){
                TeveEspaco = 0;
                if(TeveLetra == 1){
                    TeveLetra = 0;
                    TeveEspaco = 0;
                }else{
                    std::cout << "\nSem letra antes de um ponto. \n";
                    valido = 0;
                }
                TeveLetra = 0;
            }else{
                if(Check_If_Letter(Palavra[i])){
                    TeveEspaco = 0;
                    TeveLetra = 1;
                    TemLetra = 1;
                }else{
                    if(Check_If_Space(Palavra[i])){
                        if(TeveEspaco == 1){
                            std::cout << "\nDois espacos seguidos.\n";
                            valido = 0;
                        }
                        TeveEspaco = 1;
                        TeveLetra = 0;
                    }else{
                        std::cout << "\nCaractere invalido.\n";
                        valido = 0;
                    }
                }
            }
            i++;
        }

        return(valido);
    }
    int Estado_Da_Partida(std::string Palavra){/*Um dos estados do Brasil. AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE ou TO*/
        int valido = 1;

        if(Palavra[0] != '\0' && Palavra[1] != '\0' && Palavra[2] == '\0'){
            if(Palavra[0] == 'A' || Palavra[0] == 'a'){/*AC, AL, AP, AM*/
                if(Palavra[1] != 'C' && Palavra[1] != 'c' && Palavra[1] != 'L' && Palavra[1] != 'l' && Palavra[1] != 'P' && Palavra[1] != 'p' && Palavra[1] != 'M' && Palavra[1] != 'm'){
                    std::cout << "\nEstado inexistente.\n";
                    valido = 0;
                }
            }else{
                if(Palavra[0] == 'B' || Palavra[0] == 'b'){/* BA*/
                    if(Palavra[1] != 'A' && Palavra[1] != 'a'){
                        std::cout << "\nEstado inexistente.\n";
                        valido = 0;
                    }
                }else{
                    if(Palavra[0] == 'C' || Palavra[0] == 'c'){/* CE*/
                        if(Palavra[1] != 'E' && Palavra[1] != 'e'){
                            std::cout << "\nEstado inexistente.\n";
                            valido = 0;
                        }
                    }else{
                        if(Palavra[0] == 'D' || Palavra[0] == 'd'){/* DF*/
                            if(Palavra[1] != 'F' && Palavra[1] != 'f'){
                                std::cout << "\nEstado inexistente.\n";
                                valido = 0;
                            }
                        }else{
                            if(Palavra[0] == 'E' || Palavra[0] == 'e'){/* ES*/
                                if(Palavra[1] != 'S' && Palavra[1] != 's'){
                                    std::cout << "\nEstado inexistente.\n";
                                    valido = 0;
                                }
                            }else{
                                if(Palavra[0] == 'G' || Palavra[0] == 'g'){/*GO*/
                                    if(Palavra[1] != 'O' && Palavra[1] != 'o'){
                                        std::cout << "\nEstado inexistente.\n";
                                        valido = 0;
                                    }
                                }else{
                                    if(Palavra[0] == 'M' || Palavra[0] == 'm'){/* MA, MT, MS, MG*/
                                        if(Palavra[1] != 'A' && Palavra[1] != 'a' && Palavra[1] != 'T' && Palavra[1] != 't' && Palavra[1] != 'S' && Palavra[1] != 's' && Palavra[1] != 'G' && Palavra[1] != 'g'){
                                            std::cout << "\nEstado inexistente.\n";
                                            valido = 0;
                                        }
                                    }else{
                                        if(Palavra[0] == 'P' || Palavra[0] == 'p'){/* PA, PB, PR, PE, PI*//* RJ, RN, RS, RO, RR, SC, SP, SE ou TO*/
                                            if(Palavra[1] != 'A' && Palavra[1] != 'a' && Palavra[1] != 'B' && Palavra[1] != 'b' && Palavra[1] != 'R' && Palavra[1] != 'r' && Palavra[1] != 'E' && Palavra[1] != 'e' && Palavra[1] != 'I' && Palavra[1] != 'i' ){
                                                std::cout << "\nEstado inexistente.\n";
                                                valido = 0;
                                            }
                                        }else{
                                            if(Palavra[0] == 'P' || Palavra[0] == 'p'){/* PA, PB, PR, PE, PI*/
                                                if(Palavra[1] != 'A' && Palavra[1] != 'a' && Palavra[1] != 'B' && Palavra[1] != 'b' && Palavra[1] != 'R' && Palavra[1] != 'r' && Palavra[1] != 'E' && Palavra[1] != 'e' && Palavra[1] != 'I' && Palavra[1] != 'i' ){
                                                    std::cout << "\nEstado inexistente.\n";
                                                    valido = 0;
                                                }
                                            }else{
                                                if(Palavra[0] == 'R' || Palavra[0] == 'r'){/* RJ, RN, RS, RO, RR*/
                                                    if(Palavra[1] != 'J' && Palavra[1] != 'j' && Palavra[1] != 'N' && Palavra[1] != 'n' && Palavra[1] != 'S' && Palavra[1] != 's' && Palavra[1] != 'O' && Palavra[1] != 'o' && Palavra[1] != 'R' && Palavra[1] != 'r' ){
                                                        std::cout << "\nEstado inexistente.\n";
                                                        valido = 0;
                                                    }
                                                }else{
                                                    if(Palavra[0] == 'S' || Palavra[0] == 's'){/* SC, SP, SE */
                                                        if(Palavra[1] != 'C' && Palavra[1] != 'c' && Palavra[1] != 'P' && Palavra[1] != 'p' && Palavra[1] != 'E' && Palavra[1] != 'e'){
                                                            std::cout << "\nEstado inexistente.\n";
                                                            valido = 0;
                                                        }
                                                    }else{
                                                        if(Palavra[0] == 'T' || Palavra[0] == 't'){/* TO*/
                                                            if(Palavra[1] != 'O' && Palavra[1] != 'o'){
                                                                std::cout << "\nEstado inexistente.\n";
                                                                valido = 0;
                                                            }
                                                        }else{
                                                            std::cout << "\nEstado inexistente.\n";
                                                            valido = 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }else{
            std::cout << "\nEstado inexistente. (Numero de digitos diferente de 2)\n";
            valido = 0;
        }

        return(valido);
    }
    int Disponibilidade_De_Ingressos_Da_Partida(std::string Palavra){/*0 a 250*/
        int valido = 1;
        int valor = 0;
        int i = 0;

        while(Palavra[i] != '\0'){
            if(Check_If_Number(Palavra[i])){
                valor = valor*10 + Palavra[i] - 48;
            }else{
                std::cout << "\nCaractere nao numerico.\n";
                valido = 0;
            }
            i++;
        }
        if(valor > 250){
            std::cout << "\nFora da faixa de valores validos.(0 a 250)\n";
            valido = 0;

        }
        return (valido);
    }
    int Tipo_Do_Jogo(std::string Palavra){/*1 a 4. 1 -> LOCAL, 2 -> ESTADUAL, 3 -> NACIONAL e 4 -> INTERNACIONAL.*/
        int valido = 1;
        int i = 0;


        if(Palavra[i] < 49 || Palavra[i] > 52){
            std::cout << "\nValor invalido para tipo. (1 a 4)\n";
            valido = 0;
        }

        return(valido);
    }
    int CPF_Do_Usuario(std::string Palavra){/*XXX.XXX.XXX-XX, tudo número.*/
        int valido = 1;
        int i = 0;
        int soma = 0;

        valido = valido*Check_If_Number(Palavra[0]);
        valido = valido*Check_If_Number(Palavra[1]);
        valido = valido*Check_If_Number(Palavra[2]);
        valido = valido*Check_If_Dot(Palavra[3]);
        valido = valido*Check_If_Number(Palavra[4]);
        valido = valido*Check_If_Number(Palavra[5]);
        valido = valido*Check_If_Number(Palavra[6]);
        valido = valido*Check_If_Dot(Palavra[7]);
        valido = valido*Check_If_Number(Palavra[8]);
        valido = valido*Check_If_Number(Palavra[9]);
        valido = valido*Check_If_Number(Palavra[10]);
        valido = valido*(Palavra[11] == '-');
        valido = valido*Check_If_Number(Palavra[12]);
        valido = valido*Check_If_Number(Palavra[13]);
        if(valido == 0){
            std::cout << "\nCPF invalido.5\n";
        }
        soma = (((Palavra[0]-48)*10 + (Palavra[1]-48)*9  + (Palavra[2]-48)*8 + (Palavra[4]-48)*7 + (Palavra[5]-48)*6 + (Palavra[6]-48)*5 + (Palavra[8]-48)*4 + (Palavra[9]-48)*3 + (Palavra[10]-48)*2)%11);

        if(soma/2 == 0){
            if((Palavra[12]-48) != 0){
                std::cout << "\nCPF invalido.1" << Palavra[12] << "\n";
                valido = 0;
            }
        }else{
            if((Palavra[12]-48) != 11 - soma){
                std::cout << "\nCPF invalido.2" << Palavra[12] << "\n";
                valido = 0;
            }
        }


        soma = (((Palavra[0]-48)*11 + (Palavra[1]-48)*10  + (Palavra[2]-48)*9 + (Palavra[4]-48)*8 + (Palavra[5]-48)*7 + (Palavra[6]-48)*6 + (Palavra[8]-48)*5 + (Palavra[9]-48)*4 + (Palavra[10]-48)*3 + (Palavra[12]-48)*2)%11);
        if(soma/2 == 0){
            if((Palavra[13]-48) != 0){
                std::cout << "\nCPF invalido.3" << Palavra[13] << "\n";
                valido = 0;
            }
        }else{
            if((Palavra[13]-48) != 11 - soma){
                std::cout << "\nCPF invalido.4" << Palavra[13] << "\n";
                valido = 0;
            }
        }

        return(valido);
    }


    int Senha_Do_Usuario(std::string Palavra){/*6 dígitos, letras e números. Pelo menos 1 letra maiúscula, 1 minúscula e um número. sem repetições.*/
        int valido = 1;
        int LetraMasc = 0;
        int LetraMisc = 0;
        int Numero = 0;
        int j = 0;
        int i = 0;

        while(Palavra[i] != '\0'){
            j = i + 1;
            while(j < 6 && Palavra[j] != '\0'){
                if(Palavra[i] == Palavra[j]){
                    std::cout << "\nCaractere repetido\n";
                    valido = 0;
                }
                j++;
            }
            if(Check_If_Number(Palavra[i]) == 0){
                if(Check_If_Letter(Palavra[i]) == 0){
                    std::cout << "\nCaractere invalido para senha.\n";
                    valido = 0;
                }else{
                    if(Palavra[i] > 90){/*É onde tão as letras minúsculas.*/
                        LetraMisc = 1;
                    }else{
                        LetraMasc = 1;
                    }
                }
            }else{
                Numero = 1;
            }
            i++;
        }
        if(i > 6){
            std::cout << "\nTamanho limite (6) excedido.\n";
            valido = 0;
        }else{
            if(Numero == 0){
                std::cout << "\nNenhum numero.\n";
                valido = 0;
            }else{
                if(LetraMasc == 0){
                    std::cout << "\nSem letra maiuscula.\n";
                    valido = 0;
                }else{
                    if(LetraMisc == 0){
                        std::cout << "\nSem letra minuscula.\n";
                        valido = 0;
                    }
                }
            }
        }

        return(valido);
    }
    int Numero_Do_Cartao_Do_Usuario(std::string Palavra){/*16 dígitos, cujo número segue o algorítimo de Luhn (https://en.wikipedia.org/wiki/Luhn_algorithm).*/
        int valido = 1;
        int somapares = 0;
        int somaimpares = 0;
        int i = 0;

        while(i < 16){
            valido = valido*Check_If_Number(Palavra[i]);
            i++;
        }
        i = 0;
        while(i < 16){
            somapares = somapares + ((Palavra[i]-48)*2)%10 + ((Palavra[i]-48)*2)/10;
            somaimpares = somaimpares + Palavra[i+1] - 48;/*Ó, Palavra[i] - 48 é o */
            i = i + 2;
        }
        if((somaimpares+somapares)%10 != 0){
            std::cout << "\nO algoritimo disse que nao pode.\n";
            valido = 0;
        }

        return(valido);
    }
    int Codigo_De_Seguranca(std::string Palavra){/*3 dígitos, números*/
        int valido;

        valido = Codigo_Do_Jogo(Palavra);

        return(valido);
    }
    int Data_De_Validade_Do_Cartao(std::string Palavra){/*XX/YY, XX entre 1 a 12 e YY de 0 a 99*/
        int valido = 1;
        int numero = 0;

        if(Palavra[1] == 92 || Palavra[1] == 47){
            if(Check_If_Number(Palavra[0]) == 0){
                std::cout << "\nCaractere invalido para os meses.\n";
                valido = 0;
            }else{
                if(Check_If_Number(Palavra[2]) == 0 || Check_If_Number(Palavra[3]) == 0){
                    std::cout << "\nCaractere invalido para os anos.\n";
                    valido = 0;
                }
            }
        }else{
            if(Palavra[2] == 92 || Palavra[2] == 47){
                if(Check_If_Number(Palavra[0]) == 1 && Check_If_Number(Palavra[1]) == 1){
                    numero = (Palavra[0]-48)*10 + Palavra[1] - 48;
                    if(Check_If_Number(Palavra[3]) == 0 || Check_If_Number(Palavra[4]) == 0){
                        std::cout << "\nCaracteres invalidos para os anos.\n";
                        valido = 0;
                    }else{
                        if(numero > 12 || numero == 0){
                            std::cout << "\nMes invalido.\n";
                            valido = 0;
                        }
                    }
                }else{
                    std::cout << "\nCaractere invalido para os meses.\n";
                    valido = 0;
                }
            }else{
                std::cout << "\nA barra nao ta onde devia estar\n";
                valido = 0;
            }
        }

        return(valido);
    }
};

class Testador{
private:
public:
    Testador(){}
    void manager(){
        int option = 1;
        int bom = 0;
        std::string TestStr;
        Validador Verificador;

        while(option != 0){
            option = 1;
            std::cout << "\nSelecione a funcao do validador a ser testado.\n";
            std::cout << "\n01 - Codigo do jogo.";
            std::cout << "\n02 - Codigo do ingresso.";
            std::cout << "\n03 - Nome do jogo.";
            std::cout << "\n04 - Data.";
            std::cout << "\n05 - Horario.";
            std::cout << "\n06 - Preco.";
            std::cout << "\n07 - Numero da sala.";
            std::cout << "\n08 - Cidade.";
            std::cout << "\n09 - Estado.";
            std::cout << "\n10 - Disponibilidade.";
            std::cout << "\n11 - Tipo.";
            std::cout << "\n12 - CPF.";
            std::cout << "\n13 - Senha.";
            std::cout << "\n14 - Numero do cartao.";
            std::cout << "\n15 - Codigo de seguranca.";
            std::cout << "\n16 - Data de validade.";
            std::cout << "\n00 - Sair.\n\n\n";
            std::cin >> option;
            if(option != 0){
                std::cout << "\n\nDigite a std::string a ser usada para o teste.\n";
                std::cin.ignore();
                getline(std::cin,TestStr);
            }
            //getline(std::cin,TestStr);
            switch(option){
                case(1):
                    //std::cout << " - Codigo_Do_Jogo.\n";
                    bom = Verificador.Codigo_Do_Jogo(TestStr);
                    break;
                case(2):
                    //std::cout << " - Codigo_Do_Ingresso.\n";
                    bom = Verificador.Codigo_Do_Ingresso(TestStr);
                    break;
                case(3):
                    //std::cout << " - Nome_Do_Jogo.\n";
                    bom = Verificador.Nome_Do_Jogo(TestStr);
                    break;
                case(4):
                    //std::cout << " - Data_Do_Jogo.\n";
                    bom = Verificador.Data_Do_Jogo(TestStr);
                    break;
                case(5):
                    //std::cout << " - Horario_Da_Partida.\n";
                    bom = Verificador.Horario_Da_Partida(TestStr);
                    break;
                case(6):
                    //std::cout << " - Preco_Do_Ingresso.\n";
                    bom = Verificador.Preco_Do_Ingresso(TestStr);
                    break;
                case(7):
                    //std::cout << " - Numero_Da_Sala_Da_Partida.\n";
                    bom = Verificador.Numero_Da_Sala_Da_Partida(TestStr);
                    break;
                case(8):
                    //std::cout << " - Cidade_Da_Partida.\n";
                    bom = Verificador.Cidade_Da_Partida(TestStr);
                    break;
                case(9):
                    //std::cout << " - Estado_Da_Partida.\n";
                    bom = Verificador.Estado_Da_Partida(TestStr);
                    break;
                case(10):
                    //std::cout << " - Disponibilidade_De_Ingressos_Da_Partida.\n";
                    bom = Verificador.Disponibilidade_De_Ingressos_Da_Partida(TestStr);
                    break;
                case(11):
                    //std::cout << " - Tipo_Do_Jogo.\n";
                    bom = Verificador.Tipo_Do_Jogo(TestStr);
                    break;
                case(12):
                    //std::cout << " - CPF_Do_Usuario.\n";
                    bom = Verificador.CPF_Do_Usuario(TestStr);
                    break;
                case(13):
                    //std::cout << " - Senha_Do_Usuario.\n";
                    bom = Verificador.Senha_Do_Usuario(TestStr);
                    break;
                case(14):
                    //std::cout << " - Numero_Do_Cartao_Do_Usuario.\n";
                    bom = Verificador.Numero_Do_Cartao_Do_Usuario(TestStr);
                    break;
                case(15):
                    //std::cout << " - Codigo_De_Seguranca.\n";
                    bom = Verificador.Codigo_De_Seguranca(TestStr);
                    break;
                case(16):
                    //std::cout << " - Data_De_Validade_Do_Cartao.\n";
                    bom = Verificador.Data_De_Validade_Do_Cartao(TestStr);
                    break;
            }
            if(option != 0){
                if(bom == 0){
                    std::cout << "\nEntrada Invalida.\n";
                }else{
                    std::cout << "\nEntrada Valida.\n";
                }
            }
        }
    }


    int RunAll(){
        int i = 0;
        std::string Palavra;
        Validador Verificador;

        /*
        Verificador.Cidade_Da_Partida()
        */
    }
};

class Visitante{
private:
public:
    Visitante(){}
    void Ver_Horarios_Jogos(){
        std::cout << "\nTem que fazer no futuro.\n";
    }
    Menu_Visitante(){
        int Option = 1;

        while(Option != 0){
            std::cout << "\nSelecione uma opcao.";
            std::cout << "\n1 - Mostrar Jogos.";
            std::cout << "\n2 - Mostrar custos das partidas.";
            std::cout << "\n0 - Sair.\n";
            std::cin >> Option;
            switch(Option){
                case(1):
                    break;
                case(2):
                    break;
            }
        }
    }


};

class Usuario: public Visitante{
private:
    std::string CPF;
    std::string Senha;
public:
    Usuario(std::string _CPF, std::string _Senha){
        CPF = _CPF;
        Senha = _Senha;
    }
    Usuario(){
        CPF = "000.000.000-00";
        Senha = "Nenhuma.";
    }
    Create(){
        Validador Val_User;


        std::cout << "\nDigite o seu CPF. \n";
        std::cin >> CPF;
        while(Val_User.CPF_Do_Usuario(CPF) == 0){
            std::cout << "\nDigite o seu CPF.\n";
            std::cin >> CPF;
        }
        std::cout << "\nDigite sua senha. \n";
        std::cin >> Senha;
        while(Val_User.Senha_Do_Usuario(Senha) == 0){
            std::cout << "\nDigite sua senha.\n";
            std::cin >> Senha;
        }
    }
    std::string Get_CPF(){
        return(CPF);
    }
    void Set_CPF(std::string _CPF){
        CPF = _CPF;
    }
    void Set_CPF(){
        std::cout << "\nDigite uma nova senha. \n";
        std::cin >> Senha;
    }
    std::string Get_Senha(){
        return(Senha);
    }
    void Set_Senha(std::string _Senha){
        Senha = _Senha;
    }
    void Set_Senha(){
        std::cout << "\nDigite uma nova senha. \n";
        std::cin >> Senha;
    }
    void Comprar_Ingresso(){
        /*Fazer*/
    }
};

class Administrador: public Usuario{
private:
public:
    Administrador(){};
    void Criar_Jogo(){
        /*Fazer*/
    }
    void Criar_Partida(){
        /*Fazer*/
    }

};

class Jogo{
private:
    std::string Codigo;
    std::string Nome;
    std::string Cidade;
    std::string Estado;
    std::string Tipo;
public:
    Jogo(){}
    Create(){
        std::cout << "\nInforme o Codigo Do Jogo.\n";
        std::cin >> Codigo;
        std::cout << "\nInforme o Nome Do Jogo.\n";
        std::cin >> Nome;
        std::cout << "\nInforme a Cidade que vai cediar o Jogo.\n";
        std::cin >> Cidade;
        std::cout << "\nInforme o Estado que vai cediar o Jogo.\n";
        std::cin >> Estado;
        std::cout << "\nInforme o Tipo Do Jogo.\n";
        std::cin >> Tipo;
    }
    std::string Get_Codigo(){
        return(Codigo);
    }
    std::string Get_Nome(){
        return(Nome);
    }
    std::string Get_Cidade(){
        return(Cidade);
    }
    std::string Get_Estado(){
        return(Estado);
    }
    std::string Get_Tipo(){
        return(Tipo);
    }

};

class Partida{
private:
    std::string Codigo;
    std::string Data;
    std::string Horario;
    std::string Preco;
    std::string Disponibilidade;
public:
    Partida(){}
    Create(){
        std::cout << "\nInforme o Codigo Da Partida.\n";
        std::cin >> Codigo;
        std::cout << "\nInforme a data da partida.\n";
        std::cin >> Data;
        std::cout << "\nInforme o horario da partida.\n";
        std::cin >> Horario;
        std::cout << "\nInforme o preco da partida.\n";
        std::cin >> Preco;
        std::cout << "\nInforme a disponibilidade de ingressos da partida.\n";
        std::cin >> Disponibilidade;
    }
    std::string Get_Codigo(){
        return(Codigo);
    }
    std::string Get_Data(){
        return(Data);
    }
    std::string Get_Horario(){
        return(Horario);
    }
    std::string Get_Preco(){
        return(Preco);
    }
    std::string Get_Disponibilidade(){
        return(Disponibilidade);
    }


};

class Ingresso{
private:
    std::string Codigo;
public:
    Ingresso(){
        std::cout << "\nInforme o Codigo do Ingresso.\n";
        std::cin >> Codigo;
    }
    std::string Get_Codigo(){
        return(Codigo);
    }

};

class Cartao_De_Credito{
private:
    std::string Numero;
    std::string Codigo;
    std::string Data;
public:
    Cartao_De_Credito(){
        std::cout << "\nInforme o numero do cratao de credito. \n";
        std::cin >> Numero;
        std::cout << "\nInforme o codigo do cratao de credito. \n";
        std::cin >> Codigo;
        std::cout << "\nInforme a data do cratao de credito. \n";
        std::cin >> Data;
    }
    std::string Get_Numero(){
        return(Numero);
    }
    std::string Get_Codigo(){
        return(Codigo);
    }
    std::string Get_Data(){
        return(Data);
    }

};

class Gerenciador_Login{
private:
public:
    Gerenciador_Login(){}

    int Login(int* Indice, std::vector<Usuario> Lista_Usuarios, std::vector<Administrador> Lista_Admin){
        std::string CPF;
        std::string Senha;
        std::string Auxiliar;
        int Qual_lista = 0;
        int i = 0;
        int Achou = 0;

        std::cout << "\nDigite o seu CPF.\n";
        std::cin >> CPF;
        while(i < Lista_Usuarios.size() && Achou == 0){
            Auxiliar = Lista_Usuarios[i].Get_CPF();
            Achou = Geral_Comparador(Auxiliar,CPF);
            i++;
        }
        if(Achou == 0){
            i = 0;
        }else{
            Qual_lista = 1;
        }
        while(i < Lista_Admin.size() && Achou == 0){
            Auxiliar = Lista_Admin[i].Get_CPF();
            Achou = Geral_Comparador(Auxiliar,CPF);
            i++;
        }
        if(Achou == 0){
            std::cout << "\nCPF nao cadastrado.\n";
            *Indice = -1;
            return(0);
        }else{
            i--;
            if(Qual_lista == 0){
                Qual_lista = 2;
            }
            std::cout << "\nDigite a sua senha.\n";
            std::cin >> Senha;
            switch(Qual_lista){
                case(1):
                    Auxiliar = Lista_Usuarios[i].Get_Senha();
                    break;
                case(2):
                    Auxiliar = Lista_Admin[i].Get_Senha();
                    break;
            }
            if(Geral_Comparador(Auxiliar,Senha)){
                *Indice = i;
            }else{
                std::cout << "\nSenha Incorreta.\n";
                *Indice = -1;
                Qual_lista = 0;
            }
            return(Qual_lista);
        }
    }
};

class Menu{
private:
public:
    Menu(){}

    Menu_Usuario(){
        /*Nada*/
    }
    Menu_Admin(){
        /*Nada*/
    }
};

int main(){
    int i = 0;
    int seletor = 1;
    int* Indice_Lista;
    std::vector<Usuario> Lista_Usuarios;
    std::vector<Administrador> Lista_Admin;
    Gerenciador_Login Logador;
    Usuario New_User;
    Administrador New_Admin;
    Testador Tester;
    std::vector<Jogo> Lista_Games;
    std::vector<Partida> Lista_Matches;
    Jogo Game;
    Partida Match;


    Indice_Lista = (int*)malloc(sizeof(int));
    if(Modo_Teste_Validador_Prog){
        while(seletor != 0){
            std::cout << "\nSelecione uma opcao.";
            std::cout << "\n1 - Teste manual das entradas.";
            std::cout << "\n2 - Teste automatico das entradas.";
            std::cout << "\n0 - Sair.\n";
            std::cin >> seletor;
            switch(seletor){
                case(1):
                    Tester.manager();
                    break;
                case(2):
                    Tester.RunAll();
                    break;
                default:
                    break;
            }
        }
    }else{
        while(seletor != 0){
            std::cout << "\nSelecione uma opcao.";
            std::cout << "\n1 - Visualizar Jogos.";
            std::cout << "\n2 - Cadastrar.";
            std::cout << "\n3 - Cadastrar Administrador.";
            std::cout << "\n4 - Login.";
            std::cout << "\n0 - Sair.\n";
            std::cin >> seletor;
            switch(seletor){
                case(1):
                    break;
                case(2):
                    New_User.Create();
                    Lista_Usuarios.push_back(New_User);
                    for(i = 0; i < Lista_Usuarios.size();i++){
                        std::cout <<  "\nUsuario " << i  << ": " << Lista_Usuarios[i].Get_CPF();
                        std::cout <<  "\nSenha: " << Lista_Usuarios[i].Get_Senha();
                        std::cout <<  "\n";
                    }
                    break;
                case(3):
                    New_Admin.Create();
                    Lista_Admin.push_back(New_Admin);
                    for(i = 0; i < Lista_Admin.size();i++){
                        std::cout <<  "\nUsuario " << i  << ": " << Lista_Admin[i].Get_CPF();
                        std::cout <<  "\nSenha: " << Lista_Admin[i].Get_Senha();
                        std::cout <<  "\n";
                    }
                    break;
                case(4):
                    switch(Logador.Login(Indice_Lista, Lista_Usuarios, Lista_Admin)){
                        case(0):
                            break;
                        case(1):
                            std::cout << "\nBem-vindo Usuario: " << Lista_Usuarios[*Indice_Lista].Get_CPF() << "\n";

                            break;
                        case(2):
                            std::cout << "\nBem-vindo Administrador: " << Lista_Admin[*Indice_Lista].Get_CPF() << "\n";
                            break;
                    }
                default:
                    break;
            }
        }
    }



return(0);
}
