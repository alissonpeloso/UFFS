//1)Crie uma função para calcular o fatorial de um valor, por exemplo, se recebermos o valor 4, então o seu fatorial será 24

function fat(number){
    let solve = number;
    for(let i = solve-1; i > 0; i--){
        solve *= i;
    }
    return solve;
}

// 2)O triângulo é uma figura que possui três lados, e
// dependendo dos valores dos lados sua classificação pode
// ser equilátero, isósceles e escaleno dependendo se a
// quantidade de lados iguais forem respectivamente três, dois
// e nenhum. Faça uma função que receba três lados e diga
// que tipo de triângulo é.

function typeTriangle(a,b,c){
    if(( a < (b + c)) && (b < (a + c)) && (c < a + b)){
        console.log("Triângulo válido!");

        if(a == b && a == c){
            console.log("Triângulo equilatero!");
        }
        else if(a === b || a === c || b === c){
            console.log("Triângulo isósceles!");
        }
        else{
            console.log("Triângulo escaleno!");
        }
    }
    else{
        console.log("Triângulo inválido!");
    }
}

// 3)Crie uma função que receba um parâmetro X e retorne um
// array com os números primos de 1 até X; Por exemplo, ao
// receber o valor 4 o retorno será 2, 3, 5, 7 (Obs. Guarde o
// array gerado para ser utilizado novamente e facilitar o
// cálculo na próxima chamada)

function isPrime(value){
    let prime = true;
    for(let i = 2; i <= value/2; i++){
        if(value%i == 0){
            prime = false;
        }
    }
    return prime;
}

var primeVector = Array();

function primesToX(x){
    console.log(x);
    if(x <= primeVector.length){
        return primeVector.slice(0, x);
    }
    else{
        let n;
        if(primeVector.length == 0){
            n = 2;
        }
        else{
            n = primeVector[primeVector.length-1]+1;
            x -= primeVector.length;
        }
        console.log("valor de n: "+n);
        while(x > 0){
            if(isPrime(n)){
                primeVector.push(n);
                x--;
            }
            n++;
        }
        return primeVector;
    }
}