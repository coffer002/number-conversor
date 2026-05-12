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
            return 0;}
    }
    return 1;
}
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
    return decimal;
}
void imprimirNaBase(long long decimal, int base) {
    if (decimal == 0) { printf("0"); return; }
 
    // Conta quantos digitos o resultado vai ter;
    int digitos = 0;
    long long temp = decimal;
    //temp é, nesse caso, um buf

    for (; temp > 0; temp /= base) digitos++;
 
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
    long long num;
    int baseOrigem;
 

    printf("\n\n\nConversor de bases (2, 4, 8 e 10)\n\n\n\n");

 
    printf("Digite o numero a ser convertido       : ");
    scanf("%lld", &num);
 
    printf("\nDigite a base de origem (2, 4, 8 e 10): ");
    scanf("%d", &baseOrigem);
 
    if (baseOrigem != 2 && baseOrigem != 4 && baseOrigem != 8 && baseOrigem != 10) {
        printf("\nErro: a base nao eh 2, 4, 8 ou 10.\n");
        return 1;
    }
 
    if (num < 0) {
    	//nao sei como faz para valores negativos;
        printf("\nErro: o numero deve ser >= 0.\n");
        return 1;
        
    }
     	
 	
    if (!valido(num, baseOrigem)) {
        printf("\nErro: o numero %lld possui digito(s) invalido(s) para a base %d.\n", num, baseOrigem);
        return 1;
    }
 
    long long decimal = paraDecimal(num, baseOrigem);
 
    printf("Base       / Resultado \n");
    printf("-------------------------------------\n");

 
 
    //Itera apenas sobre as bases desejadas: 2, 4, 8 e 10, mas se quisesse retirar ia ser de 2 a 10..., nao sei como fazer sem array kkkkk, mas deve dar se vcs pensarem um pouco, acho que teria que fazer para cada base individualmente;
    //Talvez com algum loop fori de base *= 2 e apenas a base 10 separada;
    //Ou se quiserem pedir a base final e apresentar so 1 tem como, mas vcs qm sabem;    
    int bases[] = {2, 4, 8, 10};
    for (int i = 0; i < 4; i++) {
        int b = bases[i];
        printf("Base  %2d   / ", b);
        imprimirNaBase(decimal, b);
        if (b == baseOrigem) printf("   <- base original");
        //desnecessario se for colocar do jeito q supracitei, pedindo qual a baseDestino;
        printf("\n");}
  
    return 0;
}
