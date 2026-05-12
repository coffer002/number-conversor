//version 1.2;
//conversor de bases <= 10 :  2, 4, 8 e 10;
#include <stdio.h>

//Se quiserem fazer sem separar as funcoes só substituir onde elas sao chamadas, mas ficaria com uma identação infinitamente larga;
//Outra coisa que acho que o professor nao comentou, mas return é oq volta da funcao, por ex.: f(a, b) = c, logo se existir um return, ele vai ser c; 
//Ainda sobre o return, caso seja return 0, significa sucesso e qualquer outro numero fora de contexto significa erro;
//No caso, um dos contextos é em validacao, onde o return 1 pode ser entendido também como booleano de verdadeiro;
//sobre nomeclatura, nome de metodos, maiusculos e minusculos, acho que tanto faz, mas usei a convenção que aprendi no Java;

int valido(long long num, int base){
	
	//permite o codigo rodar <-> a%(10^n) <= base
    for(; num > 0; num /= 10){
    	//parametro = parametro pode ser omitido, entao só ";" como primeiro parametro da iteração funciona legal, nesse caso seria num = num, mas ele já é declarado, entao seria a toa;
		//num /= 10 é a mesma coisa que num = num / 10, da mesma forma que qualquer outro operador (+, *, etc);
        if(num % 10 >= base) {
            return 0;}}
    return 1;}

//long long pode ser substituído por int, double, float, short ou qualquer outro tipo de variável numérica; apenas deixei long long por armazenar valores maiores e porque, neste caso, não há problemas de memória ou tempo de processamento.
//e n passar o n° de casas maximo; e eu ja acho pouco, queria fazer com str, mas n deixaram...
long long paraDecimal(long long num, int origem) {
	//retorna em base 10
    long long decimal = 0;
    long long potencia = 1;

 // ate poderia ser declarado apenas em uma linha, mas para q kkkkk, no caso long long deciml = 0, potencia = 0; ou int decimal = 0, potencia = 0;    
 //Mas, declare os 2 a mesma coisa, se n vai dar pau ali em baixo por serem diferentes;

    for (; num > 0; num /= 10, potencia *= origem){
        decimal += (num % 10) * potencia;}
 // Em     num /= 10, potencia *= origem     são oq desejo que aconteça a cada loop;
    return decimal;}


void imprimirNaBase(long long decimal, int base) {
    if (decimal == 0) {
        printf("0");
        return;}
 
    // Conta quantos digitos o resultado vai ter;
    int digitos = 0;
    long long temp = decimal;

    //temp é, nesse caso, um buf
    for (; temp > 0; temp /= base) {
        digitos++;}
 
    // Calcula a maior potencia: base^(digitos-1);
    long long potencia = 1;

    for (int i = 0; i < digitos - 1; i++){
        potencia *= base;} 
    // printa cada digito do mais significativo ao menos;
    for (int i = 0; i < digitos; i++, potencia /= base) {

        printf("%lld", decimal / potencia);
        //acho que nem precisava deixar isso comentado, mas enfim, %lld é para long, use %d se declarou anteriormente como int ;
        decimal %= potencia;}
}

int main() {
    long long num, decimal;
    int baseOrigem, baseDestino, flag, r = 0;
    //r = resposta do usuario; 
 
    printf("\n\n\nConversor de bases (2, 4, 8 e 10)\n\n\n\n"); 

    while (1) {  

        if (r) {
            printf("\n\n\n\n\n\n\n\n Numero atual (base 10): %lld\n", decimal);} 
		else {

            printf("\nDigite o numero a ser convertido       : ");
            scanf("%lld", &num);
 
            if (num < 0) {

                // nao sei como faz para valores negativos;
                printf("Erro: apenas numeros >= 0 sao suportados.\n");
                continue;} 

            printf("Digite a base de origem (2, 4, 8 ou 10): ");
            scanf("%d", &baseOrigem);
 
            if(baseOrigem != 2 && baseOrigem != 4 && baseOrigem != 8 && baseOrigem != 10){

			    printf("Erro: base de origem invalida. Use 2, 4, 8 ou 10.\n");		
                continue;}

            if (!valido(num, baseOrigem)) {

                printf("Erro: o numero %lld possui digito(s) invalido(s) para a base %d.\n",
                       num, baseOrigem);
                continue;} 
            decimal = paraDecimal(num, baseOrigem);
        }
 
        printf("Digite a base de destino (2, 4, 8 ou 10): ");
        scanf("%d", &baseDestino);
 
        if (baseDestino != 2 && baseDestino != 4 && baseDestino != 8 && baseDestino != 10) {

        	printf("Erro: base de destino invalida. Use 2, 4, 8 ou 10.\n");
        	r = 0;
        	continue;}

        printf("\nResultado em base %d: ", baseDestino);

        if (baseDestino == 10) {
            printf("%lld", decimal);}
		else {
            imprimirNaBase(decimal, baseDestino);}

        printf("\n");
        r = 1;
 
        printf("\n\n\n\n\nO que deseja fazer agora?\n");
        printf("   1 - Converter um novo numero\n");
        printf("   2 - Reutilizar o resultado acima como entrada\n");
        printf("   3 - Fechar o programa\n");

        printf("resposta: ");
        scanf("%d", &flag);        
 
        if (flag == 1) {

			printf("\n\n\n\n\n");
            r = 0;}
            
		else if (flag == 2) {

            printf("\nReutilizando o resultado anterior como novo numero de entrada.\n");
            // r== 1, resultado = num e baseDestino = baseOrigem; 
            baseOrigem = 10;}
		else if (flag == 3) {

            break;}
		else {
            printf("?????\n");
            r = 0;}
    } 
    return 0;
}
