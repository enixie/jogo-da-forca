#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <new>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){

    //Vetor com palavras disponiveis
    string palavras[6] = {"abacaxi", "manga", "morango", "abacate", "banana", "acerola"};
    //Indice gerado no intervalo {0, 1, 2}
    int indiceAleatorio = rand() % 3;

    //Exibe a palavra aleatoria
    //cout << palavras [indiceAleatorio];

    return palavras [indiceAleatorio];

}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){

    int cont =0;
    string palavraComMascara;

    //Coloca uma mascara
    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){

        //cout << "A palavra secreta eh: " << palavra << "(Tamanho: " << tamanhoDaPalavra << ")";
        cout << mensagem;
        cout << "\nPalavra: " << palavraComMascara << "(Tamanho: " << tamanhoDaPalavra << ")";
        cout << "\nTentativas: " << tentativasRestantes;

        //Exibe as letras arriscadas
        int cont;
        cout << "\nLetras arriscadas: ";
        for(cont =0; cont < letrasJaArriscadas.size(); cont++){
            cout << letrasJaArriscadas[cont] << ", ";
        }

}

int jogar(int numeroDeJogadores){

    //Palavra a ser adivinhada
    string palavra;

    //Confere o numero de jogadores
    if(numeroDeJogadores == 1){

        //Palavra a ser adivinhada
        string palavra = retornaPalavraAleatoria();

    }else{
        cout << "\nDigite uma palavra: ";
        cin >> palavra;
    }

    //Tamanho da palavra
    int tamanhoDaPalavra = palavra.size();

    //Palavra Mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    ///Variaveis Gerais
    int tentativas = 0, maximoDeTentativas = 6;             //numero de tentativas e erros
    int cont =0;                                            //auxiliar para lacos de repeticao
    char letra;                                             //letra arriscada pelo usuario
    int opcao;                                              //Opcoes finais
    string letrasJaArriscadas;                              //Acumula as tentativas do jogador
    string mensagem = "Bem vindo ao jogo!";                 //Feedback do jogador
    string palavraArriscada;                                //Arrisca a palavra completa
    bool jaDigitouLetra = false, acertouLetra = false;      //Auxiliar para saber se a letra ja foi digitada

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){


        limpaTela();

        //Exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);

        //Lê um palpite
        cout << "\nDigite uma letra (ou digite 1 para arriscar a palavra): ";
        cin >> letra;

        //Digitando 1 o usuario pode arriscar a palavra
        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
            }else{
                tentativas = maximoDeTentativas;
            }
        }

        //Percorre as letras ja arriscadas
        for(cont = 0; cont < tentativas; cont++){

            //Se encontrar a letra
            if(letrasJaArriscadas[cont] == letra){

                    mensagem = "Essa letra ja foi digitada!";
                    //Indica com a variável booleana
                    jaDigitouLetra = true;
            }
        }

        //Se for uma letra nova
        if(jaDigitouLetra == false){

            //Incrementa as letras ja arriscadas
            letrasJaArriscadas += tolower(letra);

        //Percorre a palavra real e se a letra existir, muda  apalavra com mascara
        for(cont = 0; cont < tamanhoDaPalavra; cont++){
            //Se a letra existir na palavra escondida
            if(palavra[cont] == tolower(letra)){

                //Faz a letra aparecer na palavara com mascara
                palavraComMascara[cont] = palavra[cont];

                acertouLetra = true;
            }
        }

            if(acertouLetra == false){

                mensagem = "Voce errou!";

            }else{
                mensagem = "Voce acertou uma letra!";
                acertouLetra = false;
            }

            //Aumenta uma tentativa
            tentativas++;
        }

        //Reinicia auxiliares
        jaDigitouLetra = false;
        acertouLetra = false;
    }

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "Parabens, voce venceu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1 - Sim";
        cout << "\n2 - Nao";
        cin >> opcao;
        return opcao;

    }else{
        limpaTela();
        cout << "Voce perdeu!";
        cout << "\nDeseja reiniciar?";
        cout << "\n1 - Sim";
        cout << "\n2 - Nao";
        cin >> opcao;
        return opcao;
    }
}

void menuInicial(){
     //Opção escolhida pelo usuário
    int opcao = 0;

    //Enquanto o jogador não digita uma opcao valida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
    limpaTela();
    cout << "\nBem vindo!";
    cout << "\n1 - Jogar Sozinho";
    cout << "\n2 - Jogar em Dupla";
    cout << "\n3 - Sobre";
    cout << "\n4 - Sair";
    cout << "\nEscolha uma opcao e tecle ENTER: ";

    //Faz a leitura da opcao
    cin >> opcao;

        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                if(jogar(1) == 1){
                    menuInicial();
                }
                break;
            case 2:
                //Inicia o jogo
                if(jogar(2) == 2){
                    menuInicial();
                }
                break;

            case 3:
                //Mostra informacoes do jogo
                cout << "\nInformacoes do jogo";
                limpaTela();
                cout << "Jogo da forca desenvolvido por Evelyn - 2024\n";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair";
                cin >> opcao;
                if(opcao == 1){
                    menuInicial();
                }
                break;
            case 4:
                //Sai do jogo
                cout << "\nAte mais!";
                break;
        }
    }
}

int main(){

    //Para gerar numeros realmente aleatórios
    srand ((unsigned)time(NULL));

    menuInicial();

    return 0;
}

